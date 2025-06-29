class Solution {
    void fun(int num,vector<int> &ans,int n){
        //base case
        if(num>n){
            return;
        }
        ans.push_back(num);
        for(int i=0;i<=9;i++){
           fun(num*10+i,ans,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
      vector<int> ans;
      int num=1;
      int count=1;
      for(int i=1;i<=9;i++){
      fun(i,ans,n);
      }
      return ans;
    }
};