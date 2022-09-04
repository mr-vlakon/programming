class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> v;
        while(n) {
            int tmp = n % 3;
            v.push_back(tmp);
            n /= 3;
        }
        auto cnt = count(v.cbegin(), v.cend(), 2);
        if (cnt >= 1)
            return false;
        return true;
    }
};

int main() {
  
  
  return 0;  
}
