// PA18
// 작성자 : 21700760 하주영

#include <iostream>
#include <stdlib.h>
using namespace std;

// 코드의 가독성을 높이기 위한 부분
#define INSERT 1
#define SEARCH 2
#define DELETE 3
#define SHOW_INORDER 4
#define QUIT 5

// 이진탐색트리를 구성하는 노드
class bst_node
{
public:
    string s_id;  // 학번
    string name;  // 성명
    string phone; // 연락처
    int major;    // 전공코드
    string birth; // 생일
    double score; // 점수
    
    bst_node *left, *right; // 좌우 링크
    bst_node(); // 유효하지 않은 값들로 초기화
    bst_node(string id, string na, string ph, int ma, string bi, double sc); // 해당값 초기화
    void set_data(string id, string na, string ph, int ma, string bi, double sc); // 노드값 변경
};

// 이진탐색트리
class bst_tree
{
public:
    bst_node* root; // root 노드
    int csize; // 저장된 노드의 수
    bst_tree(); // constructor, root, csize 값을 초기화
    void insert_node(bst_node t); // 노드를 추가
    bst_node search(string id); // 주어진 id값으로 노드를 탐색
    bst_node n_delete(string id); // 주어진 id 값으로 노드를 삭제
    void show_inorder(); // key값으로 정렬된 순서로 출력
};

// 일반함수 선언부
int get_cmd(); // 사용자에게 사용옵션에 대한 정보 입력받음
void show_majorList(); // 전공코드의 리스트를 출력해서 보여줌
void add_record(bst_tree *bst); // 사용자에게 정보를 입력받아 tree에 노드를 추가
void search_record(bst_tree bst); // 저장된 정보를 key값(학번)을 이용하여 검색
void delete_record(bst_tree *bst); // 저장된 정보를 key값(학번)을 이용하여 삭제
void inorder_print(bst_node *p); // 저장된 정보를 inorder-traversal

int main()
{
    bst_tree bst; // 이진탐색트리 생성
    bst_node te;
    int option; // 사용자가 선택한 옵션값 저장
    
    do
    {
        option = get_cmd();
        switch(option)
        {
            case INSERT:
                add_record(&bst);
                break;
            case SEARCH:
                search_record(bst);
                break;
            case DELETE:
                delete_record(&bst);
                break;
            case SHOW_INORDER:
                bst.show_inorder();
                break;
            case QUIT:
                break;
            default:
                cout << "Error! : Invalide command option" << endl;
        }
    }while(option != 5);
    
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------------
// class bst_node member 함수 정의
bst_node::bst_node()
{
    s_id = "00000000"; // 학번
    name = "None"; // 성명
    phone = "None"; // 연락처
    major = -1; // 전공코드
    birth = "None"; // 생일
    score = -1; // 점수
}

bst_node::bst_node(string id, string na, string ph, int ma, string bi, double sc)
{
    s_id = id; // 학번
    name = na; // 성명
    phone = ph; // 연락처
    major = ma; // 전공코드
    birth = bi; // 생일
    score = sc; // 점수
}

void bst_node::set_data(string id, string na, string ph, int ma, string bi, double sc)
{
    s_id = id; // 학번
    name = na; // 성명
    phone = ph; // 연락처
    major = ma; // 전공코드
    birth = bi; // 생일
    score = sc; // 점수
}
// ----------------------------------------------------------------------------------------------------------------------------

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
        
        // 추가하려는 노드의 key값이 현재 탐색중인 노드의 key값보다 작은 경우
        if(p->s_id > temp->s_id){
            // 이동할 left subtree가 empty인 경우
            if(p->left == NULL){
                p->left = temp; // 노드추가
                csize++;
                return;
            }
            // 이동할 left subtree가 empty가 아닌 경우
            else
                p = p->left; // 탐색위치 이동
        }
        // 추가하려는 노드의 key값이 현재 탐색중인 노드의 key값보다 큰 경우
        else{
            // 이동할 right subtree가 empty인 경우
            if(p->right == NULL){
                p->right = temp; // 노드추가
                csize++;
                return;
            }
            // 이동할 right subtree가 empty가 아닌 경우
            else
                p = p->right; // 탐색위치 이동
        }
    }
}

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
        temp.set_data("00000000", "None", "None", -1, "None", -1);
        cout << "Error! : The tree is empty" << endl;
        cout << "The key " << id << " does not exist." << endl;
        return temp;
    }
    
    p = root; // root부터 탐색시작
    while(1)
    {
        // 현재탐색하는 노드가 일치하는 key값을 가진 경우
        if(p->s_id == id){
            return *p;
        }
        // 입력받은 key값이 현재 탐색하는 노드의 key값보다 작은 경우
        if(p->s_id > id){
            // 더 이상 탐색할 노드가 존재하지 않는 경우
            if(p->left == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", "None", -1, "None", -1);
                cout << "The key " << id << " does not exist." << endl;
                return temp;
            }
            else
                p = p->left; // 탐색위치 이동
        }
        // 입력받은 key값이 현재 탐색하는 노드의 key값 보다 큰 경우
        else{
            // 더 이상 탐색한 노드가 존재하지 않는 경우
            if(p->right == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", "None", -1, "None", -1);
                cout << "The key " << id << " does not exist." << endl;
                return temp;
            }
            else
                p = p->right; // 탐색위치 이동
        }
    }
}

