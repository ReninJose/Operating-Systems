// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void start_process(pid_t &pid, int& child_num);

void end_process(pid_t processDone, vector<int> &child_pid);

const int printError();

#endif
