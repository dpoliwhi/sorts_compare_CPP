#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <chrono>

class Sort {
 private:
  std::vector<int> data;
  int randomizer(int size);
  void parsingLine(std::string oneLine);
  size_t choiseHelper(const std::vector<int>& vec, size_t pos);

 public:
  void createFile(int size);
  void openFile(std::string fileName);
  void generateData(int size);
  void bubbleSort();
  void choiseSort();
  void printData();
  void printSortetData(const std::vector<int>& vec);
};

class Simpletimer {
 private:
  std::chrono::time_point<std::chrono::system_clock> start, end;

 public:
  Simpletimer() {
    start = std::chrono::high_resolution_clock::now();
  }
  ~Simpletimer() {
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "runtime = " << runtime.count() << "s" << std::endl;
  }
};
