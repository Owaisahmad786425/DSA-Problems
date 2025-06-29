class Solution {
   void longestCommonSubsequence(string text1, string text2,vector<vector<int>> &dp) {
        
        int n=text1.size();
        int m=text2.size();
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
         for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }

        for(int index1=1;index1<=n;index1++){
            for(int index2=1;index2<=m;index2++){
                if(text1[index1-1]==text2[index2-1]){
        dp[index1][index2]=1+dp[index1-1][index2-1];
                }
       else{  dp[index1][index2]=max(dp[index1-1][index2] ,dp[index1][index2-1]);

       }
            }
        }
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int s1=str1.size();
        int s2=str2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));
        longestCommonSubsequence(str1,str2,dp);
        string res;
        int i=s1;
        int j=s2;
        while(i>0 && j>0){
       if(str1[i-1]==str2[j-1]){
        res.push_back(str1[i-1]);
        i=i-1;
        j=j-1;
       }
     
       else if(dp[i-1][j]>=dp[i][j-1]){
            res.push_back(str1[i-1]);
            i=i-1;
        }
        else{
            res.push_back(str2[j-1]);
            j=j-1;
        }
        }
        
while(i>0){
    res.push_back(str1[i-1]);
    i--;
}

while(j>0){
    res.push_back(str2[j-1]);
    j--;
}
reverse(res.begin(),res.end());
return res;
    }
};