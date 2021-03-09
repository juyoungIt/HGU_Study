// PA19
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

// 일반함수 선언
void show_thelist(s_record a[], int n);
void insertion_sort(s_record a[], int n); // 삽입정렬
void bubble_sort(s_record a[], int n);    // 버블정렬
void selection_sort(s_record a[], int n); // 선택정렬

int main()
{
    s_record s_list[12] =
    { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
    { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
    { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
    { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
    int n = 12;

    insertion_sort(s_list, n);
    //bubble_sort(s_list, n);
    //selection_sort(s_list, n);

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

void insertion_sort(s_record a[], int n)
{
    s_record temp; // s_record 변수 임시저장
    int i, j; // 반복문 변수

    for(i=1 ; i<n ; i++){ // 정렬대상원소(현위치)를 가리키는 반복문
        temp = a[i]; // 정렬대상 원소 복사
        for(j=i-1 ; j>=0 ; j--){ // 현위치보다 앞쪽에서
            if(a[j].s_id > temp.s_id) // 자신보다 큰 값인 경우
               a[j+1] = a[j]; // 뒤로 이동
            else
                break; // 배열의 처음에 도달하거나 더 이상 자신보다 큰 값이 없을 경우
        }
        a[j+1] = temp; // 복사했던 원소를 삽입
    }
}

void bubble_sort(s_record a[], int n)
{
    s_record temp; // s_record 변수 임시저장
    int i, j; // 반복문 변수

    for(i=n-1 ; i>0 ; i--){ // 정렬대상 범위를 조정하는 반복문(범위를 1씩 줄여나감)
        for(j=0 ; j<i ; j++){ // 대상범위 내에서 비교연산 수행
            if(a[j].s_id > a[j+1].s_id){ // 인접한 두 원소, 앞의 요소의 key값이 더 큰 경우
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp; // 인접한 두 원소의 위치 교환
            }
        }
    }
}

void selection_sort(s_record a[], int n)
{
    // 대상범위 내에서의 최소 Key값을 가지는 원소를 이용하여 정렬하는 경우
    s_record temp; // s_record 변수를 임시저장
    int i, j; // 반복문 변수
    int min; // 해당범위에서 최소 key값을 가지는 원소의 index값
    
    for(i=0 ; i<n ; i++){ // 최소값의 탐색범위를 조정(범위를 1씩 줄여감)
        min=i; // 비교연산을 위하여 해당범위의 첫 index로 초기화
        for(j=i+1 ; j<n ; j++){ // 대상범위에서 비교연산 수행
            if(a[min].s_id > a[j].s_id) // 현재의 key보다 더 작은 key값을 가진 원소가 있는 경우
                min = j; // 최소 key값을 가지고 있는 index값 변경
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp; // 대상범위내에서의 최소 key값을 가지는 원소와 첫원소의 위치를 교환
    }
/*
    // 대상범위 내에서의 최대 key값을 가지는 원소를 이용하여 정렬하는 경우
     s_record temp; // s_record 변수를 임시저장
     int i, j; // 반복문 변수
     int max; // 해당범위에서 최대 key값을 가지는 원소의 index값 저장

     for(i=n-1 ; i>=0 ; i--){ // 최대값의 탐색범위를 조정(탐색범위를 1씩 줄여감)
         max = 0; // 비교연산을 위하여 해당범위의 첫 index로 초기화
         for(j=0 ; j<i+1 ; j++){ // 대상범위에서 비교연산 수행
             if(a[max].s_id < a[j].s_id) // 현재의 key보다 더 큰 key값을 가진 원소가 있는 경우
                 max = j; // 최대 key값을 가지고 있는 index값 변경
         }
         temp = a[i];
         a[i] = a[max];
         a[max] = temp; // 대상범위내에서의 최대 key값을 가지는 원소와 첫원소의 위치를 교환
     }
 */
}
