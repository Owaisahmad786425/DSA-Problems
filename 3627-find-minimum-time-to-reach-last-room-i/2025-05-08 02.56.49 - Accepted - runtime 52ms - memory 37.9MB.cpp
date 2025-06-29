class Solution {
    vector<vector<int>> direction{{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,pair<int,int>> P;
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int curr_time=pq.top().first;
            pair<int,int> cell=pq.top().second;
            int i=cell.first;
            int j=cell.second;
            pq.pop();
       

            for(auto dir:direction){
                int i_=i+dir[0];
                int j_=j+dir[1];
                if(i_>=0 && i_<n &&j_>=0 && j_<m){
                    int wait=max(moveTime[i_][j_]-curr_time,0);
                    int arr_time=curr_time+wait+1;
                    if(result[i_][j_]>arr_time){
                        result[i_][j_]=arr_time;
                        pq.push({arr_time,{i_,j_}});
                    }
                }
            }
        }
   
return result[n-1][m-1];
    }
};