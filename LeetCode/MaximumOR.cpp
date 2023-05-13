class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<int> v(64, 0);
        int maxK = 0;
        int kk = 0;
        for (auto &e: nums) {
            kk = 0;
            while ((1 << kk) <= e) {
                if (((1<<kk)&e) != 0)
                    v[kk]++;
                maxK = max(maxK, kk);
                ++kk;    
            }
        }
        long long maxCnt = 0;
        long long maxVal = 0;
        vector<int> newV(64, 0);        
        for (const auto &e: nums) {
            if ((1<<maxK) <= e) {
                long long ee = e;
                newV.assign(64, 0);
                kk = 0;
                while ((1 << kk) <= ee) {
                    if (((1<<kk)&ee) != 0)
                        newV[kk]++;
                    ++kk;
                }
                long long tmp = 0;
                for (int i = 0; i != v.size(); ++i) {
                    v[i] -= newV[i];
                }
                kk = 0;                
                for (int i = 0; i != newV.size() - k ; ++i) {
                    if (v[i + k] == 0 && newV[i] != 0) {
                        tmp += pow(2, i + k);
                    } else if (v[i + k] == 1) {
                        tmp += pow(2, i + k);
                    }
                }
                if (tmp >= maxCnt) {
                    if (maxCnt != tmp) {
                        maxCnt = tmp;
                        maxVal = e;
                    } else if (maxCnt == tmp && e > maxVal) {
                        maxVal = e;
                    }
                }
                for (int i = 0; i != v.size(); ++i) {
                    v[i] += newV[i];
                }
            }
        }
        long long answer = 0;
        bool st = false;
        long long t = 0;
        for (int i = 0; i != nums.size(); ++i) {            
            if (static_cast<long long>(nums[i]) == maxVal && !st) {
                st = true;
                t = nums[i];
                t <<= k;
            } else {
                t = nums[i];
            }
            answer |= t;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
