// CH06b_EnumTest.java
// 작성자 : 21700760 하주영

public class CH06b_EnumTest
{
	public static void main(String[] args)
	{
		CH06b_Suit s = CH06b_Suit.FRI;
		System.out.println("s.ordinal()="+s.ordinal());
		
		System.out.println("s.compareTo(Suit.WED)="+s.compareTo(CH06b_Suit.WED));
		System.out.println("s.toSting()="+s.toString());
		System.out.println("s.getColor() = "+s.getColor());
		
		// 저장된 값을 반복문을 이용하여 모두 출력
		for(CH06b_Suit status : CH06b_Suit.values())
			System.out.println(status + "  " + status.getColor());
	}
}
