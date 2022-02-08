// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "processor.h"

void printChild(){
        int processCounter = 1;

        cout << "Child " << processCounter << " PID = " << getpid() << endl;
        cout << "Child " << processCounter << " has finished" << "(PID = " << getpid() << ")" << endl;
        processCounter += 1;
}
