#include "linked.h"
#include "excel.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <bits/stdc++.h>

#include <utility>

int g_active;
vector <int> longest;
int max_ln = 0;
int columnCall = 0;

Excel::Excel()
{
    vector <vector <LL> > g_indices;
    vector <LL> g_table;
    g_rowIndex = 1;

}
Excel::~Excel()
{
    
}

void Excel::column()
{
    columnCall++;

    if(columnCall == 1){
        LL col;
        g_table.push_back(col);
    }
    string col_name;

    while(true)
    {
        cout << "Column Title: "; 
       getline(cin,col_name);
    //    longest.push_back(col_name.size());
        
         if (col_name.size() == 0) break;
        
        else{
            longest.push_back(col_name.size());
            g_table[0].push_back(col_name);
        } 

    }
}
void max_length()
{
    max_ln = longest[0];
    for(int i = 0; i < (int) longest.size(); i++)
    {
        if(longest[i] > max_ln) max_ln = longest[i];
    }
    
}
void Excel::add_data()
{
    LL rows;
    string title;
    string data;
    string empty = "___";
    g_table.push_back(rows);
    
    

    for (int i = 0; i < (int) g_table[0].sizeLL(); i++)
    {
        title = g_table[0].nthNodeValue(i);
        cout << title << ": ";
        getline(cin,data);
        if (data.size() == 0){
            //g_table[g_rowIndex].push_back(empty);
            return;
        } 
        longest.push_back(data.size());
        g_table[g_rowIndex].push_back(data);
       
    }
     g_rowIndex++;    
   
}
void Excel::print_table()
{
    g_save = true;
    max_length();
    for (int i = 0; i < (int) g_table[0].sizeLL(); i++)
    {
     
        cout << setw(5) << i + 1 << "\t\t";
    }
 
    cout << endl;
    for (int i = 0; i < (int) g_table.size(); i++)
    {
        if(i+1 < 10) cout << i + 1 << "  |";
        else cout << i + 1 << " |";
        g_table[i].print(g_table[0].sizeLL());
    }
 
    cout << endl;

    if(g_save) myfile.close();
}
void Excel::edit(int& row_num, int& col_num)
{
    string newText;

    cout << "Original text: " << g_table[row_num - 1].nthNodeValue(col_num - 1) << endl;
    cout << "New text: ";
    getline(cin, newText);
    
    if(g_table[row_num - 1].sizeLL() < col_num){
        g_table[row_num - 1].push_back(newText);
    }

    else g_table[row_num -1].changeNode(col_num -1, newText);
    cout << endl;
    print_table();
}
void Excel::printIndex(int i)
{

    g_table = g_indices[i]; 
    vector<LL> index = g_indices[i];
    max_length();
    for (int i = 0; i < (int) g_table[0].sizeLL(); i++)
    {
        cout << "  " << i + 1 << "\t\t";
    }
    
    cout << endl;
    for (int i = 0; i < (int) index.size() - 1; i++)
    {
        if(i+1 < 10) cout << i + 1 << "  |";
        else cout << i + 1 << " |";
        for (int j = 0; j < (int) g_indices.size(); j++)
        {
            if(j > 0 && (int) index[i].nthNodeValue(j-1).size() < max_ln){
                cout << setw(10 + (max_ln - (int) index[i].nthNodeValue(j-1).size() ));
            }
            else if (j > 0){
                cout << setw(10);
            }
            

            cout << index[i].nthNodeValue(j);
        }
        cout << endl;
    }
 
    
}
bool compare(LL a, LL b)
{
    string aVal = a.nthNodeValue(g_active);
    string bVal = b.nthNodeValue(g_active);

   return (aVal < bVal);
}
void Excel::indexTable(int index)
{
    
    g_indices.clear();
    g_indices.resize((int) g_table[0].sizeLL() );
    
    for (int i = 0; i < (int) g_table[0].sizeLL(); i++)
    {
        vector<LL> index = g_indices[i];
        for (int j = 0; j < (int) g_table.size(); j++)
        {

           index.push_back(g_table[j]);
           g_active = i;
           sort(index.begin() + 1 ,index.end(),compare);
           g_indices[i] = index;
            
           
        }
        
    } 
    printIndex(index);
}
void Excel::filter(int col_num, string filterVal)
{
    cout << "Filtered Table" << endl;
     for (int i = 0; i < (int) g_table.size()  ; i++)
    {
        cout << "_______" ;
    }
    cout << endl;
    for (int i = 0; i < (int) g_table.size(); i++)
    {
        if(g_table[i].nthNodeValue(col_num) == filterVal){
            g_table[i].print(g_table[0].sizeLL());
        }
    }
    for (int i = 0; i < (int) g_table.size()  ; i++)
    {
        cout << "_______" ;
    }
    
}
void Excel::add(pair<int,int> begin, pair<int,int> end, bool avg)
{
    vector <int> values;
    string temp;
    int count = 0;

    if(begin.second == end.second){
        for (int j = begin.first ; j < end.first + 1; j++)
        {
            temp = g_table[j].nthNodeValue(begin.second);
            values.push_back(stoi(temp));
            count++;
        }
    }

    else{
        for (int i = begin.second; i < end.second + 1; i++)
        {
        temp = g_table[begin.first].nthNodeValue(i);
        values.push_back(stoi(temp));
        count++;
        }
    }
    
    
    
    if(avg){
       int sum = accumulate(values.begin(), values.end(),0);
       cout << "AVERAGE OF RAGE: " << sum / count;
    }
    else cout <<"SUM OF RANGE: " << accumulate(values.begin(), values.end(),0);
    

}
void Excel::import(string filename, int numRows, int numCols)
{
    // string col1;
    // string col2;
    // string col3;
    vector <string> n;
    n.resize(numCols);
   
    
    LL row;

    ifstream iF(filename);

    if(!iF.is_open()){
        cerr << "Error" << endl;

    }
    
    for (int i = 0; i < numRows; i++)
    {
        g_table.push_back(row);

        for (int j = 0; j < (int) n.size(); j++)
        {
            iF >> n[j];
            g_table[i].push_back(n[j]);
            longest.push_back(n[j].size());
        }  
     
        
    }
    
    iF.close();

    g_rowIndex = numRows;
    print_table();
    
}