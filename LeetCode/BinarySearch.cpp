class Solution {
public:
    vector<int>::iterator binarySearch(vector<int>::iterator first, vector<int>::iterator last, const int& value) {
        first = std::lower_bound(first, last, value);
        return (!(first == last) && !(value < *first)) ? first : last;
    }
    int search(vector<int>& nums, int target) {
        auto it = binarySearch(nums.begin(), nums.end(), target);
        return it == nums.cend() ? -1 : (it - nums.cbegin());   
    }
};

int main() {
  
  return 0;  
}
