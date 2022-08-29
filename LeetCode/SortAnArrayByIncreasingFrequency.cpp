class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> map;
        for (const auto &c: nums)
            map[c]++;
        vector<pair<int,int>> v(map.cbegin(), map.cend());   

        stable_sort(v.begin(), v.end(), [](const pair<char, int> &lhs, const pair<char, int> &rhs) {
           return lhs.first > rhs.first; 
        });
        stable_sort(v.begin(), v.end(), [](const pair<char, int> &lhs, const pair<char, int> &rhs) {
           return lhs.second < rhs.second; 
        });
        vector<int> v1;
        for(const auto &e: v) {
            int cnt = e.second;
            while (cnt--) {
                v1.push_back(e.first);
            }
        }
        return v1; 
    }
};

int main() {

 return 0; 
}
