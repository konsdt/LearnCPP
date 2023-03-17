#include<iostream>
#include<string>
#include<algorithm>

int getNumberOfNames()
{
    int numberOfNames {};
    std::cout << "How many names would you like to enter? ";
    std::cin >> numberOfNames;
    return numberOfNames;
}

std::string* getNames(int numberOfNames) 
{
    auto* namesArray { new std::string[numberOfNames]{} };
    for (int i = 0; i < numberOfNames; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, namesArray[i]);
    }
    return namesArray;
    // so funktioniert es aktuell zwar, könnte aber trotzdem problematisch sein,
    // da der Speicherplatz frei gegeben wird bevor der Inhalt benutzt wird
    // In einem größeren programm könnte das zu Problemen führen wenn genau
    // diese Speicherplätze dann Überschrieben werden bevor das Programm zu Ende ist
    // Als Lösung wüsste ich an dieser Stelle nur die Entschachtelung dieser Funktion
    // Sprich was hier passiert in int main() aufdröseln und dann am ende von int main()
    // den speicher wieder frei geben
    delete[] namesArray;
}

void printSortedNamesArray(std::string* namesArray, int numberOfNames)
{
    std::sort(namesArray, namesArray + numberOfNames);
    for (int i = 0; i < numberOfNames; ++i)
    {
        std::cout << "Name #" << i + 1 << ": " << namesArray[i] << '\n';
    }
}

int main()
{
    int numberOfNames { getNumberOfNames() };
    std::string* namesArray{ getNames(numberOfNames) };
    printSortedNamesArray(namesArray, numberOfNames);
    return 0;
}