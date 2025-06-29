class Solution {
    const int MOD=1e9+7;
    bool check(string a,string b){
        for(int k=0;k<a.size();k++){
            if(a[k]==b[k]){
                return false;
            }
        }
        return true;
    }
    void fun(vector<string> &permutations,int count,char prev,string s,int m){
        if(count==m){
            permutations.push_back(s);
            return;
        }

        for(auto ch:{'R','B','G'}){
            if(ch!=prev){
                fun(permutations,count+1,ch,s+ch,m);
            }
        }

    }
    int solve(int rem,string prev,vector<string> &permutations){
        if(rem==0){
            return 1;
        }
       int ways=0;
        for(int j=0;j<permutations.size();j++){
          if(check(prev,permutations[j])){
            ways=(ways+solve(rem-1,permutations[j],permutations))%MOD;
          }
        }
        return ways;
    }
public:
    int colorTheGrid(int m, int n) {
        vector<string> permutations;
        int count=0;
        char prev='*';
        string s="";
        //find the permutation 
        int res=0;
        fun(permutations,count,prev,s,m);
        for(int i=0;i<permutations.size();i++){
           res=(res+solve(n-1,permutations[i],permutations))%MOD;
        }
        return res;

    }
};