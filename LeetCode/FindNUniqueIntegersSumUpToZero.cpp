class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        if (n % 2 == 0) {
            iota(res.begin(), res.begin() + n / 2, -n / 2);
            iota(res.begin() + n / 2, res.end(), 1);
            return res;
        } else {
            
            iota(res.begin(), res.end(), -n / 2);
            return res;
        }
    }
};

int main() {
  
  
  return 0;  
}
