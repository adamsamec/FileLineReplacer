#ifndef GLOBAL_H
#define GLOBAL_H

#include "Output.h"

/**
 * Staticka trida <code>Global</code> poskytuje pristup ke globalnim metodam a nastaveni aplikace.
 * @version     0.5, 23/12/10
 * @author      Adam Samec
 */
class Global {
private:
protected:
  /**
   * Konstruktor. Zakazany - neni treba.
   */
  Global();
  /**
   * Kopirovaci konstruktor. Zakazany - neni treba.
   * @param orig  objekt, ze ktereho se ma kopirovat
   */
  Global(const Global& orig);
  
  /**
   * Operator prirazeni. Zakazany - neni treba.
   * @param rhs   objekt, ze ktereho se ma provest prirazeni
   * @return      reference na tento objekt
   */
  Global& operator=(const Global& rhs);
  
  /**
   * Destruktor. Zakazany - neni treba.
   */
  virtual ~Global();
public:
  /**
   * V zavislosti na zadane <code>int</code> priorite
   *  a globalni urovni vypisu vypise zadany <class>T</class>.
   * @param priority   priorita tohoto vypisu
   */
  static Output& out(int priority);
  
  /**
   * V zavislosti na zadane <code>int</code> priorite
   *  a globalni urovni vypisu vypise do chybového vystupuzadany <class>T</class>.
   * @param priority   priorita tohoto vypisu
   */
  static Output& err(int priority);
  
};

#endif // GLOBAL_H
