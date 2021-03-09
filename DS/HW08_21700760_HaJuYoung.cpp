// PA08
// 작성자 : 21700760 하주영

#include <iostream>
using namespace std;

// node class 정의 - 이름 및 점수정보를 저장하는 노드
class node
{
public:
    string name;  // 이름 저장
    double score; // 점수 값 저장
    node* link;   // 다음노드를 가리키는 포인터
    void set_data(string s, double n); // 노드에 데이터를 저장하는 함수
};

// my_stack class 정의
class my_stack
{
private:
    node* top;           // 스택의 top 원소의 포인터값 저장
public:
    my_stack();          // constructor, my_stack의 top을 NULL로 초기화
    void push(node t);   // my_stack에 대한 push 연산
    node pop();          // my_stack에 대한 pop연산
    bool stack_empty();  // my_stack이 비어있는 지 여부를 검사
};

int main()
{
    my_stack a;
    node tmp;
    tmp.set_data("KIM", 22.2);
    a.push(tmp);
    tmp.set_data("LEE", 33.3);
    a.push(tmp);
    tmp.set_data("PARK", 44.4);
    a.push(tmp);
    tmp.set_data("CHOI", 55.5);
    a.push(tmp);
    tmp = a.pop();
    cout<< tmp.name << " : " << tmp.score<< "\n";
    tmp = a.pop();
    cout<< tmp.name << " : " << tmp.score<< "\n";
    return 0;
}

// class node의 member 함수 정의
// 노드에 데이터를 저장
void node::set_data(string s, double n)
{
    name = s;   // 이름 저장
    score = n;  // 점수 저장å
}

// class my_stack의 member 함수정의
my_stack::my_stack()
{
    top = NULL;  // top의 값을 저장된 값이 없음을 의미하는 NULL로 초기화
}

void my_stack::push(node t)
{
    // 새로운 node를 생성하여 값을 저장
    node* n_node;       // 새롭게 생성되는 node의 주소값을 저장
    n_node = new node;  // 새로운 node를 위한 메모리 공간 생성
    (*n_node) = t;      // 새롭게 생성한 node에 입력받은 node t의 값을 저장
    
    // 링크를 조정하여 stack에 push
    n_node->link = top;  // 새로운 node의 link가 기존의 node를 가리키도록
    top = n_node;        // my_stack의 top이 새로운 node를 가리키도록
}

node my_stack::pop()
{
    // 예외처리, stack이 빈 상황에서 pop 연산 시도할 경우
    if(stack_empty()){
        cout << "Error! : stack is empty" << endl;
        exit(-1); // 비정상적인 종료를 의미하는 -1을 입력하며 프로그램 강제종료
    }
    
    node t;             // pop하는 node의 값을 저장
    node* tp;           // pop하는 node의 포인터값을 저장
    
    t = (*top);         // pop할 node의 값을 저장
    tp = top;           // pop할 node의 포인터 값을 저장
    
    top = top->link;    // top을 다음 node로 조정
    delete tp;          // pop한 node의 메모리 공간해제
    return t;           // pop한 node의 값을 return
}

 bool my_stack::stack_empty()
{
    if(top == NULL)
        return true;   // stack에 저장된 데이터가 없을 경우 true를 return
    else
        return false;  // stack에 저장된 데이터가 있을 경우 false를 return
}
