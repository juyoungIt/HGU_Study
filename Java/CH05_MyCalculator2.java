// #1. CH05_MyCalculator2
// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH05_MyCalculator2
{
	private int a;
	private int b;

	// 사용자로부터 2개의 정수 입력
	public void getinput()
	{
		Scanner keyboard = new Scanner(System.in);
		printmenu(); // 메뉴바 출력
		System.out.print("Type 1st Num : ");
		a = keyboard.nextInt(); // 정수 a 입력받기
		System.out.print("Type 2nd Num : ");
		b = keyboard.nextInt(); // 정수 b 입력받기
	}
	
	//계산결과를 출력
	public void printresult()
	{
		System.out.println("a + b = " + addition());
		System.out.println("a - b = " + subtraction());
		System.out.println("a * b = " + multiplication());
		System.out.println("a / b = " + division());
	}
	
	// 프로그램 관련 menu를 출력
	private void printmenu()
	{
		System.out.println("*** CH05_MyCalculator2 ***");
	}
	
	// 덧셈
	private double addition()
	{
		return a+b;
	}
	// 뺄셈
	private double subtraction()
	{
		return a-b;
	}
	// 곱셈
	private double multiplication()
	{
		return a*b;
	}
	// 나눗셈
	private double division()
	{
		return a/b;
	}
}

