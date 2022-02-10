// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "process.h"

void printStart() {
    cout << "Started child with PID: " << getpid() << endl;
}

void printDone(pid_t processDone) {
    cout << "Child (PID: " << processDone << ") finished" << endl;
}

const int printError() {
    cout << "Fork Failed" << endl;
    return 1;
}