class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int index = 0;
        for (decltype(arr.size()) i = 0; i != arr.size(); ++i) {
            auto it1 = find_if(arr.cbegin(), arr.cbegin() + i, [=](const int &x) {
               return arr[i] == 2 * x; 
            });
            auto it2 = find_if(arr.cbegin() + i + 1, arr.cend(), [=](const int &x) {
               return arr[i] == 2 * x; 
            });            
            if ((it1 != arr.cbegin() + i) || (it2 != arr.cend()))
                return true;
            ++index;
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
