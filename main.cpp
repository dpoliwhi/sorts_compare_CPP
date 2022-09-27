#include "sort.h"

void sortingArrayRandom(Sort& one) {
  one.bubbleSort();
  one.choiseSort();
  one.insertionSort();
  one.quickSort();
  one.mergeSort();
  one.shellSort();
  one.heapSort();
}

void allSorts(Sort& one) {
  one.bubbleSort();
  one.choiseSort();
  one.insertionSort();
  one.quickSort();
  one.mergeSort();
  one.shellSort();
  one.heapSort();
}

void showFaster(const std::map<double, std::string>& timeOfSort) {
  std::cout << "__________________________________________________________\n";
  std::pair<double, std::string> fasterAlgo = *timeOfSort.begin();
  std::cout << "The faster algo to sort this data is " << fasterAlgo.second << " - " << fasterAlgo.first
            << "s\n";
}

void sortingArrayFile(Sort& one, std::string fileName) {
  std::cout << "__________________________________________________________\n";
  std::cout << "                     Sort random data                     \n\n";
  one.clearData();
  one.openFile(fileName);
  allSorts(one);
  showFaster(one.timeOfSort);
  one.timeOfSort.clear();

  std::cout << "__________________________________________________________\n";
  std::cout << "                Sort previosly sorted data                \n\n";
  one.clearData();
  one.openFile(fileName + "Sorted");
  // one.printData();
  allSorts(one);
  showFaster(one.timeOfSort);
  one.timeOfSort.clear();

  std::cout << "__________________________________________________________\n";
  std::cout << "                 Sort reverse sorted data                 \n\n";
  one.clearData();
  one.openFile(fileName + "SR");
  allSorts(one);
  showFaster(one.timeOfSort);
  one.timeOfSort.clear();
}

void choiseAction(Sort& sort) {
  std::cout << "press 1 to open array from file\n";
  std::cout << "press 2 to create array randomly\n";
  int choice;
  int size = 0;
  std::string fileName;
  if (std::cin >> choice) {
    switch (choice) {
      case 1:
        std::cout << "input filename (100, 500, 1000, 10000)\n";
        std::cin >> fileName;
        sortingArrayFile(sort, fileName);
        break;
      case 2:
        std::cout << "What size array do you want to sort?\n";
        std::cin >> size;
        sort.generateData(size);
        sortingArrayRandom(sort);
        break;
    }
  }
}

int main() {
  Sort one;
  // std::vector<int> sortedData;
  choiseAction(one);

  // one.openFile("1000");
  // one.bubbleSort();
  // one.choiseSort();
  // one.insertionSort();
  // one.quickSort();
  // one.mergeSort();
  // one.shellSort();
  // one.heapSort();
  //   showFaster(one.timeOfSort);
  return 0;
}
