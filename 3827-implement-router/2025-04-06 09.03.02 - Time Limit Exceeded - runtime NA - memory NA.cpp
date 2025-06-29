class Router {
queue<vector<int>> q;
int count;
public:
    Router(int memoryLimit) {
        count=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> vec(3);
        bool flag=true;
        vec[0]=source;
        vec[1]=destination;
        vec[2]=timestamp;
        if(q.size()==0){
            q.push(vec);
            count--;
        }
        else{
        queue<vector<int>> t;
        while(!q.empty()){
            vector<int> temp;
            temp=q.front();
            if(temp==vec){
                flag= false;
            }
            t.push(temp);
            q.pop();
        }
        while(!t.empty()){
            vector<int> temp;
            temp=t.front();
            q.push(temp);
            t.pop();
        }
            if(flag==false){
                return flag;
            }
        if(count==0){
            q.pop();
            q.push(vec);
        }
    else if(count>0){
      q.push(vec);
        count--;
    }
    }
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> temp;
        if(q.size()==0){
            return {};
        }
        temp=q.front();
        q.pop();
        count++;
        return temp;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int res_count=0;
        queue<vector<int>> t;
        while(!q.empty()){
            vector<int> temp;
            temp=q.front();
            int d=temp[1];
            int ts=temp[2];
            if(d==destination && ts<=endTime && ts>=startTime){
                res_count++;
            }
            t.push(temp);
            q.pop();
        }
        while(!t.empty()){
            vector<int> temp;
            temp=t.front();
            q.push(temp);
            t.pop();
        }
        return res_count;
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */