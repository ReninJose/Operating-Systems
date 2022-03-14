// Renin Kingsly Jose
// EECE.4811 Operating Systems
// rendezvous.cpp

#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

sem_t semaphore1;
sem_t semaphore2;

void* child1(void* arg){
 
    cout << "child 1: before" << endl;
    sleep(1);
    sem_post(&semaphore2);
    sem_wait(&semaphore1);
    cout << "child 1: after" << endl;

    return NULL;
}

void* child2(void* arg){

    cout << "child 2: before" << endl;
    sleep(1);
    sem_post(&semaphore1);
    sem_wait(&semaphore2);
    cout << "child 2: after" << endl;

    return NULL;
}

int main() {

    pthread_t thread[2];

    cout << "parent: begin" << endl;
    // Initializing Semaphores
    sem_init(&semaphore1, 0, 0);
    sem_init(&semaphore2, 0, 0);

    // Creating two threads
    pthread_create(&thread[0], NULL, child1, NULL);
    pthread_create(&thread[1], NULL, child2, NULL);
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    cout << "parent: end" << endl;

    return 0;

}