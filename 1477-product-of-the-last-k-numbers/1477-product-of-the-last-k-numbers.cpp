class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    ProductOfNumbers() {
        prefixProduct = {1};
    }

    void add(int num) {
        if(num == 0)
        // reset the array, as if we have to find product of previous 'k' elements
        // and if any element prev 'k' elements is '0', then we don't need to calculate further,
        //  so while calculating if we get '-ve' index, it means we have got a '0'
            prefixProduct = {1};
        else{
            // maintain prefix-product
            prefixProduct.push_back(prefixProduct.back()*num);
        }
    }
    
    int getProduct(int k) {
        int last = prefixProduct.size()-1;
        // this indicates that we have encountered zero somewhere at index <= k
        if(last-k < 0)
            return 0;
        
        // no zeros in left 'k' places
        return prefixProduct.back()/prefixProduct[last-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */