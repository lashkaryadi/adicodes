#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    int response;
};

bool compare(Process a, Process b) {
    if (a.arrival != b.arrival)
        return a.arrival < b.arrival;
    return a.burst < b.burst;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    vector<Process> p(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":" << endl;
        cout << "Process ID: ";
        cin >> p[i].pid;
        cout << "Arrival Time: ";
        cin >> p[i].arrival;
        cout << "Burst Time: ";
        cin >> p[i].burst;
        cout << endl;
    }
    
    sort(p.begin(), p.end(), compare);
    
    vector<bool> completed(n, false);
    int currentTime = 0;
    int completedCount = 0;
    
    while (completedCount < n) {
        int shortest = -1;
        int minBurst = 999999;
        
        for (int i = 0; i < n; i++) {
            if (!completed[i] && p[i].arrival <= currentTime && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                shortest = i;
            }
        }
        
        if (shortest == -1) {
            currentTime++;
            continue;
        }
        
        p[shortest].response = currentTime - p[shortest].arrival;
        p[shortest].completion = currentTime + p[shortest].burst;
        p[shortest].turnaround = p[shortest].completion - p[shortest].arrival;
        p[shortest].waiting = p[shortest].turnaround - p[shortest].burst;
        
        currentTime = p[shortest].completion;
        completed[shortest] = true;
        completedCount++;
    }
    
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.pid < b.pid;
    });
    
    cout << "\t" << "PID" << "\t" << "AT" << "\t" << "BT" 
         << "\t" << "CT" << "\t" << "TAT" << "\t" << "WT" << "\t" << "RT" << endl;
    cout << "\t" << string(50, '-') << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "\t" << p[i].pid << "\t" << p[i].arrival << "\t" << p[i].burst
             << "\t" << p[i].completion << "\t" << p[i].turnaround 
             << "\t" << p[i].waiting << "\t" << p[i].response << endl;
    }
                        
    float avgTAT = 0, avgWT = 0, avgRT = 0;
    for (int i = 0; i < n; i++) {
        avgTAT += p[i].turnaround;
        avgWT += p[i].waiting;
        avgRT += p[i].response;
    }
    
    cout << '\n' << "\t" << "Average Turnaround Time: " << avgTAT / n << endl;
    cout << "\t" << "Average Waiting Time: " << avgWT / n << endl;
    cout << "\t" <<  "Average Response Time: " << avgRT / n << endl;
   
    return 0;
}
