// Computer Vision Proeject1
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// declare function of this program
Mat negative_transformation(Mat);  // execute negative transformation
Mat gamma_transformation(Mat);     // execute gamma transformation
Mat histogram_equalization(Mat);   // execute histogram equalization
Mat color_slicing(Mat);            // execute color slicing
Mat color_conversion(Mat);         // execute color conversion
Mat average_filtering(Mat);        // execute average filtering
Mat white_balancing(Mat);          // execute white balancing


int main() {
    
    int key_input; // user key input
    
    // open lena.png
    Mat lena = imread("lena.png", 1); // read color image
    Mat current_lena = lena.clone(); // update current image
    imshow("lena", lena); // print original image
    // open colorful.jpg
    Mat colorful = imread("colorful.jpg", 1); // read color image
    Mat current_colorful = colorful.clone(); // update current image
    imshow("colorful", colorful); // print original image
    // open balancing.jpg
    Mat balancing = imread("balancing.jpg", 1); // read color image
    Mat current_balancing = balancing.clone(); // update current image
    imshow("balancing", balancing); // print original image
    
    // using loop to maintain programs logic
    while(1)
    {
        key_input = waitKey(0); // wait user input
        
        // for lena.png
        // key input 'n' - negative transformation
        if(key_input == 110) {
            current_lena = negative_transformation(current_lena);
            imshow("lena", current_lena);
        }
        // key input 'g' - gamma transformation
        if(key_input == 103) {
            current_lena = gamma_transformation(current_lena);
            imshow("lena", current_lena);
        }
        // key input 'h' - histogram equalization
        if(key_input == 104) {
            current_lena = histogram_equalization(current_lena);
            imshow("lena", current_lena);
        }
        
        // for colorful.jpg
        // key input 's' - color slicing
        if(key_input == 115) {
            current_colorful = color_slicing(current_colorful);
            imshow("colorful", current_colorful);
        }
        // key input 'c' - color conversion
        if(key_input == 99) {
            current_colorful = color_conversion(current_colorful);
            imshow("colorful", current_colorful);
        }
        
        // for balancing.jpg
        // key input 'a' - average filtering
        if(key_input == 97) {
            current_balancing = average_filtering(current_balancing);
            imshow("balancing", current_balancing);
        }
        // key input 'w' - white balancing
        if(key_input == 119) {
            current_balancing = white_balancing(current_balancing);
            imshow("balancing", current_balancing);
        }
        
        // key input 'r' - reset
        if(key_input == 114) {
            current_lena = lena; // reset current_lena
            current_colorful = colorful; // reset current_colorful
            current_balancing = balancing; // reset current_balancing
            imshow("lena", current_lena); // update
            imshow("colorful", current_colorful); // update
            imshow("balancing", current_balancing); // update
        }
        
        // key input 'ESC' - shutdown
        if(key_input == 27) {
            break; // close all images and shutdown program
        }
    }
    return 0;
}
// Negative Transformation
Mat negative_transformation(Mat input) {
    Mat temp; // store processing image
    Mat hsv_channels[3]; // hue, saturation, intensity channels
    int intensity; // intensity value;
    cvtColor(input, temp, CV_BGR2HSV); // change color model(BGR -> HSV)
    split(temp, hsv_channels); // split 3-channels of image's color
    // processing each pixel value
    for(int i=0 ; i<temp.size().width ; i++) {
        for(int j=0 ; j<temp.size().height ; j++) {
            intensity = hsv_channels[2].at<uchar>(j, i);
            hsv_channels[2].at<uchar>(j, i) = 255 - intensity; // revert intensity value
        }
    }
    merge(hsv_channels, 3, temp);
    cvtColor(temp, temp, CV_HSV2BGR);
    return temp;
}

// Gamma Transformation
Mat gamma_transformation(Mat input) {
    Mat temp; // temporary save
    Mat hsv_channels[3];
    float intensity; // intensity value;
    cvtColor(input, temp, CV_BGR2HSV);
    split(temp, hsv_channels); // split 3-channels of image
    hsv_channels[2].convertTo(hsv_channels[2], CV_32F);
    normalize(hsv_channels[2], hsv_channels[2], 0, 1, NORM_MINMAX);
    // processing each pixel value
    for(int i=0 ; i<temp.size().width ; i++) {
        for(int j=0 ; j<temp.size().height ; j++) {
            intensity = hsv_channels[2].at<float>(j, i);
            hsv_channels[2].at<float>(j, i) = 2.5 * pow(intensity, 2.5);
        }
    }
    normalize(hsv_channels[2], hsv_channels[2], 0, 255, NORM_MINMAX);
    hsv_channels[2].convertTo(hsv_channels[2], CV_8U);
    merge(hsv_channels, 3, temp);
    cvtColor(temp, temp, CV_HSV2BGR);
    return temp;
}

