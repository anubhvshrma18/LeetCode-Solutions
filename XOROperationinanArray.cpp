class Solution {
public:
    int xorOperation(int n, int start) {
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum^(start+(2*i));
        }
        
        return sum;
    }
};