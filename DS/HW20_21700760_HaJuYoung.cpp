// PA20
// 작성자 : 21700760 하주영

#include <iostream>
using namespace std;

// class s_record 정의
class s_record
{
public:
    string s_id; // 학번(Key)
    string name; // 성명
    double score; // 점수
    s_record(); // s_record의 값 초기화
    s_record(string s1, string s2, double n); // 전달받은 값으로 s_record의 값 초기화
};

// 일반함수 정의
void show_thelist(s_record a[], int n);             // 정렬결과 출력
void quick_sort(s_record a[], int left, int right); // 퀵정렬
void swap(s_record &s1, s_record &s2);              // 입력된 두 원소 자리교환
void heap_sort(s_record a[], int n);                // 힙정렬
void adjust(s_record a[], int root, int size);      // 힙이 되도록 다시 재정렬
void merge_sort(s_record a[], int n);               // 병합정렬
void merge_pass(s_record a[], s_record b[], int n, int s); // sublist 2개씩 merge -> 새로운 리스트 생성
void merge(s_record a[] , s_record b[], int n1, int n2, int n3, int n4); // 주어진 2개의 sublist를 merge

int main()
{
    s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                            { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
                            { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
                            { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 }};
    int n = 12;
    s_record s_list2[12];
    quick_sort(s_list, 0, n-1);
    //heap_sort(s_list, n);
    //merge_sort(s_list, n);
    
    cout << "< The result of the sorting >" << endl;
    show_thelist(s_list, n);
    
    return 0;
}

// class s_record의 member 함수 정의
s_record::s_record()
{
    s_id = "None s_id data"; // 학번 초기화
    name = "None name data"; // 이름 초기화
    score = -1; // 점수 초기화(저장된 값이 없음을 의미하는 음수로 초기화)
}

s_record::s_record(string s1, string s2, double n)
{
    s_id = s1; // 학번을 s1으로 초기화
    name = s2; // 이름을 s2로 초기화
    score = n; // 점수를 n으로 초기화
}

// 일반함수 정의
void show_thelist(s_record a[], int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout << a[i].s_id << " : ";
        cout << a[i].name << " : ";
        cout << a[i].score << endl;
    }
}

void quick_sort(s_record a[], int left, int right)
{
    s_record pivot; // 기준원소(해당범위의 첫번째 원소)
    int i, j; // 반복문 변수
    
    if(left >= right) return; // 대상범위 원소 수 1이하
    
    i = left+1;      // pivot보다 큰 key를 가진 원소 탐색
    j = right;       // pivot보다 작은 key를 가진 원소 탐색
    pivot = a[left]; // pivot = 대상범위 첫 원소
    
    while(1)
    {
        // pivot보다 큰 key를 가진 원소 탐색
        while(i<=right){
            if(a[i].s_id > pivot.s_id) break;
            else i++;
        }
        
        // pivot보다 작은 key를 가진 원소 탐색
        while(j>left){ // left는 pivot이므로 j의 탐색 범위에서 제외
            if(a[j].s_id < pivot.s_id) break;
            else j--;
        }
            
        if(i < j) // i, j 교차X
            swap(a[i], a[j]); // i, j위치 원소 교환
        if(i > j) // i, j 교차
            break;
    }
    swap(a[left], a[j]); // pivot, j번째 원소 위치교환 - partitioning 종료
    quick_sort(a, left, j-1); // piovt 기준 왼쪽 list에 대한 quick sort(recursion)
    quick_sort(a, j+1, right); // pivot 기준 오른쪽 list에 대하 quick sort(recursion)
}

void swap(s_record &ae1, s_record &ae2)
{
    s_record temp; // 임시저장
    temp = ae2;
    ae2 = ae1;
    ae1 = temp; // 입력받은 두 배열의 원소를 서로 교환
}

void heap_sort(s_record a[], int n)
{
/*
    // 1. 1부터 저장된 배열을 이용한 heap 사용
    s_record b[n+1]; // 1부터 저장된 재구성된 heap
    s_record temp; // 값의 교환을 위한 임시저장 변수
    int i; // 반복문 변수
    
    // 원소를 한칸씩 뒤로 당긴 배열생성
    for(i=0 ; i<n ; i++){
        b[i+1] = a[i];
    }
    
    // 입력으로 들어온 배열을 heap으로 재구성
    for(i=n/2 ; i>0 ; i--){
        adjust(b, i, n);
    }
    
    // sorting 수행
    for(i=0 ; i<n-1 ; i++){
        temp = b[1];       // 해당범위의 첫원소 복사
        b[1] = b[n-i]; // 첫원소 <- 마지막 원소
        b[n-i] = temp; // 첫원소 -> 마지막 원소
        adjust(b, 1, n-i-1); // 범위를 1줄여서 reheaping
    }
    
    // 정렬된 배열 b의 값을 기존배열 a에 반영
    for(i=0 ; i<n ; i++){
        a[i] = b[i+1];
    }
*/
     // 2. 0부터 저장된 배열을 이용한 heap 사용
     s_record temp; // 값의 교환을 위한 임시저장 변수
     int i; // 반복문 변수
     
     // 입력으로 들어온 배열을 heap으로 재구성
     for(i=(n-1)/2 ; i>=0 ; i--){
         adjust(a, i, n-1);
     }
     
     // sorting 수행
     for(i=0 ; i<n-1 ; i++){
         temp = a[0];     // 해당범위의 첫원소 복사
         a[0] = a[n-(i+1)]; // 첫원소 <- 마지막 원소
         a[n-(i+1)] = temp; // 첫원소 -> 마지막 원소
         adjust(a, 0, n-(i+2)); // 범위를 1줄여서 reheaping
     }
}

