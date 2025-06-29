class Solution {
void fun(set<string> &st,string tiles,string &temp,vector<bool> &vis,int n){
    st.insert(temp);
    for(int i=0;i<n;i++){
if(vis[i]){
    continue;
}

vis[i]=1;
temp.push_back(tiles[i]);
fun(st,tiles,temp,vis,n);
vis[i]=0;
temp.pop_back();
    }

}



public:
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        set<string> st;
        string temp;
        vector<bool> vis(n,0);
      fun(st,tiles,temp,vis,n);
      return st.size()-1;
    }
};