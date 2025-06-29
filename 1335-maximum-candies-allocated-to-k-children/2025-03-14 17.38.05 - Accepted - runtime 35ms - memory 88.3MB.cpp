class Solution {
    bool check(vector<int> &candies, long long mid, long long k){
        long long count=0;
      for(int i=0;i<candies.size();i++){
        count+=candies[i]/mid;
        if(count>=k){
            return true;
        }
      }
      return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int low=1;
        int maxi=-1e9;
    long long total=0;
        for(int i=0;i<n;i++){
            total+=candies[i];
            maxi=max(maxi,candies[i]);
        }
        if(total<k){
            return 0;
        }
        int high=maxi;
        int res=0;
       while(low<=high){
    long long  mid=low+(high-low)/2;
    if(check(candies,mid,k)==true){
         res=mid;
         low=mid+1;
    }
    else{
        high=mid-1;
    }
 

       }
return res;
    }
};