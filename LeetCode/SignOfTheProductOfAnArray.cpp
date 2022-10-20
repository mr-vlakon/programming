class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntMinus = 0;
        for (const auto &e: nums) {
            if (e == 0)
                return 0;
            e < 0 ? ++cntMinus : cntMinus;
        }        
        return cntMinus % 2 == 0 ? 1 : -1;
    }
};

int main() {
  
  
  return 0;  
}
