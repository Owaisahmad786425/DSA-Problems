class Solution {
    void merge(int low,int mid,int high,vector<int> &arr){
         vector<int> temp;
         int left=low;
         int right=mid+1;
         int cnt=0;
         while(left<=mid &&right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                long long t=2LL*arr[right];
                int l=left;
                temp.push_back(arr[right]);
                right++;
            }
         }
while(left<=mid){
    temp.push_back(arr[left]);
    left++;
}
while(right<=high){
    temp.push_back(arr[right]);
    right++;
}
for(int i=low;i<=high;i++){
    arr[i]=temp[i-low];
}

    }

int count_pair(int low,int mid,int high,vector<int> &arr){
    int count=0;
    int right=mid+1;
 
    for(int i=low;i<=mid;i++){
       
       while( right<=high&&arr[i] > 2LL * arr[right]){
            
            right++;
           
        }
        count+=(right-(mid+1));
    }
    return count;
}
int divide(int low,int high,vector<int> &arr){
if(low==high){
    return 0;
}
int count=0;
int mid=(low+high)/2;
count+=divide(low,mid,arr);
count+=divide(mid+1,high,arr);
count+=count_pair(low,mid,high,arr);
merge(low,mid,high,arr);
return count;

}


public:
    int reversePairs(vector<int>& nums) {
        vector<int> arr=nums;
        int n=nums.size();
        int low=0;
        int high=n-1;
        return divide(low,high,arr);
    }
};