// Computer Vision Assignment 12-2
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// 함수 선언부
void detect_by_bs(vector<Rect>, VideoCapture); // background-subtraction을 이용한 검출
void detect_by_pd(vector<Rect>, VideoCapture); // pedestrain detection을 이용한 검출(HoG)

int main()
{
    VideoCapture cap; // 영상을 다루기 위한 객체
    Mat frame; // 영상을 구성하는 프레임
    
    int valid_open; // 영상 정상로딩 여부를 표시하는 변수
    int frame_rate; // 프레임 수를 불러오기 위한 부분
    vector<Rect> found; // 식별한 정보를 저장하는 Vector
    
    valid_open = cap.open("background.mp4"); // 보행자 탐지를 진행할 영상 로딩
    frame_rate = cap.get(CAP_PROP_FPS); // 해당 영상의 fps 값을 구함
    
    // 예외처리 - 열 파일을 찾지 못한 경우
    if(valid_open == 0) {
        cout << "Error! : No such file!" << endl;
        return -1;
    }
    
    // 탐색을 진행하는 부분
    detect_by_bs(found, cap); // 보행자 검출 수행
    
    return 0;
}



// background-subtraction을 이용하여 보행자를 검출
void detect_by_bs(vector<Rect> found, VideoCapture cap)
{
    Mat avg, bg, img, gray_img, fgMask, image; // average image
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(10, 10));
    int fps = cap.get(CAP_PROP_FPS); // store fps value
    int count = 0; // store drawn rectangles
    int area; // 찾은 boundrect의 넓이
    vector<vector<Point>> contours; // store count info
    vector<Vec4i>hierarchy;
        
    cap >> bg; // 영상의 첫번째 프레임을 배경으로 설정함
    cvtColor(bg, bg, CV_BGR2GRAY); // convert color-scale to gray
    
    // 비디오의 매 프레임을 읽어오면서 적절한 처리를 수행함
    while(true)
    {
        if(!cap.read(img)) {
            cout << "The video is the end!" << endl;
            break;
        }
        
        cvtColor(img, gray_img, CV_BGR2GRAY);
        absdiff(bg, gray_img, fgMask);
        threshold(fgMask, fgMask, 60, 255, THRESH_BINARY);
        dilate(fgMask, fgMask, element); // 1차 dilation 수행
        dilate(fgMask, fgMask, element); // 1차 dilation 수행
        dilate(fgMask, fgMask, element); // 1차 dilation 수행
        findContours(fgMask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

        vector<Rect> boundRect(contours.size()); // store boundRect info
        for (int i=0 ; i < contours.size() ; i++)
            boundRect[i] = boundingRect(Mat(contours[i]));

        // 찾아낸 Bound rectangle을 바탕으로 하여 인식한 사람의 수를 계산함
        for (int i = 0; i < contours.size(); i++)
        {
            area = boundRect[i].area(); // 생성된 boundrect의 넓이를 구함
            // 사람의 동선이 겹치는 부분으로 인하여 round rect가 하나로 합쳐지는 부분에 대한 처리
            if(area > 60000) count += 3;
            else if(area > 35000) count += 2;
            else if(area > 2000) count++; // 일반적인 경우 인식되는 사람의 수를 카운트 하기 위한 파트
        }
        
        // 계산한 결과를 화면에 출력
        putText(img, format("#Number of people: %d", count), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 4);
        count=0; // 다음 frame에 대한 count를 위해서 count값 초기화
        imshow("Number of people", img); // 원본 이미지를 출력
        waitKey(1000 / fps);
    }
}



// pedestrain detection을 이용하여 보행자를 검출
// -> 해당 함수는 생각보다 인식률이 많이 떨어져서 솔루션 코드에는 포함시키지 않음
void detect_by_pd(vector<Rect> found, VideoCapture cap)
{
    Mat input; // 입력
    Mat frame; // 영상을 구성하는 frame
    int fps = cap.get(CAP_PROP_FPS); // 사용하는 해당 영상의 fps 값을 산출
    
    // detector (48x96 template)
    HOGDescriptor hog(Size(48, 96), Size(16, 16), Size(8, 8), Size(8, 8), 9);
        
    hog.setSVMDetector(HOGDescriptor::getDaimlerPeopleDetector());

    while (1)
    {
        cap >> frame;
        if (frame.empty()) break;
        
        // 보행자 탐지 수행
        hog.detectMultiScale(frame, found, 0.5, Size(8, 8), Size(), 1.05, 4);
        
        for (int i = 0; i < (int)found.size(); i++)
            rectangle(frame, found[i], Scalar(0, 255, 0), 2);
        
        // 인식결과를 프레임에 텍스트 형식으로 출력
        putText(frame, format("#Number of people: %d", (int)found.size()), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 4);
        imshow("Pedestrian Detection", frame);
        waitKey(1000 / fps);
    }
}
