class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int answer = 0;
        int start = 0;
        int end = 0;
        int sum = 0;
        int temp1 = 0;
        int temp2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i != arr.size() - 2; ++i) {
            start = i + 1;
            end = arr.size() - 1;
            while (start < end) {
                sum = arr[start] + arr[i] + arr[end] - target;
                if (sum == 0) {
                    temp1 = arr[start];
                    cnt1 = 0;
                    while (start < arr.size() && arr[start] == temp1) {
                        ++cnt1;
                        ++start;
                    }
                    temp2 = arr[end];
                    if (temp1 != temp2) {
                        cnt2 = 0;
                        while (end >= 0 && arr[end] == temp2) {
                            ++cnt2;
                            --end;
                        }
                    }
                    if (temp1 == temp2) {
                        answer += cnt1*(cnt1 - 1) / 2;
                    } else {
                        answer += min(cnt1, cnt2)*max(cnt1, cnt2);
                    }
                } else if (sum < 0) {
                    ++start;
                } else {
                    --end;
                }
            }
            answer %= 1000000007;
        }
        return answer % 1000000007;  
    }
};

int main() {
  
  
  
  
  return 0;  
}
