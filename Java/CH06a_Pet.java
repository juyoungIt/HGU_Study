// CH06a_Pet.java
// 작성자 : 21700760 하주영

public class CH06a_Pet
{
	private String name;
	private int age; // in years
	private double weight; // in pounds
	
	public CH06a_Pet(String initialName, int initialAge, double initialWeight)
	{
		name = initialName; // 이름값 초기화
		if((initialAge < 0) || (initialWeight < 0)) // 예외처리, 음수값이 입력된 경우
			System.out.println("Error : Negative age or weight.");
		else {
			age = initialAge; // age값 초기화
			weight = initialWeight; // weight값 초기화
		}
	}
	
	// 이름만 입력받는 경우
	public CH06a_Pet(String initialName)
	{
		name = initialName;
		age = 0;
		weight = 0;
	}
	
	// 나이만 입력받는 경우
	public CH06a_Pet(int initialAge)
	{
		name = "No name yet.";
		if(initialAge < 0) // 예외처리,음수값이 입력된 경우
		{
			System.out.println("Error : Negative age.");
			age = 0;
		}
		else
			age = initialAge;
		
		weight = 0;
	}
	
	// 체중만 입력받을 경우
	public CH06a_Pet(double initialWeight)
	{
		name = "No name yet.";
		age = 0;
		if(initialWeight < 0) // 예외처리, 음수값이 입력된 경우
		{
			System.out.println("Error : Negative weight.");
			weight = 0;
		}
		else
			weight = initialWeight;
	}
	
	// default constructor, 입력받은 값이 없을 경우
	public CH06a_Pet()
	{
		name = "No name yet.";
		age = 0;
		weight = 0;
	}
	
	//저장된 instance value를 출력
	public void writeOutput()
	{
		System.out.println("Name : " + name);
		System.out.println("Age : " + age + " years");
		System.out.println("Weight : " + weight + " pounds");
	}
	
	// 이름 가져오기
	public String getName()
	{
		return name;
	}
	
	// 나이 가져오기
	public int getAge()
	{
		return age;
	}
	
	// 체중 가져오기
	public double getWeight()
	{
		return weight;
	}
}
