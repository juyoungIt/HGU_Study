// CH08_SchoolFriend.java
// 작성자 : 21700760 하주영

public class CH08_SchoolFriend extends CH08_Friend
{
	private String school; // 학교관 문장저장
	
	// default constructor
	public CH08_SchoolFriend()
	{
		super(); // friend값 초기화
		school = "None"; // school 값 초기화
	}
	
	// constructor
	public CH08_SchoolFriend(String s)
	{
		super(); // friend값 초기화
		school = s; // school 값 초기화
	}
	
	// school 값을 반환
	public String getSchool()
	{
		return school;
	}
	
	// 저장된 정보를 문자열로 변환
	public String toString()
	{
		return(getFrined() + "\nin s" + school);
	}
	
	// 저장된 정보를 출력
	public void whatfriend()
	{
		System.out.println(this.toString());
	}
}
