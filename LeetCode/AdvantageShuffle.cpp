class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> v1;
        for (int i = 0; i != nums1.size(); ++i) {
            v1.push_back({nums1[i], i});
        }
        vector<pair<int, int>> v2;
        for (int i = 0; i != nums2.size(); ++i) {
            v2.push_back({nums2[i], i});
        }
        sort(v1.begin(), v1.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        sort(v2.begin(), v2.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        int start1 = 0;
        int start2 = 0;
        vector<int> answer(nums1.size());
        vector<bool> vis(nums2.size(), 0);
        stack<int> st;
        while (start1 != nums1.size() && start2 != nums2.size()) {
            if (v1[start1].first > v2[start2].first) {
                answer[v2[start2].second] = nums1[v1[start1].second];
                ++start1;
                vis[v2[start2].second] = true;
                ++start2;
            } else {
                st.push(v1[start1].first);
                ++start1;
            }
        }
        for (int i = 0; i != vis.size(); ++i) {
            if (vis[i] == false) {
                answer[i] = st.top();
                st.pop();
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
