class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> vis(26,0);
        for(int i=0;i<sentence.size();i++){
            if(vis[sentence[i]-'a']) continue;
            vis[sentence[i]-'a']=1;
        }
        for(int i=0;i<26;i++){
            if(!vis[i])return false;
        }
        return true;
    }
};