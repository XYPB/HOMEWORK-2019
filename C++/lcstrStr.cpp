#include<string>
#include<vector>
using namespace std;

int strStr(string haystack, string needle) 
{
	if(haystack.size()==0 && needle.size()==0) 
		return 0;
	if(haystack.size() < needle.size()) 
		return -1;
	vector<int> kmp(needle.size(), 0);
	int j = 0;
	for(int i=1; i<needle.size(); i++)
	{
		if(needle[i]==needle[j]) 
		{
			kmp[i] = ++j; 
			continue;
		}
		while(j>0 && needle[j]!=needle[i]) 
			j = kmp[j-1];
		if(needle[i]==needle[j]) 
			kmp[i] = ++j;
	}
	j = 0;
	for(int i=0; i<haystack.size(); i++)
	{
		if(j==needle.size()) 
			return i - needle.size();
		if(needle[j]!=haystack[i])
		{
			if(j>0) 
			{
				j = kmp[j-1]; 
				i--;
			}
		}
		else j++;
	}
	if(j==needle.size())
		return haystack.size()-needle.size();
	return -1;
}

int main()
{
	int x = strStr("aaaba", "ba");
	return 0;
}