class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 2);
            n /= 2;
        }
        int even = 0;
        int odd = 0;
        for (int i = 0; i != v.size(); ++i) {
            if ((i % 2) == 0 && v[i] == 1) {
                even++;
            } else if ((i % 2) == 1 && v[i] == 1) {
                odd++;
            }
        }
        return {even, odd};
    }
};

int main() {
  
  
  return 0;  
}
