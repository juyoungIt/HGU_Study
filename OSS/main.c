#include <stdio.h>
#include <string.h>
#include "order.h"

// 기능관련 함수 선언부
void create_record(); // 주문정보 추가
void show_option();   // 사용가능 옵션목록 출력
void show_prod();     // 주문가능 상품목록 출력
void read_record();   // 주문정보를 조회
void list_record();   // 전체 주문정보 출력
void search_record(); // 정보검색 기능을 통합적으로 지원하는 함수
void search_time();   // 주문정보 검색, 출력(시간값)
void search_id();     // 주문정보 검색, 출력(ID)
void search_prod();   // 주문정보 검색, 출력(제품명)
void search_phone();  // 주문정보 검색, 출력(연락처)
void search_place();  // 주문정보 검색, 출력(주소)
void search_pay();    // 주문정보 검색, 출력(결제수단)
void update_record(); // 주문정보 업데이트
void delete_record(); // 주문정보 삭제
void load_data();     // 주문정보 로딩(파일)
void save_data();     // 주문정보 저장(파일, 데이터형식)
void save_report();   // 주문정보 저장(파일, 보고서형식)
void arrange();       // 데이터 조각모음
void order_sort();    // 데이터 정렬(시간, ID)
void show_margin();   // 총 판매수익 출력
void show_report();   // 수익정보 출력(보고서 형식)

int main(){
    int option_code; // 옵션코드 값 저장(사용자 입력)
    while(1){
        show_option(); // 선택가능 옵션 출력
        printf("Enter the option code : ");
        scanf("%d", &option_code);

		switch(option_code){
			case 1: // 정보 추가
				create_record();
				break;
			case 2: // 정보 검색
				read_record();
				break;
			case 3: // 정보 업데이트
				update_record();
				break;
			case 4: // 정보 삭제
				delete_record();
				break;
			case 5: // 모든정보 출력
				list_record();
				break;
			case 6: // 통합정보검색
				search_record();
				break;
			case 7: // 주문으로 인한 총수익을 보여줌
				show_margin();
				break;
			case 8: // 주문정보를 보고서 형식으로 보여줌
				show_report();
				break;
			case 9: // 파일에서 정보로딩
				load_data();
				break;
			case 10: // 파일에 정보저장
				save_data();
				break;
			case 11: // 파일에 보고서 저장
				save_report();
				break;
			case 12: // 데이터 조각모음
				arrange();
				break;
			case 13: // 데이터 정렬
				order_sort();
				break;
			case 0:
				return 0;
			default:
				printf("Error! invalid option code\n");
				break;
        }
    }
}

// 기능관련 함수 정의부
void create_record(){
    if(!space_available()){
        printf("Error! : There is no more space!...\n");
        return; // 더 이상 값을 저장할 공간이 없는 경우 강제종료
    }
    char id[50], phone[50], place[50]; // 문자열 정보 저장
    int prod, count, pay;              // 정수값 정보 저장

    show_prod();  // 주문가능상품 목록을 사용자에게 시각화하여 출력
    printf("Please Enter the product code : ");
    scanf("%d", &prod);
    if(prod < 1 || prod > 5) // 예외처리 - 목록에 없는 코드가 입력될 경우
    {
        printf("Error! : invalid product code\n"); // 에러메시지 출력
        return;  // 강제종료
    }
    printf("Enter the order count : ");
    scanf("%d", &count);
    printf("*********************************************\n");
    printf("Enter the order id : ");
    scanf("%s", id);
    if(search_by_id(id) != NULL){ // 중복되는 id 입력에 대해서 거부
        printf("Duplicate ID! \n");
        return;
    }
    printf("Enter the order phone : ");
    scanf("%s", phone);
    if(search_by_phone(phone) != NULL){ // 중복되는 연락처 입력에 대해서 거부
        printf("Duplicate Phone! \n");
        return;
    }
    printf("Enter the order place : ");
    scanf("%s", place);
    printf("*********************************************\n");
    printf("<The list of pay method>\n\n");
    printf("1 - Card  2 - Cash\n");
    printf("*********************************************\n");
    printf("Enter the pay code : ");
    scanf("%d", &pay);
    if(pay < 1 || pay > 2) // 예외처리 - 목록에 없는 코드가 입력될 경우
    {
        printf("Error! : invalid pay code\n"); // 에러메시지 출력
        return;  // 강제종료
    }
    printf("*********************************************\n");

    order_create(prod, count, id, phone, place, pay); // 주문정보 생성
    printf("Your order is saved.\n\n\n");
}

