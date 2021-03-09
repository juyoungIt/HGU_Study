// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH03_MyCompareTo
{
	public static void main(String[] args) {
		String s1; // 문자열 1
		String s2; // 문자열 2
		String t;  // 반복여부 판별문
		
		do
		{
			System.out.println("Please input two words : ");
			Scanner keyboard = new Scanner (System.in);
			s1 = keyboard.next( ); // 문자열 1 입력
			s2 = keyboard.next( ); // 문자열 2 입력
			
			if (s1.compareTo(s2)<0)
				System.out.println( s1+" is before "+s2); // 비교결과 출력 - 1
			else if (s1.compareTo(s2)>0)
				System.out.println(s1+" is after "+s2);  // 비교결과 출력 - 2
			else 
				System.out.println(s1+" is equals! "+s2); // 비교결과 출력 - 3
			System.out.println("Want you and the program?"); // 반복여부문자 요청
			System.out.println("Enter y for yes or n for no.");
			t = keyboard.next(); // 반복여부문자 입력
		}while(!t.equals("n")); // 반복여부 검사
		System.out.println("end the program!!"); // 프로그램 종료를 알림
		System.exit(0); // 프로그램 종료
	}
}