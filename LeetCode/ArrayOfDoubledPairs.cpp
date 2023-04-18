class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> um;
        for (const auto &e: arr) {
            ++um[e];
        }
        unordered_map<int, int>::iterator it1;
        unordered_map<int, int>::iterator it2;
        for (const auto &e: arr) {
            it1 = um.find(e * 2);
            it2 = um.find(e);
            if (it1 != um.cend() && it2 != um.cend()) {
                um[e * 2]--;
                um[e]--;
                if (um[e] <= 0) {
                    um.erase(e);
                }
                if (e != 0 && um[e * 2] <= 0) {
                    um.erase(e * 2);
                }
                if (um.size() == 0) return true;
            }
        }
        return false;
    }
};

int main() {
  
  
  
  return 0;  
}
