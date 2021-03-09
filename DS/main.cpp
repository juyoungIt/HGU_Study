#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

// 스택을 class를 이용하여 정의
class mystack
{
private:
    char arr[SIZE];  // 데이터가 저장되는 부분
    int top;         // 가장최근에 데이터가 저장된 인덱스 저장
public:
    mystack();              // constructor, 스택을 초기화
    void push(char n);      // 스택에 대한 push 연산
    char pop();             // 스택에 대한 pop 연산
    bool stack_full();      // 스택이 모두 찼는 지
    bool stack_empty();     // 스택이 완전히 비었는 지
};

int main()
{
    mystack st1;     // 문자를 저장할 스택 선언
    string input;    // 사용자에게 입력받는 문자열 저장
    char buff[SIZE]; // 공백을 포함하는 문자열을 입력받기 위한 버퍼공간 할당
    int i, count;    // 반복문 변수, 반복횟수
    int length;      // 문자열의 길이를 저장

    // 판별하는 부분
    cout << "Please enter the string : ";
    // cin >> input;          // 공백을 포함하는 문자열을 받을 필요가 없다면 해당 문장을 사용해도 무방
    cin.getline(buff, SIZE);  // 공백을 포함하는 문자열을 입력받음
    input = buff;             // 입력받은 문자열을 input으로 전달
    length = input.size();    // 입력받은 문자열의 길이를 구함

    // 문자열의 앞부분의 절반을 스택에 push
    for(i=0 ; i<length/2 ; i++)
        st1.push(input[i]);

    // 뒤쪽 절반의 내용을 순선대로 반복하여 스택의 내용을 pop하여 비교
    for(i=0 ; i<length/2 ; i++)
    {
        if(st1.pop() != input[length-length/2 + i])
        {
            cout << "No, It's not a palindrome." << endl;
            break; // 다른 부분을 찾았으므로 반복문을 빠져나옴
        }
    }
    // 모든 요소가 동일하게 판별되고 종료되었다면
    if(st1.stack_empty())
        cout << "Yes, It's a palindrome." << endl; // 관련 문자열 결과로 출력

    return 0;
}

// class mystack의 member함수 정의부
mystack::mystack()
{
    top = -1;
}

void mystack::push(char n)
{
    if(stack_full()) // 예외처리, 저장공간이 모두 찬 스택에 저장을 시도할 경우
    {
        cout << "Stack is full!" << endl;
        return;
    }
    top++; // 데이터를 저장할 공간을 가리키도록 top의 값 1증가
    arr[top] = n;
}

char mystack::pop()
{
    if(stack_empty()) // 예외처리, 저장된 데이터가 없는 stack에서 pop을 시도할 경우
    {
        cout << "Stack don't have data!" << endl;
        return -1; // 비정상적인 종료를 알리는 -1을 반환하며 종료
    }
    char temp; // 문자을 일시적으로 저장할 변수
    temp = arr[top];
    top--; // pop 연산을 위해 top의 값 1감소
    return temp; // pop연산의 결과로 가져온 데이터 반환
}

bool mystack::stack_full()
{
    if(top == SIZE)
        return true;
    else
        return false;
}

bool mystack::stack_empty()
{
    if(top == -1)
        return true;
    else
        return false;
}