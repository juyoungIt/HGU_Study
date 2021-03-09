// PA16
// 작성자 : 21700760 하주영

#include <iostream>
using namespace std;

#define SIZE 100

class element
{
public:
    string name;
    double score;
    void set_data(string s, double d);
};

class my_heap
{
private:
    element h[SIZE];
    int csize; // 저장된 element 수
    void adjust(int t_root); // 임의 순서의 array를 heap으로 구성
public:
    my_heap();
    my_heap(element a[], int n);
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    
    double score_sum(); // 점수의 합
    double score_average(); // 점수의 평균
    int node_delete_by_name(string tname); // 입력한 이름의 정보를 삭제
};

// 일반함수 선언
double summation(element a[], int troot, int n);
int delete_node(element a[], int troot, string tname, int n);
void heap_adjust(element a[], int troot, int size);

int main()
{
    element temp;
    element a[10] = {{"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85}};
    my_heap h1(a, 6);
    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;
    h1.node_delete_by_name("Kim");
    cout << "\n-- After the deletion operation. --\n\n";
    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;
    while (h1.h_size() > 0) {
         temp = h1.delete_heap();
         cout << temp.name << " : " << temp.score << "\n";
    }
    return 0;
}

void element::set_data(string s, double d)
{
    name = s;
    score = d;
}

my_heap::my_heap()
{
    csize = 0;
}

my_heap::my_heap(element a[], int n)
{
    for(int i=0 ; i<n ; i++)
        h[i+1] = a[i]; // 입력받은 배열의 내용을 차례로 하나씩 가져옴
    csize = n; // heap의 size를 n으로 설정
    
    int index = csize/2; // 마지막 internal node를 가리키도록
    while(index != 0){
        adjust(index); // 입력한 index의 node를 root로 하는 tree를 정렬
        index--; // 역순으로 root에 도달할때 까지
    }
}

int my_heap::h_size()
{
    return csize;
}

bool my_heap::heap_full()
{
    if(csize >= SIZE-1) return true;
    else return false;
}

bool my_heap::heap_empty()
{
    if(csize == 0) return true;
    else return false;
}

void my_heap::insert_heap(element t)
{
    int k; // 탐색하는 인덱스 값
    csize++; // size를 1 증가시킴
    k = csize;
    
    while((k != 1) && (t.score > h[k/2].score)) // root가 아니면서 parent 보다 key값이 클 경우, 다음을 반복한다.
    {
        h[k] = h[k/2]; // parent의 원소를 현 위치로 이동시킨다.
        k /= 2; // 현위치를 parent로 조정
    }
    h[k] = t; // 찾은 위치에 주어진 값을 넣는다.
}

element my_heap::delete_heap()
{
    element root; // root
    element last; // 마지막 원소
    int parent, child; // parent와 child의 인덱스값
    
    root = h[1];
    last = h[csize];
    csize--; // size를 1감소
    parent = 1; // root
    child = 2;
    
    while(child <= csize) // 데이터가 저장된 범위내에서 다음을 반복한다.
    {
        if((child < csize) && (h[child].score < h[child+1].score)) // right가 존재하고 right가 더 크다면?
            child++; // right를 선택
        if(last.score >= h[child].score)
            break; // child가 더 작다면 현재 위치로 결정
        h[parent] = h[child]; // child가 더 크다면, parent로 위치조정
        parent = child; // 한단계 아래로 - 1
        child *= 2; // 한단계 아래로 - 2
    }
    h[parent] = last; // 찾은 위치에 원소를 저장
    return root;
}

void my_heap::adjust(int t_root)
{
    double t_key; // key값
    int child; // child의 인덱스 값
    element temp; // 노드 저장
    
    temp = h[t_root]; // root를 저장
    t_key = h[t_root].score; // root의 key값 저장
    child = t_root * 2; // left를 child로 선택
    // 데이터가 저장된 유효한 범위내에서 다음을 반복한다.
    while(child <= csize)
    {
        if((child < csize) && (h[child].score < h[child+1].score)) // right child가 존재 & right의 key값이 더 클때
            child++; // rigt를 선택
        if(t_key > h[child].score) // 해당원소의 key값과 비교하여 child가 작으면 현위치(Parent)의 위치로 결정
            break;
        else{ // child가 크면, 해당 child 원소값을 parent로 이동시키고, 위치를 child로 이동
            h[child/2] = h[child];
            child *= 2;
        }
    }
    h[child/2] = temp; // 찾은 위치에 해당원소의 값을 넣는다.
}

double my_heap::score_sum()
{
    return summation(h, 1, csize);
}

double my_heap:: score_average()
{
    if(csize == 0) return 0;
    return score_sum() / csize;
}

int my_heap::node_delete_by_name(string name)
{
    if(csize == 0) return 0; // 힙에 저장된 데이터가 없는 경우
    if(delete_node(h, 1, name, csize) == 1)
    {
        csize--;
        return 1; // 삭제성공 시
    }
    else
        return 0; // 삭제 실패 시
}

// 일반함수 정의
double summation(element a[], int troot, int size)
{
    if(troot > size) return 0; // 주어진 root가 empty면 0을 return
    return (a[troot].score + summation(a, troot*2, size) + summation(a, troot*2+1, size));
}

int delete_node(element a[], int troot, string t_name, int size)
{
    element temp;
    if(troot > size) return 0; // 주어진 root가 empty면(troot가 size보다 크면)
    if(a[troot].name == t_name) // root가 찾는 노드인 경우
    {
        a[troot] = a[size]; // root와 끝원소를 서로 교환
        heap_adjust(a, troot, size-1); // root 이하 subtree를 adjust
        return 1; // 삭제 성공 시 1을 반환
    }
    else // root가 찾는 원소가 아닐경우
    {
        if(delete_node(a, troot*2, t_name, size) == 1) return 1; // left subtree에서 동일작업 수행
        if(delete_node(a, troot*2+1, t_name, size) == 1) return 1; // right subtree에서 동일작업 수행
    }
    return 0; // 탐색하고자 하는 node를 찾지 못한 경우 0을 return
}

void heap_adjust(element a[], int troot, int size)
{
    double t_key; // key값
    int child; // child의 인덱스 값
    element temp; // 노드 저장
    
    temp = a[troot]; // root를 저장
    t_key = a[troot].score; // root의 key값 저장
    child = troot * 2; // left를 child로 선택
    // 데이터가 저장된 유효한 범위내에서 다음을 반복한다.
    while(child <= size)
    {
        if((child < size) && (a[child].score < a[child+1].score)) // right child가 존재 & right의 key값이 더 클때
            child++; // rigt를 선택
        if(t_key > a[child].score) // 해당원소의 key값과 비교하여 child가 작으면 현위치(Parent)의 위치로 결정
            break;
        else{ // child가 크면, 해당 child 원소값을 parent로 이동시키고, 위치를 child로 이동
            a[child/2] = a[child];
            child *= 2;
        }
    }
    a[child/2] = temp; // 찾은 위치에 해당원소의 값을 넣는다.
}
