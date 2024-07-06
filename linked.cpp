#include "linked.h"
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <algorithm>


bool g_save = false;
ofstream myfile;
extern int max_ln;

Node::Node(string& s)
{
    this->next = nullptr;
    this->value = s;

}
Node::~Node()
{

}




LL::LL()
{
    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;
}
LL::~LL()
{
    
}
void LL::push_back(string& s)
{
    Node* new_node = new Node(s);
    if(this->size == 0) this->first = new_node;
    if(this->size > 0) this->last->next = new_node;
    this->last = new_node;
    
    this->size++;
}

void LL::print(int num_cols)
{
    
    
    for (Node* current = this->first; current; current = current->next)
    {

        if(g_save) myfile << current->value ;
        cout << current->value;
        
        
        
        if(current->next != nullptr && g_save ){
            if((int)current->value.size() < max_ln){
                myfile << setw(9 + (max_ln - (int) current->value.size() ));
            }

            else myfile << setw(10);
        } 
        if(current->next != nullptr){
            if((int)current->value.size() < max_ln){
                cout << setw(10 + (max_ln - (int) current->value.size() ));
            }

            else cout << setw(10);
        } 
    }
    if(g_save) myfile << "\t " << endl;
    cout << "\t" << endl;
   
}
string LL::nthNodeValue(int index)
{
    Node* current = this->first;
    int count = 0;
    
    while(current != nullptr)
    {
        if(count == index) return current->value;
        count++;
        current = current->next;

    }
    return " ";
}
Node* LL::nthNode(int index)
{
    Node* current = this->first;
    int count = 0;
    
    while(current != nullptr)
    {
        if(count == index) return current;
        count++;
        current = current->next;

    }
    throw runtime_error("Non existing");
    //return;
}
int LL::sizeLL()
{
    return this->size;
}
void LL::changeNode(int i, string& n)
{
    nthNode(i)->value = n;
}
