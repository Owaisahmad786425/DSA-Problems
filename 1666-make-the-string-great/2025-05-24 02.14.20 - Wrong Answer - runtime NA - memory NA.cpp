class Solution {
public:
    string makeGood(string s) {
       //without stack
       int n=s.size();
       vector<bool> vis(n,0);
        int i=0;
        int j=1;
        while(i>=0 && j<n){
            if(vis[i]){
                if(i==0){
                    i=j+1;
                    j=i+1;
                    continue;
                }
                i--;
                continue;
            }
            if((i==0) && (s[i]==s[j]-32 || s[i]==s[j]+32)){
                vis[i]=1;
                vis[j]=1;
                i=j+1;
                j=i+1;
                continue;
            }
            else if(s[i]==s[j]-32 || s[i]==s[j]+32){
                vis[i]=1;
                vis[j]=1;
                i--;
                j++;
                continue;
            }
            i=j;
            j++;

        }
        string res="";
    for(int i=0;i<n;i++){
      if(!vis[i]){
        res+=s[i];
      }
    }
return res;
    }
};