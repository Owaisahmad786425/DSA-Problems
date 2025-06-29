class Solution {
public:
    string answerString(string word, int numFriends) {
  //sliding window type hai constant window
  //first try to identify constant window
  if(numFriends==1){
    return word;
  }
  int n=word.size();
  int high;
  for(int i=0;i<n;i++){
     if(((n-1) - i)<numFriends-1){
        high=i-1;
        break;
     }
  }
  string res="";
  //substr use kro function hojayega
  int low=0;
  while(high<n){
    if(res<word.substr(low,(high-low+1))){
        res=word.substr(low,(high-low+1));
    }
    high++;
    low++;
  }
  return res;

    }
};