class Solution {
    bool vovel(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
            return true;
        }
        return false;
    }
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
int maxi1=0;
        int maxi2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(vovel(s[i])){
                freq[s[i]-'a']++;
                maxi1=max(maxi1,  freq[s[i]-'a']);
            }
            else{
               freq[s[i]-'a']++;
                maxi2=max(maxi2,  freq[s[i]-'a']);
            }
        }
        return maxi1+maxi2;
    }
};