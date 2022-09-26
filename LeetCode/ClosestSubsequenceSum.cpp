class Solution {
public:
    void generateSubsequences(const vector<int> &arr, vector<int> &subarr, int index, int n, int status) {
        if (index == n) {
            if (status == 0)
                sumsFirst.push_back(accumulate(subarr.cbegin(), subarr.cend(), 0));
            else
                sumsSecond.push_back(accumulate(subarr.cbegin(), subarr.cend(), 0));
            return;
        }
        else {
            subarr.push_back(arr[index]);
            generateSubsequences(arr, subarr, index + 1, n, status);
            subarr.pop_back();
            generateSubsequences(arr, subarr, index + 1, n, status);
        }
    }
    
    int binarySrch(const int &val, const vector<int> & v) {
        if(val < v[0]) {
            return v[0];
        }
        
        if(val > v[v.size() - 1]) {
            return v[v.size() - 1];
        }

        int lo = 0;
        int hi = v.size() - 1;

        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            if (val < v[mid]) {
                hi = mid - 1;
            } else if (val > v[mid]) {
                lo = mid + 1;
            } else {
                return v[mid];
            }
        }
        return (v[lo] - val) < (val - v[hi]) ? v[lo] : v[hi];
    }
    
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int min = 2147483647;
        int sizeFirst = nums.size() / 2;
        vector<int> v;
        vector<int> first(nums.cbegin(), nums.cbegin() + sizeFirst);
        vector<int> second(nums.cbegin() + sizeFirst, nums.cend());
        generateSubsequences(first, v, 0, first.size(), 0);
        v.resize(0);
        generateSubsequences(second, v, 0, second.size(), 1);
        sort(sumsFirst.begin(), sumsFirst.end());
        sort(sumsSecond.begin(), sumsSecond.end());
        
        for (const auto &e : sumsSecond) {
            int search = goal - e;
            int y = binarySrch(search, sumsFirst);    
            if (abs(search - y) < min) {
                    min = abs(search - y);
            } 
        }
        return min;
    }
private:
    vector<int> sumsFirst;
    vector<int> sumsSecond;
};

int main() {
  
  
  return 0;  
}
