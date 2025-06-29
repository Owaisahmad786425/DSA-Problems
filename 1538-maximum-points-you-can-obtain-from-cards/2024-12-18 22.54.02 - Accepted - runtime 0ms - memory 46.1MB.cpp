class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int n=cardPoints.size();
       int l=k-1;
       int r=n-1;
       int max_sum=0;
       int sum=0;
       for(int i=0;i<k;i++){
        sum+=cardPoints[i];
       }
       int temp=k;
       max_sum=max(sum,max_sum);
       while(temp>0){
   sum-=cardPoints[l];
   l--;
   sum+=cardPoints[r];
   r--;
   temp--;
   max_sum=max(max_sum,sum);
       }
       return max_sum;
    }
};