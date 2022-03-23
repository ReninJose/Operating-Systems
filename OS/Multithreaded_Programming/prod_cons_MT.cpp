// Renin Kingsly Jose
// EECE.4811 Operating Systems
// prod_cons_MT.cpp

#include "prod_cons_MT.h"

extern monitor m;
extern int num_of_consumer;
int shared = 0;

void monitor::buffer_initialize(int const &size){
    // Allocate buffer's attributes
    buffer = new int[size];
    buffer_state = empty;
    buffer_size = size;
}

void monitor::buffer_modifier(int random){

    // Lock thread
    pthread_mutex_lock(&lock);
    // For producer
    if (random != 0) {
        while (buffer[i] != 0)                             // While current buffer slot is filled, go to next slot
            i++;

        if (buffer[buffer_size - 1] != 0)                  // If last slot of buffer is already filled, set buffer state to full
            buffer_state = full;
        else
            buffer[i] = random;
    }
    // for consumer
    else if (random == NULL) {
        
    }
    //unlock thread
    pthread_mutex_unlock(&lock);
}

// Producer thread function
void* producer(void* arg) {

    int thread_number = *((int*)arg);
    int producer_values = rand()% m.buffer_size + m.buffer_size;          // Produce more than enough numbers
    shared = shared + producer_values;
    int random_number;

    cout << "P" << thread_number << ": PRODUCING " << producer_values <<  "values" << endl;

    for (int i = 0; i < producer_values; i++) {
        // Generating random number between 1-10
        random_number = rand()% 11;
        cout << "P" << thread_number << ": Writing " << random_number << "to position" << thread_number - 1 << endl;
        m.buffer_modifier(random_number);
    }

    return NULL;
}

// Consumer thread function
void* consumer(void* arg) {

    int thread_number = *((int*)arg);
    int consumer_values = shared / num_of_consumer;

    // Identify lastly created consumer and allocate rest of the values
    if (thread_number == num_of_consumer) {
        consumer_values = shared - (num_of_consumer * consumer_values);
    }

    cout << "C" << thread_number << ": Consuming " << consumer_values << "values" << endl;

    for (int i = 0; i < consumer_values; i++) {
        m.buffer_modifier(NULL);
    }

    return NULL;
}