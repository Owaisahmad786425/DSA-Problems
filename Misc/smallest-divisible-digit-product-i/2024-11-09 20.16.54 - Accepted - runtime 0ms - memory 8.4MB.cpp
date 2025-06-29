class Solution {
int product(int temp){
    int p=1;
    while(temp>0){
        int temp1=temp%10;
        p*=temp1;
        temp=temp/10;
    }
    return p;
}
public:
    int smallestNumber(int n, int t) {
int i=n;
        while(product(i)%t!=0){
            i++;
        }
        return i;
    }
};