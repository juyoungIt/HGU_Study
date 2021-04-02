public abstract class Operation {
    private final String name;    // server name
    private final String opcode;  // operation code
    private Operation next; // indicate next step operation

    public Operation (String name, String opcode) {
        this.name = name;
        this.opcode = opcode;
    }
    public Operation setNext(Operation next) {
        this.next = next;
        return next;
    }
    public final void operation(Number problem) {
        if(resolve(problem)) {
            done(problem);
        } else if (next != null) {
            System.out.println(this + " server passing " + problem.getOperator() + " operator to the next server.");
            next.operation(problem);
        } else {
            fail(problem);
        }
    }
    public String toString() {
        return name;
    }
    public String getOpcode() {
        return opcode;
    }
    protected abstract boolean resolve(Number problem); // abstract method

    protected void done(Number problem) {
        System.out.println(this + " " +"Provided");
    }
    protected void fail(Number problem) {
        System.out.println("Problem solving was failed");
    }
}
