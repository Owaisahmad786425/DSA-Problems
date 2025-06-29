class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> hash(3,-1);
        int r=0;
        int res=0;
        while(r<n){
            hash[s[r]-'a']=r;
            res+=1+min(hash[0],min(hash[1],hash[2]));
            r++;
        }
return res;
    }
};