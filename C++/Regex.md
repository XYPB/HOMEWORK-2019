# C++ Regex的一点人生经验

## Part.1 正则表达式

- 什么是正则表达式

	> 正则表达式使用单个字符串来描述、匹配一系列匹配某个句法规则的字符串。(Wiki)

	我个人理解下的正则表达式就是首先你有一个pattern(模板)，然后你可以用这个模板去匹配一类字符串，这一类字符串都和模板有着相应的对应关系。

- Pattern书写规则

	~~太多了编不出来看别人的~~

	> http://www.runoob.com/regexp/regexp-metachar.html

	强调一个之前没有注意到的地方，使用```()```包裹的内容会被自动分隔开储存到一个容器模板(```smatch```)中，即我可以通过正则表达式从符合匹配的字符串中选择有用的信息。

## Part.2 C++中的正则表达式——Regex

**1. regex_match()**

函数的参数主要包含：

- s：需要被匹配的字符串
- rgx：正则表达式模板
- flags：匹配模式（见[此处](http://www.cplusplus.com/reference/regex/regex_match/)）
- first，end：两个string的迭代器/指针，划定了匹配的位置
- m：储存匹配结果（如smatch/cmatch）

直接匹配整个给定字符串，返回一个bool值

直接贴代码啦~

```C++
#include<iostream>
#include<string>
#include<regex>
using namespace std;
int main()
{
	string str = "-1.2";
	smatch result; // 若使用cmatch则将结果保存为C-string
	regex pattern("(^[-]?)[\ ]?([0-9]+[.]?[0-9]+?)");
	if (regex_match(str, result, pattern))
	// 这里第一个变量是被匹配的字符串，第二个是()中内容储存的容器，第三个是对应的正则表达式
	{
		string str = result.str(1) + result.str(2);
		// 这里result.str()函数输出的是string格式的对应位置储存的内容
		cout << result[0] << endl;
		// 这里等价于 cout << result.str(0) << endl;
		// 注意位置0始终是匹配全部字符串，包括括号外内容
		cout << result[1] << endl; // 输出-
		cout << result[2] << endl; // 输出 1.2
		cout << str << endl; // 输出 -1.2
	}
	return 0;
}
```

- 注意，smatch/cmatch本身就是一个迭代器

**2. regex_search()**

search函数的参数类型与match相同

不同于match函数，search函数只会从指定字符串中的给定范围搜索能匹配给定模板的字符串片段，并且返回一个bool值

search函数的重点在于迭代器的使用，通过迭代器确定更新搜索范围已达到完成搜索整个字符串的目的。

代码如下：

```C++
string str = "Hello 2018, Bye 2017";
smatch result;
regex pattern("\\d{4}");    //匹配四个数字

//迭代器声明
string::const_iterator iterStart = str.begin();
string::const_iterator iterEnd = str.end();
string temp;
while (regex_search(iterStart, iterEnd, result, pattern))
{
    temp = result[0];
    cout << temp << " ";
    iterStart = result[0].second;   //更新搜索起始位置,搜索剩下的字符串
}
```

**3. regex_replace()**

所谓replace，就是将匹配到的字符串用新的字符串进行替换，因此相较于之前两个函数增加了一个新的```C-string/C++-string fmt```参数，这个参数说明了将匹配到的字符串替换为什么

需要注意的是，这里的fmt可以使用```$1, $2, ...```这样的关键词来指代匹配时用```()```储存的子字符串，因此我们就可以实现替换字符串的部分内容，调换字符串内容顺序，删去特定子字符串的功能

[参考见此处](https://blog.csdn.net/qq_34802416/article/details/79307102)