void show_prod(){
    printf("*********************************************\n");
    printf("     <The list of products>\n\n");
    printf("[code]         [prod]           [price]\n");
    printf("  1            Apple             %d  \n", tell_price(1));
    printf("  2            Banana            %d  \n", tell_price(2));
    printf("  3            Melon             %d  \n", tell_price(3));
    printf("  4            Orange            %d  \n", tell_price(4));
    printf("  5            Grape             %d  \n", tell_price(5));
    printf("*********************************************\n");
}

void show_option(){
	printf("***************************************************\n");
	printf("        <Available option list>\n\n");
	printf(" 1 - create        2 - read         3 - update\n");
	printf(" 4 - delete        5 - list         6 - search\n");
	printf(" 7 - show margin   8 - show report  9 - load data\n");
	printf("10 - save file    11 - save report 12 - arrange\n");
	printf("13 - sorting       0 - quit\n");
	printf("***************************************************\n");
}

void read_record(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int read_option_code; // 조회옵션코드값 저장
    printf("*********************************************\n");
    printf("        <Pay method option>\n\n");
    printf("1 - read by id  2 - read by phone\n");
    printf("*********************************************\n");
    printf("Enter the read option : ");
    scanf("%d", &read_option_code);

    if(read_option_code == 1){
        order *p; // 주문정보의 주소값 저장
        char str[20];
        printf("Enter the id : ");
        scanf("%s", str);
        p = search_by_id(str); // 입력받은 id를 대상으로 탐색진행
        if (p == NULL){ // id를 찾지 못한 경우
            printf("Can not search this id\n");
            return;
        }
        else{
            printf("Order info found.\n");
            printf("------------------------------------------\n");
            printf("주문 시각 : %.19s\n", getTime(p));
            printf("주문 id  : %s\n", getId(p));
            printf("주문 상품 : %s\n", convProd(getProd(p)));
            printf("주문 수량 : %d\n", getCount(p));
            printf("연락 번호 : %s\n", getPhone(p));
            printf("주    소 : %s\n", getPlace(p));
            printf("청구 가격 : %d\n", getPrice(p));
            printf("결제 수단 : %s\n", convPay(getPay(p)));
            printf("------------------------------------------\n");
            printf("\n");
        }
    }

    else if(read_option_code == 2){
        order *p; // 주문정보의 주소값 저장
        char str[20];
        printf("Enter the phone : ");
        scanf("%s", str);
        p = search_by_phone(str); // 입력받은 전화번호를 대상으로 탐색진행
        if (p == NULL){ // 번호를 찾지 못한 경우
            printf("Can not search this phone\n");
            return;
        }
        else{
            printf("Order info found.\n");
            printf("------------------------------------------\n");
            printf("주문 시각 : %.19s\n", getTime(p));
            printf("주문 id  : %s\n", getId(p));
            printf("주문 상품 : %s\n", convProd(getProd(p)));
            printf("주문 수량 : %d\n", getCount(p));
            printf("연락 번호 : %s\n", getPhone(p));
            printf("주    소 : %s\n", getPlace(p));
            printf("청구 가격 : %d\n", getPrice(p));
            printf("결제 수단 : %s\n", convPay(getPay(p)));
            printf("------------------------------------------\n");
            printf("\n");
        }
    }
    else{
        printf("Error! invalid option code\n");
        return;
    }
}

