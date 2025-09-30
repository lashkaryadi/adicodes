#include <iostream>
#include <thread>
#include <mutex>  

using namespace std;

int shared_variable = 0;

std::mutex mtx;

void worker(int id) {
    for (int i = 0; i < 5; i++) {
        cout << "Thread " << id << " waiting to acquire mutex..." << endl;
        
        mtx.lock();  
        cout << "Thread " << id << " acquired mutex!" << endl;

        int temp = shared_variable;
        shared_variable = temp + 1;
        cout << "Thread " << id << " incremented shared_variable to " << shared_variable << endl;
        
        mtx.unlock();  
        cout << "Thread " << id << " released mutex!" << endl;
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
