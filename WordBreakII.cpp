class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, dict);
    }

    vector<string> helper(string s, unordered_set<string>& dict) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};

        vector<string> res;
        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> sublist = helper(s.substr(i), dict);
                for (string sub : sublist) {
                    res.push_back(word + (sub.empty() ? "" : " " + sub));
                }
            }
        }

        return memo[s] = res;
    }
};
