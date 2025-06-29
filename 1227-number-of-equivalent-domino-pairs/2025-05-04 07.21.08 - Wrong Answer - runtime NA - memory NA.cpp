class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> mp;
        int n=dominoes.size();
        int res=0;
        for(int i=0;i<n;i++){
            vector<int> temp=dominoes[i];
            reverse(temp.begin(),temp.end());
            if(mp.find(dominoes[i])!=mp.end() || mp.find(temp)!=mp.end()){
                res++;
                continue;
            }
            mp[dominoes[i]]++;
        }
        res=(res*(res+1))/2;
        return res;

    }
};