class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, long long> left;
        unordered_map<int, long long> right;
        unordered_map<int, long long> cnt;
        for (int i = 0; i != arr.size(); ++i) {
            right[arr[i]] += i;
            ++cnt[arr[i]];
        }
        vector<long long> result(arr.size(), 0);
        unordered_map<int, long long> cntL;
        for (int i = 0; i != arr.size(); ++i) {
            --cnt[arr[i]];
            right[arr[i]] -= i;
            result[i] = abs<long long>(left[arr[i]] - cntL[arr[i]]*i) + abs<long long>((cnt[arr[i]])*i - right[arr[i]]);
            left[arr[i]] += i;
            ++cntL[arr[i]];
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
