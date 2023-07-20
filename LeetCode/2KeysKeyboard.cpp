class Solution {
public:
    int minSteps(int n) {
        vector<int> v(n, 0);
        for (int i = 1; i != n; ++i) {
            for (int j = i / 2; j >= 0; --j) {
                if (((i + 1) % (j + 1)) == 0)
                {
                    v[i] = v[j] + (i + 1) / (j + 1);
                    break;
                }
            }
        }
        return v.back(); 
    }
};
/*
class Solution {
public:
    int minSteps(int n) {
        vector<int> v(n, 0);
        int tmp = 0;
        for (int i = 1; i != n; ++i) {
            tmp = INT_MAX;
            for (int j = 0; j != i; ++j) {
                if (((i + 1) % (j + 1)) == 0)
                {
                    tmp = min(tmp, v[j] + (i + 1) / (j + 1));
                }
            }
            v[i] = tmp;
        }
        return v.back(); 
    }
};
*/

int main() {


  return 0;
}
