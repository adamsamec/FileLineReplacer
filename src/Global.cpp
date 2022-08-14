#include "Global.h"

#define OUTPUT_LEVEL 1
#define ERROR_LEVEL 10

Output& Global::out(int priority) {
  static Output output(OUTPUT_LEVEL, false); // output level
  output.priority = priority;
  return output;
}

Output& Global::err(int priority) {
  static Output output(ERROR_LEVEL, true); // output level
  output.priority = priority;
  return output;
}

