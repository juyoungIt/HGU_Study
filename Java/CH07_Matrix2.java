// #2. CH07_Matrix2.java
// 작성자 : 21700760 하주영

public class CH07_Matrix2
{
	public static void makeMatrix2(int[][] arr)
	{
		int i, j; // 반복문 변수
		
		for(i=0 ; i< arr.length ; i++)
		{
			for(j=0 ; j<arr[0].length ; j++)
			{
				if(i == 0)
					arr[i][j] = 1*(j+1);
				else
					arr[i][j] = arr[i-1][arr[0].length-1] + (j+1);
			}
		}
	}
	
	public static void addition(int[][] arr1, int[][] arr2)
	{
		int[][] result_arr = new int [arr1[0].length][arr1.length]; // 결과값을 저장할 배열선언
		int i, j; // 반복문 변수
		
		// 계산하여 새로운 배열에 저장
		for(i=0 ; i<arr1.length ; i++)
			for(j=0 ; j<arr1[0].length ; j++)
				result_arr[i][j] = arr1[i][j] + arr2[i][j];
		
		// 새롭게 생성한 배열의 값들을 출력
		System.out.println("\nMatrix addition is ..");
		for(i=0 ; i<arr1.length ; i++)
		{
			for(j=0 ; j<arr1[0].length ; j++)
			{
				if(j == result_arr[0].length - 1)
					System.out.println(result_arr[i][j]); // 마지막인 경우 개행문자를 삽입하여 출력
				else
					System.out.print(result_arr[i][j] + " "); // 마지막이 아닌 경우 개행문자를 포함하지 않고 공백은 포함하여 출력
			}
		}
	}
	
	public static void subtraction(int[][] arr1, int[][] arr2)
	{
		int[][] result_arr = new int [arr1[0].length][arr1.length]; // 결과값을 저장할 배열선언
		int i, j; // 반복문 변수
		
		// 계산하여 새로운 배열에 저장
		for(i=0 ; i<arr1.length ; i++)
			for(j=0 ; j<arr1[0].length ; j++)
				result_arr[i][j] = arr1[i][j] - arr2[i][j];
		
		// 새롭게 생성한 배열의 값들을 출력
		System.out.println("\nMatrix subtraction is ..");
		for(i=0 ; i<arr1.length ; i++)
		{
			for(j=0 ; j<arr1[0].length ; j++)
			{
				if(j == result_arr[0].length - 1)
					System.out.println(result_arr[i][j]); // 마지막인 경우 개행문자를 삽입하여 출력
				else
					System.out.print(result_arr[i][j] + " "); // 마지막이 아닌 경우 개행문자를 포함하지 않고 공백은 포함하여 출력
			}
		}
	}
	
	public static void multiplication(int[][] arr1, int[][] arr2)
	{
		int[][] result_arr = new int [arr1[0].length][arr1.length]; // 결과값을 저장할 배열선언
		int i, j, k; // 반복문 변수
		
		// 계산하여 새로운 배열에 저장
		for(i=0 ; i<arr1.length ; i++)
		{
			for(j=0 ; j<arr1[0].length ; j++)
			{
				k=0;
				while(k<arr1.length)
				{
					result_arr[i][j] += arr1[i][k] * arr2[k][j];
					k++;
				}
			}
		}
			
		// 새롭게 생성한 배열의 값들을 출력
		System.out.println("\nMatrix multiplication is ..");
		for(i=0 ; i<arr1.length ; i++)
		{
			for(j=0 ; j<arr1[0].length ; j++)
			{
				if(j == result_arr[0].length - 1)
					System.out.println(result_arr[i][j]); // 마지막인 경우 개행문자를 삽입하여 출력
				else
					System.out.print(result_arr[i][j] + " "); // 마지막이 아닌 경우 개행문자를 포함하지 않고 공백은 포함하여 출력
			}
		}
	}
}
