#include "linked.h"
#include "excel.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <cstdlib> 
#include <utility>


Excel object;


void beginSort()
{
    int index;
    cout << "Enter column number: ";
    cin >> index;
    cin.ignore();
    cout << endl;
    cout << endl;
    object.indexTable(index - 1);
   
}
void beginEdit()
{
    int row_num; 
    int col_num;
    cout << endl;
    cout << "Enter row number: ";
    cin >> row_num;
    cin.ignore();
    cout << "Enter column number: ";
    cin >> col_num;
    cin.ignore();
    object.edit(row_num,col_num);
}
void beginSave()
{
    string filename;
    cout << "Enter File Name (example.txt): ";
    cin >> filename;
    cin.ignore();
    g_save = true;
    myfile.open (filename);
    object.print_table();
    cout << endl;cout << endl;
    cout << filename << " has been saved!";
}
void beginFilter()
{
    int col_num;
    string filterVal;
    cout << endl;

    cout << "Enter column number: ";
    cin >> col_num;
    cout << "Enter filter: ";
    cin >> filterVal;
    cin.ignore();
    cout << endl;
    cout << endl;
    object.filter(col_num - 1,filterVal);

}
void beginAdd(bool avg)
{
    int rowC1;
    int colC1;
    int rowC2;
    int colC2;
    
    
    
    cout << "Enter row number of first cell: ";
    cin >> rowC1;
    cout << "Enter column number of first cell: ";
    cin >> colC1;
    cout << endl;
    cout << "Enter row number of second cell: ";
    cin >> rowC2;
    cout << "Enter colum number of second cell: ";
    cin >> colC2;
    cout << endl;


    pair <int,int> CELL1;
    pair <int,int> CELL2;

    CELL1.first = rowC1 - 1;
    CELL1.second = colC1 - 1;
    CELL2.first = rowC2 - 1;
    CELL2.second = colC2 - 1;

    object.add(CELL1, CELL2,avg);

}
void beginImport()
{
    string filename;
    int num_rows;
    int num_cols;

    cout << "Enter file name: ";
    cin >> filename;
    cin.ignore();

    cout << "Enter number of rows: ";
    cin >> num_rows;
    cin.ignore();

    cout << "Enter number of columns: ";
    cin >> num_cols;
    cin.ignore();


    object.import(filename, num_rows, num_cols);
}


int main()
{
    bool avg = false;

    string password;

    while (true)
{
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
    cout << "C++ Excel" << endl << endl;
    cout << "0. Quit" << endl;
    cout << "1. Add Column" << endl;
    cout << "2. Add Data" << endl;
    cout << "3. Sort" << endl;
    cout << "4. Edit Cell" << endl;
    cout << "5. Filter Column" << endl;
    cout << "6. Summation " << endl;
    cout << "7. Average " << endl;
    cout << "8. Print Table" << endl;
    cout << "9. Save File" << endl;
    cout << "10. Import File" << endl;
    cout << "11. Encrpyt" << endl;
  

    cout << "> ";
    string option;
    getline(cin, option);
    // cin >> option;
    
    if (option.compare("0") == 0) {
        break;
    } else if (option.compare("1") == 0) {
        object.column();
    }else if (option.compare("2") == 0) {
        object.add_data();
    } else if (option.compare("3") == 0) {
        object.print_table();
        beginSort();
    } else if (option.compare("4") == 0) {
        object.print_table();
        beginEdit();
    } else if (option.compare("5") == 0) {
        object.print_table();
        beginFilter();
    } else if (option.compare("6") == 0) {
        //Finding the sum of a range
        object.print_table();
        beginAdd(avg);
    } else if (option.compare("7") == 0) {
        //Finding the average of a range
        avg = true;
        object.print_table();
        beginAdd(true);
    } else if (option.compare("8") == 0) {
        object.print_table();
    } else if (option.compare("9") == 0) {
        beginSave();
    } else if (option.compare("10") == 0) {
        beginImport();
    } 
    // cout << endl;
    
}





    return 0;
}