void list_record(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int i; // 반복문 변수
    int count; // 반복횟수
    count = order_count(); // 저장된 데이터의 수를 할당

    order* arr[MAX_SIZE];        // 저장정보를 가져올 배열 선언
    get_all_order(arr);    // 저장정보를 가져옴

    printf("--------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                               <Order list>\n\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("| %3s | %.21s | %10s | %6s | %8s | %13s | %8s | %8s | %5s |\n", 
	                 "Num", "         Time         ", " Product ", "Amount", "   ID   ",  "    Phone    ", " Place ", " Price ", " Pay ");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for(i=0 ; i<count; i++)
	{
		printf("| %3d |", i+1);
        printf("%s\n", order_to_string(arr[i]));	
	}
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("%d order information was saved.\n", count);	
    printf("--------------------------------------------------------------------------------------------------------------\n");
}

void search_record()
{
    int search_code; // 검색방식에 대한 코드값

    printf("*********************************************\n");
    printf("<Available searching option>\n\n");
    printf("1 - By time   2 - By product  3 - By id \n");
    printf("4 - By phone  5 - By place    6 - By pay\n");
    printf("*********************************************\n");

    printf("Enter the search code : ");
    scanf("%d", &search_code);
    switch(search_code){
        case 1:
            printf("Search by Time\n");
            search_time();
            break;
        case 2:
            printf("Search by Product Name\n");
            search_prod();
            break;
        case 3:
            printf("Search by order ID\n");
            search_id();
            break;
        case 4:
            printf("Search by Phone Number\n");
            search_phone();
            break;
        case 5:
            printf("Search by order Place\n");
            search_place();
            break;
        case 6:
            printf("Search by Pay Method\n");
            search_pay();
            break;
        default:
            printf("Error! : Search code invalid\n");
            break;
    }
}

void search_time(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int count; // 검색된 정보의 수
    int i;     // 반복문 변수
    char time[30]; // 사용자 입력 시간값 저장
    printf("Enter the search time : ");
    getchar();// 입력버퍼에 남아있는 개행문자 삭제
	fgets(time, 30, stdin);
	time[(strlen(time)-1)] = '\0'; // fgets로 인하여 추가되는 개행문자를 삭제

    order* t_list[MAX_SIZE]; // 선별된 정보를 저장할 배열
    count = get_all_time(t_list, time);
    printf("%d order info found\n", count);
    // 탐색한 정보를 출력
    for(i=0 ; i<count ; i++)
        printf("%s\n", order_to_string(t_list[i]));
}

void search_prod(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int count; // 검색된 정보의 수
    int i; // 반복문 변수
    int p_code; // 사용자 입력 상품코드
    printf("1 - Apple, 2 - Banana, 3 - Melon, 4 - Orange, 5 - Grape\n");
    printf("Enter the product code : ");
    scanf("%d", &p_code);

    order* t_list[MAX_SIZE]; // 선별된 정보를 저장할 배열
    count = get_all_prod(t_list, p_code);
    printf("%d order info found\n", count);
    // 탐색한 정보를 출력
    for(i=0 ; i<count ; i++)
        printf("%s\n", order_to_string(t_list[i]));
}

void search_id(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int count; // 검색된 정보의 수
    int i; // 반복문 변수
    char id[30]; // 사용자 입력 시간값 저장
    printf("Enter the search ID : ");
    scanf("%s", id);

    order* t_list[MAX_SIZE]; // 선별된 정보를 저장할 배열
    count = get_all_id(t_list, id);
    printf("%d order info found\n", count);
    // 탐색한 정보를 출력
    for(i=0 ; i<count ; i++)
        printf("%s\n", order_to_string(t_list[i]));
}

void search_phone(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int count; // 검색된 정보의 수
    int i; // 반복문 변수
    char phone[30]; // 사용자 입력 시간값 저장
    printf("Enter the search phone : ");
    scanf("%s", phone);

    order* t_list[MAX_SIZE]; // 선별된 정보를 저장할 배열
    count = get_all_phone(t_list, phone);
    printf("%d order info found\n", count);
    // 탐색한 정보를 출력
    for(i=0 ; i<count ; i++)
        printf("%s\n", order_to_string(t_list[i]));
}

