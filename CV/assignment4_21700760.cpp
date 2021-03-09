// Computer Vision Assignment4
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat drawHistogram(Mat);
void calcNormValue(Mat);

int main() {
    
    Mat original_img;
    Mat hist_equalized_image;
    
    // 1. Read an image "moon.png" as gray-scale image
    original_img = imread("moon.png", 0);
    
    // 2. Perform histogram equalization on the input image
    equalizeHist(original_img, hist_equalized_image);
    
    // 3. Display histogram of the input and the result image
    Mat hist_graph = drawHistogram(original_img); // histogram of original image
    Mat hist_equalized_graph = drawHistogram(hist_equalized_image); // histogram of equalized image
    imshow("h1", hist_graph); // print out histogram - 1
    imshow("h2", hist_equalized_graph); // print out histogram - 2
    
    // 4. Compute normalize histogram and display each element of the histogram on the image
    calcNormValue(original_img);
    calcNormValue(hist_equalized_image);
    imshow("before", original_img);
    imshow("after", hist_equalized_image);
    
    waitKey(0);
    return 0;
}

Mat drawHistogram(Mat src){
    Mat hist, histImage;
    
    // establish the number of bins
    int i, hist_w, hist_h, bin_w, histSize;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    
    hist_w = 512;
    hist_h = 512;
    histSize = 16;
    bin_w = cvRound((double)hist_w / histSize);
    
    //draw the histogram
    histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
    
    // compute the histograms
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);
    
    // Fit the histogram to [0, histImage.rows]
    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    
    for (i = 0; i < histSize; i++) {
        rectangle(histImage, Point(bin_w * i, hist_h),
                  Point(bin_w * i+hist_w/histSize, hist_h - cvRound(hist.at<float>(i))),
                  Scalar(0, 0, 0), -1); }
    return histImage;
}

void calcNormValue(Mat src) {
    Mat hist;
    
    // establish the number of bins
    int i, hist_w, hist_h, bin_w, histSize;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    
    hist_w = 512;
    hist_h = 512;
    histSize = 8;
    bin_w = cvRound((double)hist_w / histSize);
    
    // compute the histograms
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);
    
    // calculate normalize value and print out the value
    for(i=0 ; i<histSize ; i++) {
        int norm_value;
        int total_pixels = src.size().width * src.size().height;
        norm_value = hist.at<float>(i);
        putText(src, format("bin%d : %f", i+1, (float)norm_value/total_pixels), Point(10, 40+(30*(i+1))), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    }
}
