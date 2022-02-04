class Solution {
public:
    vector<string> vec;
    void generateper(int idx,int len ,map<char,int> &mp,char ofc,string asf){
        if(idx == len){
            string rev=asf;
            reverse(rev.begin(),rev.end());
            if(ofc!='\0'){
                // 
                vec.push_back(asf+ofc+rev);
            }
            else{
                // cout << asf << rev << endl;
                vec.push_back(asf+rev);
            }
            return;
        }

        for(auto x:mp){
            if(x.second>0){
                mp[x.first]--;
                generateper(idx+1,len,mp,ofc,asf+x.first);
                mp[x.first]++;
            }
        }



    }
    vector<string> generatePalindromes(string &s) {
        // write your code here
        vec.clear();
        map<char,int> map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }

        char oddf='\0';
        int odf=0,len=0;

        for(auto x:map){
            int fre=x.second;
            if(fre%2!=0){
                odf++;
                oddf=x.first;
            }

            map[x.first] = fre/2;
            len+=fre/2;

        }

        if(odf>1){
            cout << -1 << endl;
            return vec;
        }

        generateper(0,len,map,oddf,"");
        return vec;
    }
};