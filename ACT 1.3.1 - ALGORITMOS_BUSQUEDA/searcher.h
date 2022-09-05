#pragma once
#include <stdio.h>
#include <string>
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
};
