public class Stack {

  public Process currentProcess;
  public Stack nextStack;

  public Stack() {
    this.currentProcess = null;
    this.nextStack = null;
  }

  public void push(Process newProcess) {
    if (this.currentProcess == null) {
      this.currentProcess = newProcess;
      this.nextStack = new Stack();
    } else {
      this.nextStack.push(newProcess);
    }
  }

  public Process pop() {
    if (this.nextStack.nextStack == null) {
      Process removed = this.currentProcess;
      this.currentProcess = null;
      this.nextStack = null;
      return removed;
    } else {
      return this.nextStack.pop();
    }
  }

  public String checkStack(String empty) {
    if (this.nextStack.nextStack == null) {
      empty =
          " " + this.currentProcess.getPriority() + " " + this.currentProcess.getTime() + empty;
    } else {
      empty =
          this.nextStack.checkStack(empty)
              + " && "
              + this.currentProcess.getPriority()
              + " "
              + this.currentProcess.getTime()
              + " "
              + empty;
    }
    return empty;
  }

  public boolean isEmpty() {
    return this.nextStack == null;
  }

  public int timeWorked(int time) {
    return this.currentProcess.worked(time);
  }
}

