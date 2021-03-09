// CH08_ClassFriend.java
// 작성자 : 21700760 하주영

public class CH08_ClassFriend extends CH08_SchoolFriend
{
	private String s_class; // class 관련 문장저장
	
	// default constructor
	public CH08_ClassFriend()
	{
		super(); // school값 초기화
		s_class = "None"; // s_class 값 초기화
	}
	
	// constructor
	public CH08_ClassFriend(String s1, String s2)
	{
		super(s1); // school 값 초기화
		s_class = s2; // s_class 값 초기화
	}
	
	// 저장된 s_class 값을 반환
	public String getSClass()
	{
		return s_class;
	}
	
	// 저장된 정보를 문자열로 변환
	public String toString()
	{
		return(getFrined() + "\nin " + getSchool() + "\nin " + s_class);
	}
	
	// 저장된 정보를 출력
	public void whatfriend()
	{
		System.out.println(this.toString());
	}
}
