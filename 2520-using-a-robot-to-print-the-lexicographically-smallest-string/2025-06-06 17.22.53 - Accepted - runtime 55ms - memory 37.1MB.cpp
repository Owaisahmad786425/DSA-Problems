class Solution {
public:
    string robotWithString(string s) {
        //logic shi soche ho owais 
        int n=s.size();
      vector<char> minchar(n);
        minchar[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
        
            minchar[i]=min(s[i],minchar[i+1]);
        }
            string res="";
      string t="";
        int i =0;
        while(i<n){
            t+=s[i];
            char min_char;
            if(i+1<n){
                min_char=minchar[i+1];
            }
            else{
                min_char=minchar[i];
            }
            while(!t.empty()&&t.back()<=min_char){
                res+=t.back();
                t.pop_back();
            }
            i++;
        }
    while(!t.empty()){
        res+=t.back();
        t.pop_back();
    }
            return res;
    }
};