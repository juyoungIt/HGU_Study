// Computer Vision Project4
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>
#include <opencv2/dnn.hpp>
#include <fstream>

using namespace cv;
using namespace std;

// 명함의 좌표정보에 대한 Class
class EdgePoint_info
{
private:
    Point2f a; // 명함의 왼쪽 상단 모서리 좌표
    Point2f b; // 명함의 오른쪽 상단 모서리 좌표
    Point2f c; // 명함의 오른쪽 하단 모서리 좌표
    Point2f d; // 명함의 왼쪽 하단 모서리 좌표
public:
    void setPointA(double, double); // 왼쪽 상단 좌표정보를 세팅
    void setPointB(double, double); // 오른쪽 상단 좌표정보를 세팅
    void setPointC(double, double); // 오른쪽 하단 좌표정보를 세팅
    void setPointD(double, double); // 왼쪽 하단 좌표정보를 세팅
    vector<Point2f> returnPointInfo(); // 모은 꼭지점에 대한 정보를 vector로 압축하여 반환
};

// 프로그램에서 사용하는 Function을 선언하는 부분
Mat preProcess(Mat); // 전달받은 이미지를 Line detection에 적합한 형태로 변환
void findCorner(Mat, EdgePoint_info&); // 전달받은 이미지를 적절히 처리하여 모서리의 좌표정보를 업데이트 시키는 함수

// Main Function 부분
int main()
{
    Mat input_img = imread("namecard.JPG"); // 변환에 사용할 이미지를 로드
    Mat resize_img; // 크기를 줄여서 사용할 이미지
    Mat result_img; // 변환결과를 저장하는 이미지
    Mat homo_mat;
    vector<Point2f> before; // 변환 전의 좌표에 대한 정보
    vector<Point2f> after; // 변환 후의 좌표에 대한 정보
    resize(input_img, resize_img, Size(800,600)); // 원본 이미지의 크기가 너무 크기 때문에 줄여서 사용함.
    
    EdgePoint_info beforeT = EdgePoint_info();  // 변환 전 좌표정보 저장객체 생성 (before transformation)
    EdgePoint_info afterT = EdgePoint_info();   // 변환 후 좌표정보 저장객체 생성 (after transformation)
    
    // 변환 전 좌표정보 객체 data 업데이트
    findCorner(preProcess(resize_img), beforeT);
    
    // 변환 후 좌표정보 객체 data 업데이트
    afterT.setPointA(0, 0);
    afterT.setPointB(800, 0);
    afterT.setPointC(800, 500);
    afterT.setPointD(0, 500);
    
    // 좌표정보를 저장하는 vector 생성
    before = beforeT.returnPointInfo();
    after = afterT.returnPointInfo();
    
    // Persfective Transformation 수행
    homo_mat = getPerspectiveTransform(before, after); // Perspective Transformation에 사용하는 3x3 행렬을 생성
    warpPerspective(resize_img, result_img, homo_mat, Size(800, 500));
    
    // 처리결과 이미지를 화면에 출력
    // 결과확인을 편하게 할 수 있도록 좌표를 미리 설정하여서 출려되도록 하기
    namedWindow("original"); // 원본이미지를 출력하는 윈도우
    namedWindow("result");   // 변환결과를 출력하는 윈도우
    moveWindow("original", 0, 0); // 윈도우의 출력좌표 지정 - 1
    moveWindow("result", 800, 0);  // 윈도우의 출력좌표 지정 - 2
    imshow("original", resize_img); // 원본 이미지 출력
    imshow("result", result_img);   // 변환결과 출력
    waitKey();
    return 0;
}

// Class EdgePoint_info Class의 Method
// 왼쪽 상단 좌표정보 세팅
void EdgePoint_info::setPointA(double x, double y)
{
    a = Point2f(x, y);
}
// 오른쪽 상단 좌표정보 세팅
void EdgePoint_info::setPointB(double x, double y)
{
    b = Point2f(x, y);
}
// 오른쪽 하단 좌표정보 세팅
void EdgePoint_info::setPointC(double x, double y)
{
    c = Point2f(x, y);
}
// 왼쪽 하단 좌표정보 세팅
void EdgePoint_info::setPointD(double x, double y)
{
    d = Point2f(x, y);
}
// 설정된 좌표정보를 vector로 통합
vector<Point2f> EdgePoint_info::returnPointInfo()
{
    vector<Point2f> pointInfo; // 압축하여 정보를 저장할 vector
    pointInfo.push_back(a);
    pointInfo.push_back(b);
    pointInfo.push_back(c);
    pointInfo.push_back(d);
    return pointInfo;
}

// 프로그램에서 사용하는 Function을 정의하는 부분
// 입력받은 이미지를 line detection에 적합한 형태로 전처리 해주는 함수
Mat preProcess(Mat img)
{
    Mat gray_img; // deepcopy;
    Mat blur_img; // 노이즈 및 조명효과 삭제를 위해 사용하는 블러처리된 이미지
    Mat canny; // Canny Edge detection 결과를 저장
    
    cvtColor(img, gray_img, CV_BGR2GRAY); // edge detection을 위해 이미지를 gray scale로 변경
    blur(gray_img, blur_img, Size(5, 5)); // 이미지를 블러처리
    Canny(blur_img, canny, 30, 120, 3);  // Canny Edge Detection을 수행
    
    return canny;
}

// 전달받은 이미지를 처리하여 꼭짓점의 좌표를 구하고, 이를 바탕으로 좌표정보를 업데이트
void findCorner(Mat img, EdgePoint_info& beforeT)
{
    Mat edge = img.clone(); // deepcopy
    Mat element;
    vector<Vec4i> lines;
    double ax=1000, ay=1000, bx=1000, by=1000, cx=0, cy=0, dx=0, dy=0;
    dilate(edge, edge, element);
    HoughLinesP(edge, lines, 1, CV_PI/180, 50, 410, 40); // 라인검출
    
    for (int i = 0; i < lines.size(); i++) {
        Vec4i l = lines[i]; // 대응하는 라인을 획득
        
        // 최상단, 최하단 가로에 대한 좌표를 검출하여 전달
        if(cy < l[1] && dy < l[3]) {
            cx = l[2];
            cy = l[3];
            dx = l[0];
            dy = l[1];
        }
        
        if(ay > l[1] && by > l[3]) {
            ax = l[0];
            ay = l[1];
            bx = l[2];
            by = l[3];
        }
        line(img, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 255, 255), 3, 8);
    }
    // 산출한 좌표정보를 기입
    beforeT.setPointA(ax, ay);
    beforeT.setPointB(bx, by);
    beforeT.setPointC(cx, cy);
    beforeT.setPointD(dx, dy);
}
