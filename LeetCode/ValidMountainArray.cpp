class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        auto it = max_element(arr.cbegin(), arr.cend());
        if (it - arr.cbegin() == 0) {
            return false;
        }
        if (it == --arr.cend())
            return false;
        bool status1 = is_sorted(arr.cbegin(), it,[=](const int &lhs, const int &rhs) {
            return lhs <= rhs;
        });
        bool status2 = is_sorted(it, arr.cend(),[=](const int &lhs, const int &rhs) {
            return lhs >= rhs;
        });
        return status1 && status2;
    }
};

int main() {

  
  return 0;  
}
