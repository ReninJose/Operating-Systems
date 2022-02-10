// Renin Kingsly Jose
// EECE. 4810 Operating Systems

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void printStart();
const int printError();
void printDone(pid_t processDone);

#endif