// CH08_Book.java
// 작성자 : 21700760 하주영

public class CH08_Book
{
	private String name; // 책의 이름
	private int id; // ID값
	private static int save_id; // Id값을 누적해서 저장하기 위한 변수
	
	// default constructor
	public CH08_Book()
	{
		name = "No name yet"; // 이름 초기화
		save_id++; // id의 누적값을 1증가
		setId(); // id 초기화
	}
	
	// constructor
	public CH08_Book(String s)
	{
		name = s; // 초기에 입력받은 값으로 이름값 초기화
		save_id++; // id의 누적값을 1증가
		setId(); // id 초기화
	}
	
	// name 값을 반환
	public String getName()
	{
		return name;
	}
	
	// id값을 반환
	public int getId()
	{
		return id;
	}
	
	// id값을 1증가
	public void setId()
	{
		id = save_id;
	}
	
	// 저장된 정보를 문자열 형태로 반환
	public String toString()
	{
		return("<<<BOOK>>>\n" + "Id: " + id + "\nBook Name: " + name);
		
	}
	
	// 저장된 정보를 출력
	public void print()
	{
		System.out.println(this.toString());
	}
}
