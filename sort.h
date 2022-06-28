#include <chrono>

#include "data.h"

class Sort : public Data {
 private:
  size_t choiseHelper(const std::vector<int>& vec, size_t pos);
  size_t findCentralElement(std::vector<int>& vec, size_t start, size_t end);
  void quickSortHelper(std::vector<int>& vec, size_t start, size_t end);

 public:
  void bubbleSort();
  void choiseSort();
  void insertionSort();
  void quickSort();
};

class Simpletimer {
 private:
  std::chrono::time_point<std::chrono::system_clock> start, end;

 public:
  Simpletimer() { start = std::chrono::high_resolution_clock::now(); }
  ~Simpletimer() {
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtime = end - start;
    std::cout << "runtime = " << runtime.count() << "s" << std::endl;
  }
};
