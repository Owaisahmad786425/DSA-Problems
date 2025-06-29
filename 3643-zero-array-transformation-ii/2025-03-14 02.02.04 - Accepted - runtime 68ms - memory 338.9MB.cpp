class Solution {
bool check(vector<int> &nums,vector<vector<int>> &queries,int n,int index){

vector<int> diff(n,0);
for(int i=0;i<=index;i++){
    int start=queries[i][0];
    int end=queries[i][1];
    int val=queries[i][2];
    diff[start]+=val;
    if(end+1<n){
        diff[end+1]-=val;
    }
}
int prefix_sum=0;
for(int i=0;i<n;i++){
    prefix_sum+=diff[i];
    diff[i]=prefix_sum;
    if(nums[i]-diff[i]>0){
        return false;
    }
}
return true;
}


public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int low=0;
        int high=q-1;
        bool flag=0;
        for(int i=0;i<n;i++){
     if(nums[i]!=0){
        flag=1;
     }

        }
        if(flag==0){
            return 0;
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(nums,queries,n,mid)==true){
                ans=mid+1;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

return ans;

    }
};