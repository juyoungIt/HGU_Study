// PA09
// 작성자 : 217700760 하주영

#include <iostream>
using namespace std;

// class node 정의 - 이름 및 점수정보를 저장하는 노드
class node
{
public:
    string name;   // 이름저장
    double score;  // 점수저장
    node* link;    // 다음노드를 가리킴
    void set_data(string s, double n); // 노드에 data를 저장
};

// class my_queue 정의
class my_queue
{
private:
    node* front; // queue의 front 부분
    node* rear;  // queue의 rear 부분
public:
    my_queue();             // constructor, queue의 front, rear값 초기화
    void insert_q(node t);  // my_queue에 대한 insert 연산
    node delete_q();        // my_queue에 대한 delete 연산
    bool q_empty();         // my_queue가 비었는 지에 대한 여부를 검사
};

int main()
{
    my_queue  a;
    node tmp;
    tmp.set_data("KIM", 22.2);
    a.insert_q(tmp);
    tmp.set_data("LEE", 33.3);
    a.insert_q(tmp);
    tmp.set_data("PARK", 44.4);
    a.insert_q(tmp);
    tmp.set_data("CHIO", 55.5);
    a.insert_q(tmp);
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score <<"\n";
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score <<"\n";
    return 0;
}

// class node의 member함수 정의
void node::set_data(string s, double n)
{
    name = s;   // 이름저장
    score = n;  // 점수저장
}

// class my_queue의 member함수 정의
my_queue::my_queue()
{
    front = NULL; // queue의 front 값을 NULL로 초기화
    rear = NULL;  // queue의 rear 값을 NULL로 초기화
}

void my_queue::insert_q(node t)
{
    // 새로운 node 생성 및 값의 저장
    node* n_node;        // 새롭게 생성되는 node의 주소값을 저장
    n_node = new node;   // 새로운 node를 위한 메모리 공간 할당
    (*n_node) = t;       // 새로운 node에 node t의 값을 저장
    n_node->link = NULL; // 새로운 node의 link값을 NULL로 초기화
    
    // 링크를 조정하여 queue에 insert
    if(front == NULL) // queue에 처음으로 저장하는 node인 경우
    {
        rear = n_node;  // queue의 rear가 새 node를 가리키도록
        front = n_node; // queue의 front가 새 node를 가리키도록
    }
    else // 새롭게 추가되는 node가 아닌경우
    {
        rear->link = n_node; // 이전의 rear node가 새로운 node를 가리키도록
        rear = n_node;       // rear가 새로운 node를 가리키도록
    }
}

node my_queue::delete_q()
{
    // 예외처리, queue가 빈 상황에서 delete 연산을 시도할 경우
    if(q_empty()){
        cout << "Error! : queue is empty" << endl;
        exit(-1); // 비정상적인 종료를 의미하는 -1 값을 반환하며 프로그램 강제종료
    }
    
    node t;   // delete할 node의 값을 저장
    node* tp; // delete할 node의 주소값을 저장
    t = (*front); // delete할 node의 값을 저장
    tp = front;   // delete할 node의 주소값을 저장
    
    // 링크조정 및 delete 과정 수행
    front = front->link; // 다음 node를 가리키도록 설정
    // 예외처리, 지우는 node가 queue에 저장된 마지막 node일 경우
    if(front == NULL)
        rear = NULL; // rear의 값도 NULL로 설정
    delete tp; // delete할 node의 메모리 공간 해제
    return t;  // delete한 node의 값 반환
}

bool my_queue::q_empty()
{
    if(rear == NULL)
        return true; // rear 가 NULL 값을 가지는 것은 queue에 저장된 데이터가 없음을 의미하므로
    else
        return false;
}
