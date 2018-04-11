/*
*时间：2018年4月11日18:43:40-
*题号：1003. 我要通过！ 
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 
只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 
组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由
字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。
接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
输入样例：

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：

YES
YES
YES
YES
NO
NO
NO
NO
*/
//思路；之前写的详细注释都给notepad++搞没了，奔溃啊，B1040、B1035、B1045的代码也没了
//就写一下思路吧：记a为P左边的A的个数，b为P和T中间的A的个数，c为T右边的A的个数，
//由分析的满足条件的序列有c=ba，另外再加上一些其他的约束条件，比如不能有除PAT之外的其他字母
//只能有1个P和T，T的位置一定在P+1之后
#include <iostream>
using namespace std;
#include <string.h>
int main()
{
	int N;
	cin>>N;
	string PATstr[N];
	int P = 0;
	int T = 0;
	for (int i=0; i<N; i++)
	{
		cin>>PATstr[i];
		int len = PATstr[i].size();
		bool flag = true;
		int numP = 0;
		int numT = 0;
		for (int j=0; j<len; j++)
		{
			if (PATstr[i][j] != 'P' && (PATstr[i][j] != 'A') && (PATstr[i][j] != 'T'))
			{
				flag = false;
				break;
			}
			else if (PATstr[i][j] == 'P')
			{
				P = j;
				numP++;
			}				
			else if (PATstr[i][j] == 'T')
			{
				T = j;
				numT++;
			}
		}
		int a = P;
		int b = T - P - 1;
		int c = len -1 -T;
		//cout<<"a: \n"<<a<<"b: \n"<<b<<"c: \n"<<c<<"P: \n"<<P<<"T: \n"<<T<<"numP: \n"<<numP<<"numT: \n"<<numT<<endl;
		if (c == a*b && numP == 1 && numT == 1 && P < T-1 && flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
			
	}
		
	return 0;
}


/*
*时间：2018年4月11日16:49:54-2018年4月11日17:41:54
*题号：1019. 数字黑洞 
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：

给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，
然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”
之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，
直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。
输入样例1：

6767

输出样例1：

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

输入样例2：

2222

输出样例2：

2222 - 2222 = 0000
*/
//思路：这题难点倒是不多，但是实现起来还是略有麻烦，特别还有几个小bug难发现，还有就是注意下前面补0；
//用printf会比较方便一些
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <stdio.h>
bool cmp(int a, int b)//倒序排列
{
	return (a > b);
}

int increase(int a)
{
	vector <int> v(4);//用容器来排序比较方便，其实这题用数组也是一样的
	v[0] = a / 1000;
	v[1] = (a-v[0]*1000)/100;
	v[2] = (a-v[0]*1000-v[1]*100)/10;
	v[3] = a % 10;
	sort(v.begin(), v.end());
	return (v[0]*1000+v[1]*100+v[2]*10+v[3]);
}

int decrease(int a)
{
	vector <int> v(4);
	v[0] = a / 1000;
	v[1] = (a-v[0]*1000)/100;
	v[2] = (a-v[0]*1000-v[1]*100)/10;
	v[3] = a % 10;
	sort(v.begin(), v.end(), cmp);
	return (v[0]*1000+v[1]*100+v[2]*10+v[3]);
}

int main()
{	
	int num;
	cin>>num;
	//cout<<decrease(num)<<" "<<increase(num)<<" "<<decrease(num)-increase(num)<<endl
	if (decrease(num) - increase(num) == 0)//bug1：数字相同的时候是输出0000，而不是0
	{
		printf("%04d - ",decrease(num));
		printf("%04d = ",increase(num));	
		printf("0000\n");
	}
	else if (num == 6174)//bug2：为6174的时候要输出7641 - 1467 = 6174
	{
		printf("%04d - ",decrease(num));
		printf("%04d = ",increase(num));	
		printf("6174\n");
	}
	else
		while (num != 6174)//其他正常情况，注意下补0和符号间加空格就可以了
		{
			printf("%04d - ",decrease(num));
			printf("%04d = ",increase(num));	
			printf("%04d\n",decrease(num)-increase(num));
			num = decrease(num)-increase(num);
		}	
	return 0;
}

