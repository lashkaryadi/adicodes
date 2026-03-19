#include <iostream>
using namespace std;

/*int main (){
    int row=0,n;
    cin >> n;
    while (row<n){
        int space=0;
        while(space<n-row-1){
            cout << " ";
            space++;
        }

        int col=0;
        while(col<=row){
            cout << row+1;
            col++;
        }
        cout << endl;
        row++;
    }
}*/

/*int main (){
    int row=0,n;
    cin >> n;
    while (row!=n){
        int col=1;
        while(col<=n){
            if(col < row+1)
            cout << " ";
            else 
            cout << col;
            col++;
        }
        cout << endl;
        row++;
    }
}*/

/*int main (){
    int count=1,row=0,n;
    cin >> n;
    while (row<n){
        int col=1;
        while(col<=n){
        if (col<n-row)
        cout << " " << '\t';
        else{
        cout << count << '\t';
        count++;}
        col++;}
    cout << endl;
    row++; }
}*/

/*int main (){
    int row=0,n;
    cin >> n;
    while(row<n){
        int space=0,col=0,count=0;
        while (space<n-row-1)
        {
            cout << " ";
            space++;
        }
        while (col<(2*row)+1)
        {
            if (col<row+1)
            {
                count++;
                cout << count;
            }
            else{
                count--;
                cout << count;
            }
            col++;
        }
        cout << endl;
        row++;
    }

}*/

//DABANG PATTERN
/*int main (){
    int row=0,n;
    cin >>n;
    while(row<n){
        int col1=0,col2=0,col3=0;
        while (col1<n-row)
        {
            cout << col1+1 << '\t';
            col1++;
        }

        while (col2< 2*row){
            cout << "*" << '\t';
            col2++;
        }

        while (col3<n-row){
            cout << n-col3-row<<'\t';
            col3++; 
        }
        cout <<endl;
        row++;
    }
}*/

