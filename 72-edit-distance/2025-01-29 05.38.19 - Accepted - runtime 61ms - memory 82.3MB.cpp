class Solution {
int fun(int index1,int index2, string word1, string word2,vector<vector<int>> &dp){
    //let the base case for now
if(index2==0 ){
    return index1;
}
if(index1==0){
    return index2;
}

if(dp[index1][index2]!=-1){
    return dp[index1][index2];
}

if(word1[index1-1]==word2[index2-1]){
    return dp[index1][index2]=0+fun(index1-1, index2-1, word1, word2,dp);
}

return dp[index1][index2]=min(min(1+fun(index1, index2-1, word1, word2,dp),1+fun(index1-1,index2-1, word1, word2,dp)), 1+fun(index1-1,index2, word1, word2,dp));
}

public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(word1==""){
            return m;
        }
   if(word1==word2){
    return 0;
   }
   vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(n,m,word1,word2,dp);
    }
};