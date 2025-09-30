#include <iostream>
#include <thread>
#include <semaphore>  // C++20 header for semaphores

using namespace std;

// Shared variable
int shared_variable = 0;

// Create a binary semaphore with initial count 1 (acting like a mutex)
std::counting_semaphore<1> sem(1); // This is a binary semaphore

void worker(int id) {
    for (int i = 0; i < 5; i++) {
        cout << "Thread " << id << " waiting to acquire semaphore..." << endl;
        
        sem.acquire();  // Acquire semaphore (enter critical section)
        cout << "Thread " << id << " acquired semaphore!" << endl;

        // Critical section: Increment the shared variable
        int temp = shared_variable;
        shared_variable = temp + 1;
        cout << "Thread " << id << " incremented shared_variable to " << shared_variable << endl;
        
        sem.release();  // Release semaphore (leave critical section)
        cout << "Thread " << id << " released semaphore!" << endl;
    }
}

int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);
    
    t1.join();
    t2.join();
    t3.join();
    
    cout << "Final value of shared_variable: " << shared_variable << endl;
    
    return 0;
}
