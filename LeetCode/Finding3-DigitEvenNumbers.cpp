class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> v;
        int i = 100;
        unordered_map<int, int> um;
        for (const auto &e: digits) {
            ++um[e];
        }
        while (i < 1000) {
            unordered_map<int, int> tmp;
            int x = i;
            while(x) {
                tmp[x % 10]++;
                x /= 10;
            }
            bool status = true;
            for (const auto &e: tmp) {
                auto it = um.find(e.first);
                if (it == um.cend()) {
                    status = false;
                    break;
                }
                if (it->second < e.second) {
                    status = false;
                    break;
                }
            }
            if (status) {
                v.push_back(i);
            }
            i += 2;
        }
        return v;
    }
};

int main() {
  
  
  return 0;  
}
