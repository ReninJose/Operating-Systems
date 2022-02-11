// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#include "process.h"

void start_process(pid_t &pid, int& child_num) {

    cout << "Started child " << child_num << " with PID: " << pid << endl;
}

void end_process(pid_t processDone, vector<int> &child_pid) {

    for (int i = 0; i < child_pid.size(); i++) {
        if (child_pid.at(i) == processDone) {
            cout << "Child " << i+1 << " (PID: " << processDone << ") finished" << endl;
        }
        else
            continue;
    }
}

const int printError() {

    perror("Fork failed");

    return 1;
}