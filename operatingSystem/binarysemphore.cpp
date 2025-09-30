#include<bits/stdc++.h>
using namespace std;
struct cpu{
    int pid,at,bt,ct;
};
int main(){
deque<cpu> process;
deque<cpu>ready;
deque<cpu>reso;
int time_quant=2;
process.push_back({0,0,17,0});
process.push_back({1,2,13,0});
process.push_back({2,12,6,0});
process.push_back({3,8,14,0});
reso=process;
int time=0;
for (int i=0;i<process.size();i++)
time=time+process[i].bt;
int run=0;
int done=0;
cout<<"the total time is "<<time<<endl;
while(run!=time){
int i=0;
 while(i!=process.size()){
    if(run>=process[i].at){
    ready.push_back(process[i]);
    process[i].at=20000;}
    i=i+1;}
if (done==1){  
ready.push_back(ready.front());
ready.pop_front();
}
run=run+time_quant;
ready[0].bt+=-1*time_quant;
int id=ready[0].pid;
done=1;
if(ready[0].bt<=0){ 
run=run+ready[0].bt;
ready.pop_front();
done=0;
process[id].ct=run;
}}
float avg_tat=0;
float avg_wt=0;
for (int i=0;i<process.size();i++){
    float tat=process[i].ct-reso[i].at;
    avg_tat=avg_tat+tat;
    float wt=tat-process[i].bt;
    cout << process[i].pid <<"\t"<< reso[i].at <<"\t"<<process[i].bt<<"\t"<<process[i].ct<<"\t"<<tat<<"\t"<<wt<< endl;
avg_wt=avg_wt+wt;
}
cout<<"the average tat is ->"<<avg_tat/process.size()<<endl;
cout<<"the average waiting is ->"<<avg_wt/process.size()<<endl; 
}