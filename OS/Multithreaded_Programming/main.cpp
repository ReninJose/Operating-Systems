// Renin Kingsly Jose
// EECE.4811 Operating Systems
// main.cpp

#include "prod_cons_MT.h"


int main(int argc, char* argv[]){

    monitor m(atoi(argv[1]));           // Setting up buffer size

    // Initialize threads
    
    // Initialize Lock
    pthread_mutex_init(&lock,NULL);

    // Join all threads back to parent thread

    return 0;
}