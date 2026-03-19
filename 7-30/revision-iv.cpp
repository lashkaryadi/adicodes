#include<iostream>
#include<cmath>
using namespace std;

int count_digit(int n){
    int i=n;
    int count=0;
    while(i){
        count++;
        i=i/10;
    }
    return count;
}

int reverseNumber(int n) {
        int rev=0,i=n,k;
        while(i){
            k=i%10;
            rev=rev*10+k;
            i/=10;
        }
        return rev;
    }
    
int GCD(int n1,int n2) {
        int gcd=1;
        for (int i=2;i<=min(n1,n2);i++){
            if(n1%i==0 && n2%i==0){
                gcd=i;
            }
        }
        return gcd;
    }

vector<int> divisors(int n) {
        vector <int> d;
        for (int i=1;i<=n/2;i++){
            if (n%i==0)
            d.push_back(i);
        }
        d.push_back(n);
        return d ;
    }

    bool isPrime(int n) {
        vector<int> v;
        for (int i=1;i<=sqrt(n);i++){
            if (n%i==0)
            v.push_back(i);
        }
        v.push_back(n);
        if (v.size()==2) return true;
        return false;
    }

int main(){
    int n;
    cin >> n;
    cout << isPrime(n);
    
}