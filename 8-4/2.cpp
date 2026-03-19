#include <iostream>
using namespace std ;
int main (){
    int n;
    cin >>n;
    cout << 10-n;
    while (n!=0){
        
        int a=n%10;
        cout << 10-a;
        n=n/10;

    }
} 