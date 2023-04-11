class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (const auto &e: grid) {
            for (const auto &p: e) {
                v.push_back(p);
            }
        }
        sort(v.begin(), v.end());
        int mid = v.size() / 2;
        int answer = 0;
        int tmp = 0;
        for (const auto &e: v) {
            tmp = abs(e - v[mid]);
            if ((tmp % x) != 0) return -1;
            answer += tmp / x;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
