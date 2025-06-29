class Solution {
bool fun(int index,string &res, vector<string> &nums, map<string,int> &mp,int n){
if(index==n){
    if(mp.find(res)==mp.end()){
        return true;
    }
    return false;
}

for(int i=0;i<=1;i++){
    res.push_back('0'+i);
    if(fun(index+1,res,nums,mp,n)==true){
        return true;
    }
    res.pop_back();
}
return false;

}


public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string, int> mp;
        //precomputation
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
    string res;
    int n=nums.size();
    fun(0,res,nums,mp,n);
    return res;



    }
};