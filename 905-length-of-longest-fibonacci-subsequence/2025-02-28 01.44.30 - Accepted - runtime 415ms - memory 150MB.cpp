class Solution {
int fun(int a,int b,unordered_map<int,int> &mp,vector<int> &arr,int n,vector<vector<int>> &dp){
int sum=arr[a]+arr[b];
if(dp[a][b]!=-1){
    return dp[a][b];
}
if(mp.find(sum)!=mp.end()){
    int temp=mp[sum];
    return dp[a][b]=1+fun(b,temp,mp,arr,n,dp);
}
return dp[a][b]=2;


}

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int maxi=0;
        vector<vector<int>> dp(n,vector<int> (n,-1));
 for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
   int len=fun(i,j,mp,arr,n,dp);
   if(len>=3){
maxi=max(maxi,len);
   }
    }
 }
return maxi;

    }
};