#include <chrono>
#include <map>

#include "data.h"

class Sort : public Data {
 private:
  size_t choiseHelper(const std::vector<int>& vec, size_t pos);
  size_t findCentralElement(std::vector<int>& vec, size_t start, size_t end);
  void quickSortHelper(std::vector<int>& vec, size_t start, size_t end);
  void mergeSortHelper(std::vector<int>& vec, size_t start, size_t end);
  void mergeVector(std::vector<int>& vec, size_t start, size_t end, size_t mid);
  void heapSortHelper(std::vector<int>& vec, size_t n);
  void heapify(std::vector<int>& vec, size_t n, size_t i);

 public:
  std::vector<int> bubbleSort();
  std::vector<int> choiseSort();
  std::vector<int> insertionSort();
  std::vector<int> quickSort();
  std::vector<int> mergeSort();
  std::vector<int> shellSort();
  std::vector<int> heapSort();
  std::map<double, std::string> timeOfSort;
};

class Simpletimer {
 private:
  std::string sortName;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::chrono::duration<double> runtime;

 public:
  std::pair<double, std::string> getTime() {
    end = std::chrono::high_resolution_clock::now();
    runtime = end - start;
    return {runtime.count(), sortName};
  }
  Simpletimer(std::string SN) : sortName(SN) { start = std::chrono::high_resolution_clock::now(); }
  ~Simpletimer() {
    std::cout.setf(std::ios::fixed);
    std::cout << "runtime of " << sortName << " = " << runtime.count() << "s" << std::endl;
  }
};
