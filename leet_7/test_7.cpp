/*
LeetCode No.7 Reverse Integer
Description:
	Given a 32-bit signed integer, reverse digits of an integer.
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
	int reverse(int x) {
		long long res = 0;
		while (x) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (res<INT32_MIN || res>INT32_MAX) ? 0 : res;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		int ret = Solution().reverse(x);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}