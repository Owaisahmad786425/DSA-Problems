class Solution {
  bool fun(int index, int n, vector<int> &res,vector<bool> &vis){
if(index>=res.size()){
    return true;
}
if(res[index]!=0){
    return fun(index+1,n,res,vis);
}

for(int i=n;i>=1;i--){
    if(vis[i]) continue;

vis[i]=1;
res[index]=i;
if(i==1){
    if(fun(index+1,n,res,vis)==true){
        return true;
    }
}
else{
    int j=res[index]+index;
   if(j<res.size() && res[j]==0){
    res[j]=i;
    if(fun(index+1,n,res,vis)==true){
        return true;
    }
    res[j]=0;
   }
}
vis[i]=0;
res[index]=0;
}


return false;

  }


public:
    vector<int> constructDistancedSequence(int n) {
        int size=(2*n)-1;
        vector<int> res(size,0);
        vector<bool> vis(n+1,0);
  fun(0,n,res,vis);
  return  res;
    }
};