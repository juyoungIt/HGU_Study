// Computer Vision Assignment 12-1
// Writer : 21700760 Juyoung Ha

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap; // 영상을 불러오는 객체
    Mat frame, gray_frame; // 비디오 파일을 구성하는 프레임, 특정 프레임에 대한 gray-scale
    
    CascadeClassifier face_classifier; // face detection을 위한 classifier
    vector<Rect> faces; // 얼굴 정보 식별에 대한 정보를 저장
    int i; // 반복문 변수
    
    int validate_open; // 영상파일 불러오기 성공여부
    int frame_rate; // 영상의 프레임값
    int key_input; // 키보드 입력값
    int lastKey = 0; // 가장 최근에 입력한 Key의 값을 업데이트, 초기값은 null을 의미하는 0으로 초기화
    
    // 0. Face Detection을 위한 Classifier 파일을 불러옴
    face_classifier.load("haarcascade_frontalface_alt.xml");
    
    // 1. Faces.mp4 파일을 읽어들임
    validate_open = cap.open("Faces.mp4"); // Faces.mp4 파일을 읽음
    frame_rate = cap.get(CAP_PROP_FPS);    // 영상의 출력을 위해 프레임 값을 읽어들임
    
    // 예외처리 - 해당 파일이 없거나 파일 로딩을 실패한 경우
    // -> 프로그램의 실행을 중지시킴
    if(validate_open == 0) {
        cout << "Error! : No such file!" << endl;
        return -1;
    }
    
    // 읽어온 비디오 파일을 출력함
    while(1)
    {
        key_input = waitKey(frame_rate); // 사용자로부터 키 입력을 대기
        // Key 입력이 들어온 경우
        // key의 입력이 들어오지 않은 경우 이전의 값을 그대로 유지함
        // -> 이렇게 함으로서 매 frame에 가장 최근에 선택한 연산을 지속적으로 적용할 수 있도록 함
        if(key_input != -1) {
            lastKey = key_input; // 가장 최근에 입력된 key의 값을 업데이트
        }
        cout << "The value of lastKey : " << lastKey << endl;
        
        cap >> frame; // 프레임을 가져옴
        // 더 이상 불러올 프레임이 존재하지 않는 경우
        if(frame.empty()) {
            cout << "No more frame for print!" << endl;
            break; // loop를 빠져나옴
        }
        
        cvtColor(frame, gray_frame, CV_BGR2GRAY); // 읽어온 frame을 gray-scale로 변경 - 내부적인 연산에 활용하기 위해서
        
        // 키 입력에 대한 조건문 처리(대소문자 따지지 않도록 조건설정)
        // 'n' 또는 'N'을 입력 -> 가장 가까운 거리
        if(lastKey == 78 || lastKey == 110) {
            putText(frame, format("Key input: %d", lastKey), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255), 4);
            face_classifier.detectMultiScale(
                gray_frame,
                faces,
                1.1, // 각 frame의 scale을 10% 확대함
                3,   // 최소 3개 이상의 인식이 나타나야 얼굴로 인식함
                0,   // not used for a new cascade
                Size(77, 77), // 인식하는 최소 사이즈
                Size(100, 100)  // 인식하는 최대 사이즈
            );
            // 인식한 얼굴을 식별할 수 있도록 bounding rect를 그려냄
            for (i = 0; i < faces.size(); i++) {
                Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
                Point tr(faces[i].x, faces[i].y);
                rectangle(frame, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
            }
        }
        // 'f' 또는 'F'를 입력 -> 가장 먼 거리
        else if(lastKey == 70 || lastKey == 102) {
            putText(frame, format("Key input: %d", lastKey), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255), 4);
            face_classifier.detectMultiScale(
                gray_frame,
                faces,
                1.1, // 각 frame의 scale을 10% 확대함
                3,   // 최소 3개 이상의 인식이 나타나야 얼굴로 인식함
                0,   // not used for a new cascade
                Size(20, 20), // 인식하는 최소 사이즈
                Size(40, 40)  // 인식하는 최대 사이즈
            );
            // 인식한 얼굴을 식별할 수 있도록 bounding rect를 그려냄
            for (i = 0; i < faces.size(); i++) {
                Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
                Point tr(faces[i].x, faces[i].y);
                rectangle(frame, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
            }
        }
        // 'm' 또는 'M'을 입력 -> 중간 거리
        else if(lastKey == 77 || lastKey == 109) {
            putText(frame, format("Key input: %d", lastKey), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255), 4);
            face_classifier.detectMultiScale(
                gray_frame,
                faces,
                1.1, // 각 frame의 scale을 10% 확대함
                4,   // 최소 3개 이상의 인식이 나타나야 얼굴로 인식함
                0,   // not used for a new cascade
                Size(55, 55), // 인식하는 최소 사이즈
                Size(55, 55)  // 인식하는 최대 사이즈
            );
            // 인식한 얼굴을 식별할 수 있도록 bounding rect를 그려냄
            for (i = 0; i < faces.size(); i++) {
                Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
                Point tr(faces[i].x, faces[i].y);
                rectangle(frame, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
            }
        }
        // 그 이외에 프로그램 내에서 정의되지 않은 입력이 들어온 경우
        else {
            // 정의되지 입력임을 의미하는 의미하는 메시지를 출력
            putText(frame, format("Key input: %d", lastKey), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255), 4);
            cout << "Invalid Input value! : Definition cannot find" << endl;
        }
        // 원본 frame을 window Faces에 출력
        imshow("Faces", frame);
    }
    return 0;
}
