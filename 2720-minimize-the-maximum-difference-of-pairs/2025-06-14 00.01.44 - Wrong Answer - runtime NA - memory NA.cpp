class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<int> store(n-1);
   for(int i=0;i<n;i++){
    if(i<n-1)
    store[i]=abs(nums[i]-nums[i+1]);
   }
   sort(store.begin(),store.end());
   int temp=p;
   int prev=-1;
   int i=0;
   while(temp>0 && i<n-1){
   if(nums[i]!=prev){
      temp--;
      prev=store[i];
   }
   i++;
   }
   if(prev!=-1)
       return prev;

     return 0;  
    }
};