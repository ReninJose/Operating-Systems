// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "process.h"

int main(){
    int parent_pid;
    int status;
    pid_t pid;

    cout << "Parent PID is " << getpid() << endl;
    parent_pid = getpid();

    for(int i = 0; i < 3; i++){
        // Forcing only the parent process to create children
        if(getpid() == parent_pid){
            pid = fork();
            if (pid == 0){
                printStart();
            }
        }
        else
            continue;
    }
    if(getpid() == parent_pid){
        for(int i = 0; i < 3; i++){
            printDone(wait(&status));
        }
    }
    exit(0);
}