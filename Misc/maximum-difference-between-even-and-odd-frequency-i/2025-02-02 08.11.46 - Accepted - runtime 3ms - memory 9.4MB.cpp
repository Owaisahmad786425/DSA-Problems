class Solution {
public:
    int maxDifference(string s) {
        vector<int> hash(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
        }
        int maxodd=INT_MIN;
        int mineven=INT_MAX;
        for(int i=0;i<n;i++){
            if(hash[s[i]-'a']%2==0){
                mineven=min(mineven,hash[s[i]-'a']);
            }
            else {
                maxodd=max(maxodd,hash[s[i]-'a']);
            }
        }
        return (maxodd-mineven);
    }
};