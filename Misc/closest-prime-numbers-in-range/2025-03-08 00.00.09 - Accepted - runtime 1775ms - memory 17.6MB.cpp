class Solution {
bool is_prime(int num){

for(int k=2;k<=sqrt(num);k++){
    if(num%k==0){
        return false;
    }
}
return true;
}




public:
    vector<int> closestPrimes(int left, int right) {
        
 vector<int> vec;
 for(int i=left;i<=right;i++){
    if(i==2){
        vec.push_back(i);
    }
   else if(is_prime(i) &&i!=1){
        vec.push_back(i);
    }
 }
if(vec.size()<2){
    return {-1,-1};
}
int mini=1e9;
for(int i=0;i<vec.size()-1;i++){
    mini=min(mini,(vec[i+1]-vec[i]));
}
int first;
int second;
for(int i=0;i<vec.size()-1;i++){
    if(vec[i+1]-vec[i]==mini){
        first=vec[i];
        second=vec[i+1];
        break;
    }
}
return {first,second};
    }
};