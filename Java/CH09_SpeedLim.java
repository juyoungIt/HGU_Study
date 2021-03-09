// CH09_SpeedLim.java
// 작성자 : 21700760 하주영

public class CH09_SpeedLim
{
	private int limit; // 속도제한값 저장
	private int speed; // 현재속도값 저장
	
	// default constructor
	public CH09_SpeedLim()
	{
		limit = -1; // 속도제한값 초기화
		speed = -1; // 현재속도값 초기화
	}
	
	// constructor
	public CH09_SpeedLim(int n1, int n2)
	{
		limit = n1; // 속도제한값 초기화
		speed = n2; // 현재속도값 초기화
	}
	
	// 입력한 값들에 대한 판독정보를 출력
	public void SpeedWarning()
	{
		try
		{
			if(limit < speed) //현재속도가 제한속도를 초과한 경우
				throw new Exception("Speed Limit " + limit + "km " + "exceeded!");
			else // 현재속도가 제한속도 범위 내인 경우
			{
				System.out.println("You are a law abiding");
				System.out.println("citizen!");
			}
		}
		catch(Exception e) // 제한속도를 초과한 경우에 대한 예외처리
		{
			System.out.println(e.getMessage()); // 전달받은 메시지 출력
			System.out.println("You are being fined.");
		}
		System.out.println("Your current speed: " + speed); // 현재속도값을 출력
	}
}
