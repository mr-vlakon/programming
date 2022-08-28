class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(nums.cbegin(), nums.cend());
        copy(nums.begin(), nums.end(), back_inserter(result));
        return result;
    }
};

int main() {

  return 0; 
}
