// CH11_RecursionCountOnes.java
// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH11_RecursionCountOnes
{
	public static void main(String[] args)
	{
		int number; // 사용자 입력 문자열 저장
		
		System.out.println("Enter a nonnegative number :");
		Scanner keyboard = new Scanner(System.in);
		number = keyboard.nextInt();
		
		System.out.println(number + " contains " + numberOfOnes(number) + " ones.");
		
		keyboard.close(); // keyborad object close
		System.exit(0); // 프로세스 종료
	}
	
	// 입력된 수가 포함하는 1의 갯수 출력
	public static int numberOfOnes(int n)
	{
		if(n<0) { // 음수가 입력된 경우
			System.out.println("Error! : Invalid inputs(negative number)");
			System.exit(-1); // 비정상적 종료를 의미하는 -1 반환
		}
		if(n==1)
			return 1;
		else if(n<10) // 0<n<10
			return 0;
		else if(n%10 == 1) // n>10
			return (numberOfOnes(n/10) + 1);
		else
			return (numberOfOnes(n/10));
	}
}
