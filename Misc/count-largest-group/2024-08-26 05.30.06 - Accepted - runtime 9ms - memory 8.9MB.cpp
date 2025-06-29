class Solution {
    private:
    int sum(int dig){
        int res=0;
        while(dig>0){
            int temp=dig%10;
            res=res+temp;
            dig=dig/10;
        }
        return res;
    }
public:
    int countLargestGroup(int n) {
        map<int,int> mp;
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
         int s=sum(i);
         mp[s]++;
         if(maxi<mp[s]){
            maxi=mp[s];
         }
        }
        int count=0;
        for(auto it:mp){
            if(it.second==maxi){
                count++;
            }
      }
  return count;
    }
};