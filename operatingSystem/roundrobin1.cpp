#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;           
    int arrivalTime;   
    int burstTime;     
    int remainingTime; 
    int completionTime; 
    int turnaroundTime; 
    int waitingTime;   
    int responseTime;  
    bool responded;    
};

void roundRobin(vector<Process>& processes, int timeQuantum) {
    int n = processes.size();
    queue<int> readyQueue;
    int currentTime = 0;
    int completed = 0;
    vector<bool> inQueue(n, false);
    
    
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });
    
    
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].responded = false;
    }
    
    cout << "\nGantt Chart:\n";
    cout << "Time: ";
    
    while (completed < n) {
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && 
                processes[i].remainingTime > 0 && !inQueue[i]) {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }
        
        if (readyQueue.empty()) {
            
            currentTime++;
            continue;
        }
        
        
        int currentProcess = readyQueue.front();
        readyQueue.pop();
        inQueue[currentProcess] = false;
        
        
        if (!processes[currentProcess].responded) {
            processes[currentProcess].responseTime = currentTime - processes[currentProcess].arrivalTime;
            processes[currentProcess].responded = true;
        }
        
        
        int executionTime = min(timeQuantum, processes[currentProcess].remainingTime);
        
        cout << currentTime << "->";
        processes[currentProcess].remainingTime -= executionTime;
        currentTime += executionTime;
        cout << currentTime << " (P" << processes[currentProcess].pid << ") ";
        
        
        if (processes[currentProcess].remainingTime == 0) {
            processes[currentProcess].completionTime = currentTime;
            processes[currentProcess].turnaroundTime = 
                processes[currentProcess].completionTime - processes[currentProcess].arrivalTime;
            processes[currentProcess].waitingTime = 
                processes[currentProcess].turnaroundTime - processes[currentProcess].burstTime;
            completed++;
        } else {
            
            for (int i = 0; i < n; i++) {
                if (processes[i].arrivalTime <= currentTime && 
                    processes[i].remainingTime > 0 && !inQueue[i] && i != currentProcess) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                }
            }
            
            readyQueue.push(currentProcess);
            inQueue[currentProcess] = true;
        }
    }
    cout << "\n";
}

void displayResults(const vector<Process>& processes) {
    
    cout << setw(45) << "ROUND ROBIN SCHEDULING RESULTS\n";
    
    
    cout << '\t' << "PID" 
         << '\t' << "Arrival" 
         << '\t' << "Burst" 
         << '\t' << "Completion" 
         << '\t' << "Turnaround" 
         << '\t' << "Waiting" 
         << '\t' << "Response" << "\n";
    
    
    double totalWaitingTime = 0, totalTurnaroundTime = 0, totalResponseTime = 0;
    
    for (const auto& p : processes) {
        cout << '\t' << p.pid 
             << '\t' << p.arrivalTime 
             << '\t' << p.burstTime 
             << '\t' << p.completionTime 
             << '\t' << p.turnaroundTime 
             << '\t' << p.waitingTime 
             << '\t' << p.responseTime << "\n";
        
        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
        totalResponseTime += p.responseTime;
    }
    
    
    
    double avgWaitingTime = totalWaitingTime / processes.size();
    double avgTurnaroundTime = totalTurnaroundTime / processes.size();
    double avgResponseTime = totalResponseTime / processes.size();
    
    cout << fixed ;
    cout << "\nAVERAGE TIMES:\n";
    cout << "Average Waiting Time: " << avgWaitingTime << " units\n";
    cout << "Average Turnaround Time: " << avgTurnaroundTime << " units\n";
    cout << "Average Response Time: " << avgResponseTime << " units\n";
}

int main() {
    int n, timeQuantum;
    
    cout << "ROUND ROBIN CPU SCHEDULING ALGORITHM \n\n";
    
    cout << "Enter the number of processes: ";
    cin >> n;
    
    cout << "Enter time quantum: ";
    cin >> timeQuantum;
    
    vector<Process> processes(n);
    
    cout << "\nEnter process details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "  Process ID: ";
        cin >> processes[i].pid;
        cout << "  Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "  Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "\n";
    }
    
    
    roundRobin(processes, timeQuantum);
    
    
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.pid < b.pid;
    });
    
    
    displayResults(processes);
    
    return 0;
}