#include "sort.h"

int main() {
  Sort one;
  // clock_t start, end;
  // one.createFile(100000);
  // one.openFile("100000.txt");
  one.generateData(100);
  // auto start = std::chrono::high_resolution_clock::now();
  // one.bubbleSort();
  // one.choiseSort();
  // one.insertionSort();
  one.quickSort();
  // auto end = std::chrono::high_resolution_clock::now();
  // std::chrono::duration<double> runtime = end - start;
  // one.printData();
  std::cout.setf(std::ios::fixed);
  // std::cout << "runtime = " << runtime.count() / 1000 << std::endl;
  return 0;
}
