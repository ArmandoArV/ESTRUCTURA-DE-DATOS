#include "searcher.h"
#include <vector>
#include <iostream>
using namespace std;
Searcher::Searcher(string the_text, string the_pattern)
{
    this->the_text = the_text;
    this->the_pattern = the_pattern;
}
string Searcher::getText()
{
    return this->the_text;
}
string Searcher::getPattern()
{
    return this->the_pattern;
}
void Searcher::setText(string the_text)
{
    this->the_text = the_text;
}
void Searcher::setPattern(string the_pattern)
{
    this->the_pattern = the_pattern;
}
void Searcher::search_all()
{
    int const pattern_size(this->the_pattern.size());
    int const endpos(this->the_text.size() - pattern_size + 1);
    for (int POs(0); POs < endpos; ++POs)
    {
        if (this->the_text.compare(POs, pattern_size, this->the_pattern) == 0)
        {
            cout << "Match at: " << POs << "\n";
        }
    }
}

void Searcher::compare_demo()
{
    unsigned long const pattern_size(this->the_pattern.size());           // pattern size
    unsigned long const endpos(this->the_text.size() - pattern_size + 1); // end position
    short evaluation;
    int total_comparisions = 0;
    for (int POs(0); POs < endpos; ++POs)
    {                                                                              // for each letter in the text that can match the string
        evaluation = this->the_text.compare(POs, pattern_size, this->the_pattern); // compare
        total_comparisions++;
        if (evaluation == -1)
        {                                                                                                  // if comparision gives -1 formats differently
            cout << POs << " |" << this->the_text.substr(POs, pattern_size) << "| " << evaluation << "  "; // formats the print to match requirements
        }
        else
        {
            cout << POs << " |" << this->the_text.substr(POs, pattern_size) << "|  " << evaluation << "  "; // formats the print to match requirements
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

void Searcher::iter_demo()
{
    int char_compared = 0;                                                // chars compared
    unsigned long const pattern_size(this->the_pattern.size());           // pattern size
    unsigned long const endpos(this->the_text.size() - pattern_size + 1); // end position
    bool match;
    for (int i = 0; i < endpos; ++i)
    { // for each index in the text
        string substring = this->the_text.substr(i, pattern_size);
        for (int j = 0; j < pattern_size; ++j)
        { // for each char in the pattern
            if (substring[j] == this->the_pattern[j])
            {                    // if the char is equal to the pattern
                char_compared++; // add 1 to the chars compared
            }
            else
            {                    // if the char is not equal to the pattern
                char_compared++; // add 1 to the chars compared
                match = false;   // set the match to false
                break;           // break the loop
            }
            match = true; // set the match to true
        }
        if (match)
        { // if the match is true
            cout << i << " |" << substring << "|  "
                 << "1"
                 << "  <---- match!"
                 << "\n";
        }
        else
        { // if the match is false
            cout << i << " |" << substring << "|  "
                 << "0 "
                 << "\n";
        }
    }
    cout << "Total comparisions: " << endpos << "\n";          // print the total comparisions
    cout << "Total chars compared: " << char_compared << "\n"; // print the total chars compared
}

void Searcher::knuth_morris_pratt()
{
    int const pattern_size(this->the_pattern.size());
    int const endpos(this->the_text.size() - pattern_size + 1);
    int i = 0;
    int j = 0;
    int k = 0;
    int lps[pattern_size];
    lps[0] = 0;
    for (int i = 1; i < pattern_size; i++)
    {
        if (this->the_pattern[i] == this->the_pattern[j])
        {
            j++;
            lps[i] = j;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
                i--;
            }
            else
            {
                lps[i] = 0;
            }
        }
    }
    for (int i = 0; i < pattern_size; i++)
    {
        cout << lps[i] << " ";
    }
    cout << "\n";
    while (i < endpos)
    {
        if (this->the_text[i] == this->the_pattern[j])
        {
            i++;
            j++;
        }
        if (j == pattern_size)
        {
            cout << "Match at: " << i - j << "\n";
            j = lps[j - 1];
        }
        else if (i < endpos && this->the_text[i] != this->the_pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

Searcher::PrefixResult find_prefix_suffix(string the_pattern){
    int prefix_length = 0;
    vector<int> first;
    int chars_compared = 0;
    Searcher::PrefixResult answer;
    for(int i=1; i < the_pattern.size(); ++i){
        if(the_pattern[i] == the_pattern[0]){
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
        while(the_pattern[k] == the_pattern[first[i]+k]){
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



Searcher::CompareResult compare(int i, const string &pattern, unsigned long pattern_size, const string &text, vector<int> positions) {
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
    Searcher::CompareResult compare_result;
    compare_result.isMatch = match;
    compare_result.chars_compared = chars_compared;
    if (positions.empty() || j < positions[0]){
        compare_result.idx = i+j+1;
    } else {
        compare_result.idx = i+positions[0];
    }
    return compare_result;
}

void Searcher::smarter_search() { // smarter search
    int char_compared = 0; // chars compared
    int comparisons = 0;
    unsigned long const pattern_size(this->the_pattern.size()); // pattern size
    unsigned long const endpos(this->the_text.size() - pattern_size + 1); // end position
    Searcher::PrefixResult prefix_result = find_prefix_suffix(this->the_pattern);
    char_compared += prefix_result.chars_compared;
    for (int i=0; i < endpos;){ // for each index in the text

        CompareResult result = compare(i, this->the_pattern, pattern_size, this->the_text, prefix_result.positions);

        if (result.isMatch) {
            cout << i << " |" << this->the_text.substr(i,pattern_size) << "|  " << "1" << "  <---- match!" << "\n";
        } else {
            cout << i << " |" << this->the_text.substr(i,pattern_size) << "|  " << "0 " << "\n";
        }
        char_compared += result.chars_compared;
        i = result.idx;
        comparisons++;
    }
    cout << "Total comparisons: " << comparisons << "\n"; // print the total comparisons
    cout << "Total chars compared: " << char_compared << "\n"; // print the total chars compared
}
