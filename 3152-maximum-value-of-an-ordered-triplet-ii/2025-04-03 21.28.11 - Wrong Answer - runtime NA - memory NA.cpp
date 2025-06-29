class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    int i=0,j=1;
    long long maxi1=-1e9,maxi2=-1e9,mini=1e9,result=0;
    int n=nums.size();
    for(int k=2;k<n;k++){
    maxi1=max(maxi1,(long long)nums[i]);
    mini=min(mini,(long long)nums[j]);
    long long maxdiff=maxi1-mini;
    long long val=maxdiff*nums[k];
    result=max(result,val);
    i++;
    j++;
    }
    return result;
    }
};