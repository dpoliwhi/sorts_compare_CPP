#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

class Sort {
 private:
  std::vector<int> data;
  int randomizer(int size);
  void parsingLine(std::string oneLine);

 public:
  void createFile(int size);
  void openFile(std::string fileName);
  void bubbleSort();

  void printData();
};
