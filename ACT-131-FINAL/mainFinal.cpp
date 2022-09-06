//
//  main.cpp
//  Search_Algorithms
//
//  Created by Antonio Nogueron Barcenas and Armando Arredondo Valle
//  on 4/Sep/2022.
//

#include <iostream>
#include <vector>
using namespace std;

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
}

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
}


void iter_demo_bienhecho(string const& text, string const& pattern) { // iter_demo_bienhecho
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
}

struct PrefixResult {
    int prefix_length;
    vector<int> positions;
    int chars_compared;
};

PrefixResult find_prefix_suffix(string const& pattern){
    int prefix_length = 0;
    vector<int> first;
    int chars_compared = 0;
    PrefixResult answer;
    for(int i=1; i < pattern.size(); ++i){
        if(pattern[i] == pattern[0]){
            first.push_back(i);
            chars_compared++;
        }
    }
    if (first.empty()) {
        answer.prefix_length = 0;
        answer.chars_compared = chars_compared;
        answer.positions = first;
        return answer;
    }
    for (int i = 0; i < first.size(); ++i){
        int k = 1;
        while(pattern[k] == pattern[first[i]+k]){
            k++;
            chars_compared++;
        }
        if(prefix_length < k){
            prefix_length = k;
        }
    }

    answer.prefix_length = prefix_length;
    answer.positions = first;
    answer.chars_compared = chars_compared;
    return answer;
}

struct CompareResult {
    bool isMatch;
    int chars_compared;
    int idx;
};

CompareResult compare(int i, const string &pattern, unsigned long pattern_size, const string &text, vector<int> positions) {
    int chars_compared = 0;
    bool match = true;
    int j = 0;
    for(; j< pattern_size; ++j){
        if(text[j+i] == pattern[j]){ // if the char is equal to the pattern
            chars_compared++;
        } else {
            chars_compared++;
            match = false;
            break;
        }
    }
    CompareResult compare_result;
    compare_result.isMatch = match;
    compare_result.chars_compared = chars_compared;
    if (positions.empty() || j < positions[0]){
        compare_result.idx = i+j+1;
    } else {
        compare_result.idx = i+positions[0];
    }
    return compare_result;
}

void smarter_search(string const& text, string const& pattern) { // smarter search
    int char_compared = 0; // chars compared
    int comparisons = 0;
    unsigned long const pattern_size(pattern.size()); // pattern size
    unsigned long const endpos(text.size() - pattern_size + 1); // end position
    PrefixResult prefix_result = find_prefix_suffix(pattern);
    char_compared += prefix_result.chars_compared;
    for (int i=0; i < endpos;){ // for each index in the text

        CompareResult result = compare(i, pattern, pattern_size, text, prefix_result.positions);

        if (result.isMatch) {
            cout << i << " |" << text.substr(i,pattern_size) << "|  " << "1" << "  <---- match!" << "\n";
        } else {
            cout << i << " |" << text.substr(i,pattern_size) << "|  " << "0 " << "\n";
        }
        char_compared += result.chars_compared;
        i = result.idx;
        comparisons++;
    }
    cout << "Total comparisons: " << comparisons << "\n"; // print the total comparisons
    cout << "Total chars compared: " << char_compared << "\n"; // print the total chars compared
}

void knuth_morris_pratt(string const& text, string const& pattern)
{
    int const pattern_size(pattern.size());
    int const endpos(text.size() - pattern_size + 1);
    int i = 0;
    int j = 0;
    int k = 0;
    int MPTable[pattern_size];
    MPTable[0] = 0;
    for (int i = 1; i < pattern_size; i++)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            MPTable[i] = j;
        }
        else
        {
            if (j != 0)
            {
                j = MPTable[j - 1];
                i--;
            }
            else
            {
                MPTable[i] = 0;
            }
        }
    }
    
    for (int i = 0; i < pattern_size; i++)
    {
        cout << MPTable[i] << " ";
    }
    cout << "\n";
    while (i < endpos)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == pattern_size)
        {
            cout << "Match at: " << i - j << "\n";
            j = MPTable[j - 1];
        }
        else if (i < endpos && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = MPTable[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main() {
    string the_text = "panamanian banana fanatics can manage anacondas";
    string the_pattern = "ana";
    int option = 0;
    // Menu
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
            //search_all(the_text,the_pattern);
            //search_all("aabcd","abcd");
            search_all("aaaab","aaab");
            break;
        case 2:
            //compare_demo(the_text,the_pattern);
            compare_demo("aaaab","aaab");
            break;
        case 3:
            iter_demo_bienhecho(the_text,the_pattern);
            break;
        case 4:
            smarter_search(the_text,the_pattern);
            break;
        case 5:
            //knuth_morris_pratt(the_text,the_pattern);
            knuth_morris_pratt("abcabjofhabcababcabdabp","abcabdabp");
            break;
        default:
            cout << "Invalid option!";
            break;
        }
    } while (option != 0);
}