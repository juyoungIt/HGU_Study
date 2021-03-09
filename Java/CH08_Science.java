// CH08_Science.java
// 작성자 : 21700760 하주영

public class CH08_Science extends CH08_Book
{
	private String publisher; // 출판
	
	// default constructor
	public CH08_Science()
	{
		super(); // name을 초기화			
		publisher = "No publisher yet"; // 저자명 초기화
		setId();
	}
	
	// default constructor
	public CH08_Science(String s1, String s2)
	{		
		super(s1); // name을 초기화			
		publisher = s2; // 저자명 초기화
		setId();
	}
	
	// 출판사 정보 반환
	public String getPublisher()
	{
		return publisher;
	}
	
	// 저장된 정보를 문자열 형태로 반환
	public String toString()
	{
		return("<<<Science>>>\n" + "Id: " + getId() + "\nBook Name: " + getName() + "\nPublisher: " + getPublisher());
	}
		
	// 저장된 정보를 출력
	public void print()
	{
		System.out.println(this.toString());
	}
}
