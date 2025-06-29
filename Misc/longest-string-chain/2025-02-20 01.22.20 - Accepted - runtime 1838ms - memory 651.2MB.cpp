class Solution {
    static bool comp(string s, string p){
        return s.size()<p.size();
    }
    bool fun(string a, string b){
        if(a.size()==b.size()){
            return false;
        }
        else if(b.size()-a.size()>1){
            return false;
        }
        else{
        int size=max(a.size(),b.size());
        int count=0;
        int j=0;
        for(int i=0;i<size;i++){
    if(a[j]!=b[i]){
        count++;
        if(count>1){
            return false;
        }
        continue;
    }
    j++;
        }
return true;
        }
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
     for(int curr=0;curr<n;curr++){
   for(int prev=0;prev<curr;prev++){
   if(fun(words[prev],words[curr])==true && dp[curr]<dp[prev]+1){
    dp[curr]=dp[prev]+1;
   }

   }
     }

int maxi=1;
for(int i=0;i<n;i++){
    maxi=max(maxi,dp[i]);
}

        return maxi;
    }
};