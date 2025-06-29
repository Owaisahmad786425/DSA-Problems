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
  unordered_map<int,int> mp;
  for(int i=0;i<n;i++){
    if(max_character<word[i]){
        max_character=word[i];
        start_index=i;
    }
  }
  for(int i=0;i<n;i++){
    if(i==start_index){
        mp[i]++;
    }
  }
  string res="";
  int size=(n-numFriends+1);
for(auto it:mp){
    int start=it.first;
    int count=0;
    string temp="";
while(start<n && count<size){
    temp+=word[start];
    start++;
    count++;
   }
   res=max(res,temp);
}
return res;

    }
};