void adjust(s_record a[], int root, int size)
{
/*
    // 1. 1부터 저장된 배열을 이용한 heap 사용
    string t_key;  // key값
    int child;     // child의 인덱스 값
    s_record temp; // 값의 변경을 위한 임시저장 변수
    
    temp = a[root];        // root 복사
    t_key = a[root].s_id;  // root의 key값 저장
    child = root * 2;      // left를 child로 선택
    
    // 유효한 범위내 다음 반복 - root 위치찾기
    while(child <= size)
    {
        // 더 큰 key를 가진 방향 선택(left or right)
        if((child < size) && (a[child].s_id < a[child+1].s_id)) // right child 존재 & right의 key값이 더 클 때
            child++; // rigt를 선택
        
        if(t_key > a[child].s_id) // root key값과 비교하여 child가 작으면 -> 위치결정
            break;
        else{ // child가 크면
            a[child/2] = a[child]; // 해당 child -> parent
            child *= 2; // 탐색위치 -> child(left)
        }
    }
    a[child/2] = temp; // 찾은 위치 -> 원소 넣기
*/
    
    // 2. 0부터 저장된 배열을 이용한 heap 사용
    string t_key;  // key값
    int child;     // child의 인덱스 값
    s_record temp; // 값의 변경을 위한 임시저장 변수
    
    temp = a[root];        // root 복사
    t_key = a[root].s_id;  // root의 key값 저장
    child = root*2+1;  // left를 child로 선택
    
    // 유효한 범위내 다음 반복 - root 위치찾기
    while(child <= size)
    {
        // 더 큰 key를 가진 방향 선택(left or right)
        if((child < size) && (a[child].s_id < a[child+1].s_id)) // right child 존재 & right의 key값이 더 클 때
            child++; // rigt를 선택
        
        if(t_key > a[child].s_id) // root key값과 비교하여 child가 작으면 -> 위치결정
            break;
        else{ // child가 크면
            a[(child-1)/2] = a[child]; // 해당 child -> parent
            child = child*2+1; // 탐색위치 -> child(left)
        }
    }
    a[(child-1)/2] = temp; // 찾은 위치 -> 원소 넣기
}

void merge_sort(s_record a[], int n)
{
    s_record b[n]; // merge_sort 결과저장 배열
    int s = 1; // sublist size -> 1부터 시작
    
    // size가 n이 될 때 까지 다음을 반복
    while(s < n){
        merge_pass(a, b, n-1, s);
        s *= 2; // sublist의 size를 2배증가
        merge_pass(b, a, n-1, s);
        s *= 2; // sublist의 size를 2배증가
    }
}

void merge_pass(s_record a[], s_record b[], int n, int s)
{
    int i, j; // 반복문 변수
    // 1. a의 첫 위치에서부터 길이 s의 sublist가 두 개 미만의 길이가 남을 때까지 두 개씩 merge하여 b를 생성
    for(i=0 ; i<=n-2*s ; i+=2*s){
        merge(a, b, i, i+s-1, i+s,i+2*s-1);
    }
    // 2-1. 남은 list의 길이가 s보다 크면 거나 같으면
    if(i+s <= n){
        merge(a, b, i, i+s-1, i+s, n); // 두 list를 merge
    }
    // 2-2. 남은 list의 길이가 s보다 작으면
    else{
        for(j=i ; j<=n ; j++){
            b[j] = a[j]; // -> 남은 내용을 그대로 copy
        }
    }
}

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4)
{
    int i, j, k, t; // index값 저장변수
    
    i = n1; // 배열a - 1의 시작인덱스
    j = n3; // 배열a - 2의 시작인덱스
    k = n1; // 배열 b의 시작인덱스
    
    // 두 sublist에서 참조 중인 index -> 각각의 크기보다 크지 않을 경우 -> 다음을 반복
    while(i<=n2 && j<=n4){
        if(a[i].s_id > a[j].s_id)
            b[k++] = a[j++];
        else
            b[k++] = a[i++];
    }
    
    // 배열 a의 sublist 중 한 리스트가 먼저 참조를 마친 경우
    if(i>n2 && j<=n4) // 앞의 sublist가 먼저 끝난 경우
        for(t=j ; t<=n4 ; t++)
            b[k++] = a[t];
    if(j>n4 && i<=n2) // 뒤의 sublist가 먼저 끝난 경우
        for(t=i ; t<=n2 ; t++)
            b[k++] = a[t];
}
