public class Stack {

    private Process currentProcess;
    private Stack nextStack;

    public Stack() {
        currentProcess = null;
        nextStack = null;
    }

    public void push(Process newProcess) {
        if (currentProcess == null) {
            currentProcess = newProcess;
            nextStack = new Stack();
        } else {
            nextStack.push(newProcess);
        }
    }

    public Process pop() {
        if (nextStack.nextStack == null) {
            Process removed = currentProcess;
            currentProcess = null;
            nextStack = null;
            return removed;
        } else {
            return nextStack.pop();
        }
    }

    public String checkStack(String empty) {
        if (nextStack.nextStack == null) {
            empty = " " + currentProcess.getPriority() + " " + currentProcess.getTime() + empty;
        } else {
            empty = nextStack.checkStack(empty)
                    + " && "
                    + currentProcess.getPriority()
                    + " "
                    + currentProcess.getTime()
                    + " "
                    + empty;
        }
        return empty;
    }

    public boolean isEmpty() {
        return nextStack == null;
    }

    public int timeWorked(int time) {
        return currentProcess.worked(time);
    }
}
