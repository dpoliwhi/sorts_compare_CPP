#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

class Data {
 protected:
  std::vector<int> data;
  int randomizer(int size);
  void parsingLine(std::string oneLine);

 public:
  void createFile(int size);
  void openFile(std::string fileName);
  void generateData(int size);
  void printData();
  void printSortetData(const std::vector<int>& vec);
  void sortetDataToFile(const std::vector<int>& vec);
  void sortetDataToFileReverse(const std::vector<int>& vec);
  void clearData();
};