bst_node bst_tree::n_delete(string id)
{
    bst_node temp; // 삭제하는 노드의 정보를 저장
    bst_node* cur; // 탐색하는 노드의 위치를 저장
    bst_node* prev; // 탐색하는 노드의 이전노드의 주소값을 저장
    
    // tree가 empty인 상태에서 delete를 수행해야하는 경우
    if(root == NULL){
        temp.set_data("00000000", "None", "None", -1, "None", -1);
        cout << "Error! : The tree is empty" << endl;
        cout << "The key " << id << " does not exist." << endl;
        return temp;
    }
    
    cur = root; // root 부터 시작
    prev = NULL;
    while(1)
    {
        // 현재탐색하는 노드가 일치하는 key값을 가진 경우
        if(cur->s_id == id){
            temp = *cur; // 삭제할 노드의 값을 복사
            // 해당노드가 degree가 0
            if(cur->left == NULL && cur->right == NULL){
                if(cur == root){
                    root = NULL;
                    delete cur; // 삭제
                    cout << "Success! : Delete was complete." << endl;
                    return temp;
                }
                if(prev->s_id > cur->s_id)
                    prev->left = NULL;
                else
                    prev->right = NULL;
                delete cur; // 삭제
                cout << "Success! : Delete was complete." << endl;
                return temp;
                
            }
            // 해당노드가 degree가 1
            else if(cur->left == NULL || cur->right == NULL){
                if(cur->left != NULL){
                    if(prev->s_id > cur->s_id){
                        prev->left = cur->left; // parent와 child를 연결
                        delete cur; // 삭제
                        cout << "Success! : Delete was complete." << endl;
                        return temp;
                    }
                    else{
                        prev->left = cur->right; // parent와 child를 연결
                        delete cur; // 삭제
                        cout << "Success! : Delete was complete." << endl;
                        return temp;
                    }
                }
                else{
                    if(prev->s_id > cur->s_id){
                        prev->left = cur->right; // parent와 child를 연결
                        delete cur; // 삭제
                        cout << "Success! : Delete was complete." << endl;
                        return temp;
                    }
                    else{
                        prev->right = cur->right; // parent와 child를 연결
                        delete cur; // 삭제
                        cout << "Success! : Delete was complete." << endl;
                        return temp;
                    }
                }
            }
            // 해당노드가 degree가 2
            else{
                int op; // 정렬 옵션에 대한 값
                bst_node *p1; // 탐색하는 노드의 주소값을 저장 - 1
                bst_node *p2; // 탐색하는 노드의 주소값을 저장 - 2
                cout << "You need to choose the one options between 1 and 2" << endl;
                cout << "-------------------------------------" << endl;
                cout << "1. left-subtree's largest node" << endl;
                cout << "2. right-subtree's smallest node" << endl;
                cout << "-------------------------------------" << endl;
                cout << "Enter the option code : ";
                cin >> op; // 옵션값 저장
                
                p1 = cur; // 동일한 key값을 가진 노드부터 시작
                p2 = cur;
                // left-subtree의 가장 큰 값을 이용하여 정렬
                if(op == 1){
                    p1 = p1->left;
                   while(p1->right != NULL){
                       p2 = p1; // 현재 탐색 중인 노드의 위치를 저장
                       p1 = p1->right; // p1의 위치 변경
                   }
                    cur->set_data(p1->s_id, p1->name, p1->phone, p1->major, p1->birth, p1->score); // 값을 복사
                    
                    if(p1->left != NULL)
                        p2->left = p1->left;
                    else
                        p2->left = NULL;
                    delete p1; // 삭제
                    cout << "Success! : Delete was complete." << endl;
                    return temp;
                }
                // right-subtree의 가장 작은 값을 이용하여 정렬
                else if(op == 2){
                    p1 = p1->right;
                    while(p1->left != NULL){
                        p2 = p1; // 현재 탐색 중인 노드의 위치를 저장
                        p1 = p1->left; // p1의 위치 변경
                    }
                     cur->set_data(p1->s_id, p1->name, p1->phone, p1->major, p1->birth, p1->score); // 값을 복사
                     
                     if(p1->right != NULL)
                         p2->right = p1->right;
                     else
                         p2->right = NULL;
                     delete p1; // 삭제
                     cout << "Success! : Delete was complete." << endl;
                     return temp;
                }
                else{
                    cout << "Error! : Invalid option code" << endl;
                    exit(-1); // 오류를 의미하는 -1을 반환하며 강제종료
                }
            }
        }
        // 해당 key값을 가진 노드를 탐색하기 위한 부분
        // 입력받은 key값이 현재 탐색하는 노드의 key값보다 작은 경우
        else if(cur->s_id > id){
            // 더 이상 탐색할 노드가 존재하지 않는 경우
            if(cur->left == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", "None", -1, "None", -1);
                cout << "The key " << id << " does not exist." << endl;
                return temp;
            }
            else{
                prev = cur; // 현재 탐색중인 위치를 저장
                cur = cur->left; // 탐색위치 이동
            }
                
        }
        // 입력받은 key값이 현재 탐색하는 노드의 key값 보다 큰 경우
        else{
            // 더 이상 탐색한 노드가 존재하지 않는 경우
            if(cur->right == NULL){
                bst_node temp;
                temp.set_data("00000000", "None", "None", -1, "None", -1);
                cout << "The key " << id << " does not exist." << endl;
                return temp;
            }
            else{
                prev = cur; // 현재 탐색중인 위치를 저장
                cur = cur->right; // 탐색위치 이동
            }
        }
    }
}
// ----------------------------------------------------------------------------------------------------------------------------

