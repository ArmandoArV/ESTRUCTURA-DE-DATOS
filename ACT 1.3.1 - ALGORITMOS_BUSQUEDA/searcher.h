#pragma once
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Searcher
{
private:
    string the_text;
    string the_pattern;

public:
    Searcher(string the_text, string the_pattern);
    string getText();
    string getPattern();
    void setText(string the_text);
    void setPattern(string the_pattern);
    void search_all();
    void compare_demo();
    void iter_demo();
    void smarter_search();
    void knuth_morris_pratt();
    void morris_pratt();
    // Structs
    struct PrefixResult {
        int prefix_length;
        vector<int> positions;
        int chars_compared;
    };
    struct CompareResult {
        bool isMatch;
        int chars_compared;
        int idx;
    };
    PrefixResult find_prefix_suffix(string the_pattern);
    CompareResult compare(int i, string the_pattern, unsigned long pattern_size, string the_text, vector<int> positions);
};
