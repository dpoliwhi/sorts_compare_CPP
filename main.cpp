#include <ctime>

#include "sort.h"

int main() {
  Sort one;
  one.createFile(1000);
  one.openFile("1000.txt");
  clock_t start, end;
  start = clock();
  one.bubbleSort();
  end = clock();
  // one.printData();
  std::cout.setf(std::ios::fixed);
  std::cout << "runtime = " << clock() / ((double)CLOCKS_PER_SEC) << std::endl;  // время работы программы
  return 0;
}
