#include<iostream>
#include<string>
#include<regex>
#include<algorithm>
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

	int main()
{
	vector<int> a(3, 1);
	int xxx = divide(100, 25);
	cout << a[2] << endl;
	bool b = regg("aab", "c*a*b");
	return 0;
}
