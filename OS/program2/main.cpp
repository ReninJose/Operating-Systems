// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "processor.h"


int main(){
    pid_t pid;

    pid = fork();

    // First Child Processor
    if (pid == 0){
        printChild();
    }  
    // Parent Processor
    else{
        wait(NULL);
        cout << "Parent's PID = " << getpid() << endl;
    }
    return 0;
}