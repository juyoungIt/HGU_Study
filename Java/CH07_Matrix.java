// #1. CH07_Matrix.java
// 작성자 : 21700760 하주영

public class CH07_Matrix
{
	public static void makeMatrix(int[][] arr)
	{
		int i, j; // 반복문 변수
		
		for(i=0 ; i<arr.length ; i++)
			for(j=0 ; j<arr[0].length ; j++)
				arr[i][j] = i+j; // 값의 대입
	}
	
	public static void printMatrix(int[][] arr)
	{
		int i, j; // 반복문 변수
		
		for(i=0 ; i<arr.length ; i++)
		{
			for(j=0 ; j<arr[0].length ; j++)
			{
				if(j == arr[0].length - 1)
					System.out.println(arr[i][j]); // 마지막인 경우 개행문자를 삽입하여 출력
				else
					System.out.print(arr[i][j] + " "); // 마지막이 아닌 경우 개행문자를 포함하지 않고 공백은 포함하여 출력
			}
		}
	}
}