/*
LeetCode No.3 Longest Substring Without Repeating Characters
Description:
	Implement atoi which converts a string to an integer.
	The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
	The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
	If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
	If no valid conversion could be performed, a zero value is returned.
Note:
	Only the space character ' ' is considered as whitespace character.
	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
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
	int myAtoi(string str) {
		int sign = 1, pt = 0;
		long long base = 0;
		while (str[pt] == ' ')
			pt++;
		if (str[pt] == '+' || str[pt] == '-')
			sign = 1 - 2 * (str[pt++] == '-');
		while (str[pt] >= '0' && str[pt] <= '9') {
			base = 10 * base + (str[pt++] - '0');
			if (base > INT32_MAX)
				return sign == 1 ? INT32_MAX : INT32_MIN;
		}
		return (int)(base * sign);
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
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
	while (getline(cin, line)) {
		string str = stringToString(line);

		int ret = Solution().myAtoi(str);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}