public class Queue {

  public process currentProcess;
  public Queue nextQueue;

  public Queue() {
    this.currentProcess = null;
    this.nextQueue = null;
  }

  public void enqueueProcess(process newProcess) {
    if (this.currentProcess == null) {
      this.currentProcess = newProcess;
      this.nextQueue = new Queue();
    } else {
      this.nextQueue.enqueueProcess(newProcess);
    }
  }

  public process dequeueProcess() {
    process removed = this.currentProcess;
    this.currentProcess = this.nextQueue.currentProcess;
    this.nextQueue = this.nextQueue.nextQueue;
    return removed;
  }

  public String formatQueue(String empty) {
    if (this.nextQueue.nextQueue == null) {
      empty = empty + " " + this.currentProcess.getPriority() + " " + this.currentProcess.getTime();
    } else {
      empty =
          empty
              + " "
              + this.currentProcess.getPriority()
              + " "
              + this.currentProcess.getTime()
              + " &&"
              + this.nextQueue.formatQueue(empty);
    }
    return empty;
  }

  public boolean isEmpty() {
    if (this.nextQueue == null) {
      return true;
    }
    return false;
  }
}
