// PA13
// 작성자 : 21700760 하주영

#include <iostream>
using namespace std;

// tree에 사용되는 노드
class node
{
public:
    string name;  // 이름
    double score; // 점수
    node *left, *right; // 왼쪽, 오른쪽
    void set_data(string s, double n); // data 저장
};

// stack, queue에 사용되는 node
class sq_node
{
public:
    node* tree_node; // tree를 구성하는 node
    sq_node* link; // 다음노드를 가리키는 link
    void set_sq(node* t_node); // data 저장
};

class nstack
{
private:
    sq_node* top;
public:
    nstack(); // constructor, top의 값을 NULL로 초기화
    void push(node* t_node); // stack에 대한 push 연산
    node* pop(); // stack에 대한 pop연산
    bool stack_empty(); // stack이 비었는 지 검사
};

class my_queue
{
private:
    sq_node* front;
    sq_node* rear;
public:
    my_queue(); // constructor, front와 rear의 값을 NULL으로 초기화
    void insert_q(node* t_node); // queue에 대한 insert 연산
    node* delete_q(); // queue에 대한 delete 연산
    bool queue_empty(); // queue가 비었는 지 여부를 검사
};

// my_tree class 정의
class my_tree
{
private:
public:
    int node_count;          // 저장된 node 수
    node* root;              // root node
    my_tree();               // constructor, node_count, root 초기화
    int insert_root(node t); // root로 node t 내용 추가
    int insert_left(string tname, node t);  // tname의 node 왼쪽에 t 추가
    int insert_right(string tname, node t); // tname의 node 오른쪽에 t 추가
    
    double score_sum(); // 모든 node의 score 합 return
    double score_average(); // 모든 node의 score 평균 return
    void print_data_inorder(); // inorder 순서로 모든 node의 값 출력
    void print_data_preorder(); // preorder 순서로 모든 node의 값 출력
    void print_data_postorder(); // postorder 순서로 모든 node의 값 출력
    
    void nonrecursive_inorder(); // inorder traversal
    void print_data_levelorder(); // levelorder 순서로 모든 node의 값 출력
};

// 일반함수 선언
int node_insert_left(node* p, string tname, node t);  // p가리키는 node의 name이 pname이면, node t의 값을 복사하여 left에 생성
int node_insert_right(node* p, string tname, node t); // p가리키는 node의 name이 pname이면, node t의 값을 복사하여 right에 생성
double sum_allnodes(node* p); // p를 root로 하는 tree의 합산값 return
void inorder_print(node* p);
void preorder_print(node* p);
void postorder_print(node* p);
void copy_tree(my_tree &t1, my_tree t2);
node* make_copy(node *p);
bool equal_tree(my_tree t1, my_tree t2);
bool equal_test(node* n1, node* n2);

int main()
{
    my_tree thetree;
    node tmp;

    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);
          
    cout << "\nNon-recursive Inorder Result \n";
    thetree.nonrecursive_inorder();
    cout << "\nLevel-Order traversal Result \n";
    thetree.print_data_levelorder();
    my_tree tree2;
    copy_tree(tree2, thetree);
    cout << "\nThe inorder traversal Result of the new tree \n";
    tree2.print_data_inorder();
    if (equal_tree(tree2, thetree) )
        cout << "Yes\n";
    else
        cout << "No\n";
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    if (equal_tree(tree2, thetree) )
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

// class node member 함수정의
void node::set_data(string s, double n)
{
    name = s;  // 이름저장
    score = n; // 점수저장
}

// class node sq_node 함수정의
void sq_node::set_sq(node* t_node)
{
    tree_node = t_node; // tree를 구성하는 node의 주소값을 저장
}

// class nstack의 member함수 정의
nstack::nstack()
{
    top = NULL; // top의 값을 NULL로 초기화
}

void nstack::push(node* t_tree)
{
    sq_node* n_node; // stack을 구성하는 node의 주소값을 저장
    n_node = new sq_node; // stack을 위한 새로운 node공간 생성
    n_node->set_sq(t_tree); // 노드에 데이터를 저장
    if(stack_empty())
        n_node->link = NULL; // 처음저장되는 node의 경우 link 값을 NULL로 설정
    else
        n_node->link = top; // 새롭게 추가되는 노드가 이전의 노드를 가리키도록
    top = n_node; // 새롭게 추가된 node를 top이 가리키도록 설정
}

node* nstack::pop()
{
    if(stack_empty()){
        cout << "Error! : Stack memory is empty." << endl;
        exit(-1); // 프로그램 강제종료
    }
    
    sq_node* temp; // pop할 node의 주소값을 저장
    sq_node t; // pop할 노드의 값을 저장
    temp = top; // pop할 노드의 주소값을 저장
    t = (*top); // pop할 노드의 값을 저장
    top = top->link; // pop을 위한 link 조정
    free(temp); // 해당노드 삭제
    return t.tree_node; // 삭제한 노드의 값 반환
}

