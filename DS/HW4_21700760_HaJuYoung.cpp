#include <iostream>
#include <string>
using namespace std;

#define SIZE 100 // 코드의 가독성을 높이기 위한 부분

// 클래스 정의 부
class op_stack
{
private:
    char s[SIZE]; // 데이터가 저장되는 부분
    int top; // 가장 최근 데이터가 저장된 위치정보 저장
public:
    op_stack();         // Constructor, 스택 초기화
    void push(char x);  // push 연산
    char pop();         // pop 연산
    bool empty();       // 스택이 비었는 지 검사
    char top_element(); // pop 연산이 아닌 단순 조회
};

// 외부함수 선언 부
bool is_operand(char ch); // 해당함수가 피연산자인지 판별
int get_precedence(char op); // 연산자의 우선순위 정보 출력

int main()
{
    string input, output; // 입출력에 관련된 string 생성
    op_stack st1;         // 연산자를 저장할 스택 선언
    int i;                // 반복문 변수
    int length;           // 문자열의 길이

    cout << "Input a infix expression to convert. : ";
    cin >> input; // 사용자로부터 infix 표기법의 식을 전달받음
    length = input.size();

    // infix->postfix 변환부분
    for(i=0 ; i<length ; i++)
    {
        if(is_operand(input[i]))
            output += input[i]; // 피연산자인 경우 변환결과 문자열로 바로 추가
        else
        {
            if(st1.empty())
                st1.push(input[i]); // st1에 저장된 어느 연산자도 없을경우 -> 바로추가
            else if(input[i] == '(')
                st1.push(input[i]); // 소괄호인 경우 -> 바로추가
            else if(input[i] == ')')
            {
                while(st1.top_element() != '(') // '(가 나올떄까지'
                    output += st1.pop();        // 스택의 연산자들을 pop해서 output으로 저장
                st1.pop(); // 해당작업을 마무리한 후 스택에 존재하는 '(' 제거
            }
            else
            {
                // 우선순위가 더 높은 연산자인 경우
                if(get_precedence(input[i]) > get_precedence(st1.top_element()))
                    st1.push(input[i]); // 스택에 해당 연산자를 저장한다.
                else // 우선순위가 같거나 낮은 연산자인 경우
                {
                    // 자신보다 우선순위가 낮은 연산자가 나올때까지
                    while(get_precedence(input[i]) <= get_precedence(st1.top_element()))
                        output += st1.pop(); // 스택의 연산자들을 pop해서 output으로 저장
                    st1.push(input[i]); // 그리고 나서 해당 연산자를 스택에 push
                }
            }
        }
    }
    // 입력된 식의 요소들을 모두 스캔한 경우
    if(i == length)
    {
        while(!st1.empty())      // 스택에 남아있는 모든 연산자를
            output += st1.pop(); // output으로 pop
    }

    cout << "This is the result of convertion : ";
    cout << output << endl;
    return 0;
}



// 외부함수 정의 부
bool is_operand(char ch)
{
    if(ch == '*' || ch == '/' || ch == '+' || ch == '%'|| ch == '-' || ch == '(' || ch == ')')
        return false;
    else
        return true;
}

int get_precedence(char op)
{
    if(op == '*' || op == '/' || op == '%')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else if(op == '(')
        return 0;
    else
        return -1;
}

// class op_stack의 member 함수 정의부
op_stack:: op_stack()
{
    top = -1;
}

void op_stack:: push(char x)
{
    top++; // 새로운 데이터 저장을 위해 top의 값 1증가
    s[top] = x; // 스택에 연산자 저장
}

char op_stack:: pop()
{
    char temp; // 출력하고자 하는 문자 일시적으로 저장
    temp = s[top];
    top--; // 현재 top의 원소를 스택에서 배제
    return temp; // 배제한 원소값 반환
}

bool op_stack:: empty()
{
    if(top == -1)
        return true;
    else
        return false;
}

char op_stack:: top_element()
{
    return s[top]; // 가장 최근에 저장된 데이터 값 반환
}
