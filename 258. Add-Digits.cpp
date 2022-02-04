class Solution {
public:
    int addDigits(int num) {
       int x=0;
        while(num/10 > 0){
            x=num%10;
            num=num/10;
            num=num+x;
       }
        return num;
    }
};
