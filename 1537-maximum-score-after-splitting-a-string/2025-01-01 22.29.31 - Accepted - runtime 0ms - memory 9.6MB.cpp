class Solution {
public:
    int maxScore(string s) {
 int n=s.size();
 vector<int> freq1(n,0);
 vector<int> freq2(n,0);
 if(s[0]=='0'){
    freq1[0]=1;
 }
 if(s[n-1]=='1'){
    freq2[n-1]=1;
 }
for(int i=1;i<n-1;i++){
    if(s[i]=='0'){
        freq1[i]=freq1[i-1]+1;
    }
    else{
        freq1[i]=freq1[i-1];
    }
}
for(int i=n-2;i>=1;i--){
if(s[i]=='1'){
    freq2[i]=freq2[i+1]+1;
}
else{
    freq2[i]=freq2[i+1];
}
}
int maxi=INT_MIN;
for(int i=0;i<n-1;i++){
    maxi=max(maxi,freq1[i]+freq2[i+1]);
}
return maxi;

    }
};