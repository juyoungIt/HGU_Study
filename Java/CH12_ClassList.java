// CH12_ClassList.java
// 작성자 : 21700760 하주영

import java.util.ArrayList;

public class CH12_ClassList
{
	private ArrayList<String> list = new ArrayList<String> ();
	
	public void add(String str)
	{
		list.add(str);
	}
	
	public void Print()
	{
		int i = 1; // 반복문 변수
		System.out.println("\nList of classes");
		for(String s : list)
		{
			System.out.print("class " + i++ + ": ");
			System.out.println(s); // 저장내용 출력
		}
	}
}
