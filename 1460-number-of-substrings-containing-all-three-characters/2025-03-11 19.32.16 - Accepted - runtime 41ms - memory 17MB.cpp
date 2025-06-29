class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        int res=0;
        while(r<n){
     mp[s[r]]++;
     while(mp.size()==3){
        res+=(n-r);
        mp[s[l]]--;
        if(mp[s[l]]==0){
            mp.erase(s[l]);
        }
        l++;
     }

r++;
        }
        return res;
    }
};