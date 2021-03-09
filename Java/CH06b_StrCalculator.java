// CH06b_StrCalculator.java
// 작성자 : 21700760 하주영

public class CH06b_StrCalculator
{
	public static double operation(int n1, char operator, int n2)
	{	
		// 입력된 연산자 판별, 적절한 연산수행
		if(operator == '+') return n1+n2;
		if(operator == '-') return n1-n2;
		if(operator == '*') return n1*n2;
		if(operator == '/') return (double)n1/n2;
		else // 예외처리, 정의된 연산자 이외의 값이 입력된 경우
		{
			System.out.println("Error! : Invalid operator.");
			return 0; // 에러메시지가 출력된 후 출력되는 값 0은 무의미한 값으로 간주
		}
	}
	
	public static double operation(String n1, char operator, String n2)
	{
		// 입력된 문자열을 연산이 가능한 수로 변환
		double num1 = Double.valueOf(n1);
		double num2 = Double.valueOf(n2);
		
		// 입력된 연산자 판별, 적절한 연산수행
		if(operator == '+') return num1+num2;
		if(operator == '-') return num1-num2;
		if(operator == '*') return num1*num2;
		if(operator == '/') return num1/num2;
		else // 예외처리, 정의된 연산자 이외의 값이 입력된 경우
		{
			System.out.println("Error! : Invalid operator.");
			return 0; // 에러메시지가 출력된 후 출력되는 값 0은 무의미한 값으로 간주
		}
	}
	
	public static double operation(double n1, char operator, double n2)
	{	
		// 입력된 연산자 판별, 적절한 연산수행
		if(operator == '+') return n1+n2;
		if(operator == '-') return n1-n2;
		if(operator == '*') return n1*n2;
		if(operator == '/') return n1/n2;
		else // 예외처리, 정의된 연산자 이외의 값이 입력된 경우
		{
			System.out.println("Error! : Invalid operator.");
			return 0; // 에러메시지가 출력된 후 출력되는 값 0은 무의미한 값으로 간주
		}
	}
}
