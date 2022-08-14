#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <regex>
#include "Global.h"
#include "Replacer.h"

using namespace std;

Replacer::Replacer() {}

Replacer::Replacer(const Replacer& orig) {}

Replacer::~Replacer() {}

Replacer& Replacer::operator=(const Replacer& rhs) {
  if (this == &rhs) {
    return *this;
  }
  return *this;
}

bool Replacer::replace(wstring inDocPath, wstring outDocPath, wstring replacementsPath) {
  // Nejprve načteme vstupní dokument
  ifstream inFile;
  inFile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
  string line, outDoc;
  try {
    inFile.open(inDocPath.c_str());
  } catch (ifstream::failure ex) {
    Global::err(1) << "Chyba při otevírání souboru " << inDocPath << ". Soubor pravděpodobně neexistuje." << endl;
    return false;
  }
  while (true) {
    try {
      getline(inFile, line);
      outDoc += line;
    } catch (ifstream::failure ex) {
      if (inFile.eof()) {
        break;
      } else {
        Global::err(1) << "Chyba při čtení souboru " << inDocPath << endl;
        return false;
      }
    }
  }
  try {
    inFile.close();
  } catch (ifstream::failure ex) {
    Global::err(1) << "Chyba při zavírání souboru " << inDocPath << endl;
    return false;
  }
  
  // Poté načteme soubor s regulárními výrazy a náhradami a rovnou je aplikujeme
  try {
    inFile.open(replacementsPath.c_str());
  } catch (ifstream::failure ex) {
    Global::err(1) << "Chyba při otevírání souboru " << replacementsPath << ". Soubor pravděpodobně neexistuje." << endl;
    return false;
  }
  string pattern, replacement;
  while (true) {
    try {
      getline(inFile, line);
      
      // Přeskoč řádky obsahující jen netisknutelné znaky  a komentáře začínající na znak mřížky (#)
      regex re("^\\s*$");
      string replaced = regex_replace(line, re, "");
      if ((replaced == "") || (line[0] == '#')) {
        Global::out(4) << "Přeskakuji prázdný řádek nebo komentář: " << line << endl;
        continue;
      }
      
      // Zjisti regulární výraz a nahrazení
      if (pattern == "") {
        pattern = line;
        
        // Odstraň případně koncový znak "\r", jestliže soubor s regulárními výrazy a náhradami pochází z Windows
        if (pattern[pattern.length() - 1] == '\r') {
          pattern = pattern.substr(0, pattern.length() - 1);
        }
          } else if (replacement == "") {
        replacement = line;
        
            // Opět odstraň případně koncový znak "\r"
        if (replacement[replacement.length() - 1] == '\r') { // begin if 2
          replacement = replacement.substr(0, replacement.length() - 1);
        }
            
        // Aplikuj regulární výraz
        regex re(pattern);
        outDoc = regex_replace(outDoc, re, replacement);
              Global::out(4) << "Výraz: " << pattern << endl;
        Global::out(4) << "Nahrazení: " << replacement << endl;

            // Resetuj výraz a nahrazení
            pattern = "";
        replacement = "";
      }
    } catch (ifstream::failure ex) {
      if (inFile.eof()) {
      break;
      } else {
        Global::err(1) << "Chyba při čtení souboru " << replacementsPath << endl;
        return false;
      }
    }
  }
  try {
    inFile.close();
  } catch (ifstream::failure ex) {
    Global::err(1) << "Chyba při zavírání souboru " << replacementsPath << endl;
    return false;
  }

  // Text s aplikovaným nahrazením  zapiš do výstupního dokumentu
  ofstream outFile;
  outFile.exceptions(ofstream::failbit | ofstream::badbit);
    try {
    outFile.open(outDocPath.c_str());
  } catch (ofstream::failure ex) {
    Global::err(1) << "Chyba při vytváření souboru " << outDocPath << endl;
    return false;
  }
  try {
    outFile << outDoc;
  } catch (ofstream::failure ex) {
    Global::err(1) << "Chyba při zápisu do souboru " << outDocPath << endl;
    return false;
  }
  try {
    outFile.close();
  } catch (ifstream::failure ex) {
    Global::err(1) << "Chyba při zavírání souboru " << outDocPath << endl;
    return false;
  }

  Global::out(7) << outDoc << endl;
  
  return true;
  }
