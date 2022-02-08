// Renin Kingsly Jose
// EECE.4811 Operating Systems
// main.cpp

#include "data.h"

int main(int argc, char **argv) {
    string testStrings;
    vector<string> testIntegers;

    ifstream testCase(argv[1]);                      // Opening test file

    while (!testCase.eof()){
        getline(testCase, testStrings);
        testIntegers.push_back(testStrings);      
    }
    
    // Performing Stack Operation
    stackOperation(testIntegers);
    // Performing Queue Operation
    queueOperation(testIntegers);
    // Performing List Operation
    listOperation(testIntegers);

    return 0;
}