#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct dict
{
    string eng, rus;
    int proc;
};


int function_of_selectionRUS(vector<dict> &list, int k, int v, int x, int y);
int function_of_selectionENG(vector<dict> &list, int k, int v, int x, int y);
int func_check_choiseRU(vector<dict> &list, int k, int v, int i);
int func_check_choiseENG(vector<dict> &list, int k, int v, int i);
void English_Russian_test(vector<dict> &list);
void Russian_English_test(vector<dict> &list);
void correct_writing_word(vector<dict> &list);
void input_words(vector<dict> &list);
int writeinfile_1(vector<dict> &list);
int writeinfile_2(vector<dict> &list);
int readfromfile(vector<dict> &list);
void words_more_5(vector<dict> &list);

#endif