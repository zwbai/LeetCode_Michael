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
			if (base > INT_MAX)
				return sign == 1 ? INT_MAX : INT_MIN;
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
//