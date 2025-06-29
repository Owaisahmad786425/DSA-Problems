class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1){
            return word;
        }
        string res="";
        int size=(n-(numFriends-1));
        for(int i=0;i<n;i++){
            int largest_possible=min(size,(n-i));
            res=max(res,word.substr(i,largest_possible));
        }
        return res;
    }
};