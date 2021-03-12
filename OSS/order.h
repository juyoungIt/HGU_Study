#include <stdio.h>

#define SIZE 100     // redability 향상을 위한 부분
#define MAX_SIZE 100  // 저장할 수 있는 최대 주문정보의 수

typedef struct _orders
{
    char time[SIZE];  // 구매일자, 시간
    int prod;         // 주문상품- 목록은 별도로 제작, 상품명을 코드화 해서 정보를 받음
    int count;        // 수량
    char id[SIZE];    // 주문자 id
    char phone[SIZE]; // 연락처
    char place[SIZE]; // 주소
    int price;        // 청구금액
    int pay;                  // 결제수단(코드화, 카드 또는 현금으로 분류)
}order;


// 해당 구조체에 대한 함수선언
int space_available(); // 레코드에 주문정보를 저장할 수 있는 지 판단
int find_space();        // 데이터를 저장할 수 있는 가장 빠른 인덱스를 찾아 반환
int order_count();       // 저장된 주문정보의 수 반환
void order_create(int prod, int count, char* id, char* phone, char* place, int pay);
int tell_price(int prod_code); // 상품에 대한 가격정보 값을 반환
char* order_to_string(order* p); // 입력받은 주소값의 레코드 정보를 문자열로 변환
order* search_by_id(char* id); // id를 기반으로 검색하여 일치하는 주문정보의 주소값 반환
order* search_by_phone(char* phone); // 전화번호를 기반으로 검색하여 일치하는 주문값 반환
char* getTime(order* p);  // 입력받은 주소값의 레코드에 저장된 시간값 반환
int getProd(order* p);    // 입력받은 주소값의 레코드에 저장된 상품코드 반환
int getCount(order* p);   // 입력받은 주소값의 레코드에 저장된 상품코드 반환
char* getId(order* p);    // 입력받은 주소값의 레코드에 저장된 주문자 id 반환
char* getPhone(order* p); // 입력받은 주소값의 레코드에 저장된 주문자 연락처 반환
char* getPlace(order* p); // 입력받은 주소값의 레코드에 저장된 주문자 주소 반환
int getPrice(order* p);   // 입력받은 주소값의 레코드에 저장된 청구가격 반환
int getPay(order* p);     // 입력받은 주소값의 레코드에 저장된 결제수단코드 반환
int get_all_id(order* a[], char* n); // 입력받은 문자열을 포함하는 id를 가진 레코드의 주소값을 배열에 저장
int get_all_time(order* a[], char* n); // 입력받은 시간값과 같은 값을 가지는 레코드의 주소값을 배열에 저장
int get_all_prod(order* a[], int n);  // 입력받은 상품코드와 같은 값을 가지는 레코드의 주소값을 배열에 저장
int get_all_phone(order* a[], char* n); // 입력받은 전화번호와 같은 값을 가지는 레코드의 주소값을 배열에 저장
int get_all_place(order* a[], char* n); // 입력받은 주소와 같은 값을 가지는 레코드의 주소값을 배열에 저장
int get_all_pay(order* a[], int n);     // 입력받은 결제수단 코드와 같은 값을 가지는 레코드의 주소값을 배열에 저장
void get_all_order(order* a[]); // 주문정보가 들어있는 모든 레코드 포인터의 배열의 생성
char* convProd(int prod_code); // 상품명에 대한 정수코드를 문자열로 변환하여 반환
char* convPay(int pay_code);  // 결제수단에 대한 정수코드를 문자열로 변환하여 반환
void order_update(order* p, int prod, int count, char* phone, char* place, int pay);
void order_delete(order* p); // 입력받은 주소값의 레코드를 삭제
void prod_update(order* p, int prod, int count); // 해당레코드의 상품정보값 수정
void phone_update(order* p, char* phone); // 해당레코드의 전화번호 값 수정
void place_update(order* p, char* place); // 해당레코드의 주소값 변경
void pay_update(order* p, int pay); // 해당레코드의 결제수단코드 변경
void orderList_init();  // 포인터 배열에 저장된 모든 요소 삭제
void gather_piece(); // 데이터 조각모음
void sort_by_time_up(); // 시간값을 기준으로 레코드 오름차순 정렬
void sort_by_time_down(); // 시간값을 기준으로 레코드 내림차순 정렬
void sort_by_id_up(); // id값을 기준으로 레코드 오름차순 정렬
void sort_by_id_down(); // id값을 기준으로 레코드 내림차순 정렬
char* order_to_string_save(order* p); // 입력받은 주소값을 레코드 정보를 문자열로 변환(파일)
void order_create_f(char* time, int prod, int count, char* id, char* phone, char* place, int pay);
int total_margin(); // 저장된 주문정보의 모든 청구금액을 합산하여 반환
int total_count(); // 저장된 주문정보의 총 상품주문수량을 합산하여 반환
char* conv_time(char* time); // 입력받은 출력형태의 시간값을 코드형태로 변환
