class Solution {
    static bool comp(vector<int>&a1, vector<int> &a2){
        
            return a1[1]<a2[1];
       
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
int i=0;
int count=0;
int n=intervals.size();
for(int j=1;j<n;j++){
if(intervals[j][0]<intervals[i][1]){
    count++;
    continue;
}
i=j;
}
return count;
    
}
};