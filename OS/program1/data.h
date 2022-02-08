// Renin Kingsly Jose
// EECE.4811 Operating Systems
// data.h

#ifndef DATA_H
#define DATA_H

#include <iostream> 
#include <stack>
#include <queue>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void stackOperation(const vector<string> testInt_Stack);
void stackPrint(stack<string> s);

void queueOperation(const vector<string> testInt_Queue);
void queuePrint(queue<string> q);

void listOperation(const vector<string> testInt_List);
void listPrint(list<int> l);

#endif