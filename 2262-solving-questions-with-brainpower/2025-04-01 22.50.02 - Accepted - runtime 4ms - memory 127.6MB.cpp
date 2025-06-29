class Solution {
    long long fun(int index, int n , vector<vector<int>> &questions,vector<long long> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        //take
        long long take=questions[index][0]+fun(index+(questions[index][1]+1),n,questions,dp);
        long long not_take=0+fun(index+1,n,questions,dp);
        return dp[index]=max(take,not_take);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return fun(0,n,questions,dp);
    }
};