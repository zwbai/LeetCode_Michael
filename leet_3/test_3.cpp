/*
LeetCode No.3 Longest Substring Without Repeating Characters
Description:
	Given a string, find the length of the longest substring without repeating characters.
	Examples:
		Given "abcabcbb", the answer is "abc", which the length is 3.
		Given "bbbbb", the answer is "b", with the length of 1.
		Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
CodeBy: Michael_zwbai
SearchMore:https://github.com/zwbai/LeetCode_Michael
*/
#include <string>
#include <math.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);
		int maxLen = 0, start = -1;
		for (int i = 0; i != s.length(); i++) {
			if (dict[s[i]] > start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 0; i < input.length(); i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	cout << "input any string :" << endl;
	while (getline(cin, line)) {
		string s = stringToString(line);

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << "lengthOfLongestSubstring :" << out << endl;
		cout << "input any string or exit with Ctrl+C :" << endl;
	}
}