class Solution {
    void build_tree(int index,int l,int r, vector<int> &segment_tree){
        if(l==r){
            segment_tree[index]=0;
            return;
        }
        int mid=(l+r)/2;
        build_tree((2*index)+1,l,mid,segment_tree);
        build_tree((2*index)+2,mid+1,r,segment_tree);
        segment_tree[index]=segment_tree[(2*index)+1]+segment_tree[(2*index)+2];
    }
 void update_tree(int index,int l,int r, int idx,vector<int> &segment_tree){
    if(l==r){
    segment_tree[index]=1;
    return;
    }
    int  mid=(l+r)/2;
    if(mid>=idx){
        update_tree((2*index)+1,l,mid,idx,segment_tree);
    }
    else{
        update_tree((2*index)+2,mid+1,r,idx,segment_tree);
    }
    segment_tree[index]=segment_tree[(2*index)+1]+segment_tree[(2*index)+2];
 }
 int query(int start,int end,int l,int r, int index,vector<int>&segment_tree){
    if(l>end || r<start){
        return 0;
    }
    if(l>=start && r<=end){
        return segment_tree[index];
    }
    int mid=(l+r)/2;
    return query(start,end,l,mid,(2*index)+1,segment_tree)+query(start,end,mid+1,r,(2*index)+2,segment_tree);
 }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
   vector<int> segment_tree(4*n);
    build_tree(0,0,n-1,segment_tree);
     int idx=mp[nums1[0]];
     update_tree(0,0,n-1,idx,segment_tree);
     long long res=0;
     for(int i=1;i<n-1;i++){
        int end_index=mp[nums1[i]];
        if(end_index==n-1){
            continue;
        }
        long long left_common_count=query(0,end_index,0,n-1,0,segment_tree);
        long long left_uncommon_count=i-left_common_count;
        long long  remaining_size=n-end_index-1;
        long long right_common_count=remaining_size-left_uncommon_count;
        res+=(left_common_count*right_common_count);
        update_tree(0,0,n-1,end_index,segment_tree);
     }
     return res;
    }
};