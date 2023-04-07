class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        int pos = end;
        int search = 1;
        int searchPos = 0;
        vector<int> answer;
        while (!is_sorted(arr.rbegin(), arr.rend())) {
            start = 0;
            end = pos;
            searchPos = 0;
            while (start <= end) {
                if (arr[start] == search) {
                    searchPos = start;
                    break;
                } else if (arr[end] == search) {
                    searchPos = end;
                    break;
                }
                ++start;
                --end;
            }
            answer.push_back(searchPos + 1);
            ++search;
            reverse(arr.begin(), arr.begin() + searchPos + 1);
            answer.push_back(pos + 1);
            reverse(arr.begin(), arr.begin() + pos + 1);
            --pos;
        }
        answer.push_back(arr.size());
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
