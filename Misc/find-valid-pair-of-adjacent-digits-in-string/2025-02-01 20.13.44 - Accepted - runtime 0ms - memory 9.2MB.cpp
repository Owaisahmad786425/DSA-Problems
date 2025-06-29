class Solution {
public:
    string findValidPair(string s) {
int n=s.size();
        //hashing 
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;//store the frequency
        }
    int i=0;
        int j=1;
        string res;
        while(j<n){
            int freq1=s[i]-'0';
            int freq2=s[j]-'0';
            if(s[i]!=s[j] && freq1==mp[s[i]] && freq2==mp[s[j]]){
               res.push_back(s[i]);
                res.push_back(s[j]);
                return res;
                
            }
            i++;
            j++;
        }
      return "";  
        
    }
};