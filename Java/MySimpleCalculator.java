// CH02_BasicComputation
// #1 MySimpleCalculator.java
// 21700760 하주영

import java.util.Scanner;

public class MySimpleCalculator
{
    public static void main(String []args)
    {
        Scanner keyboard = new Scanner(System.in);
        int num1, num2; // 사용자에게 입력받는 정수저장

        // 2개의 정수 입력받기
        System.out.println("Please input two numbers.");
        num1 = keyboard.nextInt();
        num2 = keyboard.nextInt();

        // 입력받은 수들을 바탕으로 계산하여 그 결과를 출력
        System.out.println("a + b = " + (num1+num2));
        System.out.println("a - b = " + (num1-num2));
        System.out.println("a * b = " + (num1*num2));
        System.out.println("a / b = " + (num1/num2));
    }
}