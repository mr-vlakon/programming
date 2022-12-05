class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0) return n == 1 ? 1 : -1;
        unordered_map<int, int> um;
        for (const auto &e: trust) {
            ++um[e[1]];
        }
        auto beg = um.cbegin();
        int answer = -1;
        for (const auto &e: um) {
            if (e.second == n - 1) {
                answer = e.first;
                break;
            }
        }
        for (const auto &e: trust) {
            if (e[0] == answer)
                return -1;
        }
        
        return answer; 
    }
};

int main() {
  
  

  return 0;
}
