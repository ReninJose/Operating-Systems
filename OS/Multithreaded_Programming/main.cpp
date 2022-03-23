// Renin Kingsly Jose
// EECE.4811 Operating Systems
// main.cpp

#include "prod_cons_MT.h"

// Global monitor object
monitor m;

int main(int argc, char* argv[]){

    int num_of_producer = atoi(argv[2]);
    int num_of_consumer = atoi(argv[3]);
    int thread_id;

    m. buffer_initialize(atoi(argv[1]));           // Setting up buffer size

    // Initialize threads
    pthread_t producer_thread[num_of_producer];
    pthread_t consumer_thread[num_of_consumer];

    // Create producer threads
    for (int i = 0; i < num_of_producer; i++) {
        thread_id = i + 1;
        cout << "MAIN: Started Producer " << thread_id << endl;
        pthread_create(&producer_thread[i], NULL, producer, &thread_id);
    }

    // Reset thread_id
    thread_id = 0;

    // Create consumer threads
    for (int j = 0; j < num_of_consumer; j++) {
        thread_id = j + 1;
        cout << "MAIN: Started consumer " << thread_id << endl;
        pthread_create(&consumer_thread[j], NULL, consumer, &thread_id);
    }
    
    // Initialize Lock
    int rc = pthread_mutex_init(&lock,NULL);

    if (rc != 0) {
        cout << "Error: mutex initialization failed" << endl;
        exit(0);                        
    }

    // Join all producer threads back to parent thread
    for(int k = 0; k < num_of_producer; k++) {
        pthread_join(producer_thread[k], NULL);
        cout << "MAIN: Producer " << k + 1 << " joined" << endl;
    }

    // Join all consumer threads back to parent thread
    for(int k = 0; k < num_of_consumer; k++) {
        pthread_join(consumer_thread[k], NULL);
        cout << "MAIN: Consumer " << k + 1 << " joined " << endl;
    }

    cout << "MAIN: program completed" << endl;

    return 0;
}