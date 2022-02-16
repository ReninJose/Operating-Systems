// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "process.h"

int main(int argc, char **argv){
    int parent_pid;                             // Storing parent's PID
    int status;                                 // For wait()
    int child = 1;                              // Index to identify child on vector child_pid
    int total_child;
    int testindex = 0;                          // Index to cycle  through test cases

    // String arrays to cycle through test cases
    const char* file[5] = { "test1", "test2", "test3", "test4", "test5" };
    const char* exec[5] = { "./test1", "./test2", "./test3", "./test4", "./test5" };

    pid_t pid;                      

    vector <int> child_pid;                     // A vector for all child's PIDs

    cout << "Parent PID is " << getpid() << endl;
    parent_pid = getpid();

    // Converting command argument to int
    total_child = atoi(argv[1]);

    for(int i = 0; i < total_child; i++){
        
        if (testindex > 4){
            testindex = 0;
        }

        // Forcing only the parent process to create children
        if(getpid() == parent_pid) {
	        pid = fork();
            child_pid.push_back(pid);

            if (pid < 0) 
                return printError();

            // Parent enters here
            if (pid > 0){
                start_process(pid, child);
                child += 1;
            }

            // Child Enters here
            if (pid == 0) {
                execlp(exec[testindex], file[testindex], NULL);
                // Ending Child Processes
                exit(0);                       
                break;
            }
        }
        testindex++;
    }

    if(getpid() == parent_pid){

        for(int i = 0; i < total_child; i++){
            end_process(wait(&status), child_pid);
        }
    }

    // Ending Parent Process
    exit(0);
}
