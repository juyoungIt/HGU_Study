import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String opcode;    // store operation code from user input
        int op1, op2;     // operands
        int calCount = 1; // the number of calculation

        // set the operation server
        Operation add = new Addition("Addition", "add");
        Operation sub = new Subtraction("Subtraction", "sub");
        Operation mult = new Multiplication("Multiplication", "mult");
        Operation div = new Division("Division", "div");

        Scanner keyBoard = new Scanner(System.in); // set the scanner for keyboard input

        // build chain (add -> sub -> mult -> div)
        add.setNext(sub).setNext(mult).setNext(div);

        // Execute Infinity Loop for testing
        while(true) {
            System.out.println("Calculation: " + calCount);
            System.out.print("Enter Operation Name: ");
            opcode = keyBoard.nextLine();
            // Exception Handling - in case of opcode error
            if(!opcode.equals(add.getOpcode()) && !opcode.equals(sub.getOpcode())
                    && !opcode.equals(mult.getOpcode()) && !opcode.equals(div.getOpcode())) {
                System.out.println("Error! - please try again. (Opcode Error)");
                System.out.println("============================="); // for readability
                continue;
            }
            System.out.print("Enter the First Operand: ");
            op1 = keyBoard.nextInt();
            keyBoard.nextLine(); // clean the input buffer - 1
            System.out.print("Enter the Second Operand: ");
            op2 = keyBoard.nextInt();
            keyBoard.nextLine(); // clean the input buffer - 2

            add.operation(new Number(opcode, op1, op2)); // execute operation
            calCount++; // increase the value of calculation count
            System.out.println("=============================");
        }
    }
}
