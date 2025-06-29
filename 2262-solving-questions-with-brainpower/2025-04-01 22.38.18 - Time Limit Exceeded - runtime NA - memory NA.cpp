class Solution {
    int fun(int index, int n , vector<vector<int>> &questions){
        if(index>=n){
            return 0;
        }
        //take
        int take=questions[index][0]+fun(index+(questions[index][1]+1),n,questions);
        int not_take=0+fun(index+1,n,questions);
        return max(take,not_take);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        return fun(0,n,questions);
    }
};