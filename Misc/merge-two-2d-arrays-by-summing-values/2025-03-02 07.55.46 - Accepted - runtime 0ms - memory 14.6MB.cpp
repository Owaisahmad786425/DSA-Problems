class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
 int i=0;
 int j=0;
 vector<vector<int>> res;
 while(i<n && j<m){

if(nums1[i][0]==nums2[j][0]){
int sum=nums1[i][1]+nums2[j][1];
res.push_back({nums1[i][0],sum});
i++;
j++;
}
else if(nums1[i][0]>nums2[j][0]){
    res.push_back({nums2[j][0],nums2[j][1]});
    j++;
}
else if(nums1[i][0]<nums2[j][0]){
    res.push_back({nums1[i][0],nums1[i][1]});
    i++;
}

 }
 while(i<n){
    res.push_back({nums1[i][0],nums1[i][1]});
    i++;
 }
 while(j<m){
    res.push_back({nums2[j][0],nums2[j][1]});
    j++;
 }
return res;

    }
};