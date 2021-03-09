// CH11_Palindrome_main.java
// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH11_Palindrome_main
{
	public static void main(String[] args)
	{
		String str1; // 사용자 입력 문자열 저장
		Scanner keyboard = new Scanner(System.in); // Scanner object 생성
		
		System.out.print("Enter a string: ");
		str1 = keyboard.nextLine(); // 문자열 입력
		
		if(is_palindrome(str1, 0, str1.length()-1))
			System.out.println(str1 + " is a palindrome.");
		else
			System.out.println(str1 + " is not a palindrome.");
		
		keyboard.close(); // object keyboard close
		System.exit(0); // 프로세스 종료
	}
	
	// 해당 인덱스 범위 사이의 문자열이 Palindrome 인지 판별
	public static boolean is_palindrome(String str, int index1, int index2)
	{
		String t_str = str.toLowerCase(); // 모든 문자를 소문자로 바꾼 문자열을 저장
		
		if(index1 == index2 || index1>index2) // index1, 2가 서로 만나거나 교차된 경우
			return true;
		else
		{
			// 서로 대응하는 문자인 경우 - 대소문자 구분X
			if(t_str.charAt(index1) == t_str.charAt(index2))
				return is_palindrome(str, index1+1, index2-1); // 범위를 줄여서 나머지 범위에 대한 check(Recursion)
			else // 서로 대응하지 않는 문자인 경우
				return false;
		}
	}
}
