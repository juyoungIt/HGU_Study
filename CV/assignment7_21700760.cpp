// Computer Vision Assignment7 - line detection
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat frame;                             // store information of frame
    Mat gray_frame;                        // store gray-scale frame of video
    VideoCapture cap;                      // store information of video
    Mat left_roi, right_roi;               // left, right roi area
    Mat left_canny, right_canny;           // left, right canny result
    // declare rect for ROI
    Rect left_rect(200, 400, 400, 200);    // for left roi (600, 600)
    Rect right_rect(600, 400, 400, 200);   // for right roi (1000, 600)
    // The set of lines
    Point p1, p2;                 // points to draw line
    vector<Vec2f> left_lines;     // the set of lines in left roi
    vector<Vec2f> right_lines;    // the set of lines in right roi
    float sum_rho=0, sum_theta=0; // total sum of each rho and theta
    float ave_rho, ave_theta;     // average value of rho and theta
    float a, b, x0, y0;           // variable for lines
    
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
        // print out the frame between 0 ~ 20sec
        if(cap.get(CAP_PROP_POS_MSEC) > 1000 * 20) {
            break;
        }
            
        // 2. Set left_roi and right_roi
        left_roi = gray_frame(left_rect);  // partitioning - 1
        right_roi = gray_frame(right_rect); // partitioning - 2
            
        // 3. For each roi, display canny edges
        // process the frame for edge detection
        blur(left_roi, left_roi, Size(5, 5));     // for noise removing - 1 (mask size - 5x5)
        blur(right_roi, right_roi, Size(5, 5));   // for noise removing - 2 (mask size - 5x5)
        Canny(left_roi, left_canny, 100, 150, 3);   // execute line detection - 1 (mask size - 3x3)
        Canny(right_roi, right_canny, 100, 150, 3); // execute line detection - 2 (mask size - 3x3)
        
        // Find the hough lines
        // Need to execute line filtering
        HoughLines(left_canny, left_lines, 1, CV_PI / 180, 50, 0, 0, 30*(CV_PI/180), 60*(CV_PI/180));   // left canny
        HoughLines(right_canny, right_lines, 1, CV_PI / 180, 50, 0, 0, 120*(CV_PI/180), 150*(CV_PI/180)); // right canny
        
        // left roi Line merging and print out
        for(int i=0 ; i<left_lines.size() ; i++) {
            sum_rho += left_lines[i][0];
            sum_theta += left_lines[i][1];
        }
        ave_rho = sum_rho / left_lines.size();
        ave_theta = sum_theta / left_lines.size();
        a = cos(ave_theta);
        b = sin(ave_theta);
        x0 = a * ave_rho;
        y0 = b * ave_rho;
        sum_rho = 0;
        sum_theta = 0;
        p1 = Point(cvRound(x0 + 1000*(-b))+200, cvRound(y0 + 1000*a)+400); // calculate point cordinate - 1
        p2 = Point(cvRound(x0 - 1000*(-b)+200), cvRound(y0 - 1000*a)+400); // calculate point cordinate - 2
        line(frame, p1, p2, Scalar(0, 0, 255), 3, 8);
        
        // rigth roi line merging and print out
        for(int i=0 ; i<right_lines.size() ; i++) {
            sum_rho += right_lines[i][0];
            sum_theta += right_lines[i][1];
        }
        ave_rho = sum_rho / right_lines.size();
        ave_theta = sum_theta / right_lines.size();
        a = cos(ave_theta);
        b = sin(ave_theta);
        x0 = a * ave_rho;
        y0 = b * ave_rho;
        sum_rho = 0;
        sum_theta = 0;
        p1 = Point(cvRound(x0 + 1000*(-b)+600), cvRound(y0 + 1000*a)+400); // calculate point cordinate - 1
        p2 = Point(cvRound(x0 - 1000*(-b)+600), cvRound(y0 - 1000*a)+400); // calculate point cordinate - 2
        line(frame, p1, p2, Scalar(0, 0, 255), 3, 8);
        
        imshow("Frame", frame); // print out the result frame
        waitKey(1000 / cap.get(CAP_PROP_FPS));
    }
    return 0;
}
