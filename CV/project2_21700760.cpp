// Computer Vision project2 - detect lane departure
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat frame;                             // store information of frame
    Mat gray_frame;                        // store gray-scale frame of video
    VideoCapture cap;                      // store information of video
    Mat center_roi;   // for center roi
    Mat center_canny; // center roi canny edge detection result
    Rect center_rect(600, 400, 100, 200);  // for center roi
    // The set of lines
    Point p1, p2;                 // points to draw line
    vector<Vec2f> center_lines;   // the set of lines in center roi
    int print_count = 0;          // for print out warning message
    const int print_wait = 30;    // The constant for message delay time(30-frames delay)
    
    // 1. Read Road.mp4
    // Exception handling1 - could not find designated file
    if(cap.open("Road.mp4") == 0) {
        cout << "No such file!" << endl;
        waitKey(0);
    }
    
    // processing each frame of "Road.mp4"
    while(1)
    {
        cap >> frame; // get frame of "Road.mp4"
        cvtColor(frame, gray_frame, CV_BGR2GRAY); // convert to gray-scale image
            
        // Exception handling2- no more frames of video
        if(frame.empty()) {
            cout << "The end of the video!" << endl;
            break; // terminate the program
        }
        // print out the frame between 0 ~ 35sec
        if(cap.get(CAP_PROP_POS_MSEC) > 1000 * 35) {
            break;
        }
            
        // 2. Set left_roi and right_roi
        center_roi = gray_frame(center_rect); // partitioning
            
        // 3. For each roi, display canny edges
        // process the frame for edge detection
        blur(center_roi, center_roi, Size(5, 5));     // for noist removing - 3 (mask size - 5x5)
        Canny(center_roi, center_canny, 100, 150, 3); // execute line detection - 3 (maks size - 3x3)
        // Find the hough lines
        // Need to execute line filtering
        HoughLines(center_canny, center_lines, 1, CV_PI / 180, 80, 0, 0,(-30)*(CV_PI/180), 30*(CV_PI/180)); // center canny
        
        // execute lane departure
        int print = 0; // The key value of lane departure message(1:print, 0:nothing)
        
        if(center_lines.size() > 0) {
            print = 1; // assign value '1' to print
            print_count = print_wait; // initialize of delay frame count(메시지 출력을 이어갈 프레임의 값 초기화)
        }
        else if(print_count > 0)
            print = 1; // print count 값이 아직 0이 아닌 경우 1의 값을 유지
        else
            print = 0; // print count 값이 1보다 작은 경우 -> print에 0의 값을 할당
        
        // print 값이 1인 경우 -> 프레임 상에 lane departure를 감지했다는 메시지 출력
        if(print == 1) {
            putText(frame, format("Warning!: Lane departure"),
            Point(450, 80), FONT_HERSHEY_SIMPLEX, 1,
            Scalar(0, 0, 255), 6);
            print_count--; // 메시지를 1회 출력하였으므로 해당 변수의 크기르 1감소시킴
        }
        
        imshow("Frame", frame); // print out the result
        waitKey((double)1000 / cap.get(CAP_PROP_FPS));
    }
    return 0;
}
