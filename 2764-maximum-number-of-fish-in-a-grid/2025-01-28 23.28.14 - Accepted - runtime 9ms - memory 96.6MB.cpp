class Solution {
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>> &grid,int n,int m,int&sum,int row[],int col[]){

if(i<0 || i>=n ||j<0 || j>=m){
    return;
}
if(vis[i][j] || grid[i][j]==0){
    return;
}
vis[i][j]=1;
sum+=grid[i][j];
for(int k=0;k<4;k++){
    dfs(i+row[k],j+col[k],vis,grid,n,m,sum,row,col);
}

    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
int row[4]={0,0,-1,1};
int col[4]={-1,1,0,0};
int maxi=INT_MIN;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
if(grid[i][j]!=0 && !vis[i][j]){
    int sum=0;
    dfs(i,j,vis,grid,n,m,sum,row,col);
    maxi=max(sum,maxi);
}

    }
}
if(maxi==INT_MIN){
    return 0;
}
return maxi;
    }
};