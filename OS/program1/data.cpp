// Renin Kingsly Jose
// EECE.4811 Operating Systems
// data.cpp

#include "data.h"

// Stacks data
void stackOperation(const vector<string> testInt_Stack) {
    stack<string> stack;
    for (int i = 0; i < testInt_Stack.size(); i++) {
        stack.push(testInt_Stack.at(i));
    }
    stackPrint(stack);
}

// Prints data from the stack (filo)
void stackPrint(stack<string> s) {
    cout << "STACK CONTENTS:" << endl; 
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Queue data
void queueOperation(const vector<string> testInt_Queue){
    queue<string> queue;
    for(int j = 0; j < testInt_Queue.size(); j++){
        queue.push(testInt_Queue.at(j));
    }
    queuePrint(queue);
}

// Prints data from the queue (fifo)
void queuePrint(queue<string> q){
    cout << "QUEUE CONTENTS:" << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void listOperation(const vector<string> testInt_List){
    list<int> list;
    vector<int> listNumbers;
    int temp;
    // loop index
    int k;
  
    // converting string datas to integers
    // stringstream class is referenced from : https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    for (k = 0; k < testInt_List.size(); k++){       
        stringstream str(testInt_List.at(k));
        str >> temp;
        listNumbers.push_back(temp);
    }

    // Rearranging numbers in ascending order
    for(int l = 0; l < listNumbers.size(); l++){
        for (k = 1; k < listNumbers.size(); k++){
            if(listNumbers[k-1] > listNumbers[k]){
                temp = listNumbers[k-1];
                listNumbers[k-1] = listNumbers[k];
                listNumbers[k] = temp;
            }
            else
                continue;
        }
    }

    for (k = 0; k < listNumbers.size(); k++){
        list.push_back(listNumbers.at(k));
    }

    listPrint(list);
}

void listPrint(list<int> l){
    cout << "LIST CONTENTS:" << endl; 
    while(!l.empty()){
        cout << l.front() << " " ;
        l.pop_front();
    }
    cout << endl;
}