void search_place(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int count; // 검색된 정보의 수
    int i; // 반복문 변수
    char place[30]; // 사용자 입력 주소 저장
    printf("Enter the search place : ");
    scanf("%s", place);

    order* t_list[MAX_SIZE]; // 선별된 정보를 저장할 배열
    count = get_all_place(t_list, place);
    printf("%d order info found\n", count);
    // 탐색한 정보를 출력
    for(i=0 ; i<count ; i++)
        printf("%s\n", order_to_string(t_list[i]));
}

void search_pay(){
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }
    int count; // 검색된 정보의 수
    int i; // 반복문 변수
    int p_code; // 사용자 입력 결제수단코드
    printf("1 - Card, 2 - Cash\n");
    printf("Enter the pay code : ");
    scanf("%d", &p_code);

    order* t_list[MAX_SIZE]; // 선별된 정보를 저장할 배열
    count = get_all_pay(t_list, p_code);
    printf("%d order info found\n", count);
    // 탐색한 정보를 출력
    for(i=0 ; i<count ; i++)
        printf("%s\n", order_to_string(t_list[i]));
}

void load_data()
{
    int read_type; // 데이터를 읽어오는 방식정보를 저장
    // 데이터 파일 읽어오기
    // 사용가능한 read 옵션 정보 출력
    printf("***********************************************\n");
    printf("         <Read Options>\n\n");
    printf("mode               function\n");
    printf(" 1  Before read, initialize all orders.\n");  // 기존에 입력된 항목들을 초기화 하고 데이터 로딩
    printf(" 2  Maintain previous data.\n");               // 기존에 입력된 항목들을 유지하고 이어서 데이터 로딩
    printf("***********************************************\n");
    printf("Enter the read mode : ");
    scanf("%d", &read_type);

    if(read_type == 1) // 기존의 항목을 초기화 하고 로드
    {
        int confirm; // 초기화 작업확인 여부에 대한 확인값을 저장
        int load_count = 0; // 파일로부터 읽어온 데이터의 수를 저장

		printf("If you use the mode1, all data will be deleted. \n");
        printf("Are you want this option? (yes[1] / no[2]) : ");
        scanf("%d", &confirm);
        if(confirm == 2)
            return; // 강제종료
        else if(confirm == 1)
            orderList_init(); // 기존에 리스트에 저장되어 있던 모든 정보를 삭제
        else{
            printf("Error! : invalid option value\n");
            return; // 강제종료
        }

        FILE* f = fopen("orders.txt", "r"); // 데이터가 저장된 orders.txt 파일을 읽기모드로 open
        char time[30], id[30], phone[30], place[30]; // 주문시간, id, 전화번호, 주소지 정보 저장변수
        int prod, count, pay;                        // 상품코드, 수량, 청구가격, 결제수단 저장변수

        while(1) // 파일의 끝에 도달할 때 까지
        {
			if(!space_available()){
                printf("Lord Error! : No more space.\n");
                break;
            }
            // 각 항목별 정보를 읽어옴
            fgets(time, 20, f); // 파일의 각 내용에서 20문자에 해당하는 시간값을 읽어옴
            fscanf(f, "%d %d %s %s %s %d",&prod, &count, id, phone, place, &pay);
			fgetc(f); // fgets 가 다음라인의 문자열을 읽을 수 있도록 파일포인터의 위치를 이동
            if(feof(f)) break; // 파일포인터가 파일의 끝에 도달한 경우
			order_create_f(time, prod, count, id, phone, place, pay); // 불러온 내용을 생성
	    	load_count++; // 주문정보가 로드 되었으므로 load_count 값 1증가
        }
        printf("The %d record loaded.\n", load_count);
        fclose(f); // 파일에 대한 모든 작업을 마쳤으므로 작업 파일을 닫음
    }
    else if(read_type == 2)
    {
        FILE* f = fopen("orders.txt", "r"); // 데이터가 저장된 orders.txt 파일을 읽기모드로 open
        char time[30], id[30], phone[30], place[30]; // 주문시간, id, 전화번호, 주소지 정보 저장변수
        int prod, count, pay;                        // 상품코드, 수량, 청구가격, 결제수단 저장변수
        int load_count = 0; // 파일로부터 읽어온 데이터의 수를 저장

        while(1) // 파일의 끝에 도달할 때 까지
        {   // 정보를 로딩할 공간이 없는 경우
            if(!space_available()){
                printf("Lord Error! : No more space.\n");
                break;
            }
            // 각 항목별 정보를 읽어옴
            fgets(time, 20, f); // 파일의 각 내용에서 20문자에 해당하는 시간값을 읽어옴
            fscanf(f, "%d %d %s %s %s %d",&prod, &count, id, phone, place, &pay);
            fgetc(f); // 다음 라인을 fgets이 읽을 수 있도록 하기 위한 부분
            if(feof(f)) break; // 파일포인터가 파일의 끝에 도달한 경우
			if(search_by_id(id) != NULL){ // 기존의 데이터에서 중복되는 이름값이 존재하는 경우
                printf("Error! : Duplicated user ID (%s)\n", id);
                continue; // 중복되는 id값을 가지는 주문정보는 리스트에 포함시키지 않음.
            }
            if(search_by_phone(phone) != NULL){ // 기존의 데이터에서 중복되는 번호값이 존재할 경우
                printf("Error! : Duplicated user Phone (%s)\n", phone);
                continue; // 중복되는 연락처 값을 가지는 주문정보는 리스트에 포함시키지 않음.
            }
            order_create_f(time, prod, count, id, phone, place, pay); // 불러온 내용을 생성
            load_count++; // 주문정보가 생성되었으므로 load_count의 값을 1증가
        }
        printf("The %d record loaded.\n", load_count);
        fclose(f); // 파일에 대한 모든 작업을 마쳤으므로 작업 파일을 닫음
    }
    else{
        printf("Error! : Invalid option code\n"); // 에러메시지 출력
        return;  // 강제종료
    }
}

