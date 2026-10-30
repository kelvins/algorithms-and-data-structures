public class Stack {

  public process currentProcess;
  public Stack nextStack;

  public Stack() {
    this.currentProcess = null;
    this.nextStack = null;
  }

  public void pushProcess(process newProcess) {
    if (this.currentProcess == null) {
      this.currentProcess = newProcess;
      this.nextStack = new Stack();
    } else {
      this.nextStack.pushProcess(newProcess);
    }
  }

  public process popProcess() {
    if (this.nextStack.nextStack == null) {
      process removed = this.currentProcess;
      this.currentProcess = null;
      this.nextStack = null;
      return removed;
    } else {
      return this.nextStack.popProcess();
    }
  }

  public String formatStack(String empty) {
    if (this.nextStack.nextStack == null) {
      empty = " " + this.currentProcess.getPriority() + " " + this.currentProcess.getTime() + empty;
    } else {
      empty =
          this.nextStack.formatStack(empty)
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
    if (this.nextStack == null) {
      return true;
    }
    return false;
  }

  public int workedTime(int time) {
    return this.currentProcess.worked(time);
  }
}
