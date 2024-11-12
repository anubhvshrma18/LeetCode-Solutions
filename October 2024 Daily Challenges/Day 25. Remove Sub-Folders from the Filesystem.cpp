class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;

        ans.push_back(folder[0]);


        for(int i=1;i<folder.size();i++) {
            string cf = folder[i];
            string lastParentFolder = ans.back();
            lastParentFolder+="/";

            if(cf.compare(0, lastParentFolder.size(), lastParentFolder) != 0) {
                ans.push_back(cf);
            }
        }

        return ans;
    }
};