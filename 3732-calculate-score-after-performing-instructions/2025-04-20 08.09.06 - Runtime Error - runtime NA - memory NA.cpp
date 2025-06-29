class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
       long long score=0;
        int n=values.size();
        int i=0;
        vector<bool> vis(n,0);
        while(!vis[i]&& i>=0 && i<n){
            if(instructions[i]=="add"){
                vis[i]=1;
                score+=values[i];
                i++;
            }
            else{
                vis[i]=1;
                i+=values[i];
            }
        }
        return score;
    }
};