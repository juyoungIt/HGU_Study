#include <iostream>
using namespace std;

class weight // class 정의
{
    private: // 쓰지 않아도 되는 부분이지만 이번 예재에서 학습을 위하여 추가하였습니다.
       int k_gram; // 킬로그램 값 저장
       int gram; // 그램 값 저장
    public:
       void set_weight(int kg, int g); // 무게값을 설정
       int get_weight(void); // 무게값을 출력
};

// 일반함수 선언부분
weight add_weight(weight w1, weight w2); // 두 무게값을 더하여 결과값을 리턴
bool less_than(weight w1, weight w2); // w1이 w2보다 작은 값인 가를 판단하여 return

// main함수 부분
int main(void)
{
    weight w1, w2, w3; // weight라는 class object를 3개 생성
    w1.set_weight(3,400); // w1을 3kg 400g으로
    w2.set_weight(2,700); // w2을 2kg 700g으로
    w3 = add_weight(w1, w2); // w1과 w2를 더하여 w3에 -> w3는 6kg 100g
    cout << w3.get_weight() << "grams\n"; // w3의 값 '6100 grams 출력'
    if(less_than(w1, w2))
        cout << "yes.\n";
    else
        cout << "no.\n";
        
    return 0;
}

// class member function 정의
void weight:: set_weight(int kg, int g)
{
    k_gram = kg; // 입력받은 kg 값 저장
    gram = g; // 입력받은 g 값 저장
}

int weight:: get_weight(void)
{
    return k_gram * 1000 + gram; // 무게값을 그램으로 변환하여 return
}

// 일반함수 정의부분
weight add_weight(weight w1, weight w2)
{
    weight result; // 계산의 결과값을 저장하는 class 선언
    int t_result; // 일시적으로 gram 단위 연산값을 저장하는 변수
    
    t_result = w1.get_weight() + w2.get_weight(); // 그램단위로 합산
    result.set_weight(t_result/1000, t_result%1000); // kg단위로 단위를 다시 변환하여 저장, 나머지는 gram으로
    return result; // 덧셈연산을 진행하여 무게값을 저장한 class result를 반환
}

bool less_than(weight w1, weight w2)
{
    if(w1.get_weight() < w2.get_weight()) // 만약 w2가 w1보다 작은 값이라면
        return true;
    else
        return false;
}