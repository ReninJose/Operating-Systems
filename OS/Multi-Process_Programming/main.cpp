// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "process.h"

int main(int argc, char **argv){
    int parent_pid;                 // Storing parent's PID
    int status;                     // For wait()
    int child = 1;                   // Index to identify child on vector child_pid
    int total_child;
    int testindex = 0;

    pid_t pid;                      

    vector <int> child_pid;         // A vector for all child's PIDs

    string file[5] = { "test1", "test2", "test3", "test4", "test5" };
    

    cout << "Parent PID is " << getpid() << endl;
    parent_pid = getpid();

    // Converting command argument to int
    total_child = atoi(argv[1]);

    for(int i = 0; i < total_child; i++){
        
        if (testindex > 4)
            testindex = 0;
        // Forcing only the parent process to create children
        if(getpid() == parent_pid) {
	        pid = fork();
            child_pid.push_back(pid);

            if (pid < 0) 
                return printError();

            if (pid > 0){
                start_process(pid, child);
                child += 1;
            }
            
            if (pid == 0) {

                execlp(file[testindex].insert(0, "./"), file[testindex], NULL);
                break;
                
                // else if(i == 1) {
                //     execlp("./test2", "test2", NULL);
                //     break;
                // }
                // else if(i == 2) {
                //     execlp("./test3", "test3", NULL);
                //     break;
                // }
                // else if(i == 3) {
                //     execlp("./test4", "test4", NULL);
                //     break;
                // }
                // else if(i == 4) {
                //     execlp("./test5", "test5", NULL);
                //     break;
                // }
                
            }
        }
        testindex++;
    }
    // if (getpid() == parent_pid)
    //     for (int i = 0 ; i < child_pid.size(); i++)
	//         cout << child_pid.at(i) << endl;

//    if(pid == 0) {
	//cout << "In child." << endl;
//	execlp("/bin/test1.c", "gcc -o test1 test1.c", NULL);
//	execlp("./test1", "test1", NULL);
//	cout << "TEST1" << endl;
//    }

//     if (pid == 0) {
//         for (int i = 0; i < child_pid.size(); i++) {	   
// //		cout << "Child pid" << i << ": " << getpid() << endl;
// //		cout << "Child vpid" << i << ": " << child_pid.at(i) << endl;
	        
// 	}
//     }

    if(getpid() == parent_pid){

        for(int i = 0; i < total_child; i++){
            end_process(wait(&status), child_pid);
        }
    }

    // To end all processes
    exit(0);
}
