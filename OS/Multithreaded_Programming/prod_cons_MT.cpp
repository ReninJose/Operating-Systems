// Renin Kingsly Jose
// EECE.4811 Operating Systems
// prod_cons_MT.cpp

#include "prod_cons_MT.h"

extern int buffer_size;
extern bool buffer_state;

extern monitor m;

monitor::monitor(int const &size){
    // Allocate memory for buffer size
    buffer = new int[size];
    // Set initial state of buffer to empty
    buffer_state = empty;
}

void monitor::buffer_modifier(int random){
    
    // Lock thread
    pthread_mutex_lock(&lock);
    // Write data in buffer
    if (random != 0) {
        buffer
    }
    //unlock thread
    pthread_mutex_unlock(&lock);
}

// Producer Thread function
void* producer(void* arg) {

    int thread_number = (int)arg;
    int produce_values = rand()%buffer_size + buffer_size;          // Produce more than enough numbers
    int random_number;


    cout << "P" << thread_number << ": PRODUCING " << produce_values <<  "values" << endl;

    for (int i = 0; i < produce_values; i++) {
        // Generating random number between 1-10
        random_number = rand()% 11;
        cout << "P" << thread_number << ": Writing " << random_number << "to position" << thread_number - 1 << endl;
        m.buffer_modifier(random_number);
    }
}

void* consumer(void* arg) {

}