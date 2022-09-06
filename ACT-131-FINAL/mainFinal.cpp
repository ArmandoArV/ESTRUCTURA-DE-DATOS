//
//  main.cpp
//  Search_Algorithms
//
//  Created by Antonio Nogueron Barcenas and Armando Arredondo Valle
//  on 4/Sep/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


string readData(){
    string data;
    ifstream file;
    file.open("DATA.dat");
    if(file.is_open()){
        getline(file, data);
        // ignore the numbers and only take the letters
        data = data.substr(4);
        
        file.close();
    }
    return data;
}

int validacion(int input,int inferior,int superior){
    while (!(cin >> input) || input>superior || input<inferior) {
        cout << "Input inválido. Por favor ingrese una de las opciones." << endl;
        cin.clear(); //Limpia el input anterior
        cin.ignore(123, '\n'); //Ignora caracteres anteriores
    }
    return input;
} // Complexity: O(1)

// Brute force string matching algorithm

void search_all(string const& text, string const& pattern) {
    unsigned long const pattern_size(pattern.size()); // pattern size
    unsigned long const endpos(text.size() - pattern_size + 1); // last index to check
    short evaluation;
    int total_comparisons = 0;
    for (int POs(0); POs < endpos; ++POs) { // for each position
        evaluation = text.compare(POs, pattern_size, pattern); // compare
        total_comparisons++;
        if (evaluation == -1) { //if it is not a match, format the output
            cout << POs << " |" << text.substr(POs,pattern_size) << "| " << evaluation << "  ";
        } else { // output skips a space for the -1 to get formatted properly
            cout << POs << " |" << text.substr(POs,pattern_size) << "|  " << evaluation << "  ";
        }
        if (evaluation == 0) { // if it is a match
            cout << " <---- match! " << "\n";
        } else {
            cout << "\n";
        }
    }
    cout << "Total comparisons: " << total_comparisons << "\n";
    cout << "Total chars compared: " << total_comparisons * pattern_size << "\n";
} // Complexity: O(N*M) | N = text.size() | M = pattern.size()

void compare_demo(string const& text, string const& pattern)
{
    unsigned long const pattern_size(pattern.size());           // pattern size
    unsigned long const endpos(text.size() - pattern_size + 1); // end position
    short evaluation;
    int total_comparisions = 0;
    for (int POs(0); POs < endpos; ++POs)
    {                                                                              // for each letter in the text that can match the string
        evaluation = text.compare(POs, pattern_size, pattern); // compare
        total_comparisions++;
        if (evaluation == -1)
        {                                                                                                  // if comparision gives -1 formats differently
            cout << POs << " |" << text.substr(POs, pattern_size) << "| " << evaluation << "  "; // formats the print to match requirements
        }
        else
        {
            cout << POs << " |" << text.substr(POs, pattern_size) << "|  " << evaluation << "  "; // formats the print to match requirements
        }
        if (evaluation == 0)
        { // if the pattern is found in the index
            cout << " <---- match! "
                 << "\n"; // print the match
        }
        else
        { // if not, prints a return character
            cout << "\n";
        }
    }
    cout << "Total comparisions: " << total_comparisions << "\n";                  // print the total comparisions
    cout << "Total chars compared: " << total_comparisions * pattern_size << "\n"; // print the total chars compared
} // Complexity: O(N*M) | N = text.size() | M = pattern.size()


void iter_demo(string const& text, string const& pattern) { // iter_demo_bienhecho
    int char_compared = 0; // chars compared
    unsigned long const pattern_size(pattern.size()); // pattern size
    unsigned long const endpos(text.size() - pattern_size + 1); // end position
    bool match = false;
    for (int i=0; i < endpos; ++i){ // for each index in the text
        for(int j=0; j< pattern_size; ++j){ // for each char in the pattern
            if(text[j+i] == pattern[j]){ // if the char is equal to the pattern
                char_compared++; // add 1 to the chars compared
            } else { // if the char is not equal to the pattern
                char_compared++; // add 1 to the chars compared
                match = false; // set the match to false
                break; // break the loop
            }
            match = true;  // set the match to true
        }
        if (match) { // if the match is true
            cout << i << " |" << text.substr(i,pattern_size) << "|  " << "1" << "  <---- match!" << "\n";
        } else { // if the match is false
            cout << i << " |" << text.substr(i,pattern_size) << "|  " << "0 " << "\n";
        }
    }
    cout << "Total comparisons: " << endpos << "\n"; // print the total comparisons
    cout << "Total chars compared: " << char_compared << "\n"; // print the total chars compared
} // Complexity: O(N*M) | N = text.size() | M = pattern.size()

