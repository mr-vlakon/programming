class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int answer = 0;
        int start = 0;
        int end = 0;
        long long sum = 0;
        int temp1 = 0;
        int temp2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        long long t = 0;
        int prev = 0;
        int tmp = 0;
        int tt = 0;
        unordered_map<int, int> um1;
        for (const auto &e: nums1) {
            um1[e]++;
        }
        for (const auto &e: um1) {
            start = 0;
            tt = 0;
            end = nums2.size() - 1;
            prev = INT_MAX;
            t = static_cast<long long>(e.first)*e.first;
            while (start < end) {
                if (prev == nums2[start]) {
                    answer += tmp;
                    tt += tmp;
                    ++start;
                    continue;
                }
                sum = t - static_cast<long long>(nums2[start])*nums2[end];
                if (sum == 0) {
                    temp1 = nums2[start];
                    cnt1 = 0;
                    while (start < nums2.size() && nums2[start] == temp1) {
                        ++cnt1;
                        ++start;
                    }
                    temp2 = nums2[end];
                    if (temp1 != temp2) {
                        cnt2 = 0;
                        while (end >= 0 && nums2[end] == temp2) {
                            ++cnt2;
                            --end;
                        }
                    }
                    if (temp1 == temp2) {
                        tmp = cnt1*(cnt1 - 1)/2;
                        tt += tmp;
                    } else {
                        tmp = cnt1*cnt2;
                        tt += tmp;
                    }
                } else if (sum < 0) {
                    tmp = 0;
                    --end;
                } else {
                    tmp = 0;
                    prev = nums2[start];
                    ++start;
                }        
            }
            answer += tt*e.second;
        }
        tt = 0;
        um1.clear();
        for (const auto &e: nums2) {
            um1[e]++;
        }
        for (const auto &e: um1) {
            tt = 0;
            start = 0;
            prev = INT_MAX;
            end = nums1.size() - 1;
            t = static_cast<long long>(e.first)*e.first;
            while (start < end) {
                if (prev == nums1[start]) {
                    answer += tmp;
                    tt += tmp;
                    ++start;
                    continue;
                }
                sum = t - static_cast<long long>(nums1[start])*nums1[end];
                if (sum == 0) {
                    temp1 = nums1[start];
                    cnt1 = 0;
                    while (start < nums1.size() && nums1[start] == temp1) {
                        ++cnt1;
                        ++start;
                    }
                    temp2 = nums1[end];
                    if (temp1 != temp2) {
                        cnt2 = 0;
                        while (end >= 0 && nums1[end] == temp2) {
                            ++cnt2;
                            --end;
                        }
                    }
                    if (temp1 == temp2) {
                        tmp = cnt1*(cnt1 - 1)/2;
                        tt += tmp;
                    } else {
                        tmp = cnt1*cnt2;
                        tt += tmp;
                    }
                } else if (sum < 0) {
                    tmp = 0;
                    --end;
                } else {
                    tmp = 0;
                    ++start;
                }
            }
            answer += tt*e.second;
        }
        return answer;        
    }
};
/*
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int answer = 0;
        int start = 0;
        int end = 0;
        long long sum = 0;
        int temp1 = 0;
        int temp2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        long long t = 0;
        int prev = 0;
        int tmp = 0;
        int tt = 0;
        int prev1 = INT_MAX;
        for (int i = 0; i != nums1.size(); ++i) {
            if (prev1 == nums1[i]) {
                answer += tt;
                continue;
            }
            start = 0;
            tt = 0;
            end = nums2.size() - 1;
            prev = INT_MAX;
            t = static_cast<long long>(nums1[i])*nums1[i];
            while (start < end) {
                if (prev == nums2[start]) {
                    answer += tmp;
                    tt += tmp;
                    ++start;
                    continue;
                }
                sum = t - static_cast<long long>(nums2[start])*nums2[end];
                if (sum == 0) {
                    temp1 = nums2[start];
                    cnt1 = 0;
                    while (start < nums2.size() && nums2[start] == temp1) {
                        ++cnt1;
                        ++start;
                    }
                    temp2 = nums2[end];
                    if (temp1 != temp2) {
                        cnt2 = 0;
                        while (end >= 0 && nums2[end] == temp2) {
                            ++cnt2;
                            --end;
                        }
                    }
                    if (temp1 == temp2) {
                        tmp = cnt1*(cnt1 - 1)/2;
                        answer += tmp;
                        tt += tmp;
                        
                    } else {
                        tmp = cnt1*cnt2;
                        answer += tmp;
                        tt += tmp;
                    }
                } else if (sum < 0) {
                    tmp = 0;
                    --end;
                } else {
                    tmp = 0;
                    prev = nums2[start];
                    ++start;
                }
                
            }
            prev1 = nums1[i];
        }

        prev1 = INT_MAX;
        tt = 0;
        for (int i = 0; i != nums2.size(); ++i) {
            if (prev1 == nums2[i]) {
                answer += tt;
                continue;
            }
            tt = 0;
            start = 0;
            prev = INT_MAX;
            end = nums1.size() - 1;
            t = static_cast<long long>(nums2[i])*nums2[i];
            while (start < end) {
                if (prev == nums1[start]) {
                    answer += tmp;
                    tt += tmp;
                    ++start;
                    continue;
                }
                sum = t - static_cast<long long>(nums1[start])*nums1[end];
                if (sum == 0) {
                    temp1 = nums1[start];
                    cnt1 = 0;
                    while (start < nums1.size() && nums1[start] == temp1) {
                        ++cnt1;
                        ++start;
                    }
                    temp2 = nums1[end];
                    if (temp1 != temp2) {
                        cnt2 = 0;
                        while (end >= 0 && nums1[end] == temp2) {
                            ++cnt2;
                            --end;
                        }
                    }
                    if (temp1 == temp2) {
                        tmp = cnt1*(cnt1 - 1)/2;
                        answer += tmp;
                        tt += tmp;
                    } else {
                        tmp = cnt1*cnt2;
                        answer += tmp;
                        tt += tmp;
                    }
                } else if (sum < 0) {
                    tmp = 0;
                    --end;
                } else {
                    tmp = 0;
                    ++start;
                }
            }
            prev1 = nums2[i];
        }
        return answer;        
    }
};
*/
int main() {
  
  
  
  
  return 0;  
}
