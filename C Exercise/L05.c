#include <stdio.h>
#include <math.h>

int fibonacci(int x); // 함수 fibonacci의 선언

main()
{
	float ratio; // 현제 회차의 비율값을 저장할 변수선언
	float pre_ratio; // 이전 회차의 비율값을 저장할 변수선언
	int count = 0; // 몇번째 비율인지에 대한 값을 저장하는 변수선언

	while (1)
	{
		ratio = fibonacci(count + 2) / (float)fibonacci(count + 1); // 함수 fibonacci의 호출
		printf("%d번째 비율 (%d / %d) : %f\n", count + 2, fibonacci(count + 2), fibonacci(count + 1), ratio);
		if (count == 0){
			count++;
			pre_ratio = ratio; // 현재 회차의 비율값을 이전회차의 비율값으로 인가, 새로운 비율을 구할 준비.
			continue; // 만약 첫번째 시행이라면 이전비율과의 체크 없이 다음회차로 넘어감.
		}
		else {
			if (fabs(ratio - pre_ratio) < 0.000001) break;
			pre_ratio = ratio; // 현재 회차의 비율값을 이전회차의 비율값으로 인가, 새로운 비율을 구할 준비.
		}
		count++;
	}
}

// 함수 fibonacci의 정의부
int fibonacci(int x)
{
	if (x == 0)
		return 1;
	else if (x == 1)
		return 1;
	else
		return fibonacci(x - 2) + fibonacci(x - 1);
}