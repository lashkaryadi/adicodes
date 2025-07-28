#include <iostream>
using namespace std;

/*int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout <<"*";
        }
        cout << endl;
    }
}*/

/*void ascend(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
}*/

/*void ascend_no(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout << j+1;
        }
        cout << endl;
    }
}*/

/*void ascend_row(int n){
    for (int row=0;row<n;row++){
        for (int col=0;col<=row;col++){
            cout << row +1;
        }
        cout << endl;
    }
}*/

/*void descend(int n){
 for(int row=0;row<n;row++){
    for (int col=n-row;col>0;col--){
        cout << "*";
    }
    cout << endl;
 }
}*/

/*void descend_col(int n){
    for (int row=0;row<n;row++){
        for (int col=0;col<n-row;col++){
            cout << col+1;
        }
        cout << endl;
    }
}*/

/*void upper_tri(int n){
    for (int row=0;row<n;row++){
        for(int space=0;space<n-row-1;space++){
            cout << " ";
        }
        for(int col=0;col<(2*row)+1;col++){
            cout << "*";
        }
        cout << endl;
    }
}*/

/*void lower_tri(int n){
    for (int row=0;row<n;row++){
        for(int space=0;space<row;space++){
            cout << " ";
        }
        for(int col=0;col<2*(n-row)-1;col++){
            cout <<"*";
        }
        cout << endl;
    }
}*/

void ascend_binary(int n){
    for (int row=0;row<n;row++){
        for (int col=0;col<=row;col++){
            if((row+col)%2==0)
            cout << 1;
            else
            cout << 0;
        }
        cout << endl;
    }
}


int main(){
    int n;
    cin >> n;
    ascend_binary(n);
}