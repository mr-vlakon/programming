class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices):  disc(discount), nn(n) {
        for (decltype(products.size()) i = 0; i != products.size(); ++i) {
            um[products[i]] = prices[i];
        }        
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        ++num;
        double bill = 0.0;
        for (decltype(product.size()) i = 0; i < amount.size(); ++i) {
            bill += static_cast<double>(amount[i]) * static_cast<double>(um[product[i]]);
            
        }
        if (num == nn) {
            num = 0;
            return bill * ((100.00 - disc) / 100.00);
        } else {
            return bill;
        }
        
    }
private:
    int nn = 0;
    unordered_map<int, int> um;
    double disc = 0;
    int num = 0;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

int main() {
  
  
  return 0;  
}
