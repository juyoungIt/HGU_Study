// CH10_TimesTable.java
// 작성자 : 21700760 하주영

import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class CH10_TimesTable
{
	public static void main(String[] args)
	{
		String fileName = "ThreeTimesTable.txt"; // 파일명 지정
		
		PrintWriter outputStream = null; // output stream 생성
		try
		{
			outputStream = new PrintWriter(fileName);
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Error opening the file " + fileName);
			System.exit(-1);
		}
		
		System.out.println("I am writing the 3 times table...");
		outputStream.println("3 times table\n");
		for(int i=0 ; i<9 ; i++)
			outputStream.println((i+1) + " * 3 = " + (i+1)*3); // 계산결과를 파일로 출력
		outputStream.close(); // outputStream을 close
		System.out.println("3 times table was created in " + fileName); // 파일저장 종료 및 저장파일명을 알리는 메시지출력
		System.exit(0); // 프로그램 종료
	}
}
