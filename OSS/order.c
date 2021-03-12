#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // 시간관련 함수를 사용하기 위한 라이브러리
#include "order.h"

// 데이터가 저장되는 실질적인 부분
order* list[MAX_SIZE] = {NULL}; // 주문정보를 저장할 배열생성(전역)
int _count = 0;   // 저장되어 있는 정보의 수 저장(전역)

// 저장가능한공간이 있는 지 확인하는 함수
int space_available(){
    if(_count == MAX_SIZE)
        return 0; // 저장공간을 모두 사용한 경우
    else
        return 1; // 참인 경우
}

// 저장할 수 있는 가장 빠른 인덱스를 찾아주는 함수
int find_space(){
    int i; // 반복문 변수
    for(i=0 ; i<MAX_SIZE ; i++){
        if(list[i] == NULL) // 비어있는 공간을 찾았을 경우
            return i; // 해당인덱스 반환
    }
    return -1; // 공간이 없음을 의미하는 -1 반환
}

// 주문정보를 추가하는 함수
void order_create(int prod, int count, char* id, char* phone, char* place, int pay){
    int index; // 배열의 인덱스 값 저장
    char t[40]; // 기간값 관련 정보를 임시로 저장하는 배열
    index = find_space(); // 저장이 가능한 공간 탐색

    order* newOrd = (order*)malloc(sizeof(order)); // 주문정보를 저장할 구조체 메모리 공간 할당
    list[index] = newOrd; // 배열에 새로운 정보 추가

    // 현재 시간값을 추출하여 시스템으로 저장
    time_t now;
    time(&now);
    strcpy(t, ctime(&now));

    strcpy(newOrd->time, t);                  // 시간
#ifdef DEBUG
	printf("-->DEBUG : Time value is saved to list[%d]\n", index);
#endif	
    newOrd->prod = prod;                      // 제품
#ifdef DEBUG
	printf("-->DEBUG : Product code value is saved to list[%d]\n", index);
#endif	
	newOrd->count = count;                    // 수량
#ifdef DEBUG
	printf("-->DEBUG : Product count value is saved to list[%d]\n", index);
#endif	
	newOrd->price = tell_price(prod) * count; // 청구가격을 계산하여 저장
#ifdef DEBUG
	printf("-->DEBUG : Order price value is saved to list[%d]\n", index);
#endif
	strcpy(newOrd->id, id);                   // id
#ifdef DEBUG
	printf("-->DEBUG : ID value is saved to list[%d]\n", index);
#endif	
	strcpy(newOrd->phone, phone);             // 연락처
#ifdef DEBUG
	printf("-->DEBUG : Phone number value is saved to list[%d]\n", index);
#endif	
	strcpy(newOrd->place, place);             // 주소
#ifdef DEBUG
	printf("-->DEBUG : Place value is saved to list[%d]\n", index);
#endif	
	newOrd->pay = pay;                        // 결제방식
#ifdef DEBUG
	printf("-->DEBUG : Pay value is saved to list[%d]\n", index);
#endif	
	_count++; // 저장된 데이터의 수를 1증가
#ifdef DEBUG
	printf("-->DEBUG : _count value is increased to %d\n", _count);
#endif	
}

// 제품코드를 입력받아서 이를 문자열로 변환시켜주는 함수
char* convProd(int code){
    static char str[30]; // 변환결과를 저장(함수 종료 후에도 데이터를 유지하기 위해 static 선언 사용)
    switch(code){
        case 1:
            strcpy(str, "Apple");
            return str;
        case 2:
            strcpy(str, "Banana");
            return str;
        case 3:
            strcpy(str, "Melon");
            return str;
        case 4:
            strcpy(str, "Orange");
            return str;
        case 5:
            strcpy(str, "Grape");
            return str;
        default:
	    return "\0"; // 오류를 의미하는 null문자 return
            break;
    }
}

// 입력받은 상품코드에 해당하는 상품의 가격을 반환
int tell_price(int code){
	switch(code){
		case 1:
			return 1000;
		case 2:
			return 2000;
		case 3:
			return 4000;
		case 4:
			return 5000;
		case 5:
			return 10000;
		default:
			return -1; // 오류를 의미하는 값 -1을 반환
			break;
    }
}

// 결제수단 정보를 코드로 입력 받아서 문자열로 변환
char* convPay(int code){
	static char str[30]; // 변환결과를 저장
	switch(code){
		case 1:
			strcpy(str, "Card");
			return str;
		case 2:
			strcpy(str, "Cash");
			return str;
		default:
			return "\0"; // 오류를 의미하는 null 문자를 반환
			break;
    }
}

