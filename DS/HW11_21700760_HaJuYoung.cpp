// PA11
// 작성자 : 21700760 하주영

#include <iostream>
using namespace std;

// 프로그램의 readability 향상을 위한 macro 정의
#define INSERT      1
#define DELETE      2
#define SHOW_TOP    3
#define SHOW_STATE  4
#define QUIT        5

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
    node top_element();  // my_stack에 대한 top원소 조회
    bool stack_empty();  // my_stack이 비어있는 지 여부를 검사
};

// 일반함수 선언(Menu-driven)
int get_cmd();                  // 사용자에게 사용가능한 명령을 보여주고, 값을 입력받음
void node_insert(my_stack &p);  // 사용자에게 값을 입력받아 데이터를 저장
void node_delete(my_stack &p);             // stack에 저장된 데이터를 삭제
void show_top_element(my_stack &p);        // 가장 최근에 저장한 데이터를 사용자에게 보여줌=
void show_state(my_stack &p);              // 현재 저장된 데이터가 있는 지, 없는지 여부를 판별


int main()
{
    my_stack a;
    int cmd_option; // 사용자가 선택한 명령에 대한 값을 저장
    
    do
    {
        cmd_option = get_cmd();
        switch(cmd_option)
        {
            case INSERT:
                node_insert(a);
                break;
            case DELETE:
                node_delete(a);
                break;
            case SHOW_TOP:
                show_top_element(a);
                break;
            case SHOW_STATE:
                show_state(a);
                break;
            case QUIT:
                break;
            default:
                cout << "Error! : Invalide command option" << endl;
        }
    }while(cmd_option != 5);
    
    return 0;
}

// 일반함수 정의(Menu-driven)
int get_cmd()
{
    int cmd; // 사용자가 선택한 명령에 대한 값을 저장
    cout << "********************************\n";
    cout << "   <Available Command List>\n\n";
    cout << "1. Push node \n";
    cout << "2. Pop node \n";
    cout << "3. Show the top element \n";
    cout << "4. Show the stack state \n";
    cout << "5. Quit\n";
    cout << "--------------------------------\n";
    cout << "   Select the command : ";
    cin >> cmd; // 사용자가 입력한 값을 변수 cmd에 저장
    cout << "********************************\n";
    return cmd; // cmd값을 반환
}

void node_insert(my_stack &p)
{
    node temp;     // 사용자에게 입력받은 정보를 일시적으로 저장할 node
    string tname;  // 사용자가 입력하는 이름값 저장
    double tscore; // 사용자가 입력하는 점수값 저장
    
    cout << "Enter the name : ";
    cin >> tname;
    cout << "Enter the score : ";
    cin >> tscore;
    temp.set_data(tname, tscore); // 입력받은 정보 node에 저장
    p.push(temp); // 생성한 node의 정보를 stack에 push
    cout << "Success! : The node saved" << endl;
}

void node_delete(my_stack &p)
{
    node temp; // 삭제되는 node의 값을 저장
    // 예외처리, 저장한 데이터가 없는 상황에서 데이터 삭제를 시도할 경우
    if(p.stack_empty()){
        cout << "Error! : stack is empty" << endl;
        return;
    }
    
    temp = p.pop(); // 해당 node를 stack pop 연산을 이용하여 삭제
    cout << "Success! : The node deleted" << endl;
    cout << temp.name << " : " << temp.score << endl; // 삭제한 노드의 정보를 출력
}

void show_top_element(my_stack &p)
{
    node temp; // stack의 top node의 값을 저장
    // 예외처리, 저장한 데이터가 없는 상황에서 데이터 조회를 시도할 경우
    if(p.stack_empty()){
        cout << "Error! : stack is empty" << endl;
        return;
    }
    temp = p.top_element();
    cout << "The top element" << endl;
    cout << temp.name << " : " << temp.score << endl;
}

void show_state(my_stack &p)
{
    if(p.stack_empty())
        cout << "stack state : empty" << endl;
    else
        cout << "Stack state : exist saved data" << endl;
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

node my_stack::top_element()
{
    // 예외처리, stack이 빈 상황에서 pop 연산 시도할 경우
    if(stack_empty()){
        cout << "Error! : stack is empty" << endl;
        exit(-1); // 비정상적인 종료를 의미하는 -1을 입력하며 프로그램 강제종료
    }
    
    node t;     // 조회할 top node의 값을 저장
    t = (*top); // 조회할 top node의 값을 새롭게 생성한 node t에 저장
    return t;   // 조회한 top node의 값을 반환
}

 bool my_stack::stack_empty()
{
    if(top == NULL)
        return true;   // stack에 저장된 데이터가 없을 경우 true를 return
    else
        return false;  // stack에 저장된 데이터가 있을 경우 false를 return
}

