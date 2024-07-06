#ifndef excel_table
#define excel_table

#include "linked.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm> 
extern bool g_save;
extern ofstream myfile;


class Excel{
protected:
    vector <vector <LL> > g_indices;
    vector <LL> g_table;
    int g_rowIndex = 1;
    



public:
    Excel();
    virtual ~Excel();
    void column();
    void add_data();
    void print_table();
    void edit(int& row_num, int& col_num);
    void printIndex(int i);
    void indexTable(int index);
    void filter(int col_num, string filterVal);
    void add(pair<int,int> begin, pair<int,int> end, bool avg);
    void import(string filename, int numRows, int numCols);




};


#endif 

