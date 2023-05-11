class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        int t = 0;
        for (const auto &e: arr) {
            t = e % k;
            if(t < 0) {
                t += k;
            }
            ++um[t];
        }
        for (auto &e: um) {
            if (e.first == 0) { 
                continue;
            }
            if ((e.first * 2) == k) {
                if ((e.second % 2) != 0) return false;
            }
            if (e.second != um[k - e.first]) return false;
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
