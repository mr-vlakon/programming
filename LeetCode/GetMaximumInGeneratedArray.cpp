class Solution {
public:
    int getMaximumGenerated(int n) {
        int i = 0;
        vector<int> v;
        if (n >= 0) {
            v.push_back(0);
        }
        if (n >= 1) {
            v.push_back(1);
        }
        i = 1;
        while (v.size() < n) {
            v.push_back(v[i]);
            v.push_back(v[i] + v[i + 1]);
            ++i;
        }
        return *max_element(v.cbegin(), v.cend());
    }
};

int main() {
  
  
  
  return 0;  
}
