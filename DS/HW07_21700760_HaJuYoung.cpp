// PA07
// 작성자 : 21700760 하주영

#include <iostream>
#include <string>
using namespace std;

// node class에 대한 정의부분
class node
{
public:
    string name;   // 이름에 대한 정보저장
    double score;  // 점수에 대한 정보저장
    node* link;    // 다음노드를 가리키는 포인터
    void set_data(string s, double n); // 노드에 데이터를 저장하는 함수
};

// Linked List class에 대한 정의부분
class my_list
{
private:
    node* head; // 리스트의 머리부분의 노드를 가리킴
    node* tail; // 리스트의 꼬리부분의 노드를 가리킴
public:
    my_list(); // constructor, 리스트의 요소들을 초기화(head, tail)
    void add_to_head(node t); // 리스트의 머리 부분에 새로운 노드를 추가
    void add_to_tail(node t); // 리스트의 꼬리 부분에 새로운 노드를 추가
    node delete_from_head();  // 리스트의 머리부분의 노드 1개 삭제
    int num_nodes();          // 저장된 노드의 수를 반환
    bool list_empty();        // 노드가 비었는 지 검사
    // 실습에서 추가되는 member 함수
    double score_sum(); // 현재 list의 모든 node의 score 합을 return
    double get_score(string t_name); // t_name으로 주어진 name의 score return
    int remove_a_node(string t_name); // t_name에 해당하는 node 삭제 / 성공시 1, 탐색 실패시 0 return
};

int main( )
{
    my_list    a;
    node   tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           // head 위치로 2개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검
    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검
    tmp = a.delete_from_head();
    cout  << tmp.name << " is deleted.\n";   // 3단계 점검
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);             // 2개의 원소 추가

    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";
    cout << "Park’s score : " << a.get_score("Park") << "\n";  // 4단계 점검
    if ( a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";     // 5단계 점검
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 최종 점검
    return 0;
}

// class node의 member 함수 정의부
void node::set_data(string s, double n)
{
    name = s; // 이름정보 저장
    score = n; // 점수정보 저장
}

// class my_list의 member 함수 정의부
my_list::my_list()
{// head와 null의 값을 저장된 값이 없음을 의미하는 null로 초기화
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node* p; // 새로운 노드의 주소값을 저장하는 변수
    p = new node; // 새로운 노드에 대한 메모리동적 할당
    (*p) = t;  // 입력받은 노드의 정보를 새로운 노드에 추가
    p->link = head; // 새롭게 추가되는 노드가 이전에 head였던 노드를 가리키도록
    head = p; // head가 가리키는 노드를 새롭게 추가된 노드로 변경
    if(tail == NULL) // 리스트의 첫 노드인 경우 tail도 첫 노드를 가리키도록 지정
        tail = p;
}

void my_list::add_to_tail(node t)
{
    node* p;            // 새로운 노드의 주소값을 저장하는 변수
    p = new node;       // 새로운 노드에 대한 메모리동적 할당
    (*p) = t;           // 입력받은 노드의 정보를 새로운 노드에 추가
    p->link = NULL;     // 생성한 노드의 link가 NULL 포인터가 되도록 설정
    if(tail != NULL)    // 리스트에 처음 저장되는 노드가 아닌 경우
        tail->link = p; // 이전의 꼬리노드의 link가 새로운 노드르 가리키도로록 함
    else                // 리스트에 처음 저장되는 노드인 경우
        head = p;
    tail = p;           // 꼬리가 새롭게 추가된 노드를 가리킬 수 있도록 설정
}

node my_list::delete_from_head()
{
    node temp;           // 삭제되는 노드의 내용을 일시저장
    node* t;             // 삭제되는 노드의 주소값을 일시저장
    t = head;            // 삭제될 머리노드의 주소값을 가져옴
    temp = (*head);      // 삭제될 머리노드의 내용을 가져옴
    head = head->link;   // 이전의 노드가 리스트의 head 노드가 되도록 설정
    if(head == NULL)
        tail = NULL;     // 삭제 후 리스트에 저장되는 노드가 없을 경우
    delete t;            // 해당노드에 할당되어 있던 메모리공간 해제
    return temp;         // 삭제 한 노드의 데이터 값을 반환
}

int my_list::num_nodes()
{
    node* t;       // 반복문 변수
    int count = 0; // 저장된 노드의 수 값을 저장하는 변수

    for(t=head ; t!=NULL ; t=t->link)
        count++; // 리스트의 머리노드부터 꼬리노드를 만날때까지 탐색을 진행하며 count값을 1씩 증가하여 count
    return count; // 구한 값을 반환
}

bool my_list::list_empty()
{
    if(head == NULL)  // 머리노드를 가리키는 head가 null 값을 가진다는 것은 저장된 데이터가 없음을 의미하므로
        return true;
    else
        return false;
}

// 실습에서 추가된 member 함수 정의
double my_list::score_sum()
{
    node* t; // 리스트의 모든 노드의 주소값을 저장하는 변수
    double total_sum = 0; // 리스트에 저장된 총 score의 값을 저장하는 변수

    for(t=head ; t != NULL ; t=t->link)
        total_sum += t->score;
    return total_sum; // 총 합산값 반환
}

double my_list::get_score(string t_name)
{
    node* t;      // 반복문 변수

    for(t=head ; t != NULL ; t=t->link)
        if(t->name == t_name) // 만약 같은 이름 값을 갖는다면
            return t->score;  // 해당 노드의 점수값을 반환
    return -1; // 탐색의 실패를 의미하는 -1을 반환
}

int my_list::remove_a_node(string t_name)
{
    node* cur = NULL;  // 리스트의 모든 노드의 주소값을 저장
    node* prev = NULL; // cur가 가리키는 이전 노드의 주소값을 저장

    // 리스트에 저장된 모든 노드를 탐색하기 위한 반복문
    for(cur = head ; cur != NULL ; cur = cur->link)
    {
        if(cur->name == t_name)// 같은 이름을 찾은 경우
        {
            if (cur == head) // 리스트의 head 노드일 경우
            {
                head = cur->link;     // 리스트의 head가 다음노드를 가리키도록
                if (cur->link == NULL) // 삭제하는 노드가 리스트의 마지막 노드일 경우
                    tail = NULL;      // 리스트의 tail 도 NULL값을 가지도록 해줌
                delete cur;           // 현재 조회 중인 노드를 삭제
                return 1;             // 삭제의 성공을 의미하는 값 1을 반환
            }
            else if(cur == tail) // 리스트의 tail 노드인 경우
            {
                prev->link = NULL; // 이전노드의 link값을 NULL로 변경
                tail = prev;       // 리스트의 새로운 tail 노드 설정
                delete cur;        // 현재 조회 중인 노드를 삭제
                return 1;          // 삭제의 성공을 의미하는 값 1을 반환
            }
            else // 리스트의 head와 tail 사이에 위치하는 노드일 경우
            {
                prev->link = cur->link; // 이전노드와 그 다음노드를 연결
                delete cur;             // 현재 조회중인 노드를 삭제
                return 1;               // 삭제의 성공을 의미하는 값 1 반환
            }
        }
        prev = cur; // prev의 값을 변경, prev가 cur보다 한단계 이전의 노드를 가리킬 수 있도록 설정
    }
    if(cur == NULL) // 일치하는 이름을 찾지 못하여 삭제에 실패한 경우
        return 0;   // 조회 및 삭제의 실패를 의미하는 0의 값 반환
    else
        return -1; // 논리상 나올 수 없는 잘못된 값이 나온 경우 오류를 의미하는 -1 출력
}
