class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string res;
        for(int i=1;i<=n+1;i++){
            res.push_back('0'+i);
        }
   int l=0;
   int r=0;
   while(r<n+1){
    if(pattern[r]!=pattern[r+1]){
        if(pattern[r]=='I'){
            sort(res.begin()+l,res.begin()+l+(r-l+2));
            l=r+1;
        }
        else{
            sort(res.begin()+l,res.begin()+l+(r-l+2),greater<char>());
            l=r+1;
        }
    }
    r++;
   }
return res;
    }
};