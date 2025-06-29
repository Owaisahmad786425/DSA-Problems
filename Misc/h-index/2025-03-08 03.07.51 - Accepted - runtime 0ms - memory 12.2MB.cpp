class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
int h=n;
sort(citations.begin(),citations.end(),greater<int>());
while(h>0){
if(citations[h-1]>=h){
    break;
}
h--;

}
return h;

    }
};