class Solution {

int mindiff(char a,char b){
    return min(abs(a-b),(26-abs(a-b)));
}

  int fun(int index1,int index2,int k, string &s,vector<vector<vector<int>>> &dp){
//base case afterwards
if(index1==index2){
    return 1;
}
if(index1>index2){
    //out of bound case
    return 0;
}
if(k<0){
    return 0;
}
if(dp[index1][index2][k]!=-1){
    return dp[index1][index2][k];
}
int take=INT_MIN;
int not_take=max(fun(index1+1,index2,k,s,dp),fun(index1,index2-1,k,s,dp));
int op=mindiff(s[index1],s[index2]);
if(k>=op){
     take=2+fun(index1+1,index2-1,k-op,s,dp);
}


dp[index1][index2][k]=max(take,not_take);
return dp[index1][index2][k];
  }


public:
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
   
  vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));

        return fun(0,n-1,k,s,dp);

    }
};