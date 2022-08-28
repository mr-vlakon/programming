class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> v;
        for (decltype(v.size()) i = 0; i != n; ++i) {
            v.push_back(start + 2 * i);
        }
        if (v.size() == 0) return 0;
        int x = v[0];  
        for (decltype(v.size()) j = 1; j != n; ++j) {
            x ^= v[j];
        }
        return x;      
    }
};

int main() {
  
 return 0; 
}
