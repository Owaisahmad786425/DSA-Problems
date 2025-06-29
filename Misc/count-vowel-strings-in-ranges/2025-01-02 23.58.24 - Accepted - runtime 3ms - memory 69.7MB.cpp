class Solution {
    bool fun(char k){
        if(k =='a' || k=='e' || k=='i' || k=='o' || k=='u'){
            return true;
        }
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
     int n=words.size();
     vector<int> hash(n,0);
     int m=words[0].size();
     if(fun(words[0][0])==true && fun(words[0][m-1])==true){
        hash[0]++;
     }
     for(int i=1;i<n;i++){
        int temp=words[i].size();
        if(fun(words[i][0])==true && fun(words[i][temp-1])==true){
            hash[i]=hash[i-1]+1;
        }
        else{
            hash[i]=hash[i-1];
        }
     }  
//till above portion its working
int t=queries.size();
vector<int> res;
for(int i=0;i<t;i++){
    if(queries[i][0]==queries[i][1]){
        int tu=words[queries[i][0]].size();
    if(fun(words[queries[i][0]][0])==true && fun(words[queries[i][0]][tu-1])){
        res.push_back(1);
    }
    else{
        res.push_back(0);
    }
    }
    else if(queries[i][0]==0){
        res.push_back(hash[queries[i][1]]);
    }
    else{
        res.push_back(hash[queries[i][1]]-hash[queries[i][0]-1]);
    }
}              
return res;       
    }
};