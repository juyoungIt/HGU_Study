// CH04_MyDrawing.java
// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH04_MyDrawing
{
	public static void main(String[] args)
	{
		Scanner keyboard = new Scanner(System.in); // 사용자로부터 값을 입력받을 수 있는 object keyboard 생성
		System.out.println("Please input a number : ");
		int num = keyboard.nextInt(); // 사용자로부터 수 하나를 입력받아 int형 변수 num에 저장
		
		// 예외처리, 0 또는 음수가input data로 입력될 경우
		if(num < 1) {
			System.out.println("Error! : Invalid input data"); // input값의 오류를 알리는 메시지 출력
			System.exit(-1); // 프로그램 종료, 비정상적인 종료를 의미하는 -1 반환하며 종료
		}
		
		int repeat; // 반복횟수와 관련된 정수값을 저장하는 변수
		// 반복문을 이용하여 문자를 그리는 부분
		for(int i=0 ; i<num*2 ; i++)
		{
			// 현재 문자를 그리는 라인이 몇번째 인지에 따라서 반복횟수값이 결정됨
			if(i < num) // 그리는 라인이 2n 이전의 경우
				repeat = i+1;
			else        // 그리는 라인이 2n 이후인 경우
				repeat = num*2-i;
			for(int j=0 ; j<repeat ; j++)
				System.out.print("*"); // * 문자를 출력함
			System.out.print("\n"); // 해당라인에 해당하는 문자를 모두 적은 경우 개행문자를 삽입하여 라인을 변경
		}
	}
}
