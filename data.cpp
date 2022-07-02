#include "data.h"

void Data::createFile(int size) {
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

void Data::openFile(std::string fileName) {
  std::ifstream file;
  file.open(fileName);
  std::string line;
  while (getline(file, line)) {
    parsingLine(line);
  }
  file.close();
}

void Data::parsingLine(std::string oneLine) {
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

int Data::randomizer(int size) {
  std::random_device random;
  std::default_random_engine engine(random());
  // std::uniform_int_distribution<int> res(0, std::numeric_limits<int>::max());
  std::uniform_int_distribution<int> res(0, size);
  return res(engine);
}

void Data::printData() {
  // std::cout << data.size() << std::endl;
  for (size_t i = 0; i < data.size(); i++) {
    std::cout << data[i] << " ";
    if (i % 20 == 0 && i > 1) {
      std::cout << "\n";
    }
  }
}

void Data::printSortetData(const std::vector<int>& vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
    if (i % 20 == 0 && i > 1) {
      std::cout << "\n";
    }
  }
}

void Data::generateData(int size) {
  for (int i = 0; i < size; i++) {
    data.push_back(randomizer(size));
  }
}
