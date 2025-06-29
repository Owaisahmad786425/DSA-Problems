class Solution {
int fun(int a,int b,unordered_map<int,int> &mp,vector<int> &arr,int n){
int sum=arr[a]+arr[b];
if(mp.find(sum)!=mp.end()){
    int temp=mp[sum];
    return 1+fun(b,temp,mp,arr,n);
}
return 2;


}

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int maxi=0;
 for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
   int len=fun(i,j,mp,arr,n);
   if(len>=3){
maxi=max(maxi,len);
   }
    }
 }
return maxi;

    }
};