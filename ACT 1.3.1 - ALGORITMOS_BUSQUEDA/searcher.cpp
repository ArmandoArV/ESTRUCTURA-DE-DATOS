#include "searcher.h"
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

void Searcher::smarter_search(){  
    int char_compared = 0;
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
        //
        
    }
    cout << "Total comparisions: " << endpos << "\n";          // print the total comparisions
    cout << "Total chars compared: " << char_compared << "\n"; // print the total chars compared
    
}