class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int l=0,r=0,count=0;
        int n=s.size();
        while(r<n ){
            mp[s[r]]++;
            while(mp.size()==3){
                count+=1+((n-1)-r);
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return count;

    }
};