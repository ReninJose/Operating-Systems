// Renin Kingsly Jose
// EECE.4811 Operating Systems
// prod_cons_MT.cpp

#include "prod_cons_MT.h"

extern int buffer_size;
extern bool buffer_state;

monitor::monitor(int const &size){
    // Allocate memory for buffer size
    buffer = new int[size];
    // Set initial state of buffer to empty
    buffer_state = empty;
}

void monitor::buffer_modifier(){

    // Lock thread
    pthread_mutex_lock(&lock);

    //unlock thread
    pthread_mutex_unlock(&lock);
}

// Producer Thread function
void* producer(int* thread_id){
}