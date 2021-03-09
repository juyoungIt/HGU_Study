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
        char top_element();     // 스택의 top 원소 조회
        bool stack_full();      // 스택이 모두 찼는 지
        bool stack_empty();     // 스택이 완전히 비었는 지
};

// 관련함수 선언부
bool is_parenthesis(char n);      // 해당문자가 괄호인지 아닌 지 판별
bool is_open(char n);             // 해당괄호가 여는 괄호인지 닫는 괄호인지 판별
bool is_match(char n1, char n2);  // 두 괄호가 서로 상응하는 지 판별
char is_solution(char n);         // 입력된 괄호에 상응하는 괄호가 무엇인지 출력

int main()
{
    string input;   // 입력하는 수식을 저장
    mystack st1;    // 연산자를 저장하기 위한 스택선언
    char buff[SIZE]; // 공백을 포함하는 문자열을 입력받기 위한 버퍼공간 할당
    int i;          // 반복문 변수
    int length;    // 입력된 문자열의 길이

    cout << "Pleas enter the expression : ";
    // cin >> input;          // 공백을 포함하는 문자열을 받을 필요가 없다면 해당 문장을 사용해도 무방
    cin.getline(buff, SIZE);  // 공백을 포함하는 문자열을 입력받음
    input = buff;             // 입력받은 문자열을 input 으로 전달
    length = input.size();    // 입력받은 문자열의 길이를 구함

    // 입력받은 수식의 문자를 하나씩 가져와서 다음을 수행한다.
    for(i=0 ; i< length ; i++)
    {
        if(is_parenthesis(input[i])) // 해당문자가 괄호라면
        {
            if(is_open(input[i]))     // 해당문자가 열린괄호라면
                st1.push(input[i]);   // 스택으로 저장
            else                      // 해당문자가 닫힌괄호라면
            {
                if(st1.stack_empty()) // 닫힌괄호가 들어왔는데 비교할 수 있는 괄호가 스택상에 없는 경우
                {
                    cout << "Error: An extra parenthesis" << endl;
                    cout << "\'";
                    cout << input[i];
                    cout << "\'";
                    cout << " is found." << endl;
                    break; // 오류지점을 발견했으므로 반복문을 빠져나옴.
                }
                else // 비교할 수 있는 괄호가 스택상에 있는 경우
                {
                    if(is_match(st1.top_element(), input[i])) // 스택에 있는 열린괄호와 상응한다면
                        st1.pop(); // 상응하는 열린괄호를 스택에서 pop
                    else // 스택에 있는 열린괄호와 상응하지 않는다면
                    {
                        // 관련 메시지를 출력하는 문자열을 출력
                        cout << "Error: mis-matched parenthesis" << endl;
                        cout << "\'";
                        cout << is_solution(st1.top_element());
                        cout << "\'";
                        cout << " is expected." << endl;
                        break; // 오류지점을 발견했으므로 반복문을 빠져나옴.
                    }
                }
            }
        }
    }
    // 입력된 수식에 대한 스캔이 종료되고,
    if(i == length)
    {
        if(!st1.stack_empty())   // 여는 괄호가 스택에 남아있는 경우 - [a+{b*(c-d)}]( 같은 식을 판별하기 위함.
        {
            cout << "Error: An extra parenthesis" << endl;
            cout << "\'";
            cout << st1.pop();
            cout << "\'";
            cout << " is found." << endl;
        }
        else // 스택이 완전히 비어있는 경우
            cout << "It's a normal expression" << endl; // 문제가 없음을 의미하는 문자열 출력
    }

    return 0;
}

// class mystack의 member함수 정의부
mystack::mystack()
{
    top = -1;
}

void mystack::push(char n)
{
    top++; // 데이터를 저장할 공간을 가리키도록 top의 값 1증가
    arr[top] = n;
}

char mystack::pop()
{
    char temp; // 문자을 일시적으로 저장할 변수
    temp = arr[top];
    top--; // pop 연산을 위해 top의 값 1감소
    return temp; // pop연산의 결과로 가져온 데이터 반환
}

char mystack::top_element()
{
    return arr[top]; // 조회한 값을 반환
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


// 관련 함수 정의부
// 해당문자가 괄호인지 판별하는 함수
bool is_parenthesis(char n)
{
    if(n == '(' || n == ')' || n == '{' || n == '}' || n == '[' || n == ']')
        return true;
    else
        return false;
}

// 해당괄호가 여는 괄호인지 닫는 괄호인지 판별하는 함수
bool is_open(char n)
{
    if(n == '(' || n == '{' || n == '[')
        return true;
    else
        return false;
}

bool is_match(char n1, char n2)
{
    if((n1 == '(' && n2 == ')') || (n1 == '{' && n2 == '}') || (n1 == '[' && n2 == ']'))
        return true;
    else
        return false;
}

char is_solution(char n)
{
    if(n == '(')
        return ')';
    else if(n == '{')
        return '}';
    else
        return ']';
}