class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        int n=word.size();
        for(int i=0;i<word.size();i++){
            if(word[i]>=65 && word[i]<=90){
                count++;
            }
        }
        if(count==n || count==1 || count==0){
            return true;
        }
        return false;
    }
};