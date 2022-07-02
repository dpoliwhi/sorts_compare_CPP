#include "sort.h"

int main() {
  Sort one;
  // one.createFile(10);
  // one.openFile("10.txt");
  // one.printData();
  one.generateData(20000);
  one.bubbleSort();
  one.choiseSort();
  one.insertionSort();
  one.quickSort();
  one.mergeSort();
  return 0;
}
