class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<int> store(n-1);
   for(int i=0;i<n-1;i++){
    store[i]=abs(nums[i]-nums[i+1]);
   }
   sort(store.begin(),store.end());
   int temp=p;
   int prev=-1;
   int i=0;
   while(temp>0 && i<n-1){
   if(store[i]!=prev){
      temp--;
      prev=store[i];
   }
   i++;
   }
 if(temp>0){
    return store[n-2];
 }
 if(prev==-1){
    return 0;
 }
 return prev;
    }
};