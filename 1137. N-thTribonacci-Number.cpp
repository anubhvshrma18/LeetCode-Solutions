class Solution {
public:
    int a[38]={0};
    int tribonacci(int n) {
           a[1]=1;
           a[2]=1;
       if(n<=0){
           return 0;
       }
        if(n==1||n==2){
            return 1;
        }
        if(a[n-1]==0){
            a[n-1]=tribonacci(n-2)+tribonacci(n-3)+tribonacci(n-4);
        }
        if(a[n-2]==0){
            a[n-2]=tribonacci(n-3)+tribonacci(n-4)+tribonacci(n-5);
        }
        if(a[n-3]==0){
            a[n-3]=tribonacci(n-4)+tribonacci(n-5)+tribonacci(n-6);
        }
    return a[n-1]+a[n-2]+a[n-3];
    }
};