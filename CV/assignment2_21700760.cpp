// Computer Vision Assignment2
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 1. Read an image lena.png
    Mat original = imread("lena.png", 0); // read image an gray image
    imshow("original", original); // print out original image
    
    
    // 2. Negative Transformation(negative_img)
    Mat negative_img; // negative transformation image
    // access each pixel and convert each pixel value
    negative_img = original.clone(); // deepcopy original image
    int value;
    for(int i=0 ; i<original.rows ; i++) {
        for(int j=0 ; j<original.cols ; j++) {
            value = original.at<uchar>(i, j);
            negative_img.at<uchar>(i, j) = 255 - value; // revert each pixel values
            // cout << "result : " << negative_img.at<uchar>(i, j) << endl; // for debugging
        }
    }
    imshow("Negative Transformation", negative_img); // print out negative transformation image
    
    
    // 3. Log Transformation(log_img)
    Mat log_img; // log transformation image
    float value2;
    log_img = original.clone(); // deepcopy original image
    log_img.convertTo(log_img, CV_32F); // for accept float value
    // access each pixel and convert each pixel value
    // normalize(log_img, log_img, 0, 255, NORM_MINMAX);
    for(int i=0 ; i<original.rows ; i++) {
        for(int j=0 ; j<original.cols ; j++) {
            value2 = original.at<uchar>(i, j);
            log_img.at<float>(i, j) = 1.5 * log(1 + value2);
            // cout << "result1 : " << log_img.at<float>(i, j) << endl; // for debugging
        }
    }
    normalize(log_img, log_img, 0, 255, NORM_MINMAX); // normalize the log_img pixel value
    log_img.convertTo(log_img, CV_8U); // restore integer image
    imshow("Log Transformation", log_img); // print out log transfromation image
    
    
    // 4. Gamma Transformation(gammma_img) - constant is 1.2
    Mat gamma_img; // gamma transformation image
    gamma_img = original.clone(); // deepcopy original image
    normalize(gamma_img, gamma_img, 0, 1, NORM_MINMAX);
    gamma_img.convertTo(gamma_img, CV_32F); // for accept float value
    // access each pixel and convert each pixel value
    for(int i=0 ; i<original.rows ; i++) {
        for(int j=0 ; j<original.cols ; j++) {
            value2 = original.at<uchar>(i, j);
            gamma_img.at<float>(i, j) = 1.2 * pow(value2, 0.5);
            // cout << "result2 : " << gamma_img.at<float>(i, j) << endl; // for debugging
        }
    }
    normalize(gamma_img, gamma_img, 0, 255, NORM_MINMAX); // normalize the gamma_img pixel value
    gamma_img.convertTo(gamma_img, CV_8U); // restore integer image
    imshow("Gamma Transformation", gamma_img); // print out gamma transformation image
    
    waitKey(0);
    return 0;
}
