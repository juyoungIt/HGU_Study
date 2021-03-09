// CH10_Grader.java
// 작성자 : 21700760 하주영

import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class CH10_Grader
{
	public static void run(String in, String out)
	{	
		Scanner inputStream = null;
		PrintWriter outputStream = null;
		try
		{	
			inputStream = new Scanner(new File(in)); // inputStream 생성
			outputStream = new PrintWriter(out); // outputStream 생성
			
			String line = inputStream.nextLine(); // header 라인 읽어내기
			outputStream.println(line); // header 라인 내용 파일에 추가
			
			int java_sum = 0;     // 학생들 java 점수에 대한 총 합산값
			int ds_sum = 0;       // 학생들 Data Structure 점수에 대한 총 합산값
			int oss_sum = 0;      // 학생들 OpenSoruce 점수에 대한 총 합산값
			int cal1_sum = 0;     // 학생들 cal1 점수에 대한 총 합산값
			double avg_sum = 0.0; // 학생들 평균에 대한 총 합산값
			while(inputStream.hasNextLine())
			{
				line = inputStream.nextLine(); // 나머지 라인들 읽어내기
				String[] a = line.split(",");
				outputStream.print(line);
				
				int sum = 0; // 각 과목별 점수의 합
				for(int i=2 ; i<6 ; i++)
					sum += Integer.parseInt(a[i]);
				double avg = (double)sum / 4; // 평균값 산출
				outputStream.println("," + avg);
				
				java_sum += Integer.parseInt(a[2]); // java 점수에 대한 합산값 산출
				ds_sum += Integer.parseInt(a[3]);   // Data Structure 점수에 대한 합산값 산출
				oss_sum += Integer.parseInt(a[4]);	// Open Source 점수에 대한 합산값 산출
				cal1_sum += Integer.parseInt(a[5]); // cal1 점수에 대한 합산값 산출
				avg_sum += avg; // 각 학생의 평균에 대한 합산값 산
			}
			outputStream.print("Average,000000,");
			outputStream.print((double)java_sum / 8 + ",");
			outputStream.print((double)ds_sum / 8 + ",");
			outputStream.print((double)oss_sum / 8 + ",");
			outputStream.print((double)cal1_sum / 8 + ",");
			outputStream.println(avg_sum / 8);
		}
		catch(FileNotFoundException e) // open을 시도한 파일이 존재하지 않는 경우
		{
			System.out.println("Error opening the file " + in);
			System.exit(-1);
		}
		outputStream.close();
		inputStream.close();
	}
}
