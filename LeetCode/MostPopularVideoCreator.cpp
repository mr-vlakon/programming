class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> popul;
        unordered_map<string, vector<pair<string, int> > >qwerty;
        
        for (decltype(creators.size()) i = 0; i != creators.size(); ++i) {
            popul[creators[i]] += views[i];
            qwerty[creators[i]].push_back({ids[i], views[i]});
        }
                      
        vector<string> persons;
        long long max = 0;
        for (const auto &e: popul) {
            if (e.second > max) {
                max = e.second;
            }
        }
        
        for (const auto &e: popul) {
            if (e.second == max) {
                persons.push_back(e.first);
            }
        }
        vector<vector<string>> answer;
        
        unordered_map<string, vector<pair<string, int>> > tmp;
        
        for (const auto &e: persons) {
            auto it = qwerty.find(e);
            tmp[e] = it->second;
        }
        
        for (auto &e: tmp) {
            sort(e.second.begin(), e.second.end(), [=](const pair<string, int> &lhs, const pair<string, int> &rhs) {
                return lhs.second > rhs.second;
            });
        }
                
        for (const auto &e: tmp) {
            int max = e.second[0].second;
            vector<string> temp;
            for (const auto &p: e.second) {
                if (p.second == max) {
                    temp.push_back(p.first);
                } else {
                    break;
                }
            }
            answer.push_back({e.first, *min_element(temp.cbegin(), temp.cend())});    
        }
    
        return answer;    
    }
};

int main() {
  
  
  
  return 0;  
}
