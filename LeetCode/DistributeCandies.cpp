class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int ans = candyType.size() / 2;
        unordered_set<int> us(candyType.cbegin(), candyType.cend());
        return ans > us.size() ? us.size() : ans;
    }
};

int main() {
  
  
  return 0;  
}
