function hanoi(pin0, pin2, pin1, num) {
  if (num === 1) {
    console.log(`Move from ${pin0} to ${pin2}`);
  } else {
    hanoi(pin0, pin1, pin2, num - 1);
    hanoi(pin0, pin2, pin1, 1);
    hanoi(pin1, pin2, pin0, num - 1);
  }
}

hanoi(0,2,1,3);