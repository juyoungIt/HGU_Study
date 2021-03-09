// CH04_MySummation.java
// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH04_MySummation
{
	public static void main(String[] args)
	{
		Scanner keyboard = new Scanner(System.in);     // 사용자로부터 값을 입력받을 수 있는 object keyboard 생성
		System.out.println("Pleas input a number : "); // 정수값의 입력을 요구하는 메시지 출력
		int num = keyboard.nextInt(); // 사용자로부터 정수값 1개를 입력받아 int형 변수 num에 저장
		
		// 예외처리, 0 또는 음수가input data로 입력될 경우
		if(num < 1) {
			System.out.println("Error! : Invalid input data"); // input값의 오류를 알리는 메시지 출력
			System.exit(-1); // 프로그램 종료, 비정상적인 종료를 의미하는 -1 반환하며 종료
		}
	
		int sum = 0; // 1부터 사용자가 입력한 정수까지의 합산값 저장
		for(int i=0 ; i<num ; i++)
			sum += (i+1); // 1부터 사용자입력 정수까지 순서대로 합산
		
		System.out.println("The summation from 1 to " + num + " is\n" + sum); // 계산결과를 출력
		System.exit(0); // 결과 출력 후 프로그램을 종료
	}
}
