class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
       int n=dominoes.size();
       map<vector<int>,int> mp;
       int res=0;
       for(int i=0;i<n;i++){
        vector<int> temp=dominoes[i];
        reverse(temp.begin(),temp.end());
        if(mp.find(temp)!=mp.end()){
         mp[temp]++;
        res+=mp[temp]-1;
           
        }
        else if(mp.find(dominoes[i])!=mp.end()){
            mp[dominoes[i]]++;
            res+=mp[dominoes[i]]-1;
        }
        else{
        mp[dominoes[i]]++;
        }
       } 
       return res;
    }
};