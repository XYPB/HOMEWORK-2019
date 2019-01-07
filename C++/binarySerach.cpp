#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
{
	int l = 0, r = nums.size() - 1;
	vector<int> none = {-1, -1};
	vector<int> ans;
	int pos = 0;
	if (nums.size() == 0)
		return none;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (r == l && target != nums[r])
			return none;
		if (target == nums[mid])
		{
			pos = mid;
			break;
		}
		else if (target < nums[mid])
			r = --mid;
		else
			l = ++mid;
		if (r < 0)
			r = 0;
	}
	l = r = pos;
	while (l >= 0 && l < nums.size() && nums[l] == target)
		--l;
	while (r >= 0 && r < nums.size() && nums[r] == target)
		++r;
	ans.push_back(l + 1);
	ans.push_back(r - 1);
	return ans;
}

int main()
{
	vector<int> y = {0,0,0,0,2,2,3,3,4,4,5,5,5,6,7,7,8,9,9,9,10};
	vector<int> x = searchRange(y, 10);
	return 0;
}