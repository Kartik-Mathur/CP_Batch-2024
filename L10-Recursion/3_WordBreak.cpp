class Solution {
public:
	unordered_map<string, bool> dict;

	bool solve(string &s, int i) {

		if (i == s.size()) return true;

		for (int j = i; j < s.size(); ++j)
		{
			string x = s.substr(i, j - i + 1);
			if (dict[x]) {
				bool ans = solve(s, j + 1);
				if (ans) return true;
			}
		}

		return false;
	}


	bool wordBreak(string &s, vector<string>& wordDict) {

		for (auto w : wordDict) dict[w] = true;
		return solve(s, 0);
	}
};