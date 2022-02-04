class Solution {
public:
    int bulbSwitch(int n) {
        int count=0;
        if(n==1){
            return 1;
        }
        for(int i=1;i*i<=n;i++){
            count++;
        }
        return count;
    }
};
