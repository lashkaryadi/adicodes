#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<pair<int,int>> proc(n);
    vector<int> pid(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> proc[i].first;   
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> proc[i].second;  
        pid[i] = i + 1;
    }

    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return proc[a].first < proc[b].first;
    });
    vector<int> wt(n, 0);
    vector<int> tat(n, 0);
    
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        int idx = indices[i];
        if (proc[idx].first > current_time) {
            current_time = proc[idx].first;
        }
        wt[idx] = current_time - proc[idx].first;
        current_time += proc[idx].second;
        tat[idx] = current_time - proc[idx].first;
    }
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
float total_wt = 0, total_tat = 0;
for (int i = 0; i < n; i++) {
    int idx = indices[i]; 
    cout << "P" << pid[idx] << "\t"
         << proc[idx].first << "\t"
         << proc[idx].second << "\t"
         << wt[idx] << "\t"
         << tat[idx] << "\n";

    total_wt += wt[idx];
    total_tat += tat[idx];
}
    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;
    return 0;
}