// 주문정보를 파일에 데이터 형식으로 저장
void save_data()
{
    int size; // 저장되어 있는 주문정보의 수

    FILE* f = fopen("orders.txt", "w"); // orders.txt 파일을 쓰기 모드로 open
    size = order_count();
    order* order_list[MAX_SIZE];
    get_all_order(order_list); // 저장되어 있는 모든 주문정보를 이전에 선언한 배열 order_list로 가져옴
    for(int i=0; i<size; i++){
        order* p = order_list[i];
        fprintf(f,"%s\n", order_to_string_save(p)); // 전달받은 정보를 바탕으로 파일에 데이터 형식으로 저장
    }
    printf("Order information is saved. \n"); // 정보저장이 성공적으로 이루어졌음을 알리는 메시지 출력
    fclose(f);
}

void save_report()
{
	int size; // 저장되어 있는 주문정보의 수
	int i, j; // 반복문 변수
	int t_prod_count = 0; // 일시적으로 특정 상품의 총 주문수량을 저장
	int t_prod_margi = 0; // 일시적으로 특정 상품의 총 판매수익을 저장
	int t_paymargin = 0;  // 일시적으로 특정 결제수단으로 처리된 총 판매수익을 저장

	FILE* f = fopen("o_report.txt", "w"); // o_report 파일을 쓰기 모드로 open
	
	// 분석에 사용하기 위한 데이터를 불러오는 부분
	size = order_count();
	order* order_list[MAX_SIZE];
	get_all_order(order_list); // 저장되어 있는 모든 주문정보를 이전에 선언한 배열 order_list로 가져옴
	
	// 주문리스트를 출력
    fputs("--------------------------------------------------------------------------------------------------------------\n", f);
	fputs("                                     <The List of Order Information>\n", f);
    fputs("--------------------------------------------------------------------------------------------------------------\n", f);
	for(i=0; i<size; i++){
		order* p = order_list[i];
		fprintf(f, "| %3d | ", i+1);
		fprintf(f,"%s\n", order_to_string(p)); // 전달받은 정보를 바탕으로 파일에 데이터 형식으로 저장
    }
	fputs("----------------------------------------------------------\n", f);
	// 총 수익합산 값 출력
	fputs("    <Report of margin>\n", f);
	fprintf(f, "%s %d\n", "Total Count : ", total_count()); // 총 주문수량 정보값을 파일에 다음의 형식으로 저장
	fprintf(f, "%s %d\n", "Total Margin : ", total_margin()); // 총 수익정보 값을 파일에 다음의 형식으로 저장
	fputs("----------------------------------------------------------\n", f);

	// 각 상품별 실적 및 관련정보 계산
	fputs("----------------------------------------------------------\n", f);
	fputs("         <The Information of each Product>\n", f);
	fputs("----------------------------------------------------------\n", f);
	for(i=0 ; i<5 ; i++){
		t_prod_count = 0; // 다시 해당변수를 활용하기 위해 0으로 초기화 - 1
		t_prod_margi = 0; // 다시 해당변수를 활용하기 위해 0으로 초기화 - 2
		for(j=0 ; j < order_count() ; j++){
			if(order_list[j]->prod == i+1){
				t_prod_count += order_list[j]->count; // 해당상품의 주문수량 정보를 가져옴
				t_prod_margi += order_list[j]->price; // 해당상품의 판매수익 정보를 가져옴
			}
		}
		fprintf(f, "%d. %-10s %5d(%4.1f%%) %10d(%4.1f%%)\n", i+1, convProd(i+1), 
			   t_prod_count, ((double)t_prod_count / total_count()) * 100,
			   t_prod_margi, ((double)t_prod_margi / total_margin()) * 100); // 상품에 대한 실적정보를 파일로출력
	}
	
	// 결제수단 별 실적 및 관련정보 계산
	fputs("----------------------------------------------------------\n", f);
	fputs("        <The Information of each Pay method>\n", f);
	fputs("----------------------------------------------------------\n", f);
	for(i=0 ; i<2 ; i++){
		t_paymargin = 0; // 다시 해당변수를 활용하기 위해 0으로 초기화
		for(j=0 ; j<order_count() ; j++){
			if(order_list[j]->pay == i+1)
				t_paymargin += order_list[j]->price; // 해당결제수단의 수익정보를 가져옴
		}
		fprintf(f, "%d. %-5s %5d(%4.1f%%)\n", i+1, convPay(order_list[i]->pay), 
		        t_paymargin, ((double)t_paymargin / total_margin() * 100));
	}
	printf("Report is make to \"o_report.txt\" file. \n"); // 정보저장이 성공적으로 이루어졌음을 알리는 메시지 출력
	fclose(f); // 파일 사용 종료 후 파일 close
}