// 저장된 주문정보를 문자열의 형태로 변환하여 반환
char* order_to_string(order* p){
    static char result[100]; // 문자열의 변환결과를 저장
    sprintf(result, " [%.19s] | %10s | %6d | %8s | %13s | %8s | %8d | %5s |",
            p->time, convProd(p->prod), p->count,
            p->id, p->phone, p->place, p->price, convPay(p->pay));
#ifdef DEBUG
	printf("-->DEBUG : Convert to string complete.\n");
#endif	
    return result; // 형성된 문자열을 반환
}

// 저장되어 있는 주문정보의 수를 출력
int order_count(){
    return _count;
}

// 저장되어 있는 모든 주문정보 로드
void get_all_order(order* a[]){
    int i; // 반복문 변수
	int t; // 인자로 받은 배열 a의 index값 저장 
    t = 0;
    for(i=0 ; i<MAX_SIZE ; i++){
        if(list[i] != NULL){
            a[t] = list[i]; // 저장된 주문 정보를 가져옴
#ifdef DEBUG
	printf("-->DEBUG : list[%d] info is loaded to a[%d]\n", i, t);
#endif	
            t++; // 성공적으로 저장 시 index값 1증가
        }
    }
}

// id를 기반으로 검색하여 일치하는 데이터 출력
order* search_by_id(char* id){
    int i; // 반복문 변수
    for(i=0 ; i<MAX_SIZE ; i++){
        if(list[i] != NULL && strcmp(id, list[i]->id) == 0)
            return list[i]; // id 일치하는 정보 발견 시 해당 주소출력
    }
    return NULL; // 아무정보도 탐색하지 못할경우 NULL 포인터 return
}

// 전화번호를 기반으로 검색하여 일치하는 데이터 출력
order* search_by_phone(char* phone){
    int i; // 반복문 변수
    for(i=0 ; i<MAX_SIZE ; i++){
        if(list[i] != NULL && strcmp(phone, list[i]->phone) == 0)
            return list[i]; // id 일치하는 정보 발견 시 해당 주소출력
    }
    return NULL; // 아무정보도 탐색하지 못할경우 NULL 포인터 return
}

// 입력한 주문정보 포인터의 시간값을 가져옴
char* getTime(order* p){
    return p->time;
}

// 입력한 주문정보 포인터의 제품코드를 가져옴
int getProd(order* p){
    return p->prod;
}

// 입력한 주문정보 포인터의 주문 수량값을 가져옴
int getCount(order* p){
    return p->count;
}

// 입력한 주문정보 포인터의 id값을 가져옴
char* getId(order* p){
    return p->id;
}

// 입력한 주문정보 포인터의 연락처 값을 가져옴
char* getPhone(order* p){
    return p->phone;
}

// 입력한 주문정보 포인터의 주소지 값을 가져옴
char* getPlace(order* p){
    return p->place;
}

// 입력한 주문정보 포인터의 청구가격을 가져옴
int getPrice(order* p){
    return p->price;
}

// 입력한 주문정보 포인터의 결제수단 코드를 가져옴
int getPay(order* p){
    return p->pay;
}

// 입력한 문자열을 포함하는 시간값을 가지는 모든 주문정보의 포인터를 배열로 반환
int get_all_time(order* a[], char* n){
    int i; // 반복문 변수
    int t = 0; // 인덱스 값 일시저장
    for(i=0; i<MAX_SIZE; i++){
        if(list[i]!=NULL && (strstr(list[i]->time, n))){
            a[t] = list[i];
#ifdef DEBUG
	printf("-->DEBUG : list[%d] info searched\n", i);
#endif	
			t++;
        }
    }
    return t;
}

// 입력한 문자열을 포함하는 id를 가지는 모든 주문정보의 포인터를 배열로 변환
int get_all_id(order* a[], char* n){
    int i;     // 반복문 변수
    int t = 0; // 인덱스 값
    for(i=0; i<MAX_SIZE; i++){
        if(list[i]!=NULL && strstr(list[i]->id, n)){
            a[t]=list[i];
#ifdef DEBUG
	printf("-->DEBUG : list[%d] info searched\n", i);
#endif	
			t++;
        }
    }
    return t;
}

