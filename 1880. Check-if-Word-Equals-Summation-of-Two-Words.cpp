class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int s1=0,s2=0,s3=0;
        int i=0;
        for(int j=firstWord.length()-1;j>=0;j--){
            char ch=firstWord[j];
            s1+=((int)ch - 97)*pow(10,i);
            i++;
        }
        i=0;
        for(int j=secondWord.length()-1;j>=0;j--){
            char ch=secondWord[j];
            s2+=((int)ch - 97)*pow(10,i);
            i++;
        }
        i=0;
        for(int j=targetWord.length()-1;j>=0;j--){
            char ch=targetWord[j];
            s3+=((int)ch - 97)*pow(10,i);
            i++;
        }
        cout << s1 <<  " " << s2 << " "<< s3;
        if(s1+s2 == s3){
            return true;
        }
        else{
            return false;
        }
    }
};