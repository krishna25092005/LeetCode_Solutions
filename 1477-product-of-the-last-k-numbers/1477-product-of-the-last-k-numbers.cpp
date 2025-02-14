class ProductOfNumbers {
private:
    vector<int> prefixProducts;
public:
    ProductOfNumbers() {
        prefixProducts = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts = {1};
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefixProducts.size()) {
            return 0;
        }
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
