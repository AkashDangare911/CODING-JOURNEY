class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    ProductOfNumbers() {
        prefixProduct = {};
    }
    
    void add(int num) {
        prefixProduct.push_back(num);
    }
    
    int getProduct(int k) {
        int prod=1;
        int lastInd = prefixProduct.size()-1;
        while(k--)
        {
            prod = prod*prefixProduct[lastInd];
            lastInd--;
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */