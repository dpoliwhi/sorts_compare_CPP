#include "sort.h"

void Sort::createFile(int size) {
  std::string fileName = std::to_string(size) + ".txt";
  std::ofstream file;
  file.open(fileName);
  for (int i = 0; i < size; i++) {
    file << randomizer(size) << " ";
    if (i % 20 == 0 && i > 1) {
      file << "\n";
    }
  }
  file.close();
}

void Sort::openFile(std::string fileName) {
  std::ifstream file;
  file.open(fileName);
  std::string line;
  while (getline(file, line)) {
    parsingLine(line);
  }
  file.close();
}

void Sort::parsingLine(std::string oneLine) {
  std::string::iterator iter(oneLine.begin());
  std::string buffer;
  while (iter != oneLine.end()) {
    if (isdigit(*iter)) {
      buffer.push_back(*iter);
    } else {
      data.push_back(atoi(buffer.c_str()));
      buffer.clear();
    }
    ++iter;
  }
}

int Sort::randomizer(int size) {
  std::random_device random;
  std::default_random_engine engine(random());
  // std::uniform_int_distribution<int> res(0, std::numeric_limits<int>::max());
  std::uniform_int_distribution<int> res(0, size);
  return res(engine);
}

void Sort::printData() {
  std::cout << data.size() << std::endl;
  for (size_t i = 0; i < data.size(); i++) {
    std::cout << data[i] << " ";
    if (i % 20 == 0 && i > 1) {
      std::cout << "\n";
    }
  }
}

void Sort::printSortetData(const std::vector<int>& vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
    if (i % 20 == 0 && i > 1) {
      std::cout << "\n";
    }
  }
}

void Sort::generateData(int size) {
  Simpletimer timer;
  for (int i = 0; i < size; i++) {
    data.push_back(randomizer(size));
  }
}

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
