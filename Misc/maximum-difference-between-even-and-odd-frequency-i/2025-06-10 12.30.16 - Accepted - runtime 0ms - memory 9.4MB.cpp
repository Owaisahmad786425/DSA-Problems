class Solution {
public:
    int maxDifference(string s) {
        int odd_freq=-1e9;
        int even_freq=1e9;
        //hashing array
        vector<int> freq(26,0);
        int n=s.size();
         for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
         }
           for(int i=0;i<26;i++){
            if(freq[i]!=0 && freq[i]%2!=0){
                odd_freq=max(odd_freq,freq[i]);
            }
            else if(freq[i]!=0){
                even_freq=min(even_freq,freq[i]);
            }
           }
           return odd_freq-even_freq;
    }
};