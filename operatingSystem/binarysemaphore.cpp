#include <iostream>
#include <mutex>   
#include <thread>

using namespace std;

std::mutex mtx;

void critical_section(int id) {
    mtx.lock();  
    cout << "Thread " << id << " entered critical section." << endl;
    mtx.unlock();  
    cout << "Thread " << id << " exited critical section." << endl;
}

int main() {
    thread t1(critical_section, 1);
    thread t2(critical_section, 2);
    
    t1.join();
    t2.join();
    
    return 0;
}
