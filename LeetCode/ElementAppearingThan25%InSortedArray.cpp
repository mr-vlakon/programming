class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int freq = arr.size() / 4;
        map<int, size_t> mp;
        for (const auto &e: arr) {
            ++mp[e];
        }
        for (const auto &e: mp) {
            if (e.second > freq)
                return e.first;
        }
        return 0;
    }
};

int main() {
 
  
  return 0;
}
