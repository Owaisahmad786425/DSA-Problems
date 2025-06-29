class Solution {
public:
    string minWindow(string s, string t) {
         string ans="";
        int l=0;
        int r=0;
        unordered_map<char,int> mp;
        int m=s.size();
        int n=t.size();
        if(n>m){
            return ans;
        }
        for(int i=0;i<n;i++){
            mp[t[i]]++;
        }
        unordered_map<char,int> mpp;
        int mini=INT_MAX;
        int match=0;
        int startindex=-1;
        while(r<m){
            if(mp.find(s[r])!=mp.end()){
                mpp[s[r]]++;
                if(mpp[s[r]]==mp[s[r]]){
                    match++;
                }
            }
              
                  
            while(match==mp.size() ){
           
                   if(mini>(r-l+1) ){
                    mini=r-l+1;
                    startindex=l;
            }
                if(mp.find(s[l])!=mp.end()){
                mpp[s[l]]--;
                if(mpp[s[l]]<mp[s[l]]){
                    match--;
                }
                }
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
                }
                r++;
            }
            if(startindex==-1){
                return "";
            }
            else{
                return s.substr(startindex,mini);
            }
    }
};