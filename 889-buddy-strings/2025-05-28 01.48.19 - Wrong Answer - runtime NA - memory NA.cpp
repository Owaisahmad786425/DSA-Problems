class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size()){
            return false;
        }
        int cnt=0;
        int index1,index2;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                cnt++;
                if(cnt==1){
                    index1=i;
                }
                if(cnt==2){
                    index2=i;
                }
            }
        }
        if(cnt>2){
            return false;
        }
        swap(s[index1],s[index2]);
        return s==goal;
    }
};