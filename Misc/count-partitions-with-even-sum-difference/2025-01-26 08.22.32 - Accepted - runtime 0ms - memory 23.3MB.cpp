class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixleft(n,0);
        vector<int> prefixright(n,0);
        prefixleft[0]=nums[0];
        prefixright[n-1]=nums[n-1];
        for(int i=1,j=n-2;i<n && j>=0;i++,j--){
            prefixleft[i]=prefixleft[i-1]+nums[i];
            prefixright[j]=prefixright[j+1]+nums[j];
        }
int count=0;
        for(int i=0;i<n-1;i++){
            int diff=(prefixleft[i]-prefixright[i+1]);
            if(diff%2==0){
                count++;
            }
        }
        return count;
    }
};