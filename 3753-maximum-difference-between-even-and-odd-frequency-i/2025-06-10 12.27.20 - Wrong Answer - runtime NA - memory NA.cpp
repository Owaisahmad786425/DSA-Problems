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
            if(freq[s[i]-'a']%2!=0 && odd_freq<freq[s[i]-'a']){
                odd_freq=freq[s[i]-'a'];
            }
            else if(even_freq>freq[s[i]-'a']){
                even_freq=freq[s[i]-'a'];
            }
        }
        return (odd_freq-even_freq)-1;
    }
};