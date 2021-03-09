// CH08_History.java
// 작성자 : 21700760 하주영

public class CH08_History extends CH08_Book
{
	private String author; // 저자명
	
	// default constructor
	public CH08_History()
	{
		super(); // name을 초기화
		author = "No author name yet"; // 저자명 초기화
		setId(); // id값을 초기화
	}
	
	// Constructor
	public CH08_History(String s1, String s2)
	{
		super(s1); // name을 초기화
		author = s2; // 저자명 초기화
		setId(); // id값을 초기화
	}
	
	// 저자명 반환
	public String getAuthor()
	{
		return author;
	}
	
	// 저장된 정보를 문자열 형태로 반환
	public String toString()
	{
		return("<<<History>>>\n" + "Id: " + getId() + "\nBook Name: " + getName() + "\nAuthor: " + getAuthor());
	}
	
	// 저장된 정보를 출력
	public void print()
	{
		System.out.println(this.toString());
	}
}
