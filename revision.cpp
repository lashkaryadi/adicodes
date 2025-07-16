#include <iostream>
using namespace std;

int main() {
int i=0,n;
cout << "ENTER VALUE OF 'N'";
cout<<endl;
cin >> n;

while(i!=n){
    int j=1;
    while(j!=n+1){
        cout << j<<'\t';
        j+=1;
    }
    cout << endl;
    i+=1;
}

};