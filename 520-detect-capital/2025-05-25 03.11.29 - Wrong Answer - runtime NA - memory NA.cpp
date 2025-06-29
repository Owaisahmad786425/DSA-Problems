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
        if(count==n || count==0){
          return true;
        }
        else if(count==0 && word[0]<=65 && word[0]>=90) return true;
        return false;
    }
};