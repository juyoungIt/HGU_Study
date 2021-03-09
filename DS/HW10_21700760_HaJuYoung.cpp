// PA09
// 작성자 : 21700760 하주영

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

// class my_list 정의
class my_list
{
private:
    node* head; // list node의 head
    node* tail; // list node의 tail
public:
    my_list();                // constructor, list의 head, tail을 NULL로 초기화
    void add_to_head(node t); // list의 head에 node 추가
    void add_to_tail(node t); // list의 tail에 node 추가
    node delete_from_head();  // list의 head의 node 삭제
    int num_nodes();          // 현재 list에 저장된 node의 수를 반환
    bool list_empty();        // list가 비었는 지 여부를 판별
    void invert();            // list의 data node를 역순으로 재구성
    friend bool list_equal(my_list a, my_list b);
};

// 일반함수 선언
bool is_equal(node* p1, node* p2); // 재귀적인 호출을 위해 사용하는 함수, 입력된 두 node가 같은 node인지를 판별
bool equal_data(node t1, node t2); // 입력된 두 node가 같은 값을 가지는 node인지 판별

int main()
{
    my_list a,b;
    node tmp;
    
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    b.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    b.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    b.add_to_head(tmp);
    tmp.set_data("Kim", 83.5);
    b.add_to_head(tmp);
    
    b.invert();
    
    if (list_equal(a, b))
        cout << "Yes, the two lists are identical. \n";
    else
        cout << "No, They are not identical.\n";
    tmp = b.delete_from_head();
    cout << tmp.name << " : " << tmp.score << "\n";
    
    return 0;
}

// class node의 member함수 정의
void node::set_data(string s, double n)
{
    name = s;   // 이름저장
    score = n;  // 점수저장
}

// class my_list의 member함수 정의
my_list::my_list()
{
    head = NULL;  // list의 head를 NULL로 초기화
    tail = NULL;  // list의 tail을 NULL로 초기화
}

void my_list::add_to_head(node t)
{
    // node의 생성 및 데이터 저장
    node* n_node; // 새로 생성하는 node의 주소값 저장
    n_node = new node; // 새로운 node를 위한 메모리 공간할당
    (*n_node) = t;     // 새로운 node에 node t의 값을 저장
    
    // link를 조정하여 list에 node를 추가
    n_node->link = head; // 새로운 node가 기존의 list head node를 가리키도록
    head = n_node;       // list의 head가 새로운 node를 가리키도록
    if(list_empty())         // list에 저장된 node가 없을 경우
        tail = n_node;       // list의 tail이 새로운 node를 가리키도록
}

void my_list::add_to_tail(node t)
{
    // node의 생성 및 데이터 저장
    node* n_node; // 새로 생성하는 node의 주소값 저장
    n_node = new node;   // 새로운 node를 위한 메모리 공간할당
    (*n_node) = t;       // 새로운 node에 node t의 값을 저장
    n_node->link = NULL; // 새롭게 추가되는 node의 link를 NULL로 초기화
    
    // link를 조정하여 list에 node를 추가
    if(tail == NULL)   // list에 저장된 데이터가 없을 경우
        head = n_node;
    else // list에 데이터가 저장되어 있는 상태라면
        tail->link = n_node; // 이전의 tail이 새로운 node를 가리키도록
    tail = n_node; // list의 tail이 새로운 node를 가리키도록
}

node my_list::delete_from_head()
{
    // 예외처리, list가 빈 상황에서 delete를 시도하는 경우
    if(list_empty()){
        cout << "Error! : list is empty" << endl;
        exit(-1); // 비정상적인 종료를 의미하는 -1을 반환하며 프로그램 강제종료
    }
    
    node t;   // 삭제하고자 하는 node의 값을 저장
    node* tp; // 삭제하고자 하는 node의 주소값을 저장
    
    t = (*head); // 삭제하고자 하는 node의 값을 저장
    tp = head;   // 삭제하고자 하는 node의 주소값을 저장
    
    // link를 조정한 후 해당 node를 삭제
    head = head->link; // list head가 다음 노드를 가리키도록
    if(head == NULL)   // 만약 해당 node가 list의 마지막 노드라면
        tail = NULL;   // list의 tail도 NULL로 변경
    delete tp;         // 삭제하고자 하는 node 삭제
    return t;          // 삭제한 node의 값을 반환
}

int my_list::num_nodes()
{
    node* temp;
    int count = 0; // list에 저장된 node의 갯수 저장
    // list의 모든 node를 스캔하기 위해 반복문 구성
    for(temp=head ; temp!=NULL ; temp=temp->link)
        count++;
    return count;
}

bool my_list::list_empty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

void my_list::invert()
{
    node* oldHead; // 재정렬을 하지 않은 남아있는 list의 head
    node* newHead; // 재정렬한 list의 head
    node* temp;    // link 변경 시 사용하기 위해 일시적으로 특정노드를 저장
    
    oldHead = head;
    newHead = NULL;
    while(true)
    {
        temp = newHead;          // temp가 newHead를 가리키도록
        newHead = oldHead;       // newHead가 oldHead가 가리키는 node를 가리키도록
        oldHead = oldHead->link; // oldHead가 그 다음 node를 가리키도록
        newHead->link = temp;    // newHead의 노드가 이전의 노드를 가리키도록
        if(oldHead == NULL)      // 만약 리스트의 끝까지 재정렬을 모두 마쳤다면
            break;               // 무한루프 탈출
    }
    tail = head;    // list의 tail을 head로 변경
    head = newHead; // list의 head를 newHead로 변경
}

// 일반함수 정의
bool list_equal(my_list a, my_list b)
{
    return is_equal(a.head, b.head); // 각각 list a, b의 head에서 비교를 시작
}

bool is_equal(node* p1, node* p2)
{
    if(p1 == NULL && p2 == NULL)
        return true; // 둘다 NULL인 것도 같은 것임을 의미하므로
    if(p1 == NULL || p2 == NULL)
        return false; // 위에서 && 케이스가 걸러졌기 때문에 이렇게 사용해도 무방
    if(!equal_data(*p1, *p2))
        return false;  // 데이터를 가지고 있는 노드인데 두 노드의 값이 다르다면
    else
        return is_equal(p1->link, p2->link); // 함수의 재귀적인 호출을 이용, 각각 다음 node의 주소값을 넘겨줌
}

bool equal_data(node t1, node t2)
{
    if(t1.name != t2.name) // 이름이 다른 경우
        return false;
    if(t1.score != t2.score) // 점수가 다른 경우
        return false;
    return true; // 위의 두 조건에서 걸리지 않는다면 입력된 두 node는 같은 값을 가지는 것을 의미하므로
}
