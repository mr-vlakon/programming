class Solution {
public:
    string lastSubstring(string s) {
        char max = *max_element(s.cbegin(), s.cend());
        auto start = find(s.cbegin(), s.cend(), max);
        auto end = s.cend();
        --end;
        while (start < end) {
            if (*end == max) {
                break;
            }
            --end;
        }
        auto endStr = s.cend();
        while (start < endStr) {
            auto start_ = start;
            auto end_ = end;
            int counter1 = 0;
            while (start_ != endStr) {
                if (*start_ == max) {
                    ++counter1;
                } else {
                    break;
                }
                ++start_;
            }
            int counter2 = 0;
            bool status = false;
            while (end_ >= s.cbegin()) {
                if (*end_ == max) {
                    ++counter2;
                } else {
                    break;
                }
                if (end_ == s.cbegin()) {
                    status = true;
                    break;
                }
                --end_;
            }
            if (counter1 > counter2) {
                end = end_;
                endStr = end + 1;
                if (*endStr == max) {
                    ++endStr;
                }
                while (end > start) {
                    if (*end == max) {
                        break;
                    }
                    --end;
                }
                continue;
            } else if (counter1 < counter2) {
                start = find(start_, s.cend(), max);
                continue;
            } else if (counter1 == counter2) {
                if (!status) {
                    ++end_;
                }
                start_ = start;
                auto remStart = start;
                auto remEnd = end_;
                start_ = start + counter1;
                if ((end_ + counter2) >= endStr) {
                    return {start, s.cend()};
                }
                end_ = end_ + counter2;
                while (end_ <= endStr) {
                    if (end_ == endStr) {
                        end_ = remEnd;
                        --end_;
                        endStr = end_ + 1;
                        while (start < end_) {
                            if (*end_ == max) {
                                break;
                            }
                            --end_;
                        }
                        end = end_;
                        break;                        
                    }
                    if (*start_ > *end_) {
                        end_ = remEnd;
                        --end_;
                        endStr = end_ + 1;
                        while (start < end_) {
                            if (*end_ == max) {
                                break;
                            }
                            --end_;
                        }
                        end = end_;
                        break;
                    } else if (*start_ < *end_) {
                        start = find(start_, s.cend(), max);
                        break;
                    }
                    ++start_;
                    ++end_;
                }
            }
        }
        return {start, s.cend()};
    }
};

int main() {
  
  
  
  return 0;  
}
