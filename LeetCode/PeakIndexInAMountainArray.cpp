class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto it = max_element(arr.cbegin(), arr.cend());
        return it - arr.cbegin();
    }
};

int main() {
  
  return 0;  
}
