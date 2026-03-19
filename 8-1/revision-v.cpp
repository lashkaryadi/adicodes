#include <iostream>
using namespace std;

void reName(int count){
    cout << "aditya\n";
    count--;
    if (count==0) return;
    reName(count);
}

int k=1;
void n_numbers(int n){
    cout << k <<'\n';
    k++;
    if (k==n+1)return;
    n_numbers(n);
}

void woplus(int i, int n){
    if (n<i)return;
    woplus(i,n-1);
    cout << n << '\t' ;
}

void wominus(int i, int n){
    if (n>i) return;
    wominus(i,n+1);
    cout << n << '\t';
}

int NnumbersSum(int n){
			if(n<1) return 0;
            int sum = n + NnumbersSum(n-1);
            return sum;
		}

int nfactorial(int n){
    if(n<2) return 1;
    int factorial = n*nfactorial(n-1);
    return factorial;
} 

void arrinput(int arr[],int n){
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
}

void arroutput (int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i];
    }
}

int i=0;
    void reverse(int arr[], int n){
        if (i>n-1) return;
        swap(arr[i],arr[n-1-i]);
        i=i+1;
        reverse(arr,n-i);
    }

    void revstring(string& r,int i,int n){
        if(i>=n)return;
        swap(r[i],r[n-1]);
        revstring(r,i+1,n-1);
    }

    bool palindromeCheck(string& s){
        string r=s;
        int n=s.size();
        int i=0;
        revstring(r,i,n);
        if(r==s)return true;
        return false;
    }
    
    int main(){
int n;
cin >> n;
int arr[n+1];
arrinput(arr,n);
reverse(arr,n);
arroutput(arr,n);

}