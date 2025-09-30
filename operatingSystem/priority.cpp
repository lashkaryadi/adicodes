#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

bool compare(Process a, Process b) {
    if (a.arrival_time == b.arrival_time) {
        return a.priority > b.priority;
    }
    return a.arrival_time < b.arrival_time;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    Process p[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter details for Process " << i + 1 << ":\n";
        cout << "Process ID: ";
        cin >> p[i].pid;
        cout << "Arrival Time: ";
        cin >> p[i].arrival_time;
        cout << "Burst Time: ";
        cin >> p[i].burst_time;
        cout << "Priority: ";
        cin >> p[i].priority;
        cout << endl;
    }
    
    sort(p, p + n, compare);
    
    int current_time = 0;
    bool completed[n] = {false};
    int completed_count = 0;
    
    while (completed_count < n) {
        int highest_priority = 100;
        int selected = -1;
        
        for (int i = 0; i < n; i++) {
            if (!completed[i] && p[i].arrival_time <= current_time) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    selected = i;
                }
            }
        }
        
        if (selected == -1) {
            current_time++;
            continue;
        }
        
        p[selected].response_time = current_time - p[selected].arrival_time;
        current_time += p[selected].burst_time;
        p[selected].completion_time = current_time;
        p[selected].turnaround_time = p[selected].completion_time - p[selected].arrival_time;
        p[selected].waiting_time = p[selected].turnaround_time - p[selected].burst_time;
        
        completed[selected] = true;
        completed_count++;
    }
    
    cout << "\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\tResponse\n";
    
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" 
             << p[i].priority << "\t\t" << p[i].completion_time << "\t\t" << p[i].turnaround_time 
             << "\t\t" << p[i].waiting_time << "\t" << p[i].response_time << endl;
        
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    
    cout << "\nAverage Waiting Time: " << total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << total_turnaround_time / n << endl;
    
    return 0;
} 