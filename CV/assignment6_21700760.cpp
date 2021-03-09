// Computer Vision Assignment6
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    
    Mat frame;                             // store information of frame
    Mat gray_frame;                        // store gray-scale frame of video
    VideoCapture cap;                      // store information of video
    Mat detecting_part1, detecting_part2;  // left, right roi area
    Mat left_result, right_result;         // left, right canny result
    // declare rect for ROI
    Rect left_rect(200, 400, 400, 200);    // for left roi (600, 600)
    Rect right_rect(600, 400, 400, 200);   // for right roi (1000, 600)

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
        
        // 2. Set left_roi and right_roi
        detecting_part1 = gray_frame(left_rect);  // partitioning - 1
        detecting_part2 = gray_frame(right_rect); // partitioning - 2
        
        // 3. For each roi, display canny edges
        // process the frame for edge detection
        blur(detecting_part1, detecting_part1, Size(5, 5)); // for noise removing - 1 (mask size - 5x5)
        blur(detecting_part2, detecting_part2, Size(5, 5)); // for noise removing - 2 (mask size - 5x5)
        Canny(detecting_part1, left_result, 10, 60, 3); // execute line detection - 1 (mask size - 3x3)
        Canny(detecting_part2, right_result, 10, 60, 3); // execute line detection - 2 (mask size - 3x3)

        // print out edge detection result of each frame
        namedWindow("Left canny");  // for left canny
        namedWindow("Right canny"); // for right canny
        moveWindow("Left canny", 200, 0); // move the windows - 1
        moveWindow("Right canny", 600, 0); // move the windows - 2
        imshow("Left canny", left_result); // print out left canny
        imshow("Right canny", right_result); // print out right canny
        
        // calculate frame rate of video
        int frame_rate = cap.get(CAP_PROP_FPS);
        waitKey(1000 / frame_rate);
    }
    return 0;
}
