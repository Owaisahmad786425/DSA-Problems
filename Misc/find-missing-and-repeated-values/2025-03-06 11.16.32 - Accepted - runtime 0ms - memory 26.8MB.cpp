class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> hash((n*n)+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[grid[i][j]]++;
            }
        }
     int missing;
     int repeating;
for(int i=1;i<hash.size();i++){
    if(hash[i]==2){
        repeating=i;
    }
    if(hash[i]==0){
        missing =i;
    }
}
return {repeating,missing};

    }
};