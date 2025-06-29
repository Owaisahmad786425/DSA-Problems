class Solution {
    int fun(int index1,int index2,string word1,string word2,vector<vector<int>> &dp){
        if(index1<0 ||index2<0){
            return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if(word1[index1]==word2[index2]){
            return dp[index1][index2]= 1+fun(index1-1,index2-1,word1,word2,dp);
        }
        return dp[index1][index2]= max(fun(index1-1,index2,word1,word2,dp),fun(index1,index2-1,word1,word2,dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
          vector<vector<int>> dp(n,vector<int>(m,-1));
        int get_common=fun(n-1,m-1,word1,word2,dp);
        int uncommon1=n-get_common;
        int uncommon2=m-get_common;
      
        return (uncommon1+uncommon2);
    }
};