#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> trips;
	if (nums.size() < 3)
		return trips;
	sort(nums.begin(), nums.end());
	bool isUsed[999999] = {0};
	int min = abs(nums[0]);
	for (int i = 0; i < (int)nums.size(); i++)
	{
		for (int j = i + 1; j < (int)nums.size(); j++)
		{
			if (isUsed[nums[i] + min] && isUsed[nums[j] + min])
				continue;
			for (int k = j + 1; k < (int)nums.size(); k++)
			{
				if (nums[k] == nums[k - 1] && isUsed[nums[k - 1] + min])
					continue;
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					vector<int> newTri;
					newTri.push_back(nums[i]);
					isUsed[nums[i] + min] = 1;
					newTri.push_back(nums[j]);
					isUsed[nums[j] + min] = 1;
					newTri.push_back(nums[k]);
					isUsed[nums[k] + min] = 1;
					trips.push_back(newTri);
				}
			}
		}
	}
	return trips;
}

int main()
{
	vector<int> z = {0, 0, 0, 0};
	vector<vector<int>> x = threeSum(z);
	return 0;
}