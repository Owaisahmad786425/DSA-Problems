class Solution {
    void fun(int index,vector<int> &candidates, vector<int> &temp, vector<vector<int>> &res, int t){
if(t==0){
    res.push_back(temp);
    return;
}
if(t<0 || index>=candidates.size()){
    return;
}
temp.push_back(candidates[index]);
fun(index,candidates,temp,res,t-candidates[index]);
temp.pop_back();
fun(index+1,candidates,temp,res,t);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        fun(0,candidates,temp,res,target);
        return res;

    }
};