// Histogram Equalization
Mat histogram_equalization(Mat input) {
    Mat temp;
    Mat hsv_channels[3];
    cvtColor(input, temp, CV_BGR2HSV);
    split(temp, hsv_channels); // split 3-channels of image
    equalizeHist(hsv_channels[2], hsv_channels[2]);
    merge(hsv_channels, 3, temp);
    cvtColor(temp, temp, CV_HSV2BGR);
    return temp;
}

// Color Slicing
Mat color_slicing(Mat input) {
    Mat temp;
    Mat hsv_channels[3];
    int hue; // hue value
    cvtColor(input, temp, CV_BGR2HSV);
    split(temp, hsv_channels); // split 3-channels of image
    for(int i=0 ; i<temp.size().width ; i++) {
        for(int j=0 ; j<temp.size().height ; j++) {
            hue = hsv_channels[0].at<uchar>(j, i);
            // if hue value range are not 9<hue<23
            if(!(hue>9 && hue<23))
                hsv_channels[1].at<uchar>(j, i) = 0; // edit saturation value of other pixels
        }
    }
    merge(hsv_channels, 3, temp);
    cvtColor(temp, temp, CV_HSV2BGR);
    return temp;
}

// Color Conversion
Mat color_conversion(Mat input) {
    Mat temp;
    Mat hsv_channels[3];
    int hue; // hue value
    cvtColor(input, temp, CV_BGR2HSV);
    split(temp, hsv_channels); // split 3-channels of image
    for(int i=0 ; i<temp.size().width ; i++) {
        for(int j=0 ; j<temp.size().height ; j++) {
            hue = hsv_channels[0].at<uchar>(j, i);
            if(hue <= 129)
                hsv_channels[0].at<uchar>(j, i) += 50; // add 50 to hue value of each pixels
            else // if (hue > 129)
                hsv_channels[0].at<uchar>(j, i) -= 129; // subtract 129
        }
    }
    merge(hsv_channels, 3, temp);
    cvtColor(temp, temp, CV_HSV2BGR);
    return temp;
}

// Average Filtering
Mat average_filtering(Mat input) {
    Mat temp;
    Mat hsv_channels[3];
    cvtColor(input, temp, CV_BGR2HSV);
    split(temp, hsv_channels); // split 3-channels of image
    blur(hsv_channels[2], hsv_channels[2], Size(9, 9));
    merge(hsv_channels, 3, temp);
    cvtColor(temp, temp, CV_HSV2BGR);
    return temp;
}

// White Balancing
Mat white_balancing(Mat input) {
    Mat temp;
    Mat bgr_channels[3];
    split(input, bgr_channels);      // split b, g, r channel
    // execute white balancing
    for(int i=0 ; i<temp.size().width ; i++) {
        for(int j=0 ; j<temp.size().height ; j++) {
            bgr_channels[0].at<uchar>(j, i) = (255 / bgr_channels[0].at<uchar>(j, i) * 128); // processing - 1 (gray world assumption)
            bgr_channels[1].at<uchar>(j, i) = (255 / bgr_channels[1].at<uchar>(j, i) * 128); // processing - 2 (gray world assumption)
            bgr_channels[2].at<uchar>(j, i) = (255 / bgr_channels[2].at<uchar>(j, i) * 128); // processing - 3 (gray world assumption)
        }
    }
    normalize(bgr_channels[0], bgr_channels[0], 0, 255, NORM_MINMAX); // normalize pixel value of b channel
    normalize(bgr_channels[1], bgr_channels[1], 0, 255, NORM_MINMAX); // normalize pixel value of g channel
    normalize(bgr_channels[2], bgr_channels[2], 0, 255, NORM_MINMAX); // normalize pixel value of r channel
    merge(bgr_channels, 3, temp); // merge each three channels of image
    return temp;
}
