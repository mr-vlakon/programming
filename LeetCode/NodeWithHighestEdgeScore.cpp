class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int, long long> um;
        int i = 0;
        long long maxV = 0;      
        for (const auto &e: edges) {
            um[e] += i;
            maxV = max(maxV, um[e]);
            ++i;
        }
        int minInd = 1000000;
        for (const auto &e: um) {
            if (e.second == maxV) {
                minInd = min(minInd, e.first);
            }
        }
        return minInd;
    }
};

int main() {
  
  
  return 0;  
}
