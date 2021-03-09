// Computer Vision Assignment11
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap("background.mp4");
    Mat avg, bg, img, fgMask, image; // average image
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(10, 10));
    int cnt = 2; // store frame count
    int fps = cap.get(CAP_PROP_FPS); // store fps value
    int count = 0; // store drawn rectangles
    int area; // 찾은 boundrect의 넓이
    vector<vector<Point>> contours; // store count info
    vector<Vec4i>hierarchy;
    
    cap >> avg; // assign first frame to avg
    cvtColor(avg, avg, CV_BGR2GRAY); // convert color-scale to gray
    
    // 처음 10프레임을 해당 영상의 배경이미지로 설정함
    while(cnt <= 10)
    {
        if(!cap.read(img)) {
            cout << "Error! : Cannot read 10-frames" << endl;
            break; // no more reading frame -> break
        }
        cvtColor(img, img, CV_BGR2GRAY); // 읽어들인 프레임을 gray-scale로 변경
        add(img/cnt, avg*(cnt-1)/cnt, avg);
        cnt++;
    }
    bg = avg.clone(); // 얻어낸 배경이미지에 대한 값을 deepcopy 함
    
    // 비디오의 매 프레임을 읽어오면서 적절한 처리를 수행함
    while(true)
    {
        // 더 이상 읽어올 프레임이 존재하지 않는 경우 -> 메시지를 출력한 후 프로그램 종료
        if(!cap.read(img)) {
            cout << "The video is the end!" << endl;
            break;
        }
        
        cvtColor(img, img, CV_BGR2GRAY); // 읽어온 프레임의 색상을 gray-scale로 변경함
        absdiff(bg, img, fgMask); // background subtraction 수행
        threshold(fgMask, fgMask, 50, 255, THRESH_BINARY); // threshold 수행
        // imshow("before", fgMask);
        
        // 인식의 정확도를 높이기 위한 부분
        // dilation을 여러회차 반복하여 수행함으로서 존재하는 노이즈나 빈공간을 삭제함
        // -> 인식의 정확도 향상이 목적이므로 크기가 커지는 현상은 크게 문제가 되지 않음
        // -> erosion을 사용하여 이를 더 개선할 수 있지만 정확도에 큰 영향을 미치지 않으므로 연산회수를 줄이기 위해 따로 넣지 않음
        dilate(fgMask, fgMask, element); // 1차 dilation 수행
        dilate(fgMask, fgMask, element); // 2차 dilation 수행
        dilate(fgMask, fgMask, element); // 3차 dilation 수행
        
        // imshow("after", fgMask); // 테스트를 위한 디버깅 코드파트

        // countours의 갯수를 카운트 함
        findContours(fgMask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
        
        // bounding rectangle을 정의함
        vector<Rect> boundRect(contours.size()); // store boundRect info
        for (int i=0 ; i < contours.size() ; i++)
            boundRect[i] = boundingRect(Mat(contours[i]));
        
        // 찾아낸 bounding rectangle을 그려냄
        for (int i = 0; i < contours.size(); i++)
        {
            area = boundRect[i].area();
            
            // 사람의 동선이 겹치는 부분으로 인하여 round rect가 하나로 합쳐지는 부분에 대한 처리
            if(area > 60000) count += 3;
            else if(area > 30000) count += 2;
            // 일반적인 경우 인식되는 사람의 수를 카운트 하기 위한 파트
            else if(area > 1200) count++;
        }
        
        // 계산한 결과를 화면에 출력
        putText(img, format("#Number of people: %d", count), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255), 4);
        count=0; // 다음 frame에 대한 count를 위해서 count값 초기화
        imshow("Number of people", img); // 원본 이미지를 출력
        waitKey(1000 / fps);
    }
    return 0;
}
