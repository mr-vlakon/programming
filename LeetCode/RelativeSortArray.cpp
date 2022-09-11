class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        for (const auto &p: arr2) {
            auto cnt = count(arr1.begin(), arr1.end(), p);
            while (cnt) {
                result.push_back(p);
                --cnt;
            }
        }

        vector<int> tmp;
        for (const auto &e: arr1) {            
            auto cnt = count(arr2.begin(), arr2.end(), e);
            if (cnt == 0)
                tmp.push_back(e);

        }
        sort(tmp.begin(), tmp.end());
        for (const auto &e: tmp) {
            result.push_back(e);
        }
        
        return result;
    }
};

int main() {



  return 0;
}
