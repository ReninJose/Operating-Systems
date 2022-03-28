// Renin Kingsly Jose
// Thrishanth Anandaraj
// EECE.4811 Operating Systems
// prod_cons_MT.h

#ifndef PROD_CONS_MT_H
#define PROD_CONS_MT_H

#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

// Preprocessors
#define empty 0
#define full 1
#define neither 2

using namespace std;

class monitor {
    public:
        void buffer_initializer(int const &size);
        void buffer_modifier(int data, int thread_id);
        void check_buffer();
        
        int buffer_size;                // User defined Buffer size
        int *buffer;                    // Address for the buffer 
        int buffer_state;              // To check if buffer is full or empty
        // int index;                      // Index    
};

// Producer function
void* producer(void* arg);

//consumer function
void* consumer(void* arg);

// Function for producer thread to generate number
void generate(int thread_number, int producer_values, int iterator);

// Function to keep consumer thread in loop
void consumer_loop(int consumer_val, int thread_number, int iterator);

#endif