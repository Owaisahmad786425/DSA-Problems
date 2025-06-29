class Solution {
public:
    string answerString(string word, int numFriends) {
  //find the maximum among all the character
  if(numFriends==1){
    return word;
  }
  char max_character='.';
  int n=word.size();
  int start_index;
  for(int i=0;i<n;i++){
    if(max_character<word[i]){
        max_character=word[i];
        start_index=i;
    }
  }
  string res="";
  int size=(n-numFriends+1);
int i=start_index;
int count=0;
while(i<n && count<size){
    res+=word[i];
    count++;
    i++;
}
return res;

    }
};