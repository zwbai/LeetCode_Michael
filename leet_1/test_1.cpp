#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int num = nums.size();
		vector<int> sum;
		for (int i = 0; i < num; i++) {
			for (int j = i + 1; j < num; j++) {
				if (nums[i] + nums[j] == target) {
					sum.push_back(i);
					sum.push_back(j);
				}
			}
		}
		return sum;
	}
};

int main(){
	int a,b;
	a = 0;
	b = 0;
	while(cin >> a >> b){
		
	}
}
