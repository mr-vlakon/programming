/*
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int answer = 0; 
        int pref = 0;
        unordered_map<int, int> cnt;
        unordered_map<int, int> sum;
        cnt[0] = 1;
        for (int i = 0; i != arr.size(); ++i) {
            pref ^= arr[i];
            answer += cnt[pref]*i - sum[pref];
            sum[pref] += i + 1;
            ++cnt[pref];
        }
        return answer;
  }
};
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int answer = 0; 
        int pref = 0;
        unordered_map<int, pair<int, int>> um;
        um[0].first = 1;
        for (int i = 0; i != arr.size(); ++i) {
            pref ^= arr[i];
            answer += um[pref].first*i - um[pref].second;
            um[pref].second += i + 1;
            ++um[pref].first;
        }
        return answer;
  }
};

int main() {
  
  
  
  return 0;  
}
