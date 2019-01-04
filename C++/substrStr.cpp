#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// Solution with Recution
void fSS(const vector<string> ss, const vector<string> words, vector<int> &ans, int d, vector<bool> ex, int start)
{
	if (d > (int)ss.size())
		return;
	bool flag = true;
	for (int i = 0; i < (int)words.size(); i++)
		if (!ex[i])
		{
			flag = false;
			break;
		}
	if (flag)
	{
		ans.push_back((d - words.size()) * words[0].size() + start);
		return;
	}
	for (int i = 0; i < (int)words.size(); i++)
	{
		if (!ex[i] && ss[d] == words[i])
		{
			ex[i] = 1;
			fSS(ss, words, ans, d + 1, ex, start);
			break;
		}
	}
	return;
}

vector<int> findSubstring(string s, vector<string>& words) 
{
	vector<int> ans;
	if (s.size() == 0 && words.size() == 0)
	{
		ans.push_back(0);
		return ans;
	}
	else if (s.size() == 0 || words.size() == 0)
		return ans;
	vector<vector<string>> ss;
	for (int i = 0; i < (int)words[0].size(); i++)
	{
		vector<string> buffss;
		for (int j = i; j < (int)s.size(); j += words[0].size())
		{
			string buff;
			for (int k = 0; k < (int)words[0].size(); k++)
				buff.push_back(s[k + j]);
			buffss.push_back(buff);
		}
		ss.push_back(buffss);
	}
	vector<bool> ex;
	for (int i = 0; i < (int)words.size(); i++)
		ex.push_back(0);
	vector<int> p;
	for (int i = 0; i < (int)ss.size(); i++)
		for (int j = 0; j < (int)ss[i].size(); j++)
			fSS(ss[i], words, ans, j, ex, i);
	return ans;
}

// Solition with unordered_map(wihch is actually a hash dictionary)
vector<int> findSubstring(string S, vector<string> &L) 
{
	vector<int> ans;
	int n = S.size(), cnt = L.size();
	if (n <= 0 || cnt <= 0) return ans;
	
	// init word occurence
	unordered_map<string, int> dict;
	for (int i = 0; i < cnt; ++i) dict[L[i]]++;
	
	// travel all sub string combinations
	int wl = L[0].size();
	for (int i = 0; i < wl; ++i) {
		int left = i, count = 0;
		unordered_map<string, int> tdict;
		for (int j = i; j <= n - wl; j += wl) {
			string str = S.substr(j, wl);
			// a valid word, accumulate results
			if (dict.count(str)) {
				tdict[str]++;
				if (tdict[str] <= dict[str]) 
					count++;
				else {
					// a more word, advance the window left side possiablly
					while (tdict[str] > dict[str]) {
						string str1 = S.substr(left, wl);
						tdict[str1]--;
						if (tdict[str1] < dict[str1]) count--;
						left += wl;
					}
				}
				// come to a result
				if (count == cnt) {
					ans.push_back(left);
					// advance one word
					tdict[S.substr(left, wl)]--;
					count--;
					left += wl;
				}
			}
			// not a valid word, reset all vars
			else {
				tdict.clear();
				count = 0;
				left = j + wl;
			}
		}
	}
	
	return ans;
}

// Solution with hash-map
vector<int> findSubstring(string s, vector<string>& words) 
{
	vector<int> retVal;
	if (words.size()<1 || s.size()<1) 
		return retVal;
	// Hash all the words seperately then add them together to get a magic number
	std::hash<std::string> hash_fn;
	size_t magicNumber = 0;
	for (int i=0; i<words.size(); i++) 
		magicNumber += hash_fn(words[i]);
	int wordLength = words[0].size();
	// Concatenated substring will be a given length
	int minimumSize = words.size()*wordLength;
	// We do a sliding window calculation for each 'offset' a pattern might have
	// This is faster than re-hashing the entire window because we can just drop the least recently hashed value
	for (int startOffset=0; startOffset<wordLength; startOffset++)
	{
		int i;
		size_t hashSum = 0;
		int minimum = 0LL-minimumSize-startOffset+s.size();
		// This means that the requested offset does not leave us with enough characters in the string!
		if (minimum < 0) 
			return retVal;
		for (i=s.size()-startOffset-wordLength; i>=minimum; i-=wordLength) 
			hashSum+=hash_fn(s.substr(i,wordLength));
		if (hashSum==magicNumber) 
			retVal.push_back(i+wordLength);
		// Then we move word by word in such dividing
		for (;i>=0; i-=wordLength) 
		{
			hashSum-=hash_fn(s.substr(i+minimumSize,wordLength));
			hashSum+=hash_fn(s.substr(i,wordLength));
			if (hashSum==magicNumber) 
				retVal.push_back(i);
		}
	}        
	return retVal;
}

int main()
{
	vector<int> ans;
	vector<string> words = {"fooo","barr","wing","ding","wing"};
	ans = findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", words);
	return 0;
}