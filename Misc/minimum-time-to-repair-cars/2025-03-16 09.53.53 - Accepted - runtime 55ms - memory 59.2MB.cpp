class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
      long long high=1LL*cars*cars*ranks[0];
      long long low=1;
      while(low<high){
        long long mid=low+(high-low)/2;
       long long car=0;
        for(auto rank:ranks)
            car+=sqrt(1.0*mid/rank);
            
            if(car<cars)
            low=mid+1;
            else{
                high=mid;
            }


        
      }
      return low;
    }
};