// 입력한 문자열을 포함하는 연락처를 가지는 모든 주문정보의 포인터를 배열로 반환
int get_all_phone(order* a[], char* n){
    int i; // 반복문 변수
    int t = 0; // 인덱스 값
    for(i=0; i<MAX_SIZE; i++){
        if(list[i]!=NULL && strstr(list[i]->phone, n)){
            a[t]=list[i];
#ifdef DEBUG
	printf("-->DEBUG : list[%d] info searched\n", i);
#endif	
			t++;
        }
    }
    return t;
}

// 같은 제품코드를 가지는 모든 주문정보의 포인터를 배열로 반환
int get_all_prod(order* a[], int n){
    int i; // 반복문 변수
    int t = 0; // 새로운 배열의 인덱스 값
    for(i=0; i<MAX_SIZE; i++){
        if(list[i]!=NULL && (list[i]->prod == n)){
            a[t] = list[i];
#ifdef DEBUG
	printf("-->DEBUG : list[%d] info searched\n", i);
#endif	
			t++;
        }
    }
    return t;
}

// 같은 주소지값을 가지는 모든 주문정보의 포인터를 배열로 반환
int get_all_place(order* a[], char* n){
    int i; // 반복문 변수
    int t = 0; // 인덱스 값 일시저장
    for(i=0; i<MAX_SIZE; i++){
        if(list[i]!=NULL && (strcmp(list[i]->place, n)==0)){
            a[t] = list[i];
#ifdef DEBUG
	printf("-->DEBUG : list[%d] info searched\n", i);
#endif	
			t++;
        }
    }
    return t;
}

// 같은 결제수단 코드를 가지는 모든 주문정보의 포인터를 배열로 반환
int get_all_pay(order* a[], int n){
    int i; // 반복문 변수
    int t = 0; // 인덱스 값 일시저장
    for(i=0; i<MAX_SIZE; i++){
        if(list[i]!=NULL && (list[i]->pay == n)){
            a[t] = list[i];
#ifdef DEBUG
	printf("-->DEBUG : list[%d] info searched\n", i);
#endif	
			t++;
        }
    }
    return t;
}

// 파일로부터 읽어온 새로운 주문정보를 추가함
void order_create_f(char* time, int prod, int count, char* id, char* phone, char* place, int pay){
    int index; // 배열의 인덱스 값 저장
    index = find_space(); // 저장이 가능한 공간 탐색

    order* newOrd = (order*)malloc(sizeof(order)); // 주문정보를 저장할 구조체 메모리 공간 할당
    list[index] = newOrd; // 배열에 새로운 정보 추가

    strcpy(newOrd->time, time);               // 시간
#ifdef DEBUG
	printf("-->DEBUG : (file) Time value is saved to list[%d]\n", index);
#endif	
    newOrd->prod = prod;                      // 제품
#ifdef DEBUG
	printf("-->DEBUG : (file) Product code value is saved to list[%d]\n", index);
#endif
	newOrd->count = count;                    // 수량
#ifdef DEBUG
	printf("-->DEBUG : (file) Product count value is saved to list[%d]\n", index);
#endif    
	newOrd->price = tell_price(prod) * count; // 청구가격을 계산하여 저장
#ifdef DEBUG
	printf("-->DEBUG : (file) Order price value is saved to list[%d]\n", index);
#endif	
	strcpy(newOrd->id, id);                   // id
#ifdef DEBUG
	printf("-->DEBUG : (file) ID value is saved to list[%d]\n", index);
#endif	
	strcpy(newOrd->phone, phone);             // 연락처
#ifdef DEBUG
	printf("-->DEBUG : (file) Phone number value is saved to list[%d]\n", index);
#endif	
	strcpy(newOrd->place, place);             // 주소
#ifdef DEBUG
	printf("-->DEBUG : (file) Place value is saved to list[%d]\n", index);
#endif	
	newOrd->pay = pay;                        // 결제방식
#ifdef DEBUG
	printf("-->DEBUG : (file) Pay method value is saved to list[%d]\n", index);
#endif	
	_count++; // 저장된 데이터의 수를 1증가
#ifdef DEBUG
	printf("-->DEBUG : (file) _count value is increased to %d\n", _count);
#endif	
}

// 주문정보의 포인터를 저장하는 배열의 전체내용 삭제(초기화)
void orderList_init()
{
    int i; // 반복문 변수선언
    for(i=0; i<MAX_SIZE; i++){
        if(list[i]!=NULL) {
            free(list[i]); // 메모리공간 삭제
        }
        list[i] = NULL;
    }
    _count = 0;
}

