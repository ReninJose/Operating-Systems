// Renin Kingsly Jose
// Thrishanth Anandaraj
// EECE.4811 Operating Systems
// main.cpp

#include "prod_cons_MT.h"

// Declaration of mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t producer_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t consumer_lock = PTHREAD_MUTEX_INITIALIZER;                       

// Global data
monitor m;
int number_of_consumer;
int number_of_producer;

extern pthread_cond_t cond1;
extern pthread_cond_t cond2;

int main(int argc, char* argv[]){

    int num_of_producer = atoi(argv[2]);
    int num_of_consumer = atoi(argv[3]);
    int thread_id;
    int rc;

    m.buffer_initializer(atoi(argv[1]));           // Setting up buffer size

    // Initialize threads
    pthread_t producer_thread[num_of_producer];
    pthread_t consumer_thread[num_of_consumer];

    // Initialize Locks
    pthread_mutex_init(&producer_lock,NULL);
    pthread_mutex_init(&consumer_lock, NULL);
    pthread_mutex_init(&lock, NULL);

    // Set extern data
    number_of_consumer = num_of_consumer;
    number_of_producer = num_of_producer;

    // Create producer threads
    for (int i = 0; i < num_of_producer; i++) {
        thread_id = i + 1;
        cout << "MAIN: Started Producer " << thread_id << endl;
        rc = pthread_create(&producer_thread[i], NULL, producer, &thread_id);
        if (rc) {
            cout << "ERROR: Producer pthread_create failed" << endl;
            return 1;
        }
        sleep(0.25);
    }
    
    // Reset thread_id
    thread_id = 0;

    // Create consumer threads
    for (int j = 0; j < num_of_consumer; j++) {
        thread_id = j + 1;
        cout << "MAIN: Started Consumer " << thread_id << endl;
        pthread_create(&consumer_thread[j], NULL, consumer, &thread_id);
        if (rc) {
            cout << "ERROR: Consumer pthread_create failed" << endl;
            return 1;
        }
        sleep(0.3);
    }

    // Join all producer threads back to parent thread
    for(int k = 0; k < num_of_producer; k++) {
        pthread_join(producer_thread[k], NULL);
        cout << "MAIN: Producer " << k + 1 << " joined" << endl;
    }

    // Broadcast any remaining consumer thread that is stuck
    pthread_cond_broadcast(&cond1);
    pthread_cond_broadcast(&cond2);

    // Join all consumer threads back to parent thread
    for(int k = 0; k < num_of_consumer; k++) {
        pthread_join(consumer_thread[k], NULL);
        cout << "MAIN: Consumer " << k + 1 << " joined " << endl;
    }

    cout << "MAIN: program completed" << endl;

    return 0;
}