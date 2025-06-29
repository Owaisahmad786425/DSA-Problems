class Solution {
bool fun(int index,int t,string s,int target){
 if(index==s.size()){
    return target==t;
 }
 if(t>target){
    return false;
 }


bool partition=false;
for(int i=index;i<s.size();i++){
string current=s.substr(index,i-index+1);
int append=stoi(current);
partition = partition || fun(i+1, t + append, s, target);

}
return partition;

}


public:
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int temp=(i*i);
            string s=to_string(temp);

if(s.size()==1 && i==temp){
    sum+=temp;
}
else{
    if(fun(0,0,s,i)){
        sum+=temp;
    }
}


        }
        return sum;
    }
};