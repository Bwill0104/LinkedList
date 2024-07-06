#include <string>
#ifndef linked_list
#define linked_list

using namespace std;




class Node{
protected:
    Node* next;
    string value;

public:
    Node(string& s);
    virtual ~Node();

    friend class LL;
};

class LL{
protected:
    Node* first;
    Node* last;
    int size;

public:
    LL();
    virtual ~LL();
    void push_back(string& s);
    void print(int num_cols);
    string nthNodeValue(int index);
    Node* nthNode(int index);
    int sizeLL();
    void changeNode(int i, string& n);
    void sort();


};

#endif