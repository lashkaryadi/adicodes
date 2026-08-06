class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0;
        if(t >= n) return t;
       
        for(int i=0;i<t;i++){
        int num = n;
        int product=1; 
        while( num>0 ){
            product *= num%10;
            num /= 10;
        }
        if(product % t == 0) {ans = n; break;}
        n++;
        }
        return ans;
    }
}; 