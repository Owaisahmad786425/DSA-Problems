class Solution {
    const int MOD=1e9+7;
    bool check(string a,string b){
        for(int k=0;k<a.size();k++){
            if(a[k]==b[k]){
                return false;
            }
        }
        return true;
    }
    void fun(vector<string> &permutations,int count,char prev,string s,int m){
        if(count==m){
            permutations.push_back(s);
            return;
        }

        for(auto ch:{'R','B','G'}){
            if(ch!=prev){
                fun(permutations,count+1,ch,s+ch,m);
            }
        }

    }
    int solve(int rem,int perm_index,string prev,vector<string> &permutations,vector<vector<int>> &dp){
        if(rem==0){
            return 1;
        }
        if(dp[rem][perm_index]!=-1){
            return dp[rem][perm_index];
        }
       int ways=0;
        for(int j=0;j<permutations.size();j++){
          if(check(prev,permutations[j])){
            ways=(ways+solve(rem-1,j,permutations[j],permutations,dp))%MOD;
          }
        }
        return dp[rem][perm_index]=ways;
    }
public:
    int colorTheGrid(int m, int n) {
        vector<string> permutations;
        int count=0;
        char prev='*';
        string s="";
        //find the permutation 
        int res=0;
        fun(permutations,count,prev,s,m);
        vector<vector<int>> dp(n,vector<int>(permutations.size(),-1));
        for(int i=0;i<permutations.size();i++){
           res=(res+solve(n-1,i,permutations[i],permutations,dp))%MOD;
        }
        return res;

    }
};