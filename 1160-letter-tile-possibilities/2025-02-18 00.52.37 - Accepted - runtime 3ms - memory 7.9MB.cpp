class Solution {
    void fun(map<char,int>&mp,int &count){
  for(auto &it:mp){
    if(it.second>0){
        count++;
        it.second--;
        fun(mp,count);
          it.second++;
    }
  
  }


    }
public:
    int numTilePossibilities(string tiles) {
        map<char, int> mp;
        int n=tiles.size();
        int count=0;
        for(int i=0;i<n;i++){
            mp[tiles[i]]++;
        }
        fun(mp,count);
        return count;
    }
};