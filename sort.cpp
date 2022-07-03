#include "sort.h"

std::vector<int> Sort::bubbleSort() {
  Simpletimer timer("bubbleSort");
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
  timeOfSort.insert(timer.getTime());
  return temp;
}

std::vector<int> Sort::choiseSort() {
  Simpletimer timer("choiseSort");
  std::vector<int> temp = data;
  for (size_t i = 0; i < temp.size(); i++) {
    size_t smallerPos = choiseHelper(temp, i);
    std::swap(temp[i], temp[smallerPos]);
  }
  timeOfSort.insert(timer.getTime());
  return temp;
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

std::vector<int> Sort::insertionSort() {
  Simpletimer timer("insertionSort");
  std::vector<int> temp = data;
  for (size_t i = 1; i < temp.size(); i++) {
    size_t j = i - 1;
    while (temp[j] > temp[j + 1]) {
      std::swap(temp[j], temp[j + 1]);
      j--;
    }
  }
  timeOfSort.insert(timer.getTime());
  return temp;
}

std::vector<int> Sort::quickSort() {
  Simpletimer timer("quickSort");
  std::vector<int> temp = data;
  quickSortHelper(temp, 0, temp.size() - 1);
  timeOfSort.insert(timer.getTime());
  return temp;
}

void Sort::quickSortHelper(std::vector<int>& vec, size_t start, size_t end) {
  if (start >= end) return;
  int mid = findCentralElement(vec, start, end);
  quickSortHelper(vec, start, mid);
  quickSortHelper(vec, mid + 1, end);
}

size_t Sort::findCentralElement(std::vector<int>& vec, size_t start, size_t end) {
  int pivot = vec[start];
  size_t left = start + 1;
  size_t right = end;
  while (true) {
    while (left < right && vec[right] >= pivot) right--;
    while (left < right && vec[left] < pivot) left++;
    if (left == right) break;
    std::swap(vec[left], vec[right]);
  }
  if (vec[left] >= pivot) return start;
  vec[start] = vec[left];
  vec[left] = pivot;
  return left;
}

std::vector<int> Sort::mergeSort() {
  Simpletimer timer("mergeSort");
  std::vector<int> temp = data;
  mergeSortHelper(temp, 0, temp.size() - 1);
  timeOfSort.insert(timer.getTime());
  return temp;
}

void Sort::mergeSortHelper(std::vector<int>& vec, size_t start, size_t end) {
  size_t mid = (start + end) / 2;
  if (start < end) {
    mergeSortHelper(vec, start, mid);
    mergeSortHelper(vec, mid + 1, end);
    mergeVector(vec, start, end, mid);
  }
}

void Sort::mergeVector(std::vector<int>& vec, size_t start, size_t end, size_t mid) {
  std::vector<int> mergedVec;
  mergedVec.resize(vec.size());
  size_t i = start;
  size_t j = mid + 1;
  size_t k = start;
  while (i <= mid && j <= end) {
    if (vec[i] < vec[j]) {
      mergedVec[k] = vec[i];
      k++;
      i++;
    } else {
      mergedVec[k] = vec[j];
      k++;
      j++;
    }
  }
  while (i <= mid) {
    mergedVec[k] = vec[i];
    k++;
    i++;
  }
  while (j <= end) {
    mergedVec[k] = vec[j];
    k++;
    j++;
  }
  for (i = start; i < k; i++) {
    vec[i] = mergedVec[i];
  }
}

std::vector<int> Sort::shellSort() {
  Simpletimer timer("shellSort");
  std::vector<int> temp = data;
  for (int step = temp.size() / 2; step > 0; step /= 2) {
    for (int i = step; i < (int)temp.size(); i++) {
      int j = i;
      while (j >= step && temp[j - step] > temp[i]) {
        std::swap(temp[j], temp[j - step]);
        j -= step;
      }
    }
  }
  timeOfSort.insert(timer.getTime());
  return temp;
}

std::vector<int> Sort::heapSort() {
  Simpletimer timer("heapSort");
  std::vector<int> temp = data;
  heapSortHelper(temp, temp.size());
  timeOfSort.insert(timer.getTime());
  return temp;
}

void Sort::heapSortHelper(std::vector<int>& vec, size_t n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(vec, n, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    std::swap(vec[0], vec[i]);
    heapify(vec, i, 0);
  }
}

void Sort::heapify(std::vector<int>& vec, size_t n, size_t root) {
  size_t largest = root;
  size_t l = 2 * root + 1;
  size_t r = 2 * root + 2;
  if (vec[l] > vec[largest] && l < n) {
    largest = l;
  }
  if (vec[r] > vec[largest] && r < n) {
    largest = r;
  }
  if (largest != root) {
    std::swap(vec[root], vec[largest]);
    heapify(vec, n, largest);
  }
}
