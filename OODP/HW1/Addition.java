public class Addition extends Operation {
    public Addition (String name, String opcode) {
        super(name, opcode);
    }
    protected boolean resolve(Number problem) {
        if(problem.getOperator().equals(super.getOpcode())) {
            System.out.println(this + " Server Working ...");
            System.out.println(problem.getOperand1() + " + " + problem.getOperand2() + " = " + (problem.getOperand1() + problem.getOperand2()));
            return true;
        }
        else
            return false;
    }
}
