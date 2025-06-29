class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
      int l=0;
      int r=k-1;
      int count=0;
      int mini=1e9;
      for(int i=l;i<=r;i++){
        if(blocks[i]=='W'){
            count++;
        }
      }
      mini=min(mini,count);
      
      while(r<n){
     if(blocks[l]=='W'){
        count--;
     }
     l++;
     r++;
     if(r!=n){
        if(blocks[r]=='W'){
            count++;
        }
     }
     if(r<n)
     mini=min(mini,count);

      }
return mini;


    }
};