class Solution {
public:
    void generate(int &i) {
        if (i == (n_ - 1)) {
            return;
        }
        int tmp = 0;
        for (int k = 0; k != 31; ++k) {
            tmp = result[i - 1] ^ (1 << k);
            if (us.find(tmp) == us.cend()) {
                us.insert(tmp);
                result[i] = tmp;
                break;
            }
        } 
        ++i;
        generate(i);
    }
    vector<int> circularPermutation(int n, int start) {
        n_ = pow(2, n);
        result.resize(pow(2, n), 0);
        result[0] = start;
        us.insert(result[0]);
        result[result.size() - 1] = result[0] ^ (1 << 0);
        us.insert(result[result.size() - 1]);
        int i = 1;
        generate(i);
        return result;
    }
private:
    unordered_set<int> us;
    int n_ = 0;
    vector<int> result;
};

int main() {
  
    
  return 0; 
}
