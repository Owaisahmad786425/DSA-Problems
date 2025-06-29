class Solution {
private:
 void dfs(int r, int c, int delr[], int delc[], int n,int m, vector<vector<int>>&vis,vector<vector<int>>&grid2,vector<pair<int,int>> &temp){
    vis[r][c]=1;
    temp.push_back({r,c});
    for(int i=0;i<4;i++){
        int nrow=r+delr[i];
        int ncol=c+delc[i];
       if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid2[nrow][ncol]==1){
        dfs(nrow,ncol,delr,delc,n,m,vis,grid2,temp);
       }


    }
 }


public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        queue<vector<pair<int,int>>> q;
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(grid2[i][j]==1&&!vis[i][j]){
                    vector<pair<int,int>> temp;
                    dfs(i,j,delr,delc,n,m,vis,grid2,temp);
                    q.push(temp);
                  }
            }
        }
      
        int count=0;
while(!q.empty()){
    vector<pair<int,int>> vec;
    int flag=0;
    vec=q.front();
    q.pop();
    for(int i=0;i<vec.size();i++){
        int r=vec[i].first;
        int c=vec[i].second;
        if(grid1[r][c]!=1){
            flag=1;
            break;
        }
    }
    if(flag==0){
        count++;
    }
}
return count;
    }
};