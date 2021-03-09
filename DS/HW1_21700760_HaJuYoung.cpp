#include <iostream>
using namespace std;

void my_sort(int list[], int num); // 정렬함수 선언

int main()
{
    int list[10] = {23,11,15,8,17,33,7,14,19,21};
    int i; // 반복문 변수

    my_sort(list, 10); // 배열 list의 원소 10개를 sort하는 함수
    for(i=0 ; i<10 ; i++)
        cout << list[i] << "\n";
    return 0;
}

// 정렬함수 정의
void my_sort(int list[], int num)
{
    int min_idx; // 최소 인덱스
    int temp; // 일시적으로 배열의 값 저장
    int i, j; // 반복문 변수

    for(i=0 ; i<num ; i++)
    {
        min_idx = i; // 최소값 인덱스 현재 인덱스로 초기화
        for(j=i+1 ; j<num ; j++) // 현재위치 기준 반복하며 범위내에서 가장 작은 값의 인덱스 찾기
            if(list[j]<list[min_idx])
                min_idx = j; // 범위 내 최소값 인덱스 저장

        // 찾은 범위내 가장 작은 값과 현위치 원소를 교환
        temp = list[i];
        list[i] = list[min_idx];
        list[min_idx] = temp;
    }
}
