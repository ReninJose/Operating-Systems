// Renin Kinglsy Jose
// EECE.4811 Operating Systems
// barrier.cpp

// NOTE: The code is completely made from scratch and the sample code was not used.

#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

using namespace std;

sem_t sem1;

class barrier{
    public:
        int thread_id;
        int max_count;
};

void* child(void* arg) {

    barrier bar = *(barrier*)arg;

    cout << "child " << bar.thread_id << " before" << endl;
    
    /* ------- Barrier Code Starts ------- */
    if(bar.thread_id != bar.max_count){
        sem_wait(&sem1);
    }
    sem_post(&sem1);
    /* ------- Barrier Code Ends ------- */

    cout << "child " << bar.thread_id << " after" << endl;
    

    return NULL;
}

int main (int argc, char* argv[]) {
    
    int num_threads = atoi(argv[1]);

    sem_init(&sem1, 0, 0);

    pthread_t threads[num_threads];
    barrier b[num_threads];

    for (int i = 1; i <= num_threads; i++) {
        b[i-1].thread_id = i;
        b[i-1].max_count = num_threads;
        pthread_create(&threads[i-1], NULL, child, &b[i-1]);
        // Sleep is required so that threads don't modify other thread's ID.
        sleep(0.80);
    }

    for (int j = 0; j < num_threads; j++) {
        pthread_join(threads[j], NULL);
    }

    cout << "Parent: end" << endl;

    return 0;
}