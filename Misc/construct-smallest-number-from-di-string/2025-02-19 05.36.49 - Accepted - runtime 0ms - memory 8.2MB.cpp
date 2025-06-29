class Solution {
bool fun(int index,string &res, string pattern, vector<bool> &vis,int n){
//base index
if(index<0){
    return true;
}

if(index==n){
    for(int i=n+1;i>=1;i--){
        vis[i]=1;
        res[index]='0'+i;
        if(fun(index-1,res,pattern,vis,n)==true){
            return true;
        }
        vis[i]=0;
    }
}
else if(pattern[index]=='D'){
    for(int i=1;i<=n+1;i++){
        if(('0'+i)>res[index+1] &&!vis[i]){
            vis[i]=1;
            res[index]='0'+i;
            if(fun(index-1,res,pattern,vis,n)==true){
                return true;
            }
            vis[i]=0;
        }
    }
    return false;
}
else if(pattern[index]=='I'){
    for(int i=n+1;i>=1;i--){
        if(('0'+i)<res[index+1] && !vis[i]){
            vis[i]=1;
             res[index]='0'+i;
            if(fun(index-1,res,pattern,vis,n)==true){
                return true;
            }
            vis[i]=0;
        }
    }
    return false;
}
return false;
}



public:
    string smallestNumber(string pattern) {
    int n=pattern.size();
    string res(n+1,'0');
    vector<bool> vis(n+2,0);
    fun(n,res,pattern,vis,n);
    return res;


    }
};