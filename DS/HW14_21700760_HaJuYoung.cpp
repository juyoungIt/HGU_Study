// PA14
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
    
public:
    my_heap();
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};

int main()
{
    my_heap   h1;

    element   temp;
    temp.set_data("Kim", 88);
    h1.insert_heap(temp);
    temp.set_data("Lee", 77);
    h1.insert_heap(temp);
    temp.set_data("Park", 98);
    h1.insert_heap(temp);
    temp.set_data("Choi", 74);
    h1.insert_heap(temp);
    temp.set_data("Ryu", 94);
    h1.insert_heap(temp);
    temp.set_data("Cho", 85);
    h1.insert_heap(temp);

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
