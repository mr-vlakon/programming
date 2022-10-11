class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const auto &e: operations) {
            if (e == "--X" || e == "X--")
                --x;
            if (e == "++X" || e == "X++")
                ++x;
        }
        return x;
    }
};

int main() {
  
  
  return 0;  
}
