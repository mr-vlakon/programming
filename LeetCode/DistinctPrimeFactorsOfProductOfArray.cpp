class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> us;
        for (auto &e: nums) {
            unordered_map<int, int> um;
            if (e > 1) {
                for (int i = 2; (i * i) <= e; ++i) {
                    while ((e % i) == 0) {
                            if (um[i] == 0) {
                                us.insert(i);
                                um[i] = 1;
                            }
                            e = e / i;
                    }
                }
                if (e >= 2) {
                    us.insert(e);
                }
            }
        }  
        return us.size();
    }
};

int main() {
  
  
  
  return 0;  
}
