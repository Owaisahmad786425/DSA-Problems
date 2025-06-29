class Solution {
public:
    int minimumLength(string s) {
        map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
      mp[s[i]]++;
        }
        int count=0;
    for(int i=0;i<n;i++){
            while(mp[s[i]]>=3){
                mp[s[i]]-=2;
            }
        
    }
      for(auto it:mp){
        count+=it.second;

      }
      return count;
    }
};