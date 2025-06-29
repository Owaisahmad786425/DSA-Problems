class Solution {
    int sum_of_digits(int num){
        int temp=num;
        int sum=0;
        while(temp>0){
            sum+=(temp%10);
            temp=temp/10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> hash;
        for(int i=0;i<n;i++){
            hash.push_back({sum_of_digits(nums[i]),nums[i]});
        }
        int maxi=-1;
        sort(hash.begin(),hash.end());
        for(int i=0;i<n-1;i++){
            if(hash[i].first==hash[i+1].first){
                maxi=max(maxi,(hash[i].second+hash[i+1].second));
            }
        }
        return maxi;
    }
};