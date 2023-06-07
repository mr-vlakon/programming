class Solution {
public:
    int beautySum(string s) {
        vector<int> v(26, 0);
        int answer = 0;
        int minV = 0;
        int maxV = 0;
        vector<int> tmp(26, 0);
        for (int i = 0; i != s.size(); ++i) {
            ++v[s[i] - 'a']; 
            tmp = v;
            for (int j = 0; j != i; ++j) {
                minV = INT_MAX;
                maxV = 0;
                for (const auto &e: tmp) {
                    if (e != 0) {
                        minV = min(minV, e);
                        maxV = max(maxV, e);
                    }
                }
                --tmp[s[j] - 'a'];
                answer += abs(maxV - minV);
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
