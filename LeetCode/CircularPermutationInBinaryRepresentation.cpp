class Solution {
public:
    void generate(int &i) {
        if (i == n_) {
            return;
        }
        if (i > n_) {
            return;
        }
        for (int k = 0; k != 31; ++k) {
            tmp = result[i - 1] ^ (1 << k);
            if (tmp < n_ && ban[tmp] == false) {
                ban[tmp] = true;
                result[i] = tmp;
                ++i;
                generate(i);
                break;
            }      
        } 
    }
    vector<int> circularPermutation(int n, int start) {
        n_ = pow(2, n);
        result.resize(n_, 0);
        ban.resize(n_, false);
        ban[start] = true;
        result[0] = start;
        int i = 1;
        generate(i);
        return result;
    }
private:
    vector<bool> ban;
    int tmp = 0;
    int n_ = 0;
    vector<int> result;
};

int main() {
  
    
  return 0; 
}
