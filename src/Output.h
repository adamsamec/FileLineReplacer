#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>

/**
 * Třída <code>Output</code> umožňuje kontrolovat množství výstupu,
 *  které bude aplikace vypisovat do <code>std::cout</code> nebo do <code>std::cerr</code*
 * podle toho, jestli je atribut {@see #error} nastaven na <code>false</code> respektive <code>true</code>.
 * Globální úroveň {@see #level} se nastaví jednou a určuje jak moc zpráv bude na výstup vypisováno.
 *  Při {@see #level} &lt;= 0 nebude vypisován žádný výstup.
 *  Hodnota {@see #priority} určuje jaká globální úroveň je minimálně potřeba,
 *  aby příští výpis  proběhl a je třeba ji tedy přenastavit před výpisem pomocí <code>operator&lt;&lt;</code>.
 * @version     0.6, 12/09/2019
 * @author      Adam Samec
 */
class Output {
private:
protected:
  int level;
  bool error;
  
public:
  int priority;
  
  /**
   * Vytvoří a inicializuje nový <code>Output</code>.
   */
  Output(int level, bool error);
  
  /**
   * Kopírovací konstruktor.
   * @param orig  Objekt, ze kterého se má kopírovat.
   */
  Output(const Output& orig);
  
  /**
   * Destruktor.
   */
  virtual ~Output();
  
  /**
   * Operátor přiřazení.
   * @param rhs   Objekt, ze kterého se má provést přiřazení.
   * @return      Reference na tento objekt.
   */
  Output& operator=(const Output& rhs);
  
  /**
   * Zavolá <code>std::cout.operator&lt;&lt;()</code> se stejným parametrem jako zadaný
   *  <class>T</class>, pokud je {@see #level} &gt; {@see #priority} a {@see #level} &gt; 0.
   * @param param  Parametr, který bude zavolán na <code>std::cout.operator&lt;&lt;()</code>
   */
  Output& operator<<(const std::string& param);
  
  Output& operator<<(const std::wstring& param);
  
  /**
   * Viz. ostatní přetížené <code>operator&lt;&lt;</code>.
   */
  Output& operator<<(char param);
  
  /**
   * Viz. ostatní přetížené <code>operator&lt;&lt;</code>.
   */
  Output& operator<<(double param);
  
  /**
   * Viz. ostatní přetížené <code>operator&lt;&lt;</code>.
   */
  Output& operator<<(std::ostream& (*param)(std::ostream&));
};

#endif // OUTPUT_H
