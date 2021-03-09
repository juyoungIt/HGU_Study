// #3. CH07_Morse.java
// 작성자 : 21700760 하주영

public class CH07_Morse
{
	private static String[] morse = {"o-", "-ooo", "-o-o","-oo","o",
			"oo-o","--o","oooo","oo","o---", 
			"-o-","o-oo","--","-o","---", 
			"o--o","--o-","o-o","ooo","-", 
			"oo-","ooo-","o--","-oo-","-o--","--oo"};
	
	public static String convert(String word)
	{
		String result = new String(); // 변환된 문자열을 저장
		char[] alpha = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M' ,'N',
				'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		int i, j; // 반복문 변수
		
		// 입력받은 문자열을 모스부호로 변환시키는 부분
		for(i=0 ; i<word.length() ; i++)
		{
			for(j=0 ; j<alpha.length; j++)
				if(word.charAt(i) == alpha[j])
					result += morse[j]; // 해당문자에 해당하는 모스부호를 찾아서 결과 문자열에 넣는다.
		}
		return result;
	}

}
