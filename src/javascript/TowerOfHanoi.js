function hanoi(sourcePin, targetPin, auxiliaryPin, numberOfDisks) {
  if (numberOfDisks === 1) {
    console.log(`Move from ${sourcePin} to ${targetPin}`);
  } else {
    hanoi(sourcePin, auxiliaryPin, targetPin, numberOfDisks - 1);
    hanoi(sourcePin, targetPin, auxiliaryPin, 1);
    hanoi(auxiliaryPin, targetPin, sourcePin, numberOfDisks - 1);
  }
}

hanoi(0, 2, 1, 3);
