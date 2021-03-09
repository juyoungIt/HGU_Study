// PA12
// 작성자 : 21700760 하주영

#include <iostream>
using namespace std;

// node class 정의
class node
{
public:
    string name;  // 이름
    double score; // 점수
    node *left, *right; // 왼쪽, 오른쪽
    void set_data(string s, double n); // data 저장
};

// my_tree class 정의
class my_tree
{
private:
    int node_count;          // 저장된 node 수
    node* root;              // root node
public:
    my_tree();               // constructor, node_count, root 초기화
    int insert_root(node t); // root로 node t 내용 추가
    int insert_left(string tname, node t);  // tname의 node 왼쪽에 t 추가
    int insert_right(string tname, node t); // tname의 node 오른쪽에 t 추가
    
    double score_sum(); // 모든 node의 score 합 return
    double score_average(); // 모든 node의 score 평균 return
    void print_data_inorder(); // inorder 순서로 모든 node의 값 출력
    void print_data_preorder(); // preorder 순서로 모든 node의 값 출력
    void print_data_postorder(); // postorder 순서로 모든 node의 값 출력
};

// 일반함수 선언
int node_insert_left(node* p, string tname, node t);  // p가리키는 node의 name이 pname이면, node t의 값을 복사하여 left에 생성
int node_insert_right(node* p, string tname, node t); // p가리키는 node의 name이 pname이면, node t의 값을 복사하여 right에 생성
double sum_allnodes(node* p); // p를 root로 하는 tree의 합산값 return
void inorder_print(node* p);
void preorder_print(node* p);
void postorder_print(node* p);

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

    cout<< "Score Sum : " << thetree.score_sum() << "\n";
    cout<< "Score Average : " << thetree.score_average() << "\n";
    cout <<"\nInorder Traversal Result \n";
    thetree.print_data_inorder();
    cout << "\nPreorder Traversal Result \n";
    thetree.print_data_preorder();
    cout << "\nPostorder Traversal Result \n";
    thetree.print_data_postorder();
    return 0;
}

// class node member 함수정의
void node::set_data(string s, double n)
{
    name = s;  // 이름저장
    score = n; // 점수저장
}

// class my_tree member 함수정의
my_tree::my_tree()
{
    node_count = 0;
    root = NULL;
}

int my_tree::insert_root(node t)
{
    if(root != NULL) return 0; // tree의 node가 NULL이 아닌 경우
    
    node* p = new node; // node 공간생성
    (*p) = t;           // 주어진 node 내용 copy
    p->left = NULL;
    p->right = NULL;
    root = p; // root node 설정
    node_count++; // 저장성공시 node_count의 값을 1증가
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
    if(result == 1) node_count++; // 저장성공 시 node_count의 값을 1증가
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


// 일반함수 정의
/*
   반환값의 의미
   1. 1 : insert 과정의 성공
   2. 0 : tname을 가지는 node가 없음
   3. -1 : tname을 가지는 node는 있으나 추가하려는 방향(Left or right)이 NULL이 아닌 경우
 */
int node_insert_left(node* p, string tname, node t)
{
    if(p == NULL) return 0; // 조회할 노드가 존재하지 않는 경우
    if(p->name == tname) // p의 name이 tname인 경우
    {
        if(p->left != NULL) return -1; // 예외처리, 이미 left에 저장된 값이 있는 경우
        node* np = new node; // node 공간 생성
        (*np) = t; // 주어진 node 내용 copy
        np->left = NULL;  // Left를 NULL로 초기화
        np->right = NULL; // Right를 NULL로 초기화
        p->left = np; // p의 left에 연결
        return 1; // insert 과정의 성공
    }
    else // p의 name이 t_name이 아닌경우
    {
        int result = node_insert_left(p->left, tname, t); // left subtree에 대하여 동일한 작업을 수행(재귀)
        if(result != 0) return result; // 그 후에 반환된 값이 0이 아니면 해당값을 반환(어떤 쪽으로든 값을 찾고 결론을 낸 것이므로)
        return node_insert_left(p->right, tname, t); // right subtree에 대하여 동일한 작업을 수행(재귀), 그후 해당값을 반환
    }
}

int node_insert_right(node* p, string tname, node t)
{
    if(p == NULL) return 0; // 조회할 노드가 존재하지 않는 경우
    if(p->name == tname) // p의 name이 tname인 경우
    {
        if(p->right != NULL) return -1; // 예외처리, 이미 right에 저장된 node가 존재하는 경우
        node* np = new node; // node 공간 생성
        (*np) = t; // 주어진 node 내용 copy
        np->left = NULL;  // left를 NULL로 초기화
        np->right = NULL; // right를 NULL로 초기화
        p->right = np; // root의 right에 연결
        return 1; // insert 과정의 성공
    }
    else // p의 name이 t_name이 아닌경우
    {
        int result = node_insert_right(p->left, tname, t); // left subtree에 동일한 작업을 시도(재귀)
        if(result != 0) return result; // 그 후에 반환된 값이 0이 외의 값이면 반환(어떤 쪽으로든 값을 찾고 결론을 낸 것이므로)
        return node_insert_right(p->right, tname, t); // right subtree에 동일한 작업을 시도(재귀), 그 결과값을 반환
    }
}

double sum_allnodes(node* p)
{
    if(p == NULL) return 0; // 값을 조회할 노드가 더 이상 없을 경우 0을 반환
    // 노드 p 기준 좌측, 우측 subtree의 합과 자기자신의 값을 합하여서 합산값을 도출(재귀)
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

void inorder_print(node* p)
{
    if(p == NULL) return; // root값이 NULL인 경우
    
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