struct PrefixResult {
    int prefix_length;
    vector<int> positions;
    int chars_compared;
};

PrefixResult find_prefix_suffix(string const& pattern){ //
    int prefix_length = 0; //
    vector<int> first;
    int chars_compared = 0;
    PrefixResult answer;
    for(int i=1; i < pattern.size(); ++i){ // for every char inside the pattern
        if(pattern[i] == pattern[0]){ // if the char that is being compared is equal to the first char
            first.push_back(i); // push the index of the char to the vector
            chars_compared++; // add 1 to the chars compared
        }
    }
    if (first.empty()) { // if the vector is empty
        answer.prefix_length = 0; // set the prefix length to 0
        answer.chars_compared = chars_compared; // set the chars compared to the chars compared
        answer.positions = first; // set the positions to the vector
        return answer; // return the answer
    }
    for (int i = 0; i < first.size(); ++i){ // for every index in the vector
        int k = 1; // set k to 1
        while(pattern[k] == pattern[first[i]+k]){ // while the char that is being compared is equal to the char in the pattern
            k++; // add 1 to k
            chars_compared++; // add 1 to the chars compared
        }
        if(prefix_length < k){ // if the prefix length is less than k
            prefix_length = k; // set the prefix length to k
        }
    }

    answer.prefix_length = prefix_length; // set the prefix length to the prefix length
    answer.positions = first; // set the positions to the vector
    answer.chars_compared = chars_compared; // set the chars compared to the chars compared
    return answer;
} // Complexity: O(M) |  M = pattern.size()

struct CompareResult {
    bool isMatch;
    int chars_compared;
    int idx;
};

CompareResult compare(int i, const string &pattern, unsigned long pattern_size, const string &text, vector<int> positions) {
    int chars_compared = 0;
    bool match = true;
    int j = 0; // j is the index of the pattern
    for(; j< pattern_size; ++j){
        if(text[j+i] == pattern[j]){ // if the char is equal to the pattern
            chars_compared++; // add 1 to the chars compared
        } else { // if the char is not equal to the pattern
            chars_compared++; // add 1
            match = false; // set the match to false
            break;
        }
    }
    CompareResult compare_result; // create a compare result
    compare_result.isMatch = match; // set the isMatch to the match
    compare_result.chars_compared = chars_compared; // set the chars compared to the chars compared
    if (positions.empty() || j < positions[0]){ // if the positions vector is empty or j is less than the first index in the vector
        compare_result.idx = i+j+1; // set the index to i+j+1
    } else {
        compare_result.idx = i+positions[0]; // set the index to i+the first index in the vector
    }
    return compare_result; // return the compare result
} // Complexity: O(M) | M = pattern.size()

void smarter_search(string const& text, string const& pattern) { // smarter search
    int char_compared = 0; // chars compared
    int comparisons = 0;
    unsigned long const pattern_size(pattern.size()); // pattern size
    unsigned long const endpos(text.size() - pattern_size + 1); // end position
    PrefixResult prefix_result = find_prefix_suffix(pattern);
    char_compared += prefix_result.chars_compared;
    for (int i=0; i < endpos;){ // for each index in the text

        CompareResult result = compare(i, pattern, pattern_size, text, prefix_result.positions); 

        if (result.isMatch) { // if the match is true
            cout << i << " |" << text.substr(i,pattern_size) << "|  " << "1" << "  <---- match!" << "\n"; // print the match and the index
        } else { // if the match is false
            cout << i << " |" << text.substr(i,pattern_size) << "|  " << "0 " << "\n";
        }
        char_compared += result.chars_compared; // add the chars compared to the total chars compared
        i = result.idx; // set i to the index
        comparisons++; // add 1 to the comparisons
    }
    cout << "Total comparisons: " << comparisons << "\n"; // print the total comparisons
    cout << "Total chars compared: " << char_compared << "\n"; // print the total chars compared
} // Complexity: O(N*M) | N = text.size() | M = pattern.size() | It is better than brute force algorithms as it skips some backtracking


