class Solution {

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
 int n=isWater.size();
 int m=isWater[0].size();

vector<vector<bool>> vis(n,vector<bool>(m,0));
queue<pair<int,int>> q;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(isWater[i][j]==1){
            isWater[i][j]=0;
            q.push({i,j});
            vis[i][j]=1;
        }
    }
}
while(!q.empty()){
int size=q.size();
for(int i=0;i<size;i++){
pair<int, int> p;
p=q.front();
int row=p.first;
int col=p.second;

q.pop();
if(row+1<n && !vis[row+1][col]){
    vis[row+1][col]=1;
    isWater[row+1][col]=isWater[row][col]+1;
    q.push({row+1,col});
}
if(row-1>=0 && !vis[row-1][col]){
    vis[row-1][col]=1;
    isWater[row-1][col]=isWater[row][col]+1;
    q.push({row-1,col});
}
if(col+1<m && !vis[row][col+1]){
    vis[row][col+1]=1;
    isWater[row][col+1]=isWater[row][col]+1;
    q.push({row,col+1});

}
if(col-1>=0 && !vis[row][col-1]){
    vis[row][col-1]=1;
    isWater[row][col-1]=isWater[row][col]+1;
    q.push({row,col-1});
}

}


}
return isWater;

    }
};