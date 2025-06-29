class Solution {
public:
    int countLargestGroup(int n) {
       unordered_map<int,int> mp;
       int maxi=-1e9;
       for(int i=1;i<n;i++){
          int temp=i;
          int sum=0;
          while(temp>0){
            sum+=(temp%10);
            temp/=10;
          }
      
          mp[sum]++;
          maxi=max(maxi,mp[sum]);
          
       }
       int res=0;
       for(auto it:mp){
        if(it.second==maxi){
            res++;
        }
       }
       return res+1;
    
    }
};