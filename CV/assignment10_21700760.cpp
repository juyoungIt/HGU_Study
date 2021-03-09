// Computer Vision Assignment10 - Background Subtraction
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap("background.mp4");
    Mat avg; // store average image
    Mat bg;  // store background image
    Mat img; // store current frame
    Mat fgMask; // store foreground mask
    int cnt = 2; // store frame count
    int fps = cap.get(CAP_PROP_FPS); // store fps value
    int count = 0; // store drawn rectangles
    vector<vector<Point>> contours; // store count info
    vector<Vec4i>hierarchy;
    
    cap >> avg; // assign first frame to avg
    cvtColor(avg, avg, CV_BGR2GRAY); // convert color-scale to gray
    
    // calculate background image
    // first 10 frames of "background.mp4"
    while(cnt <= 10) {
        
        if(!cap.read(img)) {
            cout << "Error! : Cannot read 10-frames" << endl;
            break; // no more reading frame -> break
        }
        cvtColor(img, img, CV_BGR2GRAY); // convert color-scale to gray
        add(img/cnt, avg*(cnt-1)/cnt, avg);
        cnt++;
    }
    bg = avg.clone(); // deepcopy to bg
    
    // 3. Generate a binary image by using the following equation
    while(true) {
        if(!cap.read(img)) {
            cout << "The video is the end!" << endl;
            break;
        }
        cvtColor(img, img, CV_BGR2GRAY); // convert color-sacle to gray
        absdiff(bg, img, fgMask);
        threshold(fgMask, fgMask, 20, 255, CV_THRESH_BINARY); // threshold
        findContours(fgMask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); // find contours
        
        //defining bounding rectangle
        vector<Rect> boundRect(contours.size()); // store boundRect info
        for (int i=0 ; i < contours.size() ; i++)
            boundRect[i] = boundingRect(Mat(contours[i]));
        //draw rectangles on the contours
        for (int i = 0; i < contours.size(); i++) {
            if(boundRect[i].area() > 400) {
                rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 255, 255), 2, 8, 0);
                count++;
            }
        }
        putText(img, format("#Rect: %d", count), Point(10, 30),
                FONT_HERSHEY_SIMPLEX, 1, Scalar(255), 4); // printout the text of object count info
        count=0; // reset the count value
        
        imshow("background subtraction", img);
        waitKey(1000 / fps);
    }
    return 0;
}
