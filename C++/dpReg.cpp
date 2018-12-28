#include<string>
#include<vector>
using namespace std;

bool myReg(string s, string p)
{
	int m = s.length(), n = p.length(); 
	vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= m; i++) // 遍历s
		for (int j = 1; j <= n; j++)// 遍历p
		// 问s的前i-1个和p的前j-1个是否能匹配
			if (p[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] // *匹配到0个
				|| (i > 0 // *匹配到至少一个（则s的前i-2个必然要能匹配）
				&& (s[i - 1] == p[j - 2] || p[j - 2] == '.') // s的第i-1个于p的j-2个（即*前面的那一个）匹配 或 *前面的是.
				&& dp[i - 1][j]); // 并且 s的前i-2个与p的前j-1个匹配
			else dp[i][j] = i > 0 
			&& dp[i - 1][j - 1] // 前面的都匹配
			&& (s[i - 1] == p[j - 1] || p[j - 1] == '.'); // 这两个一样
	return dp[m][n];
}

int main()
{
	bool a = myReg("aaa", "a*a");
	return 0;
}
