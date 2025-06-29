class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
int n=startTime.size();
vector<int>freeTime(n+1,0);
        freeTime[0]=startTime[0]-0;
        int i=0;
        int j=1;
int h=1;
        while(j<n){
            freeTime[h]=startTime[j]-endTime[i];
            i++;
            j++;
            h++;
        }
        freeTime[n]=eventTime-endTime[n-1];
     
        int l=0;
        int r=(l+k);
        int sum=0;
        for(int o=l;o<=r;o++){
            sum+=freeTime[o];
        }
        int maxi=sum;
       
        
        while(r<freeTime.size()){
       sum-=freeTime[l];
            l++;
            r++;
            if(r<freeTime.size()){
                sum+=freeTime[r];
            }
            maxi=max(maxi,sum);
        
        }
        return maxi;
    }
};