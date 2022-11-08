class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> um;
        for (const auto &e: tasks) {
            ++um[e];
        }
        int cnt = 0;
        for (auto &e: um) {
            while (e.second != 0) {
                if (e.second % 2 == 0 && e.second % 3 != 0) {
                    cnt += 1;
                    e.second -= 2;
                } else if (e.second % 3 == 0) {
                    cnt += 1;
                    e.second -= 3;
                } else {
                    cnt += 1;
                    e.second -= 3;
                }
                if (e.second < 0) {
                    return -1;
                }
                
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
