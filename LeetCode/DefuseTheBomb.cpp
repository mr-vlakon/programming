class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> v;
        for (int i = 0; i != code.size(); ++i) {
            int j = i + 1;
            int t = j + k;
            int x = 0;
            if (k > 0) {
                while (j != t) {
                    x += code[j % code.size()];
                    ++j;
                }
            } else if (k < 0) {
                int j = i - 1;
                int q = 0;
                if (j < 0) {
                    j = code.size() - 1;
                }
                while (q != abs(k)) {
                    x += code[j % code.size()];
                    --j;
                    ++q;
                    if (j < 0) {
                        j = code.size() - 1;
                    }
                }
                
            } else {
                return vector<int>(code.size(), 0);
            }
            v.push_back(x);
        }
        return v;
    }
};

int main() {
  
  
  return 0;  
}
