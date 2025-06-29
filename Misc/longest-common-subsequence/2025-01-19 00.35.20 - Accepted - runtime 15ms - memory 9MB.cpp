class Solution {

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
     
         for(int i=0;i<=m;i++){
            prev[i]=0;
        }

        for(int index1=1;index1<=n;index1++){
            for(int index2=1;index2<=m;index2++){
                if(text1[index1-1]==text2[index2-1]){
        curr[index2]=1+prev[index2-1];
                }
       else{  curr[index2]=max(prev[index2] ,curr[index2-1]);

       }
            }
            prev=curr;
        }
        return prev[m];
    }
};