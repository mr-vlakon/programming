class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        unordered_map<int, size_t> um;
        for (int i = 0; i != rounds.size() - 1; ++i) {
            if (i > 0 && rounds[i - 1] == rounds[i]) {
                ++rounds[i];
            }
            while(rounds[i] != rounds[i + 1]) {
                ++um[rounds[i]];
                ++rounds[i];       
                if (rounds[i] == rounds[i + 1])
                    break;
                if (rounds[i] > n) {
                    rounds[i] = 1;
                }
            }
            ++um[rounds[i]];
        }
        int max = 0;
        for (const auto &e: um) {
            if (e.second > max)
                max = e.second;
        }
        vector<int> result;
        for (const auto &e: um) {
            if (e.second == max)
                result.push_back(e.first);
        }
        sort(result.begin(), result.end());
        return result;  
    }
};

int main() {
  
  
  return 0;  
}
