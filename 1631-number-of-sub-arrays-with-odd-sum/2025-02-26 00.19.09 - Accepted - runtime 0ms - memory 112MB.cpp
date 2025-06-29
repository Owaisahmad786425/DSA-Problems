class Solution {
    const int MOD=1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
int n=arr.size();
long long int count=0;
int prefix=0,oddcount=0,evencount=1;
for(int i=0;i<n;i++){
    prefix+=arr[i];
    if(prefix%2==0){
        count+=oddcount;
        evencount++;
    }
    else{
        count+=evencount;
        oddcount++;
    }
}

return count%MOD;
    }
};