class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int tot_sum1=0,tot_sum2=0,zero1=0,zero2=0;
        for(int i=0;i<n1;i++){
            tot_sum1+=nums1[i];
            if(nums1[i]==0){
                zero1++;
            }
        }
        for(int i=0;i<n2;i++){
            tot_sum2+=nums2[i];
            if(nums2[i]==0){
                zero2++;
            }
        }
        //invalid case ;
        if(tot_sum1==tot_sum2 && ((zero1>0 && zero2==0) ||(zero1==0 &&zero2>0))){
            return -1;
        }
        else if(tot_sum2!=tot_sum1 && zero2==0 && (tot_sum2+zero2<tot_sum1+zero1)){
            return -1;
        }
        else if(tot_sum1!=tot_sum2 && zero1==0 && (tot_sum1+zero1<tot_sum2+zero2)){
            return -1;
        }
    // you are very close owais just try it 
    long long temp1=tot_sum1+zero1;
    long long temp2=tot_sum2+zero2;
    if(temp1>temp2){
        return temp1;

    }
    return temp2;
    }
};