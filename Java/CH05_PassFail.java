// #3. CH05_PassFail
// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH05_PassFail
{
	private String name;
	private int score;
	
	// 해당 object의 Pass or Fail 결과값을 판정하여 출력
	public void writeoutput()
	{
		String grade; // 성적값을 저장
		if(score > 50)
			grade = "Pass";
		else
			grade = "Fail";
		System.out.println(name + ": " + score + ": " + grade);
	}
	
	public String getName()
	{
		return name; // 이름반환
	}
	
	public int getScore()
	{
		return score; // 정수반환
	}
	
	// 해당 object에 대한 name, score값 초기화
	public void setdata(String s_name, int s_score)
	{
		name = s_name; // 이름저장
		score = s_score; // 점수저장
	}
	
	// 해당 object와 입력된 object가 같은 값을 가지는 지 판정
	public Boolean equals(CH05_PassFail in_object)
	{
		if(this.name.equals(in_object.name) && this.score == in_object.score)
			return true;
		else
			return false;
	}
	
	public void copyFrom(CH05_PassFail in_object)
	{
		this.name = in_object.name;
		this.score = in_object.score;
	}
	
	public static void identifyOrSamevalue(CH05_PassFail student1, CH05_PassFail student2)
	{
		
		// 두 object의 레퍼런스에 대한 비교
		if(student1 == student2)
			System.out.println("Student1 and Studnet2 are Same object, Same Hashcode");
		else
			System.out.println("Student1 and Studnet2 are differnt object, differnt Hashcode");
				
		// 단순히 두 object의 값에 대한 비교
		if(student1.equals(student2))
			System.out.println("Student1 and Studnet2 have Same state, Same value of instance variable");
		else
			System.out.println("Student1 and Studnet2 have differnt value of instance variable");
	}
}
