class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       //got the eroor
       int n=nums.size();
       //no need of taking mini as it is tampering the data order as asked in question 
       //got that owais
       //now same logic but this time maxdiff
       int i=0;
       int j=1;
       long long maxi=-1e9,maxdiff=-1e9;
       long long result=0;
       for(int k=2;k<n;k++){
        maxi=max(maxi,(long long)nums[i]);
        maxdiff=max(maxdiff,(long long)(maxi-nums[j]));
        long long val=maxdiff*nums[k];
        result=max(val,result);
        i++;
        j++;
       } 
       return result;
    }
};