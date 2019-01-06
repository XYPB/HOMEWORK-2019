#include<iostream>
#include<string>
#include<regex>
#include<algorithm>
#include<stack>
using namespace std;

struct PatternUnit
{
	char ch;
	bool isMul;
};

bool reg(const vector<PatternUnit> pu, const string s, int d, int sp)
{
	while (true)
	{
		if (d == (int)pu.size())
		{
			if (sp != (int)s.size())
				return false;
			else
				return true;
		}
		if (!pu[d].isMul)
		{
			if (pu[d].ch == '.')
			{
				sp++;
				d++;
				continue;
			}
			else if (pu[d].ch == s[sp])
			{
				sp++;
				d++;
				continue;
			}
			else
				return false;
		}
		else 
		{
			int recD = 0;
			if (pu[d].ch == '.')
				recD = (int)s.size() - sp;
			else
			{
				int temp_sp = sp;
				while (pu[d].ch == s[temp_sp])
				{
					recD++;
					temp_sp++;
				}
			}
			for (int i = 0; i <= recD; i++)
			{
				if (reg(pu, s, d + 1, sp + i))
					return true;
			}
			return false;
		}
	}
}

bool regg(string s, string p)
{
	if (s.size() == 0)
	{
		if (p.size() == 0)
			return true;
	}
	vector<PatternUnit> pu;
	for (int i = 0; i < (int)p.size(); i++)
	{
		PatternUnit newpu;
		newpu.ch = p[i];
		newpu.isMul = 0;
		if (p[i + 1] == '*')
		{
			newpu.isMul = 1;
			i++;
		}
		pu.push_back(newpu);
	}
	int pup = 0, sp = 0;
	return reg(pu, s, pup, sp);
}

	/*要做什么
对这个vector深搜
怎么深搜
于是参数有
const pu，const s，pud是vec的指针，sp是s的指针
函数类型为 bool；
循环
如果！isMul
说明这个时候只用读一个，匹配一个，continue
如果isMul
说明这个时候可以读+匹配0-第一个不是的个
开始深搜如果只匹配0个再继续可以吗？如果1个再继续？。。。
递归出口处，如果return true了，直接return true；
如果 return false就继续循环；
如果一个*循环都完了还是不行就return false
如果发现走到了pu的底部开始判断
这个时候s的指针到底了吗
到了说明匹配成功，return true
每到说明使不得就return false*/

int divide(int dividend, int divisor) 
{
	if(divisor == 0 || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
	int sign = ((dividend<0)^(divisor<0))?-1:1;
	long long res = 0;
	
	long long div = labs(dividend);
	long long dis = labs(divisor);
	
	while(div >= dis){
		long long mult = 1;
		long long temp = dis;
		
		while(div >= (temp << 1)){
			temp <<= 1;
			mult <<= 1;
		}
		
		div = div - temp;
		res += mult;
	}
	
	return res*sign;
}

void nextPermutation(vector<int>& nums) 
{
	int l = nums.size() - 1;
	if (nums.size() <= 1)
		return;
	for (; l > 0; l--)
		if (nums[l] > nums[l - 1])
			break;
	if (l == 0)
	{
		sort(nums.begin(), nums.end());
		return;
	}
	int r = l--;
	while (r < (int)nums.size() 
	&& nums[l] < nums[r]) 
		r++;
	r--;
	swap(nums[l], nums[r]);
	sort(nums.begin() + l + 1, nums.end());
	return;
}

bool isVal(string s, int l, int r)
{
    stack<char> paras;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '(')
            paras.push('(');
        else if (s[i] == ')')
        {
			if (paras.empty())
				return false;
			else if (paras.top() == '(')
				paras.pop();
            else
                return false;
        }
    }
    if (paras.empty())
        return true;
    else
        return false;
}

int longestValidParentheses(string s) 
{
	int lvp = 0;
	stack<int> paras({0});
	for (int i = 1; i <= s.size(); i++)
	{
		if (s[i - 1] == '(')
			paras.push(i);
		else if (paras.size() > 1)
		{
			paras.pop();
			lvp = max(lvp, i - paras.top());
		}
		else if (paras.size() == 1)
		{
			paras.pop();
			paras.push(i);
		}
	}
	return lvp;
}

int longestValidParentheses(string s) 
{
	int lvp = 0;
	for (int l = 0; l < (int)s.size(); l++)
	{
		for (int r = (int)s.size() - 1; r > l; r--)
		{
			if (isVal(s, l, r))
				lvp = max(lvp, r - l + 1);
		}
	}
	return lvp;
}

int main()
{
	vector<int> nums = {1, 2, 4, 3, 5, 7, 6};
	int num = longestValidParentheses(")()())");
	nextPermutation(nums);
	vector<int> a(3, 1);
	int xxx = divide(100, 25);
	cout << a[2] << endl;
	bool b = regg("aab", "c*a*b");
	return 0;
}
