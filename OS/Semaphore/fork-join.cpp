// Renin Kinglsy Jose
// EECE.4811 Operating Systems
// fork-join.cpp

#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

sem_t semaphore;

void* child(void* arg) {

    sleep(1);
    cout << "child" << endl;

    // Signal Child is done
    sem_post(&semaphore);

    return NULL;
}

int main(){
    pthread_t thread;

    // Initiating Semaphore
    sem_init(&semaphore, 0, 0);

    cout << "parent: begin" << endl;

    // Creating Child Thread
    pthread_create(&thread, NULL, child, NULL);
   
    sem_wait(&semaphore);

    cout << "Parent: end" << endl;

    return 0;
}
