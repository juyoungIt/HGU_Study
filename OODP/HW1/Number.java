public class Number {
    private final String operator; // operator from user input
    private final int operand1;    // first operand from user input
    private final int operand2;    // second operand from user input

    public Number(String operator, int operand1, int operand2) {
        this.operator = operator;
        this.operand1 = operand1;
        this.operand2 = operand2;
    }
    public String getOperator() {
        return operator;
    }
    public int getOperand1() {
        return operand1;
    }
    public int getOperand2() {
        return operand2;
    }
}
