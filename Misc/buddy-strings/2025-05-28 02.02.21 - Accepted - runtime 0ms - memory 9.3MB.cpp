class Solution {
public:
    bool buddyStrings(string s, string goal) {
      vector<int> hash(26,0);
      int n=s.size();
      if(n!=goal.size()){
        return false;
       }
int cnt=0,idx1=-1e9,idx2=-1e9;
bool flag=0;
       for(int i=0;i<n;i++){
       hash[s[i]-'a']++;
       if(!flag && hash[s[i]-'a']>1){
        flag=true;
       }
       if(s[i]!=goal[i]){
        cnt++;
        if(cnt==1){
            idx1=i;
        }
        else if(cnt==2){
            idx2=i;
        }
       }
       }
       if(cnt>2 || ((idx1==-1e9 && idx2!=-1e9) || (idx1!=-1e9 &&idx2==-1e9))){
        return false;
       }

       if(cnt<2 && flag==1){
        return true;
       }
       if(idx1==-1e9 || idx2==-1e9){
        return false;
       }
       swap(s[idx1],s[idx2]);
       return goal==s;
    }
};