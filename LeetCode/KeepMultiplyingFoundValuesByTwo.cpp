class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while (true) {
            bool status = true;
            for (const auto &e: nums) {
                if (e == original) {
                    status = false;
                    original *= 2;
                }
            }
            if (status)
                break;
        }
        return original;
    }
};

int main() {
  
  
  
  return 0;  
}
