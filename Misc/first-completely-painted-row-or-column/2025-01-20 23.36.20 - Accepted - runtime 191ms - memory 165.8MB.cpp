class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=arr.size();
map<int, pair<int,int>> mp;
//precomputation starts here
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
    mp[mat[i][j]]={i,j};
}
}
//pre computation is done
vector<int> hash1(m,0);
vector<int> hash2(n,0);
int ans;
for(int i=0;i<l;i++){
    pair<int,int> p;
    p=mp[arr[i]];
    hash1[p.first]++;
    hash2[p.second]++;
    if(hash1[p.first]==n || hash2[p.second]==m){
        ans=i;
        break;
    }
}
return ans;
    }
};