void show_margin()
{
	printf("---------------------------------------------------\n");
	printf("           <Total order information>\n");
	// 구한결과를 화면상에 출력
	printf("---------------------------------------------------\n");
	printf("The total order : %d\n", order_count());                     // 총 주문건수 출력
	printf("The total selling count : %d\n", total_count());             // 총 판매수량 출력
	printf("The total margin of orders : %d Won\n", total_margin());     // 총 판매수익 출력
	printf("---------------------------------------------------\n");
}

void show_report()
{
	
	int size; // 저장되어 있는 주문정보의 수
	int i, j; // 반복문 변수
	int t_prod_count = 0; // 일시적으로 특정 상품의 총 주문수량을 저장
	int t_prod_margi = 0; // 일시적으로 특정 상품의 총 판매수익을 저장
	int t_paymargin = 0;  // 일시적으로 특정 결제수단으로 처리된 총 판매수익을 저장

	// 분석에 사용하기 위한 데이터를 불러오는 부분
	size = order_count();
	order* order_list[MAX_SIZE];
	get_all_order(order_list); // 저장되어 있는 모든 주문정보를 이전에 선언한 배열 order_list로 가져옴
	
	// 주문리스트를 출력
    printf("--------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                           <Order list Report>\n\n");
    printf("--------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                               <Order list>\n\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("| %3s | %.21s | %10s | %6s | %8s | %13s | %8s | %8s | %5s |\n", 
	                 "Num", "         Time         ", " Product ", "Amount", "   ID   ",  "    Phone    ", " Place ", " Price ", " Pay ");
    printf("--------------------------------------------------------------------------------------------------------------\n");
	for(i=0; i<size; i++){
		order* p = order_list[i];
		printf("| %3d |", i+1);
		printf("%s\n", order_to_string(p)); // 전달받은 정보를 바탕으로 파일에 데이터 형식으로 저장
    }
    printf("--------------------------------------------------------------------------------------------------------------\n\n");

	// 총 수익합산 값 출력
	printf("----------------------------------------\n");
	printf("           <Margin Report>            \n");
	printf("----------------------------------------\n");
	printf(" %s %d\n", "Total Count : ", total_count());    // 총 주문수량 정보값을 파일에 다음의 형식으로 저장
	printf(" %s %d\n", "Total Margin : ", total_margin());  // 총 수익정보 값을 파일에 다음의 형식으로 저장
	printf("----------------------------------------\n\n");

	// 각 상품별 실적 및 관련정보 계산
	printf("----------------------------------------------\n");
	printf("      <The Information of each Product>       \n");
	printf("----------------------------------------------\n");	
	for(i=0 ; i<5 ; i++){
		t_prod_count = 0; // 다시 해당변수를 활용하기 위해 0으로 초기화 - 1
		t_prod_margi = 0; // 다시 해당변수를 활용하기 위해 0으로 초기화 - 2
		for(j=0 ; j < order_count() ; j++){
			if(order_list[j]->prod == i+1){
				t_prod_count += order_list[j]->count; // 해당상품의 주문수량 정보를 가져옴
				t_prod_margi += order_list[j]->price; // 해당상품의 판매수익 정보를 가져옴
			}
		}
		printf("%d. %-10s %5d(%4.1f%%) %10d(%4.1f%%)\n", i+1, convProd(i+1), 
			   t_prod_count, ((double)t_prod_count / total_count()) * 100,
			   t_prod_margi, ((double)t_prod_margi / total_margin()) * 100); // 상품에 대한 실적정보를 파일로출력
	}
	printf("---------------------------------------------\n");
	
	// 결제수단 별 실적 및 관련정보 계산
	printf("----------------------------------------\n");
	printf("  <The Information of each Pay method>  \n");
	printf("----------------------------------------\n");
	for(i=0 ; i<2 ; i++){
		t_paymargin = 0; // 다시 해당변수를 활용하기 위해 0으로 초기화
		for(j=0 ; j<order_count() ; j++){
			if(order_list[j]->pay == i+1)
				t_paymargin += order_list[j]->price; // 해당결제수단의 수익정보를 가져옴
		}
		printf("%d. %-5s %5d(%4.1f%%)\n", i+1, convPay(order_list[i]->pay), t_paymargin, ((double)t_paymargin / total_margin() * 100));
	}
	printf("----------------------------------------\n");
}

