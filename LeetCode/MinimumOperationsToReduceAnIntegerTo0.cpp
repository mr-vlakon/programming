class Solution {
public:
    int minOperations(int n) {
        if ( (n & (n - 1)) == 0) return 1;
        vector<int> v;
        while (n) {
            v.push_back(n % 2);
            n /= 2;
        }    
        int cnt = 0;
        for (int i = 0; i < (static_cast<int>(v.size()) - 2); ++i) {
            if (v[i] == 1 && v[i + 1] == 1) {
                v[i] = 0;
                v[i + 1] = 0;
                v[i + 2] = v[i + 2] + 1;
                i = i + 2;
                ++cnt;
                while (i < (v.size() - 1) && v[i] > 1) {
                    v[i] = 0;
                    v[i + 1] += 1;
                    ++i;
                }
                --i;
            }
        } 
        return cnt + count_if(v.begin(), v.end(), [](const int &x) {
            return x >= 1;
        });
    }
};

int main() {
  
  
  
  return 0;  
}
