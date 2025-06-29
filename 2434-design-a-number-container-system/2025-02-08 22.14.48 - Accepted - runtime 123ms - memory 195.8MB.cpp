class NumberContainers {
    unordered_map<int,int> index_to_num;
    unordered_map<int ,set<int>> num_to_index;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(index_to_num.find(index)!=index_to_num.end()){
         num_to_index[index_to_num[index]].erase(index);
          index_to_num[index]=number;
            num_to_index[number].insert(index);
        }
        else{
            index_to_num[index]=number;
            num_to_index[number].insert(index);
        }
    }
    
    int find(int number) {
        if(num_to_index.find(number)!=num_to_index.end()){
            if(num_to_index[number].size()!=0){
            return *num_to_index[number].begin();
            }
            return -1;
        }
        
            return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */