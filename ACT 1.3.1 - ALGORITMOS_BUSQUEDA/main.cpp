//
//  main.cpp
//  Search_Algorithms
//
//  Created by Antonio Nogueron Barcenas and Armando Arredondo Valle
//  on 4/Sep/2022.
//

#include <iostream>
#include "searcher.cpp"
using namespace std;

int main()
{
    int option = 0;
    // Menu
    Searcher searcher1("panamanian banana fanatics can manage anacondas", "ana");
    do
    {
        cout << "----------------------------------------\n";
        cout << "      ACT 1.3.1 - ALGORITMOS_BUSQUEDA\n";
        cout << "----------------------------------------\n";
        cout << "[1] Search all\n";
        cout << "[2] Compare demo\n";
        cout << "[3] Iter demo\n";
        cout << "[4] Smarter search\n";
        cout << "[5] Morris Pratt\n";
        cout << "[0] Exit\n";
        cout << "----------------------------------------\n";
        cout << "Option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            searcher1.search_all();
            break;
        case 2:
            searcher1.compare_demo();
            break;
        case 3:
            searcher1.iter_demo();
            break;
        case 4:
            searcher1.smarter_search();
            break;
        case 5:
            searcher1.knuth_morris_pratt();
            break;
        default:
            cout << "Invalid option!";
            break;
        }
    } while (option != 0);
}