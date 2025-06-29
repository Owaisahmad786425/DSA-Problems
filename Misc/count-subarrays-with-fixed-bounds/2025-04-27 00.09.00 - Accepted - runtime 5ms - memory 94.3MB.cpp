class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        queue<int> q;
        int n=nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]>maxk || nums[i]<mink){
            q.push(i);
        }
       }

       //apply sliding window here
       int  l=0;
       int r=0;
       int mini=1e9,last_min_seen=-1;
       int maxi=-1e9,last_max_seen=-1;
       long long res=0;
       while(r<n){
      if(!q.empty() && r==q.front()){
        l=r+1;
        r=l;
        maxi=-1e9;
        mini=1e9;
        q.pop();
       continue;
      }
        mini=min(mini,nums[r]);
        if(nums[r]==mink){
            last_min_seen=r;
        }
        maxi=max(maxi,nums[r]);
        if(nums[r]==maxk){
            last_max_seen=r;
        }
      while(mink==mini && maxk==maxi){
        if(!q.empty()){
        res+=q.front()-r;
        }
        else{
            res+=n-r;
        }
        //reset while invalid check this in copy owais
        if(l==last_min_seen){
            mini=1e9;
        }
        if(l==last_max_seen){
            maxi=-1e9;
        }
        l++;
      }


        r++;
       }
       return res;
    }
};