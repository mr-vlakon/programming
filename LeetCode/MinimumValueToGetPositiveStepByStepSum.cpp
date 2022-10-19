class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int x = 0;
        int min = 10000000;
        for (const auto &e: nums) {
            x += e;
            if (x < min && x < 0) {
                min = x;
            }
        }
        return (min == 10000000) ? 1 : (abs(min) + 1);
    }
};

int main() {
  
  
  
  return 0;  
}
