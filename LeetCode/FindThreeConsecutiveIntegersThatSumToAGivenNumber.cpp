class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long x = num / 3;
        long long tmp = num % 3;
        if (tmp != 0)
            return {};
        return {x - 1, x, x + 1};
    }
};

int main() {
  
  return 0; 
}
