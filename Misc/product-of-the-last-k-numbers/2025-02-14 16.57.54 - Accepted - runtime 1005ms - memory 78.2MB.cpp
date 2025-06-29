class ProductOfNumbers {
    vector<int> vec;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        int n=vec.size();
         int product=1;
        for(int i=n-1;i>=(n-k);i--){
       product*=vec[i];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */