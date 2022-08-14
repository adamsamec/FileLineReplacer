#ifndef REPLACER_H
#define REPLACER_H

#include <string>

/**
 *Tato třída slouží pro načtení dokumentu a souboru
 * obsahujícího regulární výrazy a pro provedení nahrazení v dokumentu.
 * @version     0.5, 23/12/10
 * @author      Adam Samec
 *
 */
class Replacer {
private:
protected:
  public:
  /**
     * Vytvori a inicializuje novy <code>Replacer</code>.
     */
    Replacer();

    /**
     * Kopírovací konstruktor..
     * @param orig  Objekt, ze kterého se má kopírovat
     */
    Replacer(const Replacer& orig);

    /**
     * Destruktor. Dealokuje pouze pomocné objekty vytvořené pro účely parsování.
     */
    virtual ~Replacer();

    /**
     * Operator přiřazení.
     * @param rhs   Objekt, ze kterého se má provést přiřazení.
     * @return      Reference na tento objekt
     */
    Replacer& operator=(const Replacer& rhs);

    /**
     * Spustí nahrazení na zadaném  vstupním dokumentu podle zadaného souboru
     *  s regulárními výrazy a výsledek zapíše do zadaného výstupního dokumentu.
     * @param inDocumentPath  Cesta k vstupnímu dokumentu, který má být zdrojem pro nahrazení.
     * @param outDocumentPath  Cesta k výstupnímu dokumentu, kam má být uložen výsledek nahrazení.
     * @param replacementsPath  cesta k souboru, který  obsahuje regulární výrazy pro provedení nahrazení.
     * @return <code>true</code>, jestliže nahrazení proběhlo v pořádku, jinak <code>false</code>.
     */
    static bool replace(std::wstring inDocPath, std::wstring outDocPath, std::wstring replacementsPath);
};

#endif // REPLACER_H