void update_record()
{
	char id[30], phone[30], place[30];
	int prod, count, pay; // 제품코드, 수량
	int update_option; // 사용자 선택 update option 값
	
	// id를 이용하여 검색해 찾고자 하는 주문정보 탐색
	printf("Enter the order ID : ");
	scanf("%s", id);
	order* p = search_by_id(id); // id를 기반으로 해당하는 주소값 검색

	if(p == NULL) // 해당id를 가진 주문정보가 존재하지 않는 경우
	{
		printf("Error! : Can not search this id(%s)\n", id);
		return;
	}
	else // 해당 id를 가진 주문정보가 존재할 경우
	{
		// 사용자가 이용 가능한 update 옵션의 목록을 보여주고 선택
		printf("-------------------------------------------\n");
		printf("<Available update options>\n");
		printf("1. update(prod, count, phone, place, pay)\n");
		printf("2. update(product code, count)\n");
		printf("3. update(Phone number)\n");
		printf("4. update(place)\n");
		printf("5. update(Pay method)\n");	
		printf("-------------------------------------------\n");
		printf("Enter the update options : ");
		scanf("%d", &update_option); // updata option 값을 입력받음

		if(update_option == 1)
		{
			show_prod(); // 상품목록 출력
			printf("Enter the product code : ");
			scanf("%d", &prod);
			printf("Enter the product count : ");
			scanf("%d", &count);
			printf("Enter the phone : ");
			scanf("%s", phone);
			if(search_by_phone(phone) != NULL){ // 중복되는 연락처 입력에 대해서 거부
				printf("Duplicate Phone! \n");
				return;
			}
			printf("Enter the place : ");
			scanf("%s", place);	
    		printf("*********************************************\n");
   			printf("<The list of pay method>\n\n");
   			printf("1 - Card  2 - Cash\n");
   			printf("*********************************************\n");
   			printf("Enter the pay code : ");
			scanf("%d", &pay);
			order_update(p, prod, count, phone, place, pay);
			printf("Success! : Update is complete.\n");
		}
		else if(update_option == 2)
		{
			show_prod(); // 상품목록 출력
			printf("Enter the product code : ");
			scanf("%d", &prod);
			printf("Enter the product count : ");
			scanf("%d", &count);
			prod_update(p, prod, count); // 업데이트
			printf("Success! : Update is complete.\n");
		}
		else if(update_option == 3)
		{
			printf("Enter the phone : ");
			scanf("%s", phone);
			if(search_by_phone(phone) != NULL){ // 중복되는 연락처 입력에 대해서 거부
				printf("Duplicate Phone! \n");
				return;
			}
			phone_update(p, phone);
			printf("Success! : Update is complete.\n"); // 업데이트
		}
		else if(update_option == 4)
		{
			printf("Enter the place : ");
			scanf("%s", place);
			place_update(p, place); // 업데이트
			printf("Success! : Update is complete.\n");
		}
		else if(update_option == 5)
		{
			printf("*********************************************\n");
   			printf("<The list of pay method>\n\n");
   			printf("1 - Card  2 - Cash\n");
   			printf("*********************************************\n");
   			printf("Enter the pay code : ");
			scanf("%d", &pay);
			pay_update(p, pay); // 업데이트	
			printf("Success! : Update is complete.\n");
		}
		else
		{
			printf("Error! : Invalid option code\n");
		}
	}
}

