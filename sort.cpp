#include "sort.h"

void Sort::bubbleSort() {
  Simpletimer timer;
  std::vector<int> temp = data;
  bool changes = true;
  size_t sortEnd = temp.size();
  while (changes) {
    changes = false;
    for (size_t i = 0; i + 1 < sortEnd; i++) {
      if (temp[i] > temp[i + 1]) {
        std::swap(temp[i], temp[i + 1]);
        changes = true;
      }
    }
    sortEnd--;
  }
}

void Sort::choiseSort() {
  Simpletimer timer;
  std::vector<int> temp = data;
  for (size_t i = 0; i < temp.size(); i++) {
    size_t smallerPos = choiseHelper(temp, i);
    std::swap(temp[i], temp[smallerPos]);
  }
  // printSortetData(temp);
}

size_t Sort::choiseHelper(const std::vector<int>& vec, size_t pos) {
  size_t smallerPos = pos;
  for (size_t i = pos; i < vec.size(); i++) {
    if (vec[i] < vec[smallerPos]) {
      smallerPos = i;
    }
  }
  return smallerPos;
}

void Sort::insertionSort() {
  Simpletimer timer;
  std::vector<int> temp = data;
  for (size_t i = 1; i < temp.size(); i++) {
    size_t j = i - 1;
    while (j >= 0 && temp[j] > temp[j + 1]) {
      std::swap(temp[j], temp[j + 1]);
      j--;
    }
  }
  // printSortetData(temp);
}

void Sort::quickSort() {
  Simpletimer timer;
  std::vector<int> temp = data;
  quickSortHelper(temp, 0, temp.size() - 1);
  printSortetData(temp);
}

void Sort::quickSortHelper(std::vector<int>& vec, size_t start, size_t end) {
  if (start < end) {
    size_t centr = findCentralElement(vec, start, end);
    quickSortHelper(vec, start, centr - 1);
    quickSortHelper(vec, centr + 1, end);
  }
}

size_t Sort::findCentralElement(std::vector<int>& vec, size_t start, size_t end) {
  size_t i = start;
  while (i < end) {
    if (vec[i] > vec[end] && i == (end - 1)) {
      std::swap(vec[i], vec[end]);
      end--;
    } else if (vec[i] > vec[end]) {
      std::swap(vec[end - 1], vec[end]);
      std::swap(vec[i], vec[end]);
      end--;
    } else {
      i++;
    }
  }
  return end;
}
