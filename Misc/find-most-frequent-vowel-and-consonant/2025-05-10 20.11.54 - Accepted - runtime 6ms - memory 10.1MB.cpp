class Solution {
    bool vovel(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
            return true;
        }
        return false;
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp1;
        unordered_map<char,int>mp2;
int maxi1=0;
        int maxi2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(vovel(s[i])){
                mp1[s[i]]++;
                maxi1=max(maxi1,mp1[s[i]]);
            }
            else{
                mp2[s[i]]++;
                maxi2=max(maxi2,mp2[s[i]]);
            }
        }
        return maxi1+maxi2;
    }
};