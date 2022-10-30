class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        int sum = 0;
        for (const auto &e: nums) {
            if (e % 2 == 0 && e % 3 == 0) {
                sum += e;
                ++cnt;
            }
        }
        if (cnt == 0) return 0;
        return sum / cnt;
    }
};

int main() {
  
  
  return 0;  
}
