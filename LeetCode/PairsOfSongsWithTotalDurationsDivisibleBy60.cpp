class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(61);
        for (const auto &e: time) {
            v[e % 60]++;
        }
        long long score = 0;
        for (int i = 0; i <= v.size()/2; ++i) {
            if (i != v.size() - i - 1 && i != 0) {
                score += static_cast<long long>(v[i]) * static_cast<long long>(v[v.size() - i - 1]);
            } else {
                score += static_cast<long long>(v[i]) *static_cast<long long>(v[i] - 1) / 2;
            }
        }
        return score;
    }
};

int main() {
  
  
  
  return 0;  
}