bool nstack::stack_empty()
{
    if(top == NULL) return true;
    else return false;
}

// class my_queue에 대한 member함수 정의
my_queue::my_queue()
{
    front = NULL;
    rear = NULL;
}

void my_queue::insert_q(node* t_node)
{
    sq_node* n_node; // 새로운 노드의 주소값
    n_node = new sq_node; // 새로운 노드 생성
    n_node->set_sq(t_node); // 생성한 노드에 값을 저장
    if(queue_empty()){
        n_node->link = NULL; // queue에 처음 저장되는 데이터인 경우
        front = n_node; // front가 새로운 노드를 가리키도록
    }
    else // queue에 처음 저장하는 데이터가 아닌 경우
        rear->link = n_node; // 링크를 조정하여 연결
    rear = n_node; // rear가 새로운 노드를 가리키도록
}

node* my_queue::delete_q()
{
    if(queue_empty()){
        cout << "Error! : queue is empty" << endl;
        exit(-1); // 프로그램 강제종료
    }
    sq_node* temp; // 삭제하는 노드의 주소값
    sq_node t; // 삭제하는 노드의 값
    temp = front; // 삭제하는 노드의 주소값 저장
    t = (*front); // 삭제하는 노드의 값 저장
    
    
    if(front == rear) // 해당노드가 queue에 저장된 마지막 노드인 경우
        rear = NULL;
    front = front->link; // 링크를 조정
    delete(temp); // 노드를 삭제
    return t.tree_node; // 삭제한 노드의 값을 반환
}

bool my_queue::queue_empty()
{
    if(rear == NULL) return true;
    else return false;
}

// class my_tree member 함수정의
my_tree::my_tree()
{
    node_count = 0;
    root = NULL;
}

int my_tree::insert_root(node t)
{
    if(root != NULL) return 0; // 예외처리 - tree의 node가 NULL이 아닌 경우
    
    node* p = new node; // node 공간생성
    (*p) = t;           // 주어진 node 내용 copy
    p->left = NULL;
    p->right = NULL;
    root = p; // root node 설정
    node_count++;
    return 1;
}

int my_tree::insert_left(string tname, node t)
{
    int result; // 결과값
    
    result = node_insert_left(root, tname, t);
    if(result == 1) node_count++; // 저장성공 시 node_count의 값을 1증가
    return result;
}

int my_tree::insert_right(string tname, node t)
{
    int result; // 결과값
    result = node_insert_right(root, tname, t);
    if(result == 1)
        node_count++;
    return result;
}

double my_tree::score_sum()
{
    return sum_allnodes(root);
}

double my_tree::score_average()
{
    return score_sum() / node_count;
}

void my_tree::print_data_inorder()
{
    inorder_print(root);
}

void my_tree::print_data_preorder()
{
    preorder_print(root);
}

void my_tree::print_data_postorder()
{
    postorder_print(root);
}

void my_tree::nonrecursive_inorder()
{
    nstack s1; // 알고리즘 상에서 사용하는 스택을 1개 생성
    node* p; // node의 주소값을 저장
    
    p = root; // root 노드부터 시작
    while(1)
    {
        while(p != NULL) // 왼쪽 끝 노드를 찾을 때까지 - 1
        {
            s1.push(p); // 노드를 스택에 넣는다.
            p = p->left; // 왼쪽 끝노드를 찾을 때까지 - 2
        }
       
        if(s1.stack_empty())
            return; // 스택이 empty면 return
        p = s1.pop(); // 1개의 원소를 pop함
        cout << p->name << " : " << p->score << endl; // pop한 원소를 traverse
        p = p->right; // 해당노드의 오른쪽 child를 기준으로 이를 다시 반복
    }
}

void my_tree::print_data_levelorder()
{
    my_queue q1; // node* type을 저장하는 queue 생성
    node* p; // node의 주소값 저장
    
    if(root == NULL) return; // root가 NULL이라면 return
    q1.insert_q(root); // root를 queue에 넣는다.
    // 다음을 반복한다.
    while(1)
    {
        if(q1.queue_empty()) break;
        p = q1.delete_q(); // queue로부터 1개의 원소를 가져온다.
        cout << p->name << " : " << p->score << endl; // 가져온 원소를 traverse
        if(p->left != NULL) q1.insert_q(p->left); // 그 원소의 left가 NULL이 아니면 queue에 넣는다.
        if(p->right != NULL) q1.insert_q(p->right); // 그 원소의 right가 NULL이 아니면 queue에 넣는다.
    }
}