// 파일에 데이터를 저장하는 형식의 문자열로 주문정보를 변환
char* order_to_string_save(order* p)
{
    static char result[100]; // 파일에 입력될 문자열을 저장하는 함수
    sprintf(result, "%s %d %d %s %s %s %d", p->time, p->prod, p->count, p->id, p->phone, p->place, p->pay);
#ifdef DEBUG
	printf("-->DEBUG : Complete convert to string for file \n");
#endif	
	return result;
}

// 입력된 주문정보로 인해 발생하는 총 수익값을 계산하여 출력
int total_margin()
{
    int sum = 0; // 모든 청구금액에 대한 합산값을 저장
    for(int i=0 ; i<MAX_SIZE ; i++)
	{
		if(list[i] == NULL) // 조각모음을 하지 않은 경우 발생할 오류를 방지하기 위한부분
			continue;
        sum += list[i]->price;
	}
#ifdef DEBUG
	printf("-->DEBUG : Complete calculation of total margin\n");
#endif	
    return sum; // 총 합산값을 반환
}

// 접수된 주문의 총 상품수량에 대한 합산값을 저장
int total_count()
{
	int sum = 0; // 모든 주문수량에 대한 합산 값을 저장
	for(int i=0 ; i<MAX_SIZE ; i++)
	{
		if(list[i] == NULL) // 조각모음을 하지 않은 경우 발생할 수 있는 오류를 막기위한 부분
			continue;
		sum += list[i]->count;
	}
#ifdef DEBUG
	printf("-->DEBUG : Complete calculation of total count\n");
#endif	
	return sum; // 총 주문수량 값을 반환	
}

// 해당주문정보의 전반적인 모든 정보를 변경
void order_update(order* p, int prod, int count, char* phone, char* place, int pay)
{
	p->prod = prod; // 상품코드 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update product code\n");
#endif	
	p->count = count; // 상품수량 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update order count\n");
#endif	
	p->price = tell_price(prod) * count; // 수정된 값을 반영하여 청구가격 조정
#ifdef DEBUG
	printf("-->DEBUG : Complete Update order price\n");
#endif	
	strcpy(p->phone, phone); // 연락처 값 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Upadate phone number\n");
#endif	
	strcpy(p->place, place); // 주소지 값 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update place\n");
#endif	
	p->pay = pay; // 결제수단 코드 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update pay code\n");
#endif	
}

// 해당주문정보의 주문상품 관련정보 변경(상품코드, 주문수량)
void prod_update(order* p, int prod, int count)
{
	p->prod = prod;   // 제품코드 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update product code\n");
#endif	
	p->count = count; // 주문상품 수량변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update order count\n");
#endif	
	p->price = tell_price(prod) * count; // 수정된 값을 반영하여 청구가격 조정
#ifdef DEBUG
	printf("-->DEBUG : Complete Update order price\n");
#endif	
}

// 해당주문정보의 연락처 변경
void phone_update(order* p, char* phone)
{
	strcpy(p->phone, phone); // 연락처 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Upadate phone number\n");
#endif	
}

// 해당주문정보의 주소지 변경
void place_update(order* p, char* place)
{
	strcpy(p->place, place); // 주소지 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update place\n");
#endif	
}

// 해당주문정보의 결제수단코드 변경
void pay_update(order* p, int pay)
{
	p->pay = pay; // 결제수단 코드값 변경
#ifdef DEBUG
	printf("-->DEBUG : Complete Update pay code\n");
#endif	
}

// 해당주문정보를 삭제
void order_delete(order* p)
{
	int i; // 반복문 변수
	int index; // 인덱스 값 저장

	for(i=0 ; i<_count ; i++){
		if(list[i] == p){
			index = i; // 일치하는 주소값을 가지는 정보의 인덱스 저장
			break;
		}
	}
	free(p); // 해당 정보의 메모리 공간 해제
#ifdef DEBUG
	printf("-->DEBUG : The memory space is deleted\n");
#endif	
	list[index] = NULL; // 삭제되어 빈 공간을 NULL 값으로 변경
	_count--; // 데이터를 삭제했으므로 저장된 데이터의 수 1감소
}

void gather_piece()
{
	int index; // index값 저장
	int cur; // 현재 탐색 index
	int i; // 반복문 변수

	// 배열에서 마지막으로 유효한 값을 가진 index 탐색
	for(i=0 ; i<MAX_SIZE ; i++)
	{
		if(list[i] != NULL)
			index = i;
	}

	for(cur=0 ; cur<index ; cur++)
	{
		if(list[cur] == NULL)
		{
			for(i=cur ; i<index ; i++)
			{
				list[i] = list[i+1];
#ifdef DEBUG
	printf("-->DEBUG : Adjust : list[%d] <--- list[%d]\n", i, i+1);
#endif
			}
			list[index] = NULL; // 새로운 내용 추가를 위한 NULL값 삽입
			// index 값 갱신
			for(i=0 ; i<MAX_SIZE ; i++)
			{
				if(list[i] != NULL)
					index = i;
			}
			cur--; // 값의 재참조를 위해 cur값 1감소
		}
	}
}

