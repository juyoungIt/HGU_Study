#include <iostream>
#include <string>
using namespace std;

#define Q_SIZE 10 // 코드의 가독성을 위한 부분

// 사람의 이름과 연락처 정보를 저장하는 class
class element
{
public:
    string s_name;     // 이름을 문자열로 저장
    string phone_no;  // 전화번호를 문자열로 저장
    void set_data(string s1, string s2);
};

// 자료구조 queue를 나타내는 class 정의
class my_queue
{
private:
    element q[Q_SIZE]; // element 값을 저장하는 배열
    int front;         // 데이터를 읽는 부분
    int rear;          // 다음 데이터를 저장할 부분
public:
    my_queue();            // constructor, queue 초기화
    void insert_q(element x); // queue에 데이터 저장
    element delete_q();       // queue에 저장된 데이터 삭제 및 조회
    bool full();    // queue의 저장공간이 모두 찼는 지 검사
    bool empty();   // queue에 저장된 데이터가 없는 지 검사
};

int main()
{
    my_queue  a;
    element  tmp;

    tmp.set_data("KIM", "010-1234-5678");
    a.insert_q(tmp);
    tmp.set_data("LEE", "010-1357-2468");
    a.insert_q(tmp);
    tmp.set_data("PARK", "010-9876-5432");
    a.insert_q(tmp);

    while (!a.empty() ) {
        tmp = a.delete_q();
        cout << tmp.s_name << " : " << tmp.phone_no<< "\n";
    }
    return 0;
}

// queue의 멤버함수 구현
my_queue::my_queue()
{
    front = 0;  // front 값을 0으로 초기화, 삭제된 데이터가 없으므로
    rear = 0;   // rear 값을 0으로 초기화, 저장된 데이터가 없으므로
};

// queue에 대한 insert 연산을 수행
void my_queue::insert_q(element x)
{
    if(!full())
    {
        q[rear] = x; // 다음데이터를 저장할 위치인 rear에 입력정수 x를 저장
        rear = (rear+1)%Q_SIZE; // 데이터 저장 후 rear의 값을 조정
    }
    else // queue에 더 이상 저장공간이 없는 경우에 대한 예외처리
    {
        cout << "Error : Queue is full\n"; // 오류메시지 출력
        return;                            // 함수 종료
    }
}

// queue에 대한 delete 연산을 수행
element my_queue::delete_q()
{
    element temp; // queue에서 꺼내오는 값을 저장
    if(!empty())
    {
        temp = q[front]; // front 위치의 데이터에 대한 값을 저장
        front = (front+1)%Q_SIZE; // front의 값을 조정
        return temp; // delete 한 값을 반환
    }
    else // queue 에 저장된 데이터가 없는 경우에 대한 예외처리
    {
        cout << "Error : Queue data is not exist\n"; // 오류 메시지 출력
        // 별도로 값을 반환하지 않음
    }
}

// queue의 저장공간이 모두 찼는지에 대하여 검사
bool my_queue::full()
{
    if((rear+1)%Q_SIZE == front)
        return true;
    else
        return false;
}

// queue에 저장된 데이터가 없는 지 검사
bool my_queue::empty()
{
    if(rear == front)
        return true;
    else
        return false;
}

// class element의 member 함수 정의부
void element::set_data(string s1, string s2)
{
    s_name = s1;    // 이름에 대한 값을 저장
    phone_no = s2; // 전화번호에 대한 값을 저
}