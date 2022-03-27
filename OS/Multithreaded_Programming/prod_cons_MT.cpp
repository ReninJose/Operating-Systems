// Renin Kingsly Jose
// EECE.4811 Operating Systems
// prod_cons_MT.cpp

#include "prod_cons_MT.h"

// Declaration condition variable for producer and consumer threads
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

extern monitor m;                       // Shared object from main
extern int number_of_consumer;          // Number of consumer data from main
extern int number_of_producer;          // Number of producer data from main
extern pthread_mutex_t lock;            // Lock for buffer 
extern pthread_mutex_t producer_lock;   // Lock for producer CS in buffer
extern pthread_mutex_t consumer_lock;   // Lock for consumer CS in buffer

// Global data
int shared = 0;                         // Shared between producer and consumer
int p_counter = 0;                      // Counter to incremement through buffer
int c_counter = 0;

void monitor::buffer_initializer(int const &size){
    buffer = new int[size];
    buffer_state = empty;
    buffer_size = size;
}

void monitor::buffer_modifier(int data, int thread_id){

    pthread_mutex_lock(&lock);
    
    sleep(0.5);
    check_buffer();
    
    // For producer
    if (data != 0) {
        
        // Lock CS
        if (buffer_state == full){
            pthread_mutex_unlock(&lock);
            pthread_mutex_lock(&producer_lock);
            pthread_mutex_lock(&lock);
        }
        else
            pthread_mutex_lock(&producer_lock);
        
        bool write = false;
        // If buffer full, wait
        if (buffer_state == full) {
            cout << "P" << thread_id << " : Blocked due to buffer full" << endl;
            pthread_cond_wait(&condition, &lock);
            cout << "P" << thread_id << " : Done waiting on full buffer" << endl;
        }

        // Check for free space and write data in Buffer
        while(write != true) {
            if(buffer[p_counter] != 0) {
                write = false;
                p_counter ++;
                if(p_counter == buffer_size - 1) {
                    p_counter = 0;
                }
            }
            else {
                cout << "P" << thread_id << " : Writing " << data << " in position " << p_counter << endl;
                buffer[p_counter] = data;
                pthread_cond_signal(&condition);
                write = true;
                if(p_counter == buffer_size - 1) {
                    p_counter = 0;
                }
                else
                    p_counter ++;
            }
        }

        pthread_mutex_unlock(&producer_lock);
    }

    // for consumer
    else if (data == 0) {
    
        // Lock CS
        if (buffer_state == empty){
            pthread_mutex_unlock(&lock);
            pthread_mutex_lock(&consumer_lock);
            pthread_mutex_lock(&lock);
        }
        else
            pthread_mutex_lock(&consumer_lock);
        
        //cout << data << " " << thread_id << " "<< buffer_state << endl;
        bool read = false;
        // If buffer empty, wait
        if (buffer_state == empty) {
            cout << "C" << thread_id << " : Blocked due to empty buffer" << endl;
            pthread_cond_wait(&condition, &lock);
            cout << "C" << thread_id << " : Done waiting on empty buffer" << endl;
        }
        // Read and clear data in buffer
        while(read != true){
            
            if (buffer[c_counter] == 0) {
                read = false;
                c_counter ++;
                if(c_counter == buffer_size -1) {
                    c_counter = 0;
                }
            }
            else {
                cout << "C" << thread_id << " : Reading " << buffer[c_counter] << " from position " << c_counter << endl;
                buffer[c_counter] = 0;
                pthread_cond_signal(&condition);
                read = true;
                if(c_counter == buffer_size - 1) {
                    c_counter = 0;
                }
                else
                    c_counter ++;
            }
        }

        pthread_mutex_unlock(&consumer_lock);
    }
    
    pthread_mutex_unlock(&lock);
}

void monitor::check_buffer() {

    int not_empty = 0;
    int not_full = 0;
    int j;
    
    for(int i = 0; i < buffer_size; i++) {
        
        if (i == buffer_size - 1) {
            j = -1;
        }
        else
            j = i;

        //cout << i << " " << j << endl;

        if(buffer[i] != 0 && buffer[j+1] != 0) {
            not_empty ++;
        }
        else if (buffer[i] == 0 && buffer[j+1] == 0) {
            not_full++;
        }
        else {
            buffer_state = neither;
            break;
        }
    }
    
    if(not_empty == buffer_size ) {
       
        buffer_state = full;
    }
    else if (not_full == buffer_size ) {
        
        buffer_state = empty;
    }

}

void generate(int thread_number, int producer_values, int iterator) {

    int random_number;

    for (iterator = 0; iterator < producer_values; iterator++) {
        
        // Generating random number between 1-10
        random_number = (rand()% 10) + 1;
        sleep(0.2);
        m.buffer_modifier(random_number, thread_number);
    }
}

void consumer_loop(int consumer_val, int thread_number, int iterator) {                          

    for (iterator = 0; iterator < consumer_val; iterator++) {
        sleep(0.2);
        m.buffer_modifier(0, thread_number);
    }
}

// Producer thread function
void* producer(void* arg) {

    int thread_number = (*(int*)arg);
    shared = shared + (m.buffer_size * 2);

    cout << "P" << thread_number << ": producing " << m.buffer_size * 2 <<  " values" << endl;

    generate(thread_number, (m.buffer_size * 2), 0);

    return NULL;
}

// Consumer thread function
void* consumer(void* arg) {

    int thread_number = *((int*)arg);
    int consumer_values = shared / number_of_consumer;

    // Identify lastly created consumer and allocate rest of the values
    if (thread_number == number_of_consumer) {
        consumer_values = shared - (consumer_values * (number_of_consumer - 1));
    }

    cout << "C" << thread_number << ": Consuming " << consumer_values << " values" << endl;

    consumer_loop(consumer_values, thread_number, 0);

    return NULL;
}

