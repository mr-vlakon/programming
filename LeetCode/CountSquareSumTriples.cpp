class Solution {
public:
    int countTriples(int n) {
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        int answer = 0;
        for (int i = 0; i != v.size(); ++i) {
            for (int j = 0; j != v.size(); ++j) {
                if (i != j) {
                    double tmp = v[i] * v[i] + v[j] * v[j];
                    tmp = sqrt(tmp);
                    int x = tmp;
                    if ( tmp <= static_cast<double>(n) && (abs(tmp - x) < 0.00001)) {
                        ++answer;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
