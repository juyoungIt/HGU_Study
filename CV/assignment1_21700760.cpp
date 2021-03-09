// Computer Vision Assignment1
// writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat frame; // store information of frame
    VideoCapture cap; // store information of video
    
    int isValidFile = cap.open("background.mp4");
    
    // Exception handling1 - could not find designated file
    if(isValidFile == 0) {
        cout << "No such file!" << endl;
        waitKey(0);
    }
    
    // print the video(each frame - every interval) - just 3 seconds
    while(1) {
        cap >> frame; // get frame of video
        
        // Exception Handling2 - no more frames of video
        if(frame.empty()) {
            cout << "The end of the video!" << endl;
            break;
        }
        
        // Exception Handling3 - for 3 seconds printing
        if(cap.get(CAP_PROP_POS_MSEC) >= 3000)
            break;
        
        // show the frames
        imshow("video show", frame);
        
        // print information of frames
        int total_frames; // total frames of video
        int current_frame; // current frame of video
        current_frame = cap.get(CAP_PROP_POS_FRAMES);   // load current frame count
        total_frames = cap.get(CAP_PROP_FRAME_COUNT); // load total frame count
        
        cout << "frames: ";
        cout << current_frame;
        cout << " / ";
        cout << total_frames << endl;
        
        /*
         <The procedure of calculate value for waitKey>
         
         The Frame rate(FPS) of background.mp4 : 24FPS
         1sec == 1000ms
         
         The interval of each frames = 1000 / 24 = 41.6666 -> 42(Rounds)
         */
        waitKey(42); // set waitKey value
    }
    return 0;
}
