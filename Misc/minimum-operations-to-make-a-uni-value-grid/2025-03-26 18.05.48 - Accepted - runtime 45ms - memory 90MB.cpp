class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
     vector<int> vec;
     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            vec.push_back(grid[i][j]);
        }
     }
     sort(vec.begin(),vec.end());
     int res=0;
     int n=vec.size();
     int index=(n/2);
     int mid_element=vec[index];
     for(auto &num:vec){
        if(mid_element%x!=num%x){
        return -1;
        }
        res+=abs(mid_element-num)/x;

     }
return res;
    }
};