// CH06b_Suit.java
// 작성자 : 21700760 하주영

enum CH06b_Suit
{
	MON("red"), TUE("orange"), WED("yellow"), THU("green"), FRI("blue"), SAT("indigo"), SUN("purple");
	
	private final String color;
	
	private CH06b_Suit(String SuitColor)
	{
		color = SuitColor;
	}
	
	public String getColor()
	{
		return color;
	}
}
