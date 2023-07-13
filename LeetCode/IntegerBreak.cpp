class Solution {
public:
    int integerBreak(int n) {
        vector<int> v(n, 1);
        v[0] = 1;
        v[1] = 1;
        int tmp = 0;
        for (int i = 0; i != n; ++i) {
            tmp = 0;
            for (int j = 0; j != i; ++j) {
                tmp = max((j + 1)*(i - j),max(tmp, v[j]*(i - j)));
            }
            v[i] = tmp;
        }
        return v.back();
    }
};

int main() {




  return 0;
}
