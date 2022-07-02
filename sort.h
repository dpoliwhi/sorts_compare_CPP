#include <chrono>

#include "data.h"

class Sort : public Data {
 private:
  size_t choiseHelper(const std::vector<int>& vec, size_t pos);
  size_t findCentralElement(std::vector<int>& vec, size_t start, size_t end);
  void quickSortHelper(std::vector<int>& vec, size_t start, size_t end);
  void mergeSortHelper(std::vector<int>& vec, size_t start, size_t end);
  void mergeVector(std::vector<int>& vec, size_t start, size_t end, size_t mid);

 public:
  void bubbleSort();
  void choiseSort();
  void insertionSort();
  void quickSort();
  void mergeSort();
  void shellSort();
};

class Simpletimer {
 private:
  std::string sortName;
  std::chrono::time_point<std::chrono::system_clock> start, end;

 public:
  Simpletimer(std::string SN) : sortName(SN) { start = std::chrono::high_resolution_clock::now(); }
  ~Simpletimer() {
    std::cout.setf(std::ios::fixed);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "runtime of " << sortName << " = " << runtime.count() << "s" << std::endl;
  }
};
