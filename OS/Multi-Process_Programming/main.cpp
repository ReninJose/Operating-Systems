// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "process.h"

int main(int argc, char **argv){
    int parent_pid;                 // Storing parent's PID
    int status;                     // For wait()
    int child = 1;                   // Index to identify child on vector child_pid
    int total_child;

    pid_t pid;                      

    vector <int> child_pid;         // A vector for all child's PIDs

    cout << "Parent PID is " << getpid() << endl;
    parent_pid = getpid();

    // Converting command arguement to int
    total_child = atoi(argv[1]);

    for(int i = 0; i < total_child; i++){
        // Forcing only the parent process to create children
        if(getpid() == parent_pid){
            pid = fork();
            child_pid.push_back(pid);
            if (pid > 0){
                start_process(pid, child);
                child += 1;
            }
        }
        else 
            continue;
    }
    if(getpid() == parent_pid){

        for(int i = 0; i < total_child; i++){
            end_process(wait(&status), child_pid);
        }
    }

    // To end all processes
    exit(0);
}