// 일반함수 정의
/*
   반환값의 의미
   1. 1 : insert 과정의 성공
   2. 0 : tname을 가지는 node가 없음
   3. -1 : tname을 가지는 node는 있으나 추가하려는 방향(Left or right)이 NULL이 아닌 경우
 */
int node_insert_left(node* p, string tname, node t)
{
    if(p == NULL) return 0; // 예외처리, 조회할 노드가 존재하지 않는 경우
    if(p->name == tname) // p의 name이 tname인 경우
    {
        if(p->left != NULL) return -1; // 예외처리, 이미 left에 저장된 값이 있는 경우
        node* np = new node; // node 공간 생성
        (*np) = t; // 주어진 node 내용 copy
        np->left = NULL;
        np->right = NULL;
        p->left = np; // p의 left에 연결
        return 1; // insert 과정의 성공
    }
    else // p의 name이 t_name이 아닌경우
    {
        int result = node_insert_left(p->left, tname, t); // 재귀적 호출 - 1
        if(result != 0) return result; // node를 찾지 못한 상황이 아니라면 그 결과값을 그대로 반환
        return node_insert_left(p->right, tname, t); // 재귀적 호출 - 2
    }
}

int node_insert_right(node* p, string tname, node t)
{
    if(p == NULL) return 0; // 예외처리, 조회할 노드가 존재하지 않는 경우
    if(p->name == tname) // p의 name이 tname인 경우
    {
        if(p->right != NULL) return -1; // 예외처리, 이미 right에 저장된 node가 존재하는 경우
        node* np = new node; // node 공간 생성
        (*np) = t; // 주어진 node 내용 copy
        np->left = NULL;
        np->right = NULL;
        p->right = np; // root의 right에 연결
        return 1; // insert 과정의 성공
    }
    else // p의 name이 t_name이 아닌경우
    {
        int result = node_insert_right(p->right, tname, t); // 재귀적 호출
        if(result != 0) return result; // node를 찾지 못한 상황이 아니라면 그 결과값을 그대로 반환
        return node_insert_right(p->left, tname, t); // 재귀적 호출 - 2
    }
}

double sum_allnodes(node* p)
{
    if(p == NULL) return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

void inorder_print(node* p)
{
    if(p == NULL) return; // 예외처리, root값이 NULL인 경우
    
    inorder_print(p->left); // left subtree 에 대한 traversal
    cout << p->name << " : " << p->score << endl; // root node의 data에 대한처리
    inorder_print(p->right); // right subtree에 대한 traversal
}

void preorder_print(node* p)
{
    if(p == NULL) return; // 예외처리, root값이 NULL인 경우
    
    cout << p->name << " : " << p->score << endl; // root node의 data에 대한처리
    preorder_print(p->left); // left subtree 에 대한 traversal
    preorder_print(p->right); // right subtree에 대한 traversal
}

void postorder_print(node* p)
{
    if(p == NULL) return; // 예외처리, root값이 NULL인 경우
    
    postorder_print(p->left); // left subtree 에 대한 traversal
    postorder_print(p->right); // right subtree에 대한 traversal
    cout << p->name << " : " << p->score << endl; // root node의 data에 대한처리
}

void copy_tree(my_tree &t1, my_tree t2)
{
    t1.node_count = t2.node_count; // node count를 copy
    t1.root = make_copy(t2.root);
}

node* make_copy(node *p)
{
    node *t; // 노드의 주소값을 일시저장
    if(p == NULL) return NULL; // 주어진 포인터가 NULL일 경우, NULL을 return 한다.
    t = new node; // 노드공간을 생성
    *t = *p; // root의 데이터를 copy
    t->left = make_copy(p->left); // root의 왼쪽을 copy하여 연결
    t->right = make_copy(p->right); // root의 오른쪽을 copy하여 연결
    return t;
}

bool equal_tree(my_tree t1, my_tree t2)
{
    if(t1.node_count != t2.node_count) return false; // 두 tree의 node_count 값이 다르면 false를 return
    return equal_test(t1.root, t2.root); // 두 tree의 root 이하 내용의 동일여부를 확인하여 그 결과를 return
}

bool equal_test(node* n1, node* n2)
{
    if(n1 == NULL && n2 == NULL) return true;  // 두 root가 모두 NULL이면 true를 return
    if(n1 == NULL || n2 == NULL) return false; // 두 root중 하나가 NULL이면 false를 return
    if(n1->name != n2->name) return false; // 두 root의 데이터 값이 다르면 false를 return - 1
    if(n1->score != n2->score) return false; // 두 root의 데이터 값이 다르면 false를 return - 2
    // 두 root의 왼쪽 subtree, 오른쪽 substree에 대하여 비교하고 그 결과를 return
    if(equal_test(n1->left, n2->left) && equal_test(n1->right, n2->right)) return true;
    else return false;
}
