class Solution {
   typedef pair<int,pair<int,int>> P;
   vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
     int n=moveTime.size();
     int m=moveTime[0].size();
     priority_queue<P,vector<P>,greater<P>> q;
     vector<vector<int>> res(n,vector<int>(m,INT_MAX));
     res[0][0]=0;
     //intitial comdition owais
      q.push({0,{0,0}});
      //altenative we will handle using flag owais
      bool flag=0; 
      while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int curr_time=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            for(auto dir:directions){
                int new_row=row+dir[0];
                int new_col=col+dir[1];
                int time_diff;
                if(new_row>=0 && new_row<n && new_col>=0 && new_col<m){
                    time_diff=max(moveTime[new_row][new_col]-curr_time,0);
                    int tot_time;
                    if(flag==0){
                    tot_time=curr_time+time_diff+1;
                    }
                    else{
                        tot_time=curr_time+time_diff+2;
                    }
                     if(tot_time<res[new_row][new_col]){
                        res[new_row][new_col]=tot_time;
                        q.push({tot_time,{new_row,new_col}});
                     }
                }

            }
        }
        flag=!flag;
      }
      return res[n-1][m-1];
    }
};