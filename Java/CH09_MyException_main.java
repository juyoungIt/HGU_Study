// CH09_MyException_main.java
// 작성자 : 21700760 하주영

import java.util.Scanner;
public class CH09_MyException_main
{
	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		
		try
		{
			String str = kb.nextLine();
			Mytest(str);
		}
		catch(CH09_MyException mae)
		{
			System.out.println(mae);
		}
		kb.close();
	}
	
	static void Mytest(String str) throws CH09_MyException
	{
		if(str.indexOf("$") != -1) // 입력받은 문자열이 '$'문자를 포함하는 경우
			throw new CH09_MyException();
		else // '$'를 포함하지 않는 문자열이 입력된 경우
			System.out.println("String :" + str);
	}
}