void delete_record()
{
    if(order_count() == 0){ // 저장된 데이터가 없다면
        printf("Error! order info are not exist\n\n"); // 오류메시지 출력
        return; // 그리고 종료
    }	
	char id[30]; // 사용자가 입력하는 id값을 저장
	order* p; // 탐색되는 주문정보의 포인터값 저장

	printf("Enter the order ID : ");
	scanf("%s", id); // id값을 저장
	
	p = search_by_id(id); // 저장된 정보 중에 동일한 id값을 가진 정보탐색
	// id를 찾지 못한 경우
	if(p == NULL){ 
		printf("Error! : Can not find id(%s)\n", id);
		return;
	}
	order_delete(p); // 주문정보 삭제
	printf("Success! : delete is complete\n"); // 삭제완료 시 메시지 출력
	printf("If you want to use all function of this program, you have to use arrange function(option12)\n");
}

void arrange()
{
	gather_piece(); // 조각모음 수행
	printf("Adjustment is  complete!\n");
}

void order_sort()
{
	int sort_option; // 정렬옵션
	
	printf("<Available Sorting  Options>\n\n");
	printf("1. Sorting by time (ascending order)\n");
	printf("2. Sorting by time (descending order)\n");
	printf("3. Sorting by ID   (ascending order)\n");
	printf("4. Sorting by ID   (descending order)\n");
	printf("Enter the sorting options : ");
	scanf("%d", &sort_option);

	if(sort_option == 1)
	{
		sort_by_time_up();
		printf("Success! : Sorting is complete.\n");
	}
	else if(sort_option == 2)
	{
		sort_by_time_down();
		printf("Success! : Sorting is complete.\n");
	}
	else if(sort_option == 3)
	{
		sort_by_id_up();
		printf("Success! : Sorting is complete.\n");
	}
	else if(sort_option == 4)
	{
		sort_by_id_down();
		printf("Success! : Sorting is complete.\n");
	}
	else
	{
		printf("Error! : Invalid sorting option code.\n");
		return;
	}
	return;
}
