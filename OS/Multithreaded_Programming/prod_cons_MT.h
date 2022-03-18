// Renin Kingsly Jose
// EECE.4811 Operating Systems
// prod_cons_MT.h

#ifndef PROD_CONS_MT_H
#define PROD_CONS_MT_H

#include<iostream>
#include<pthread.h>
#include<stdlib.h>

// Preprocessors
#define empty false
#define full true

using namespace std;

pthread_mutex_t lock;


class monitor {
    public:
        monitor(int const &size);       // Constructor

        void buffer_modifier(int random);
        
    private:
        int buffer_size;                // User defined Buffer size
        int *buffer;                    // Address for the buffer 
        bool buffer_state;              // To check if buffer is full or empty
        int index;                      // Index    
};

// Producer function
void* producer(void* arg);

//consumer function
void* consumer(void* arg);

#endif