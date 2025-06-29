class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //lets code the brute one and then think of some optimization ok
        int n=grid.size();
        int m=grid[0].size();
int res=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
    
    if(grid[i][j]==1){
        bool flag=0;
    for(int row=0;row<n;row++){
        if(grid[row][j]==1 && row!=i){
            res+=1;
            flag=1;
            break;
        }
    }
    if(flag==0){
        for(int col=0;col<m;col++){
            if(grid[i][col]==1 && col!=j){
                res+=1;
                break;
            }
        }
    }
}
}
}
return res;
    }
};