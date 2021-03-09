// CH12_NumIntegers.java
// 작성자 : 21700760 하주영

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;

public class CH12_NumIntegers
{
	private HashSet<Integer> intSet = new HashSet<Integer> ();
	
	public void readdata(String f_name)
	{
		Scanner inputStream = null;
		
		try
		{
			inputStream = new Scanner(new File(f_name)); // inputStream 생성
			String line; // 파일에서 읽어오는 값
			while(inputStream.hasNextLine())
			{
				line = inputStream.nextLine(); // 파일을 한 라인값을 읽어옴
				intSet.add(Integer.parseInt(line)); // 값 전달
			}
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Error opening the file " + f_name);
			System.exit(-1);
		}
	}
	
	public void printIntegers()
	{
		for(Object obj : intSet.toArray())
		{
			Integer num = (Integer)obj;
			System.out.print(num + " ");
		}
	}
	
	public int getNumIntegers()
	{
		int count; // intSet의 원소수 저장
		count = intSet.size(); // 저장된 원소 수 산출
		return count;
	}
}
