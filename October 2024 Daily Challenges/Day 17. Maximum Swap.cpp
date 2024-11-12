class Solution {
public:
    int maximumSwap(int num) {
       string number = to_string(num);
       int size = number.length();

       vector<int> digits(10, -1);

       for(int i=size-1;i>=0;i--) {
        int digit = number[i]-'0';
        if(digits[digit]==-1) {
            digits[digit]=i;
        }
       }

       // build our answer
       for(int i=0;i<size;i++) {
        bool isSwapped = false;
        int digit = number[i]-'0';

        for(int j=9;j>digit;j--) {
            if(i<digits[j]) {
                swap(number[i], number[digits[j]]);
                isSwapped = true;
                break;
            }
        }

        if(isSwapped) {
            break;
        }
       }

       return stoi(number);
    }
};