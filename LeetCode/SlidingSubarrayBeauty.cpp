class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> v(50, 0);
        int cntNeg = 0;
        for (int i = 0; i != k; ++i) {
            if (nums[i] < 0) {
                ++cntNeg;
                v[abs(nums[i]) - 1]++;
            }
        }
        vector<int> answer;
        int cnt = 0;
        int find = 0;
        if (cntNeg >= x) {
            for (int i = v.size() - 1; i >= 0; --i) {
                if (cnt < x) {
                    cnt += v[i];
                    find = -(i + 1);
                } else {
                    break;
                }
            }
        }
        if (cnt < x) {
            answer.push_back(0);
        } else {
            answer.push_back(find);
        }
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            cnt = 0;            
            find = 0;
            if (nums[i - 1] < 0) {
                --cntNeg;
                v[abs(nums[i - 1]) - 1]--;
            }
            if (nums[i + k - 1] < 0) {
                ++cntNeg;
                v[abs(nums[i + k - 1]) - 1]++;
            }
            if (cntNeg >= x) {
                for (int i = (v.size() - 1); i >= 0; --i) {
                    if (cnt < x) {
                        cnt += v[i];
                        find = -(i + 1);
                    } else {
                        break;
                    }
                }
            }
            if (cnt < x) {
                answer.push_back(0);
            } else
                answer.push_back(find);
        }    
        return answer;
    }
};
/*
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multiset<int> ms;
        //cout << *(next(ms.begin(), 2)) << endl;
        for (int i = 0; i != k; ++i) {
            if (nums[i] < 0) {
                ms.insert(nums[i]);
            }
        }
        vector<int> answer;
        if (ms.size() >= x) {
            answer.push_back(*next(ms.begin(), x - 1));
        } else {
            answer.push_back(0);
        }
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            auto it = ms.find(nums[i - 1]);
            if (it != ms.cend())
                ms.erase(it);
            if (nums[i + k - 1] < 0) {
                ms.insert(nums[i + k - 1]);
            }
            if (ms.size() >= x) {
                answer.push_back(*next(ms.begin(), x - 1));
            } else {
                answer.push_back(0);
            }
        }       
        return answer;
    }
};
*/
/*
Other solution

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> v(50, 0);
        for (int i = 0; i != k; ++i) {
            if (nums[i] < 0) {
                v[abs(nums[i]) - 1]++;
            }
        }
        vector<int> answer;
        int cnt = 0;
        int find = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            if (cnt < x) {
                cnt += v[i];
                find = -(i + 1);
            } else {
                break;
            }
        }
        if (cnt < x) {
            answer.push_back(0);
        } else {
            answer.push_back(find);
        }
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            cnt = 0;            
            find = 0;
            if (nums[i - 1] < 0) {
                v[abs(nums[i - 1]) - 1]--;
            }
            if (nums[i + k - 1] < 0) {
                v[abs(nums[i + k - 1]) - 1]++;
            }
            for (int i = (v.size() - 1); i >= 0; --i) {
                if (cnt < x) {
                    cnt += v[i];
                    find = -(i + 1);
                } else {
                    break;
                }
            }
            if (cnt < x) {
                answer.push_back(0);
            } else
                answer.push_back(find);
        }    
        return answer;
    }
};

*/

int main() {
  
  
  
  return 0;  
}
