// PA17
// 작성자 : 21700760 하주영

#include <iostream>
using namespace std;

// 이진탐색트리를 구성하는 노드
class bst_node
{
public:
    string s_id; // 학번
    string name; // 성명
    double score; // 점수
    bst_node *left, *right; // 좌우 링크
    bst_node(); // constructor, 학번, 성명, 점수값 초기화 - 1
    bst_node(string s1, string s2, double n); // constructor, 학번, 성명, 점수값 초기화 - 2
    void set_data(string s1, string s2, double n); // 노드의 값을 변경
};

// 이진탐색트리
class bst_tree
{
    bst_node* root; // root 노드
    int csize; // 저장된 노드의 수
public:
    bst_tree(); // constructor, root, csize 값을 초기화
    void insert_node(bst_node t); // 노드를 추가
    void show_inorder(); // key값으로 정렬된 순서로 출력
    bst_node search(string id); // 주어진 id값으로 node를 탐색
};

// 일반함수 선언부
void inorder_print(bst_node *p); // 입력받은 주소값의 노드를 root로 한 tree에 대한 inorder traversal

int main()
{
    bst_node temp;
    bst_tree t1;
    temp.set_data("21900013", "Kim", 6.5);
    t1.insert_node(temp);
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);
    cout << "\n\n Node List : inorder sequence \n";
    t1.show_inorder();
    string s_key = "21800442";
    temp = t1.search(s_key);
    cout << "\n -- " << s_key << "\'s record ---" << endl;
    cout << " Student ID   : "<< temp.s_id << endl;
    cout << " Student Name : "<< temp.name << endl;
    cout << " Score  : " << temp.score << endl;
    return 0;
}

// class bst_node member 함수 정의
bst_node::bst_node()
{
    s_id = "00000000"; // 학번
    name = "Unknown data"; // 성명
    score = 0.0; // 점수
}

bst_node::bst_node(string s1, string s2, double n)
{
    s_id = s1; // 학번
    name = s2; // 성명
    score = n; // 점수
}

void bst_node::set_data(string s1, string s2, double n)
{
    s_id = s1; // 학번
    name = s2; // 성명
    score = n; // 점수
}

// class bst_tree member 함수정의
bst_tree::bst_tree()
{
    root = NULL; // root 노드
    csize = 0; // 저장노드 수
}

// 노드 추가연산
void bst_tree::insert_node(bst_node t)
{
    bst_node* temp; // 생성한 노드의 주소값
    bst_node* p; // tree에서 탐색하는 노드의 주소값
    
    // 추가할 노드 미리생성
    temp = new bst_node; // node 생성
    *(temp) = t; // 값을 복사
    // 좌우 link를 NULL로 초기화
    temp->left = NULL;
    temp->right = NULL;
    
    // tree가 empty 상태인 경우 - 생성한 노드를 root에 추가
    if(root == NULL){
        root = temp;
        return;
    }
    
    p = root; // root 부터 탐색
    while(1)
    {
        // 중복되는 key값을 가진 노드를 추가할 경우
        if(p->s_id == temp->s_id){
            cout << "Error! : Duplicated key value(" << temp->s_id << ")" << endl;
            return; // 종료
        }
        
        // 추가하려는 노드의 key값이 현재 탐색중인 노드의 key값보다 작은 경우 -> left subtree로 이동
        if(p->s_id > temp->s_id){
            // 이동할 left subtree가 empty인 경우
            if(p->left == NULL){
                p->left = temp; // 노드추가
                return;
            }
            // 이동할 left subtree가 empty가 아닌 경우
            else
                p = p->left; // 탐색위치 이동
        }
        // 추가하려는 노드의 key값이 현재 탐색중인 노드의 key값보다 큰 경우 -> right subtree로 이동
        else{
            // 이동할 right subtree가 empty인 경우
            if(p->right == NULL){
                p->right = temp; // 노드추가
                return;
            }
            // 이동할 right subtree가 empty가 아닌 경우
            else
                p = p->right; // 탐색위치 이동
        }
    }
}

// 저장된 노드값을 순서대로 출력
void bst_tree::show_inorder()
{
    inorder_print(root);
}

// 저장된 노드 key값으로 검색
bst_node bst_tree::search(string id)
{
    bst_node* p; // tree에서 탐색하는 노드의 주소값
    
    // tree에 저장된 노드가 없는 경우
    if(root == NULL){
        bst_node temp;
        temp.set_data("00000000", "None", -1);
        cout << "Error! : The tree is empty" << endl;
        cout << "The key " << id << " does not exist." << endl;
        return temp; // 탐색의 실패를 의미하는 값을 가진 node를 반환
    }
    
    p = root; // root부터 탐색시작
    while(1)
    {
        // 현재탐색하는 노드가 일치하는 key값을 가진 경우
        if(p->s_id == id){
            return *p;
        }
        // 입력받은 key값이 현재 탐색하는 노드의 key값보다 작은 경우 -> left subtree 로 이동
        if(p->s_id > id){
            // 더 이상 탐색한 노드가 존재하지 않는 경우
            if(p->left == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", -1);
                cout << "The key " << id << " does not exist." << endl;
                return temp; // 탐색의 실패를 의미하는 값을 가진 node를 반환
            }
            else
                p = p->left; // 탐색위치 이동 -> left subtree로 이동
        }
        // 입력받은 key값이 현재 탐색하는 노드의 key값 보다 큰 경우
        else{
            // 더 이상 탐색한 노드가 존재하지 않는 경우
            if(p->right == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", -1);
                cout << "The key " << id << " does not exist." << endl;
                return temp; // // 탐색의 실패를 의미하는 값을 가진 node를 반환
            }
            else
                p = p->right; // 탐색위치 이동
        }
    }
}

// 일반함수 정의부
void inorder_print(bst_node *p)
{
    if(p == NULL) return;
    
    inorder_print(p->left); // recursive, left-subtree에 대하여
    cout << p->s_id << " : ";
    cout << p->name << " : ";
    cout << p->score << endl;
    inorder_print(p->right); // recursive, right-subtree에 대하여
    return;
}
