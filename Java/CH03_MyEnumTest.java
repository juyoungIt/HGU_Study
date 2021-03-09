// 작성자 : 21700760 하주영

public class CH03_MyEnumTest
{
	enum Weeks 
	{
		MON, TUE, WED, THR, FRI, SAT, SUN
	};
	
	public static void main(String []args)
	{
		Weeks[] arr = Weeks.values();
		for(Weeks days : arr)
		{
			switch(days)
			{
			case MON:
				System.out.println("Monday!");
				break;
			case TUE:
				System.out.println("Tuesday!");
				break;
			case WED:
				System.out.println("Wednesday!");
				break;
			case THR:
				System.out.println("Thursday!");
				break;
			case FRI:
				System.out.println("Friday!");
				break;
			case SAT:
				System.out.println("Saturday!");
				break;
			case SUN:
				System.out.println("Sunday!");
				break;
			default:
				System.out.println("Something is wrong"); // 정의한 범위 밖의 값이 입력될 경우에 대한 예외처리
			}
					
		}
		System.exit(0); // 프로그램 종료
	}
}
