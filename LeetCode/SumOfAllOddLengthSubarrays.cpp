class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int answer = 0;
        for (decltype(arr.size()) i = 0; i != arr.size(); ++i) {
            int sum = 0;
            for (decltype(arr.size()) j = i; j != arr.size(); ++j) {
                sum += arr[j];
                if ((j - i) % 2 == 0) {
                    answer += sum;
                }
            }
        }
        return answer;
    }
};

int main() {
  
  

  return 0;
}
