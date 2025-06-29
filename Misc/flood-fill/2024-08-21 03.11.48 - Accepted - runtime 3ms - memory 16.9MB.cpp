class Solution {
        private:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int delr[],int delc[],int color,int n,int m,int store){
   // vis[row][col]=1; 
        ans[row][col]=color;
        for(int i=0;i<4;i++){
            int nrow=row+delr[i];
            int ncol=col+delc[i];
            if(ncol>=0&&ncol<m&&nrow>=0&&nrow<n&&image[nrow][ncol]==store&&ans[nrow][ncol]!=color){
          
                dfs(nrow,ncol,ans,image,delr,delc,color,n,m,store);
            }
        }
        
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
           int n=image.size();
        int m=image[0].size();
        int store=image[sr][sc];
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        vector<vector<int>> ans=image;
        dfs(sr,sc,ans,image,delr,delc,color,n,m,store);
        return ans; 
    }
};