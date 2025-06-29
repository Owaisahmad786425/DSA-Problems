class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        if(n==1) return false;
        vector<int> lps(n);
        if(n%2!=0){
        bool flag=0;
        int count=0;
        char var=' ';
        for(int i=0;i<n;i++){
            if(var!=s[i]){
                var=s[i];
                count++;
            }
            if(count>1){
                flag=1;
                break;
            }
        }
      return !flag;
        }
    lps[0]=0;
    for(int i=1;i<n;i++){
        if(lps[i-1]==0 && s[i]!=s[0]){
            lps[i]=0;
            continue;
        }
        if(s[i]!=s[lps[i-1]]){
            return false;
        }
      lps[i]=lps[i-1]+1;
    }
    return true;
    }
};