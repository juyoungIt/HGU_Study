// CH02_BasicComputation
// #2 MyKoreanChangeMaker.java
// 21700760 하주영

import java.util.Scanner;

public class MyKoreanChangeMaker
{
    public static void main (String []args)
    {
        Scanner keyboard = new Scanner(System.in);
        int originalAmount; // 사용자에게 입력받은 금액
        int amount;         // 다음 단위로 넘겨주는 나머지 값을 일시저장

        // 금액값을 입력받아 저장
        System.out.println("Enter a whole number from 1 to 10000.");
        originalAmount = keyboard.nextInt();
        System.out.println(originalAmount+" won in coins can be given as : ");

        // 계산을 통해서 필요한 동전의 수를 구하여 출력
        System.out.println(originalAmount/500 + " 500 won");
        amount = originalAmount%500;
        System.out.println(amount/100 + " 100 won");
        amount %= 100;
        System.out.println(amount/10 + " 10 won");
        amount %= 10;
        System.out.println(amount/5 + " 5 won");
        amount %= 5;
        System.out.println(amount + " 1 won");
    }
}
