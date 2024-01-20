class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> findA;
        vector<int> findB;
        int position = 0;
        if (a.size() > s.size())
        {
            return {};
        }
        if (b.size() > s.size())
        {
            return {};
        }
        for (int i = 0; i != s.size();)
        {
            auto pos = s.find(a, position);
            if (pos != string::npos)
            {
                findA.push_back(pos);
            }
            else
            {
                break;
            }
            position = pos + 1;
        }

        position = 0;
        for (int i = 0; i != s.size();)
        {
            auto pos = s.find(b, position);
            if (pos != string::npos)
            {
                findB.push_back(pos);
            }
            else
            {
                break;
            }
            position = pos + 1;
        }
        if (findB.size() == 0) return {};
        
        vector<int> answer;
        
        for (int i = 0; i != findA.size(); ++i)
        {
            auto it = upper_bound(findB.cbegin(), findB.cend(), findA[i]);
            if (it == findB.cend())
            {
                if (abs(findB.back() - findA[i]) <= k)
                {
                    answer.push_back(findA[i]);
                }
            }
            else
            {
                if ((it != findB.cend()) && (abs(*it - findA[i]) <= k))
                {
                    answer.push_back(findA[i]);
                }
                else
                {
                    if (it != findB.cend())
                    {
                        if (it != findB.cbegin())
                        {
                            --it;
                            if (abs(*it - findA[i]) <= k)
                            {
                                answer.push_back(findA[i]);
                            } 
                            else
                            {
                                ++it;
                                ++it;
                                if (it == findB.cend()) continue;
                                if (abs(*it - findA[i]) <= k)
                                {
                                    answer.push_back(findA[i]);
                                }                             
                            }
                        } 
                        else
                        {
                            ++it;
                            if (it == findB.cend()) continue;
                            if (abs(*it - findA[i]) <= k)
                            {
                                answer.push_back(findA[i]);
                            }

                        }
                    }
                }           
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}
