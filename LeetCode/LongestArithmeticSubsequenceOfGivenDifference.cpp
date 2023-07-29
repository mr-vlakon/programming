class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> um;
        um[arr[0]] = 1;
        int answer = 0;
        unordered_map<int, int>::iterator it;
        for (int i = 1; i != arr.size(); ++i) {
            it = um.find(arr[i] - difference);
            if (it != um.cend()) {
                um[arr[i]] = um[arr[i] - difference] + 1;
            } else {
                um[arr[i]] = 1;
            }
            answer = max(answer, um[arr[i]]);
        }
        return answer;
    }
};

int main() {




  return 0;
}