// 일반함수 정의부

int get_cmd()
{
    int op_code; // 사용자 입력 옵션코드값 저장
    cout << "*******************************" << endl;
    cout << "   <Available Option List>" << endl;
    cout << "--------------------------------" << endl;
    cout << "| op_code |      function      |" << endl;
    cout << "|    1    |   insert element   |" << endl;
    cout << "|    2    |   search element   |" << endl;
    cout << "|    3    |   delete element   |" << endl;
    cout << "|    4    |    show inorder    |" << endl;
    cout << "|    5    |        Quit        |" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter the option code : ";
    cin >> op_code;
    cout << "*******************************" << endl;
    return op_code; // 입력받은 코드값을 반환
}

void show_majorList()
{
    cout << "*****************************************" << endl;
    cout << "         <Major List>" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|              major             | code |" << endl;
    cout << "|    Global Leadership School    |  01  |" << endl;
    cout << "|     International Studies      |  02  |" << endl;
    cout << "|     Management & Econmics      |  03  |" << endl;
    cout << "|         School of Law          |  04  |" << endl;
    cout << "|  School of Communication Arts  |  05  |" << endl;
    cout << "|   Spatial Environment System   |  06  |" << endl;
    cout << "|      Mechanical & Control      |  07  |" << endl;
    cout << "|   Contents Convergence Design  |  08  |" << endl;
    cout << "|         Life Sciences          |  09  |" << endl;
    cout << "| Computer Science & Electrical  |  10  |" << endl;
    cout << "|     Counselling Psychology     |  11  |" << endl;
    cout << "| Global Entrepreneurship and ICT|  12  |" << endl;
    cout << "-----------------------------------------" << endl;
}

void add_record(bst_tree* tree)
{
    bst_node t; // 입력정보를 일시적으로 저장할 노드
    string t_id; // 학번
    string t_name; // 성명
    string t_phone; // 연락처
    int t_major; // 전공코드
    string t_birth; // 생일
    double t_score; // 점수
    
    // 데이터를 입력받는 파트
    cout << "Enter the student id : ";
    cin >> t_id;
    cout << "Enter the student name : ";
    cin >> t_name;
    cout << "Enter the student phone number : ";
    cin >> t_phone;
    show_majorList(); // 전공리스트 출력
    cout << "Enter the major code : ";
    cin >> t_major;
    cout << "Enter the birth date(ex. 1998/07/29 -> 19980729) : ";
    cin >> t_birth;
    cout << "Enter the score : ";
    cin >> t_score;
    
    // 노드생성 및 추가
    t.set_data(t_id, t_name, t_phone, t_major, t_birth, t_score); // 노드에 값 저장
    tree->insert_node(t); // 노드 추가
}

void search_record(bst_tree bst)
{
    bst_node t; // 검색한 노드의 값을 저장
    string t_id; // 일시적으로 학번값을 저장
    cout << "Enter the student id : ";
    cin >> t_id;
    t = bst.search(t_id); // 검색결과를 저장
    // 검색한 key값을 갖는 노드를 찾지 못한 경우
    if(t.s_id == "00000000")
        return; // 함수를 종료
    
    cout << "*******************************" << endl;
    cout << "  <" << t_id << "'s informations>" << endl;
    cout << "-------------------------------" << endl;
    cout << "   ID  : " << t.s_id << endl;
    cout << "  name : " << t.name << endl;
    cout << " phone : " << t.phone << endl;
    cout << " major : " << t.major << endl;
    cout << " birth : " << t.birth << endl;
    cout << " score : " << t.score << endl;
}

void delete_record(bst_tree *bst)
{
    string tid; // 사용자가 입력하는 학번값 일시저장
    
    cout << "Enter the student ID : ";
    cin >> tid;
    bst->n_delete(tid); // 삭제
}

void inorder_print(bst_node *p)
{
    if(p == NULL) return;
    
    inorder_print(p->left); // recursive, left-subtree에 대하여
    cout << p->s_id << " : ";
    cout << p->name << " : ";
    cout << p->phone << " : ";
    cout << p->major << " : ";
    cout << p->birth << " : ";
    cout << p->score << endl;
    inorder_print(p->right); // recursive, right-subtree에 대하여
    return;
}
