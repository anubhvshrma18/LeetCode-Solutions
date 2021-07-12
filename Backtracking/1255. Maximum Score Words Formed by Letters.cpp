class Solution {
public:
    int maxscore(vector<string> &v,vector<int> &fre,vector<int> &score, int idx){
	//base case
        if(idx==v.size()){
            return 0;
        }

        int no = maxscore(v,fre,score,idx+1);

        int msc=0;
        string s=v[idx];
        int li=s.length();
        for(int i=0;i<s.length();i++){
            if(fre[s[i]-'a']>0){
                fre[s[i]-'a']--;

            }else{
                li=i;
                break;
            }
            msc+=score[s[i]-'a'];
        }

        int yes=0;
        int ans=no;
        if(li==s.length()){
            yes = maxscore(v,fre,score,idx+1);
            ans = max(no,yes+msc);
        }
        for(int i=0;i<li;i++){
            fre[s[i]-'a']++;
        }
        return ans;

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> fre(26,0);
        for(char ch:letters){
            fre[ch-'a']++;
        }
        return maxscore(words,fre,score,0);
    }
};
//IO
 int _IO =[](){
     std :: ios :: sync_with_stdio (0);
     cin .tie (0);
     return 0;
 }();