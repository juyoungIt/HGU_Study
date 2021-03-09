// CH08_Friend.java
// 작성자 : 21700760 하주영

public class CH08_Friend
{
	private String friend; // 친구관련 문장저장
	
	// default constructor
	public CH08_Friend()
	{
		friend = "We are friends."; // friend값 초기화
	}
	
	// friend 값을 반환
	public String getFrined()
	{
		return friend;
	}
	
	// 저장된 정보를 문자열로 변환
	public String toString()
	{
		return(friend);
	}
	
	// 저장된 정보를 출력
	public void whatfriend()
	{
		System.out.println(this.toString());
	}
}
