class Solution {
public:
    void binary(const vector<int> &nums, int &left, int &right) {
        if (left > right) {
            return;
        }
        tmp = 0;
        mid = (left + right) / 2;
        for (int i = 0; i != nums.size(); ++i) {
            tmp += nums[i] / (mid + 1);
            if ((nums[i] % (mid + 1)) != 0) {
                tmp++;
            }
        }
        if (tmp > N) {
            answer = max(answer, mid + 1);
            left = mid + 1;
            binary(nums, left, right); 
        } else {
            right = mid - 1;
            binary(nums, left, right);
        }
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        N = n;
        int maxV = *max_element(quantities.cbegin(), quantities.cend()) - 1;
        int left = 0;
        binary(quantities, left, maxV);
        return answer + 1;
    }
private:
    int N = 0;
    int mid = 0;
    int tmp = 0;
    int answer = 0;
};

int main() {
  
  
  
  return 0;  
}
