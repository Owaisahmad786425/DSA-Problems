class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        int n=word1.size();
      vector<int> freq1(26,0);
      vector<int> freq2(26,0);
      for(int i=0;i<n;i++){
        freq1[word1[i]-'a']++;
         freq2[word2[i]-'a']++;
      }
        for(int i=0;i<26;i++){
            if((freq1[i]==0 && freq2[i]!=0) || (freq1[i]!=0 && freq2[i]==0)){
                return false;
            }
            else{
                bool flag=0;
                for(int j=0;j<26;j++){
                    if(freq1[i]==freq2[j] && i!=j){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    return false;
                }
            }
        }
        return true;
    }
};