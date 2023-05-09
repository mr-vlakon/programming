class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (is_sorted(arr.rbegin(), arr.rend())) {
            return 1;
        }
        if (is_sorted(arr.begin(), arr.end())) {
            return arr.size();
        }
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int i = 0;
        int j = 0;
        int maxV = 0;
        int answer = 0;
        int cnt = 0;
        int prev = 0;
        while (j < arr.size()) {
            maxV = arr[j];
            while (i < sorted.size() && maxV != sorted[i]) {
                ++i;
            }
            while (j < i && j < arr.size() && i < arr.size()) {
                cnt = 0;
                prev = -1;
                ++j;
                while (j <= i) {
                    if (arr[j] == maxV) {
                        ++cnt;
                    }
                    prev = maxV;
                    maxV = max(maxV, arr[j]);
                    if (prev != maxV) {
                        cnt = 0;
                    } 
                    ++j;
                }
                --j;
                while (i < sorted.size() && maxV != sorted[i]) {
                    ++i;
                }
                i += cnt;
            }
            j = max(j + 1, i);
            ++answer;
        }
        return answer;    
    }
};
/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (is_sorted(arr.rbegin(), arr.rend())) {
            return 1;
        }
        if (is_sorted(arr.begin(), arr.end())) {
            return arr.size();
        }
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int i = 0;
        int j = 0;
        int maxV = 0;
        int answer = 0;
        int cnt = 0;
        int prev = 0;
        while (j < arr.size()) {
            maxV = arr[j];
            while (i < sorted.size() && maxV != sorted[i]) {
                ++i;
            }
            while (j < i && j < arr.size() && i < arr.size()) {
                cnt = (arr[j] != maxV) ? 1 : 0;
                prev = -1;
                while (j <= i) {
                    if (arr[j] == maxV) {
                        ++cnt;
                    }
                    prev = maxV;
                    maxV = max(maxV, arr[j]);
                    if (prev != maxV) {
                        cnt = 1;
                    } 
                    ++j;
                }
                --j;
                while (i < sorted.size() && maxV != sorted[i]) {
                    ++i;
                }
                i += cnt - 1;
            }
            ++j;
            j = max(j, i);
            ++answer;
        }
        return answer;    
    }
};
*/
/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (is_sorted(arr.rbegin(), arr.rend()))
            return 1;
        if (is_sorted(arr.begin(), arr.end())) {
            return arr.size();
        }
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int i = 0;
        int j = 0;
        int maxV = 0;
        int answer = 0;
        int cnt = 0;
        int prev = 0;
        while (j < arr.size()) {
            maxV = arr[j];
            while (i < sorted.size() && maxV != sorted[i]) {
                ++i;
            }
            while (j < i && j < arr.size() && i < arr.size()) {
                if (arr[j] != maxV) {
                    cnt = 1;
                } else {
                    cnt = 0;
                }
                prev = -1;
                while (j <= i) {
                    if (arr[j] == maxV) {
                        ++cnt;
                    }
                    prev = maxV;
                    maxV = max(maxV, arr[j]);
                    if (prev != maxV) {
                        cnt = 1;
                    } 
                    ++j;
                }
                --j;
                while (i < sorted.size() && maxV != sorted[i]) {
                    ++i;
                }
                i += cnt - 1;
            }
            ++j;
            j = max(j, i);
            ++answer;
        }
        return answer;    
    }
};
*/

int main() {
  
  
  
  return 0;  
}
