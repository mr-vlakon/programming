class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> um(k, 0);
        int t = 0;
        for (const auto &e: arr) {
            t = e % k;
            if(t < 0) {
                t += k;
            }
            ++um[t];
        }
        for (int i = 0; i != um.size(); ++i) {
            if (um[i] == 0) continue;
            if (i == 0) { 
                continue;
            }
            if ((i * 2) == k) {
                if ((um[i] % 2) != 0) return false;
            }
            if (um[i] != um[k - i]) return false;
        }
        return true;
    }
};
/*
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
*/
int main() {
  
  
  return 0;  
}
