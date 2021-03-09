// CH02_BasicComputation
// #3 MyStringDemo.java
// 21700760 하주영

public class MyStringDemo
{
    public static void main(String []args)
    {
        String sentence = "Jesus Christ Is My Savior";
        int position = sentence.indexOf("Savior");

        System.out.println(sentence);
        System.out.println("012345678901234567890123456");
        System.out.println("The word \"Savior\" starts at index " + position);

        // first change
        sentence = sentence.substring(0, position) + "friend";
        System.out.println("The changed string is:");
        System.out.println(sentence);

        // second change
        sentence = sentence.replace("friend", "joy");
        sentence = sentence.toUpperCase(); // 대문자로 변환
        System.out.println("The changed string is:");
        System.out.println(sentence);
    }
}
