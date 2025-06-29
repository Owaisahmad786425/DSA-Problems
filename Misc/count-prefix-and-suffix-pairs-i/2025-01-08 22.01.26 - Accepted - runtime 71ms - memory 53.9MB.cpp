class Solution {
    bool isPrefixAndSuffix(string a, string b){
        int f=a.size();
        int s=b.size();
        if(f==s && a==b){
            return true;
        }
vector<string> prefix(s,"");
vector<string> suffix(s,"");
bool flag1=0;
bool flag2=0;
int l=0;
while(l<s){
prefix[l]=b.substr(0,l);
suffix[l]=b.substr(l);
if(prefix[l]==a){
    flag1=1;
}
if(suffix[l]==a){
    flag2=1;
}
if(flag1==1 &&flag2==1){
    break;
}
l++;
}
if(flag1==1 && flag2==1){
    return true;
}
return false;

    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};