char* conv_time(char* time)
{
	static char timeCode[20];
	char month[5];
	strncpy(month, time+4, 3); // 문자로 된 월값 읽어오기
	// 문자로 구성된 월값을 수의형태로 변환	
	if(strncmp(month, "Jan", 3) == 0)
		strcpy(timeCode, "01");
	else if(strncmp(month, "Feb", 3) == 0)
		strcpy(timeCode, "02");
	else if(strncmp(month, "Mar", 3) == 0)
		strcpy(timeCode, "03");
	else if(strncmp(month, "Apr", 3) == 0)
		strcpy(timeCode, "04");
	else if(strncmp(month, "May", 3) == 0)
		strcpy(timeCode, "05");
	else if(strncmp(month, "Jun", 3) == 0)
		strcpy(timeCode, "06");
	else if(strncmp(month, "Jul", 3) == 0)
		strcpy(timeCode, "07");
	else if(strncmp(month, "Aug", 3) == 0)
		strcpy(timeCode, "08");
	else if(strncmp(month, "Sep", 3) == 0)
		strcpy(timeCode, "09");
	else if(strncmp(month, "Oct", 3) == 0)
		strcpy(timeCode, "10");
	else if(strncmp(month, "Nov", 3) == 0)
		strcpy(timeCode, "11");
	else if(strncmp(month, "Dec", 3) == 0)
		strcpy(timeCode, "12");
	else
	{
		printf("Error! : Invalid time value\n");
		exit(-1);
	}

	// 일, 시간, 분, 초 값추가
	if(*(time+8) == ' ')
		*(time+8) = '0'; 
	strncat(timeCode, time+8, 2); // 일 추가
	strncat(timeCode, time+11, 2); // 시간추가
	strncat(timeCode, time+14, 2); // 분 추가
	strncat(timeCode, time+17, 2); // 초 추가
	return timeCode;
}

void sort_by_time_up()
{
	order* p; // 배열에 저장된 주문정보의 주소값
	char str1[20];
	char str2[20];
	int i, j; // 반복문 변수
	

	for(i=0 ; i<_count ; i++)
	{
		for(j=i ; j<_count ; j++)
		{
			strcpy(str1, conv_time(list[i]->time));
			strcpy(str2, conv_time(list[j]->time));
			
			if(strcmp(str1, str2) > 0)
			{
				p = list[i];
				list[i] = list[j];
				list[j] = p;
#ifdef DEBUG
	printf("-->DEBUG : Sort data list[%d] <-- list[%d]\n", i, j);
#endif
			}
		}
	}
}

void sort_by_time_down()
{
	order* p; // 배열에 저장된 주문정보의 주소값
	char str1[20];
	char str2[20];
	int i, j; // 반복문 변수
	

	for(i=0 ; i<_count ; i++)
	{
		for(j=i ; j<_count ; j++)
		{
			strcpy(str1, conv_time(list[i]->time));
			strcpy(str2, conv_time(list[j]->time));
			
			if(strcmp(str1, str2) < 0)
			{
				p = list[i];
				list[i] = list[j];
				list[j] = p;
#ifdef DEBUG
	printf("-->DEBUG : Sort data list[%d] <-- list[%d]\n", i, j);
#endif
			}
		}
	}
}

void sort_by_id_up()
{
	order* p; // 배열에 저장된 주문정보의 주소값
	int i, j; // 반복문 변수
	
	for(i=0 ; i<_count ; i++)
	{
		for(j=i ; j<_count ; j++)
		{
			if(strcmp(list[i]->id, list[j]->id) > 0)
			{
				p = list[i];
				list[i] = list[j];
				list[j] = p;
			}
		}
	}
}

void sort_by_id_down()
{	
	order* p; // 배열에 저장된 주문정보의 주소값
	int i, j; // 반복문 변수
	
	for(i=0 ; i<_count ; i++)
	{
		for(j=i ; j<_count ; j++)
		{
			if(strcmp(list[i]->id, list[j]->id) < 0)
			{
				p = list[i];
				list[i] = list[j];
				list[j] = p;
			}
		}
	}
}
