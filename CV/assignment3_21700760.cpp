// Computer Vision Assignment3
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    
    // 1. Perform Average filtering on the left-half of the image
    // 1-1. Read an Image "lena.png"
    Mat lena = imread("lena.png"); // original image of lana.png
    Mat lena_filtered = lena.clone(); // filtered image - store filtering result
    Rect rect1(0, 0, lena_filtered.size().width/2, lena_filtered.size().height); // set the rect area
    Mat filtering_part1 = lena_filtered(rect1); // partitioning left-half
    // 1-2. Perform average filtering on the left-half of the image
    blur(filtering_part1, filtering_part1, Size(7, 7)); // Perform average filtering (just left-half)
    imshow("lena", lena); // print out original image
    imshow("lena_filtered", lena_filtered); // print out filtering image
    
    // 2. Perform sharpening on the right-half of the image
    // 2-1. Read an Image "moon.png"
    Mat moon = imread("moon.png", 0); // original image of moon.png
    Mat moon_laplacian = moon.clone(); // laplacian image of moon.png
    Mat moon_filtered = moon.clone(); // filtered image of moon.png
    Rect rect2(moon.size().width/2, 0, moon.size().width/2, moon.size().height); // set the rect area
    Mat filtering_part2 = moon_filtered(rect2); // partitioning right-half-1
    Mat laplacian_part = moon_laplacian(rect2); // partitioning right-half-2
    // 2-2.  Perform sharpening on the right-half of the image
    Laplacian(filtering_part2, laplacian_part, CV_16S); // Get a second derivative
    convertScaleAbs(laplacian_part, laplacian_part);
    add(laplacian_part, filtering_part2, filtering_part2);
    imshow("moon", moon); // print out original image
    imshow("moon_filtered", moon_filtered); // print out filtering image
    
    // 3. Perform median filtering on the image
    // 3-1. Read an image "saltnpepper.png"
    Mat saltnpepper = imread("saltnpepper.png"); // original image of saltnpepper.png
    Mat saltnpepper_filtered; // filtered image of saltnpepper.png
    // 3-2. Perform median filtering on the image
    medianBlur(saltnpepper, saltnpepper_filtered, 9); // Perform median filtering
    imshow("saltnpepper", saltnpepper); // print out original image
    imshow("saltnpepper_filtered", saltnpepper_filtered); // print out median filtering image
    
    waitKey(0);
    return 0;
}
