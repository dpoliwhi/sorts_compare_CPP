#include "sort.h"

int main() {
  Sort one;
  std::cout << "What size array do you want to sort?\n";
  int size = 0;
  std::cin >> size;
  // one.createFile(10);
  // one.openFile("10.txt");
  // one.printData();
  std::vector<int> sortedToPrint;
  one.generateData(size);
  one.bubbleSort();
  one.choiseSort();
  one.insertionSort();
  one.quickSort();
  one.mergeSort();
  one.shellSort();
  sortedToPrint = one.heapSort();
  // std::cout << "Do you want to print sorted array?\n";
  std::cout << "______________________________________________________________________\n";
  std::pair<double, std::string> fasterAlgo = *one.timeOfSort.begin();
  std::cout << "The faster algo to sort this random data is " << fasterAlgo.second << " - "
            << fasterAlgo.first << "s\n";
  return 0;
}
