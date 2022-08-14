#include "Output.h"

Output::Output(int level, bool error): level(level), priority(level), error(error) {}

Output::Output(const Output& orig): level(orig.level), priority(orig.priority), error(orig.error) {}

Output::~Output() {}

Output& Output::operator=(const Output& rhs) {
  if (this == &rhs) {
    return *this;
  }
  this->level = rhs.level;
  this->priority = rhs.priority;
  this->error = rhs.error;
  return *this;
}

Output& Output::operator<<(const std::string& param) {
  if ((this->level >= this->priority) && (this->level > 0)) {
    if (this->error) {
      std::cerr << param;
    } else {
      std::cout << param;
    }
  }
  return *this;
}

Output& Output::operator<<(const std::wstring& param) {
  if ((this->level >= this->priority) && (this->level > 0)) {
    if (this->error) {
      std::wcerr << param;
    } else {
      std::wcout << param;
    }
  }
  return *this;
}

Output& Output::operator<<(char param) {
  if ((this->level >= this->priority) && (this->level > 0)) {
    if (this->error) {
      std::cerr << param;
    } else {
      std::cout << param;
    }
  }
  return *this;
}

Output& Output::operator<<(double param) {
  if ((this->level >= this->priority) && (this->level > 0)) {
    if (this->error) {
      std::cerr << param;
    } else {
      std::cout << param;
    }
  }
  return *this;
}

Output& Output::operator<<(std::ostream& (*param)(std::ostream&)) {
  if ((this->level >= this->priority) && (this->level > 0)) {
    if (this->error) {
      std::cerr << param;
    } else {
      std::cout << param;
    }
  }
  return *this;
}