void MPentry(string const& pattern, int pattern_size, int* MPtable, int& chars_compared){
    int l = 0;
    MPtable[0] = 0; // set the first index to 0
    int i = 1;
    while (i < pattern_size) { // while i is less than the pattern size
        if (pattern[i] == pattern[l]) { // if the char is equal to the pattern
            chars_compared++;
            l++; // add 1 to l
            MPtable[i] = l; // set the index to l 
            i++; // add 1 to i
        }
        else //if the char isn't equal to the pattern 
        {
            chars_compared++; // add 1 to the chars compared
            if (l != 0) { // if l is not equal to 0
                chars_compared++; // add 1 to the chars compared
                l = MPtable[l - 1]; // set l to the index of the table
            }
            else // if l is equal to 0
            {
                chars_compared++; // add 1 to the chars compared
                MPtable[i] = 0; // set the index to 0
                i++;
            }
        }
    }
} // Complexity: O(M) | M = pattern.size()

void knuth_morris_pratt(string const& text, string const& pattern)
{
    int const pattern_size(pattern.size());
    int const endpos(text.size() - pattern_size + 1);
    int chars_compared = 0;

    int MPTable[pattern_size]; // create a table
    MPentry(pattern, pattern_size, MPTable, chars_compared); // call the MPentry function
    int i = 0;
    int j = 0;
    while (i < endpos) // while i is less than the end position
    {
        if (text[i] == pattern[j]) // if the char is equal to the pattern
        {
            chars_compared++; // add 1 to the chars compared
            i++; // add 1 to i
            j++; // add 1 to j
        }
        if (j == pattern_size) // if j is equal to the pattern size
        {
            cout << "Match at: " << i - j << "\n";
            j = MPTable[j - 1]; // set j to the index of the table
            chars_compared++; // add 1 to the chars compared
        }
        else if (i < endpos && text[i] != pattern[j]) // if i is less than the end position and the char is not equal to the pattern
        {
            chars_compared++; // add 1 to the chars compared
            if (j != 0) // if j is not equal to 0
            {
                j = MPTable[j - 1]; // set j to the index of the table
                chars_compared++; // add 1 to the chars compared
            }
            else // if j is equal to 0
            {
                i++; // add 1 to i
                chars_compared++; // add 1 to the chars compared
            }
        }
    }
    cout << "Total comparisons: " << chars_compared << "\n"; // print the total chars compared
} // Complexity: O(N+M) | N = text.size() | M = pattern.size()


void mp_demo (string const& pattern) {
    int pattern_size = pattern.size();
    int MPTable[pattern_size];
    int chars_compared = 0;
    MPentry(pattern, pattern_size, MPTable, chars_compared);
    cout << "|-| 0 | " << "-1" << " |" << endl;
    for (int i = 1; i < pattern.size(); ++i) {
        cout << "| " << pattern.substr(0,i) << " | " << i << " | " << MPTable[i-1] << " |" << endl;
    }
    cout << "| " << pattern << " | " << pattern.size() << " | " << "0" << " |" << endl;
} // Complexity: O(2M) | M = pattern.size()

int main() {
    string the_text = "panamanian banana fanatics can manage anacondas";
    string the_pattern = "ana";
    string sequence1 = "CCTAAGG";
    string sequence2 = "GCGGCCGC";
    string sequence3 = "TCGA";
    string original_sequence = "";
    int option = 0;

    
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
        cout << "[6] Knuth-Morris_Pratt\n";
        cout << "[7] KMP for Genetic code\n";
        cout << "[0] Exit\n";
        cout << "----------------------------------------\n";
        cout << "Option: ";
        option = validacion(option, 0,7);

        switch (option)
        {
            case 1:
                search_all(the_text,the_pattern);
                break;
            case 2:
                compare_demo(the_text,the_pattern);
                break;
            case 3:
                iter_demo(the_text,the_pattern);
                break;
            case 4:
                smarter_search(the_text,the_pattern);
                break;
            case 5:
                mp_demo(the_pattern);
                break;
            case 6:
                knuth_morris_pratt(the_text,the_pattern);
                break;
            case 7:
                knuth_morris_pratt(readData(),sequence1);
                knuth_morris_pratt(readData(),sequence2);
                knuth_morris_pratt(readData(),sequence3);
                break;
        }
    } while (option != 0);
    cout << "Ending..." << endl;
}