//
//  main.cpp
//  Search_Algorithms
//
//  Created by Antonio Nogueron Barcenas and Armando Arredondo Valle
//  on 4/Sep/2022.
//

#include <iostream>
using namespace std;

// Brute force string matching algorithm

void search_all(string const& text, string const& pattern) {
    unsigned long const pattern_size(pattern.size()); // pattern size
    unsigned long const endpos(text.size() - pattern_size + 1); // end position
    short evaluation; // evaluation of the comparison
    int total_comparisions = 0;
    for (int POs(0); POs < endpos; ++POs) { // for each position
        evaluation = text.compare(POs, pattern_size, pattern); // compare
        total_comparisions++;
        if (evaluation == -1) { // if the pattern is less than the text
            cout << POs << " |" << text.substr(POs,pattern_size) << "| " << evaluation << "  "; // print the position, the text and the evaluation
        } else { // if the pattern is greater than the text
            cout << POs << " |" << text.substr(POs,pattern_size) << "|  " << evaluation << "  "; // print the position, the text and the evaluation
        } // end if
        if (evaluation == 0) { // if the pattern is equal to the text
            cout << " <---- match! " << "\n"; // print the match
        } else { // if the pattern is not equal to the text
            cout << "\n"; // print a new line
        }
    }
    cout << "Total comparisions: " << total_comparisions << "\n"; // print the total comparisions
    cout << "Total chars compared: " << total_comparisions * pattern_size << "\n"; // print the total chars compared
}

void iter_demo(string const& text, string const& pattern) { 
    cout << "------------------\n";
    cout << "Text: " << text << "\n";
    cout << "Pattern: " << pattern << "\n";
    cout << "Position | Substring | Evaluation | Match? " << "\n";
    search_all(text, pattern);
}

void iter_demo_bienhecho(string const& text, string const& pattern) { // iter_demo_bienhecho
    int char_compared = 0; // chars compared
    unsigned long const pattern_size(pattern.size()); // pattern size
    unsigned long const endpos(text.size() - pattern_size + 1); // end position
    bool match;
    for (int i=0; i < endpos; ++i){ // for each index in the text
        string substring = text.substr(i, pattern_size);
        for(int j=0; j< pattern_size; ++j){ // for each char in the pattern
            if(substring[j] == pattern[j]){ // if the char is equal to the pattern
                char_compared++; // add 1 to the chars compared
            } else { // if the char is not equal to the pattern
                char_compared++; // add 1 to the chars compared
                match = false;
                break; // break the loop
            }
            match = true; 
        }
        if (match) {
        cout << i << " |" << substring << "|  " << "1" << "  <---- match!" << "\n";

        } else {
        cout << i << " |" << substring << "|  " << "0 " << "\n";
        }
    }
    cout << "Total comparisions: " << endpos << "\n"; // print the total comparisions
    cout << "Total chars compared: " << char_compared << "\n"; // print the total chars compared
}



int main() {
    string the_text = "panamanian banana fanatics can manage anacondas";
    string the_pattern = "ana";
    search_all(the_text, the_pattern);
    iter_demo_bienhecho(the_text, the_pattern);
    return 0;
}
    