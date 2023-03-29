class Solution {
public:
    void binaryF(const string &nums, const int &flip, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        tmp = 100000;
        tmp = min(tmp, prefix1[mid]);
        for (int i = 1; i <= nums.size() - mid + 1; ++i) {
            tmp = min(tmp, prefix1[mid + i - 1] - prefix1[i - 1]);
        }
        if (tmp <= flip) {
            answer = max(answer, mid);
            left = mid + 1;
            binaryF(nums, flip, left, right);
        } else {
            right = mid - 1;
            binaryF(nums, flip, left, right);
        }
    }
    void binaryT(const string &nums, const int &flip, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        tmp = 100000;
        tmp = min(tmp, prefix[mid]);
        for (int i = 1; i <= nums.size() - mid + 1; ++i) {
            tmp = min(tmp, prefix[mid + i - 1] - prefix[i - 1]);
        }
        if (tmp <= flip) {
            answer = max(answer, mid);
            left = mid + 1;
            binaryT(nums, flip, left, right);
        } else {
            right = mid - 1;
            binaryT(nums, flip, left, right);
        }
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int pref = 0;
        prefix.push_back(0);
        int pref1 = 0;
        prefix1.push_back(0);
        for (int i = 0; i != answerKey.size(); ++i) {
            if (answerKey[i] == 'T') {
                pref++;
            } else {
                pref1++;
            }
            prefix1.push_back(pref1);
            prefix.push_back(pref);
        }
        left = 0;
        right = answerKey.size();     
        binaryT(answerKey, k, left, right);
        left = 0;
        right = answerKey.size();
        binaryF(answerKey, k, left, right);
        return answer;
    }
private:
    int tmp = 0;
    vector<int> prefix1;
    vector<int> prefix;
    int answer = 0;
    int left = 0;
    int right = 0;
    int mid = 0;
};

int main() {
  
  
  
  return 0;  
}
