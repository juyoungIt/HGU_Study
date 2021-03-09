// CH06a_Neo.java
// 작성자 : 21700760 하주영

public class CH06a_Neo
{
	private String emoticons; // 관련 문자열을 저장
	private static int howmany = 0; // 저장된 감정의 수 저장(static variable), 여러 객체들이 공
	
	public CH06a_Neo(String emoticon)
	{
		emoticons = "Neo is " + emoticon + '.';
		howmany++; // 저장된 감정의 수 1증가
	}
	
	// 저장된 문자열을 출력
	public void EmoticonStyle()
	{
		System.out.println(emoticons);
	}
	
	// howmany값 가져오기
	public static int gethowmany()
	{
		return howmany;
	}
}
