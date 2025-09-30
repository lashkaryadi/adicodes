#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> burst_time(n);
    vector<int> process_id(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst_time[i];
        process_id[i] = i + 1; 
    }

    vector<pair<int, int>> proc; 
    for (int i = 0; i < n; i++) {
        proc.push_back({burst_time[i], process_id[i]});
    }

    sort(proc.begin(), proc.end()); 

    vector<int> wt(n, 0);
    vector<int> tat(n, 0);
    float total_wt = 0, total_tat = 0;

  wt[0] = 0;
  tat[0] = proc[0].first;
   for(int i = 1; i < n ; i++){
    wt[i] = wt[i-1] + proc[i-1].first;
    tat[i] = wt[i] + proc[i].first;
   } 
   cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << proc[i].second << "\t"
             << proc[i].first << "\t"
             << wt[i] << "\t"
             << tat[i] << "\n";
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

    return 0;
   } 
  
