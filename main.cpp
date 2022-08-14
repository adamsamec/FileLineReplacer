#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include "src/Global.h"
#include "src/Replacer.h"

using namespace std;

int wmain(int argc, wchar_t** argv) {
  SetConsoleOutputCP(CP_UTF8);
  if ((argv[1] == 0) || (argv[2] == 0) || argv[3] == 0) {
    Global::err(1) << "Chyba: Některé argumenty chybí. Zadejte cestu k vstupnímu dokumentu, cestu k výstupnímu dokumentu a cestu k souboru s regulárními výrazy. Cesty oddělte mezerou." << endl;
    return EXIT_FAILURE;
  }
  
  bool success = Replacer::replace(argv[1], argv[2], argv[3]);
  if (!success) { // begin if 1
    return EXIT_FAILURE;
  } // end if 1
  
  return EXIT_SUCCESS;
}

