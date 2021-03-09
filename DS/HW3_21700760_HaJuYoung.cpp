#include <iostream>
using namespace std;

#define SIZE 100  // 코드의 가독성을 높이기 위한 부분

// 스택 관련 class 정의
class mystack
{
    private:
       int arr[SIZE]; // 데이터 값이 저장되는 부분
       int top; // 가장 최근에 데이터가 추가된 위치
    public:
       mystack(); // stack 초기화(Construtor)
       void push(int x); // stack에 데이터 저장
       int pop(); // stack에서 데이터 추출
       bool stack_full(); // 스택이 모두 찼는 지 판별
       bool stack_empty(); // 스택이 완전히 비었는 지 판별
};

int main()
{
mystack  s1;

int list[5] = { 32, 123, 27, 131, 242 }, i, x;
           // s1.init();  // constructor로 초기화하였다면, 생략 가능
           for (i = 0; i < 5; i++ )
              if (list[i] > 100)
                 s1.push( list[i] );
           while ( ! s1.stack_empty( ) )
           {
             x = s1.pop( );
             cout << x << endl ; 
           }
           return 0;
}

// mystack member 함수정의
// 생성한 스택을 초기화 (Construtor)
mystack::mystack()
{
    top = -1; // stack에 아무것도 저장되지 않은 상태를 가리키는 -1로 초기화
}

// stack에 데이터 저장
void mystack:: push(int x) // 예외처리가 필요하지만 main함수가 동작하는데에는 예외처리가 없어도 되어 따로 구현하지 않음 - 1
{
    top++; // 새로운 데이터가 저장될 위치를 가리키도록 top의 값을 1증가
    arr[top] = x; // stack에 데이터 저장
}

// stack에서 데이터를 추출
int mystack:: pop() // 예외처리가 필요하지만 main함수가 동작하는데에는 예외처리가 없어도 되어 따로 구현하지 않음 - 2
{
    int temp; // pop되는 데이터를 임시저장

    temp = arr[top];
    top--; // pop연산이 되었으므로 top 값 1감소
    return temp; // 추출된 데이터값 반환
}

// stack이 완전히 찼는 지 판별
bool mystack:: stack_full()
{
    if(top == SIZE)
        return true;
    else
        return false;
}

// stack이 완전히 비었는 지 판별
bool mystack:: stack_empty()
{
    if(top == -1)
        return true;
    else
        return false;
}