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


/*
*时间：2018年4月12日08:35:53
*题号：1049. 数列的片段和
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：
给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。例如，给定数列
{0.1, 0.2, 0.3, 0.4}，我们有(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) 
(0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这10个片段。

给定正整数数列，求出全部片段包含的所有的数之和。如本例中10个片段总和是
0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。

输入格式：

输入第一行给出一个不超过105的正整数N，表示数列中数的个数，第二行给出N个不超过1.0的正数，
是数列中的数，其间以空格分隔。

输出格式：

在一行中输出该序列所有片段包含的数之和，精确到小数点后2位。
输入样例：

4
0.1 0.2 0.3 0.4 

输出样例：

5.00
*/

#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	int N;
	cin>>N;
	double num[N];
	for (int i=0; i<N; i++)
	{
		scanf("%lf",&num[i]);
	}
	double sum = 0;
	double temp = 0;
	for (int i = 0; i<N; i++)
	{
		sum += (double)(N-i)*num[i];
	}	
	temp = sum;
	for (int i = 1; i<N; i++)
	{
		temp -= (double)(N-i+1) * num[i-1];
		sum += (double)temp;
	}	
	printf("%.2f",sum);
	return 0;
}
/*
*17分，还有一个点没过,应该是精度不够了,再写了一份下面的代码，满分通过
*/
#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	int N;
	cin>>N;
	double num[N];
	double sum = 0;
	for (int i=1; i<=N; i++)
	{
		scanf("%lf",&num[i-1]);
		sum += num[i-1] * i* (N + 1 -i);
	}
	printf("%.2f",sum);
	return 0;
}

/*
*时间：2018年4月12日15:25:44-
*题号：1034. 有理数四则运算
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：
本题要求编写程序，计算2个有理数的和、差、积、商。

输入格式：

输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型
范围内的整数，负号只可能出现在分子前，分母不为0。

输出格式：

分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。
注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；
若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。
输入样例1：

2/3 -4/2

输出样例1：

2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

输入样例2：

5/3 0/6

输出样例2：

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
//这题是我见过最烦的一体了，写了半个小时果断放弃了，下面是正确答案
#include <iostream>
using namespace std;

int main()
{
	string A;
	string B;
	vector<vector<char>> v1(2);
	vector<vector<char>> v2(2);
	cin>>A>>B;
	int lenA = A.size();
	int lenB = B.size();
	bool Afu = false;
	bool Bfu = false;
	int a1, b1, a2, b2;
	int tempA[2];

	for (int i=0, j=0; j<2; j++)
	{
		if (i == 0 && A[i] == '-')
		{
			Afu = true;
			i++;
		}
		while (A[i] >= '0' && A[i] <= '9')
		{
			temp[j] +=  temp[j] * 10 + (A[i] - '0'); 
			i++;
		}
	}
	a1 = temp[0];
	b1 = temp[1];
	j = 0;
	for (int i=0, j=0; j<2; j++)
	{
		if (i == 0 && B[i] == '-')
		{
			Bfu = true;
			i++;
		}
		while (B[i] >= '0' && B[i] <= '9')
		{
			temp[j] +=  temp[j] * 10 + (A[i] - '0'); 
			i++;
		}
	}
	a2 = temp[0];
	b2 = temp[1];
	
	bool aDAb1 = (a1 > b1);
	bool aDAb2 = (a2 > b2);
	
	if (Afu) cout<<"(-";
	if (aDAb1) cout<<a1/b1<<" "<<a1%b1<<"/"<<b1; else cout<<a1<<"/"<<b1;
	if (Afu) cout<<")";
	cout<<" + ";
	if (Afu) cout<<"(-";
	if (aDAb1) cout<<a2/b2<<" "<<a2%b2<<"/"<<b2; else cout<<a2<<"/"<<b2;
	if (Afu) cout<<")";
	cout<<" = ";
	
	return 0;
}



/*
*时间：2018年4月13日08:22:04-2018年4月13日08:45:20
*题号：1007. 素数对猜想
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1
有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
输入样例：

20

输出样例：

4
*/
//思路，这题题目还是很直观的，i是素数，i+2也是素数就满足一个素数对，但是也有其他一些约束
//这题不能直接去遍历所有的数，特别是在判断素数的时候，对除数要开平方，不然速度太慢
#include <iostream>
using namespace std;
#define Debug false
#include <math.h>
bool isSUSHU(int a)//判断是否为素数
{
	int sqr = (int)sqrt(1.0 * a);//这里有个小技巧，大大加快速度，不然最后一个点过不去
	for (int i=2; i<=sqr; i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	cin>>num;
	int sushudui = 0;
	for (int i=1; i<num; i+=2)//题目说了dn是为偶数，那么素数一定是奇数（这不是常识吗，傻逼了）
	{						  //不需要遍历每个数，把所有的奇数遍历了就满足了，也可以加快一倍的速度
		if(Debug) cout<<isSUSHU(i);
		if (i != 1 && isSUSHU(i) && isSUSHU(i+2) && i+2<=num)//要保证i+2<=num
			sushudui++;
	}
	cout<<sushudui;
	return 0;
}



/*
*时间：2018年4月13日21:29:16-2018年4月13日21:46:57
*题号：1013. 数素数
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
输入样例：

5 27

输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
//思路：这题的判断方法和之前是差不多的，判断素数的时候的技巧。
//我是把第一个到第N个素数都压进了一个容器里，容器下表即第几个素数。
//之后把第M个到第N个素数打印出来即可
#include <iostream>
using namespace std;
#define Debug false
#include <math.h>
#include <vector>
bool isSUSHU(int a)//判断是否为素数
{
	int sqr = (int)sqrt(1.0 * a);//这里有个小技巧，大大加快速度，不然最后一个点过不去
	for (int i=2; i<=sqr; i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int M, N;
	cin>>M>>N;
	vector<int> v;//装素数的容器
	int num = 0;
	int i = 2;
	while(num != N)//对1开始每个每个数判断是否为素数，是的话就压进容器，当然可以从1=1开始用i+=2会更好
	{
		if(Debug) cout<<isSUSHU(i);
		if (isSUSHU(i))
		{
			v.push_back(i);//判断为素数就压进容器
			num++;//当前是第num个素数
		}	
		i++;	
	}		
	for (int i=M, j=1; i<=N; i++)//输出素数，当然要按着输出的格式
	{
		if (i == N) 
		{
			cout<<v[N-1];//第i个素数对应的下边是i-1
			break;//最后一个输出完之后就跳出循环，免得刚好是第十个又输出回车了
		}
		else if (j%10 == 0) cout<<v[i-1]<<endl;//每十个要加回车，而且末尾不能有空格
		else cout<<v[i-1]<<" ";
		j++;
	}
	return 0;
}



/*
*时间：2018年4月13日21:57:15-2018年4月13日22:22:33
*题号：B1017. A除以B
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，
使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。
输入样例：

123456789050987654321 7

输出样例：

17636684150141093474 3

*/
//思路：这题还是写的比较满意的，就20行左右的代码解决了一个书上40多行代码的问题，而且一次AC
//用小学学过的除法法则，对于被除数的高位开始依次除以除数（这里除数是各位数比较好处理）
//除下来的余数*10+下一位的数再除以除数，直到被除数每一位除尽。
#include <iostream>
using namespace std;
#include <vector>
#include <string.h>
int main()
{
	string A;
	int B;
	cin>>A>>B;
	int lenA = A.size();
	vector<int> v;//用来存放商的结果
	int left = 0;
	for(int i=0; i<lenA; i++)
	{
		v.push_back((left * 10 + (A[i] - '0')) / B);//每一位除了的结果压入容器
		left = (left * 10 + (A[i] - '0')) % B;//除了之后的余数
	}
	int len = v.size();
	for (int i=0; i<len; i++)
	{
		if(i==0 && v[0] == 0 && len > 1) continue;//如果第一位为0，而且商的结尾大于1位，则跳过第一位
		else if (i==0 && v[0] == 0 && len == 1) cout<<"0";//如果商就为0，这里好像不加也没关系哦
		else cout<<v[i];
	}
	cout<<" "<<left;//空格在这里打印比较方便，再打印余数
	return 0;
}		


/*
*时间：2018年4月14日18:27:19-2018年4月14日19:45:47
*题号：B1044. 火星数字
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：
火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：
tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。 

例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。
为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，
或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
输入样例：

4
29
5
elo nov
tam

输出样例：

hel mar
may
115
13
*/
//思路:本题主要是做了一个数字到火星文和火星文到数字的映射
//num到str的比较简单，直接用下标对应就可以了，str到num的话用map<string, num>
#include <iostream>
using namespace std;
#include <string.h>
#include <map>
#include <stdio.h>
#define Debug false      
string unitDigtal[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigtal[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string num2str[200];
map<string, int> str2num;
void mapInit()//169组映射关系
{
	for (int i=0; i<13; i++)//对于某一位为0的情况，第二位非零的情况，结果为1位火星文
	{
		num2str[i] = unitDigtal[i];
		str2num[num2str[i]] = i;
		num2str[i*13] = tenDigtal[i];
		str2num[num2str[i*13]] = i * 13;
	}
	for (int i =1; i<13; i++)//结果为两位火星文
	{
		for (int j=1; j<13; j++)
		{
			num2str[i*13+j] = tenDigtal[i] + " " + unitDigtal[j];
			str2num[num2str[i*13+j]] = i*13+j;
		}
	}
}
int a2i(string a)//写了一个字符串到int类型的转换
{
	int len = a.size();
	int temp = 0;
	for (int i=0; i <len; i++)
	{
		temp = temp * 10 + (a[i] - '0');
	}
	return temp;
}

int main()
{
	if (Debug) cout<<"begin"<<endl;
	mapInit();
	int T;
	scanf("%d%*c", &T); //%*后面加类型表示跳过这个类型，这里应该是用于跳过回车的
	while(T--)
	{
		string str;
		getline(cin, str);//用于保留空格
		if (Debug) cout<<str<<endl;
		if (str[0] >= '0' && str[0] <= '9')//数字转换为火星文
		{
			cout<<num2str[a2i(str)]<<endl;
		}
			
		else cout<<str2num[str]<<endl;//火星文转化为数字
	}
	
	return 0;
}


/*
*时间：2018年4月14日19:48:52-2018年4月14日20:14:21
*题号：B1025. 反转链表
*语言：C++ (g++ 4.7.2)
*分数：25
*题目描述：
给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。
例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，
则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、
以及正整数K(<=N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
输入样例：

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

输出样例：

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
//思路：建立两个容器v1、v2，v1用于每trans个node将node倒序放入到v2中
//最后输出v2即可
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
struct Node
{
	int head;
	int num;
	int next;
};
int main()
{
	int begin;
	int pnum;
	int trans;
	scanf("%d %d %d",&begin, &pnum, &trans);
	Node node[pnum];
	for (int i=0; i<pnum; i++)
	{
		scanf("%d %d %d",&node[i].head, &node[i].num, &node[i].next);
	}
	int pnext = begin;
	vector<Node> v1; 
	vector<Node> v2; 
	while (pnext != -1)
	{
		for (int i=0; i<pnum; i++)//用于遍历找到下一个node（这里有一个双层循环，估计超时了）
		{
			if(pnext == node[i].head)
			{
				v1.push_back(node[i]);
				pnext = node[i].next;
				break;
			}			
		}
		if (v1.size() == trans)//每trans个node将v1中的node倒序放到v2中
		{
			for ( int i=v1.size()-1; i>=0; i--)
				v2.push_back(v1[i]);
			v1.clear();//放入后清空v1继续接受node
		}
	}
	for ( int i=0; i<v1.size(); i++)//将剩下的node正序放入到v2中
		v2.push_back(v1[i]);
	for (int i=0; i<v2.size(); i++) //我这儿输出的都是头地址，下一个的头地址即上一个的尾地址，并没有改变node的尾地址
	{								//最后一个地址一定是-1，输出即可
		if (i == v2.size()-1) printf("%05d %d -1\n", v2[i].head, v2[i].num);
		else printf("%05d %d %05d\n", v2[i].head, v2[i].num, v2[i+1].head);
	}
				
	return 0;
}


/*
*第三个点一直超时，先放一放，应该是双层循环的问题
*/


/*
*时间：2018年4月14日22:09:00
*题号：B1010. 一元多项式求导
*语言：C++ (g++ 4.7.2)
*分数：25
*题目描述：
设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。
数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，
但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
输入样例：

3 4 -5 2 6 1 -2 0

输出样例：

12 3 -10 1 6 0
*/
//思路：这个好像很寻常，只是注意下输出格式和一些特殊情况就好，虽然我还有一个点没过
#include <iostream>
using namespace std;
#include <stdio.h>
#define Debug false
int main()
{
	int i = 0;
	int num[999999];//这里到底多少个我也不清楚就增大了数组
	if (Debug)cout<<"begin";
	while (1)//这个到回车为止记录输入值的技巧一定要记得
	{
		cin>>num[i];
		i++;
		if (getchar() == '\n') break;
	}
	i = 0;
	while (num[i] != '\0')
	{
		if (num[2] == '\0' && num[1] == 0) 
		{
			cout<<"0 0";
			break;
		}
		if (num[i+2] == '\0' && num[i+1] == 0) break;//这里有好几种输出情况，比如最后一位不是0次和最后一位是0次之类的，还有个bug没找到
		else if (num[i+2] == '\0' && num[i+1] != 0) cout<<num[i]*num[i+1]<<" "<<num[i+1]-1;
		else cout<<num[i]*num[i+1]<<" "<<num[i+1]-1;
		if (num[i+4] != '\0' || num[i+3] != 0) cout<<" ";
		i += 2;
	}
	return 0;
}

/*
*最后一个点没过
*/


/*
*时间：2018年4月15日15:26:26-2018年4月15日16:07:04
*题号：B1022. D进制的A+B
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：

输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。
输入样例：

123 456 8

输出样例：

1103
*/
//这题没什么难点，就是按照进制转换的公式写成代码就ok了
//即余数倒序
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

int main()
{
	long long a, b;
	int c;
	vector<int> v;
	cin>>a>>b>>c;
	long long sum = a + b;
	int shang = sum / c;
	int yushu = sum % c;
	
	while (shang != 0)
	{
		//cout<<shang<<" "<<yushu<<endl;
		v.push_back(yushu);
		yushu = shang % c;
		shang = (long long)shang / c;			
	}
	cout<<yushu;
	int lenV = v.size();
	for (int i=lenV-1; i>=0; i--)//余数倒序输出
	{
		cout<<v[i];
	}
	return 0;
}


/*
*时间：2018年4月15日16:08:17-2018年4月15日16:33:46
*题号：B1037. 在霍格沃茨找零钱
*语言：C(gcc 4.7.2)
*分数：20
*题目描述：
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：
“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。
”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。
这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
输入样例1：

10.16.27 14.1.28

输出样例1：

3.2.1

输入样例2：

14.1.28 10.16.27

输出样例2：

-3.2.1
*/
//思路：这题思路上好像也没什么难点，就是先判断一下是给的钱多还是需要的钱多，
//如果钱不够就用应付减去自己有的钱再加一个-号就好
#include <stdio.h>

int main()
{
	int Galleon1, Sickle1, Knut1;//价格
	int Galleon2, Sickle2, Knut2;//自己的money
	scanf("%d.%d.%d %d.%d.%d",&Galleon1, &Sickle1, &Knut1, &Galleon2, &Sickle2, &Knut2);
	int GalleonLeft, SickleLeft, KnutLeft;
	if (Galleon1*107+Sickle1*17+Knut1*29 <= Galleon2*107+Sickle2*17+Knut2*29 )
	{
		if (Knut2 >= Knut1) KnutLeft = Knut2 - Knut1;
		else 
		{
			KnutLeft = 29 + Knut2 - Knut1;
			Sickle2--;
		}
		if (Sickle2 >= Sickle1) SickleLeft = Sickle2 - Sickle1;
		else 
		{
			SickleLeft = 17 + Sickle2 - Sickle1;
			Galleon2--;
		}
		GalleonLeft = Galleon2 - Galleon1;
		printf("%d.%d.%d", GalleonLeft, SickleLeft, KnutLeft);
	}
	else
	{
		if (Knut1 >= Knut2) KnutLeft = Knut1 - Knut2;
		else 
		{
			KnutLeft = 29 + Knut1 - Knut2;
			Sickle1--;
		}
		if (Sickle1 >= Sickle2) SickleLeft = Sickle1 - Sickle2;
		else 
		{
			SickleLeft = 17 + Sickle1 - Sickle2;
			Galleon1--;
		}
		GalleonLeft = Galleon1 - Galleon2;
		printf("-%d.%d.%d", GalleonLeft, SickleLeft, KnutLeft);
	}
	return 0;
}


/*
*时间：2018年4月15日15:26:26-2018年4月15日16:07:04
*题号：B1050. 螺旋矩阵
*语言：C++ (g++ 4.7.2)
*分数：20
*题目描述：
本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，
是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，
满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。

输入格式：

输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，
相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
输入样例：

12
37 76 20 98 76 42 53 95 60 81 58 93

输出样例：

98 95 93
42 37 81
53 20 76
58 60 76
*/
//思路：我觉得这题还是有一定的挑战的，接下来谈谈思路
//第一个难点，给定一个N如何找到差值最小的m、n，我开始的想法是对每个m遍历得到n，记录差值，取最小的一对，这部分代码也还在
//不过这个方法自己想想也不是很好，果然超时了，然后看了书上的方法，先找到大于等于根号N的最小整数，然后递增遍历
//找到的第一个可以被N整除的m即是
//第二个难点，如何降序螺旋输入矩阵的值。
//我的方法的→↓←↑的顺序对每一个矩阵中没有被赋值的元素进行降序赋值
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
#if 0
void findMN(int* m, int* n)
{
	int cha = 105;
	int chaNow = 0;
	int a, b;
	for (int i=1; i<=sqrt(N); i++)
	{
		if (N % i == 0)
		{
			a = i;
			b = N / a;
			chaNow = b - a;
			//cout<<a<<" "<<b<<endl;
			if (chaNow < cha)
			{
				cha = chaNow;
				*m = b;
				*n = a;
			}
		}			
	}	
}
#endif
bool cmp(int a, int b)
{
	return (a>b);
}

int main()
{
	cin>>N;
	int m, n;
	//findMN(&m, &n);
	//cout<<m<<" "<<n;
	m = ceil(1.0 * sqrt(N));//N来寻找m、n
	while(1)
	{
		if (N % m == 0)
		{
			break;
		}
		m++;
	}
	n = N / m;
	int A[N];
	for (int i=0; i<N; i++)
		cin>>A[i];
	sort (A, A+N, cmp);//降序
	int B[m][n];
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
			B[i][j] = -1;//先标记为赋值的元素为-1，之后这个元素只能是-1才赋值，不然就break
	}
	int i = -1;//这两个值要和下面配合使用
	int j = -1;
	int k = 0;
	while (k <= N-1)
	{
		for (i++,j++; j<n; j++)//这时候j会加到n才跳出循环，所以下一步要先j--，使得j=n-1
		{
			if(B[i][j] == -1)
			{
				B[i][j] = A[k];
				k++;
				//printf("B[%d][%d] = %d.\n",i, j, B[i][j]);
			}
			else break;			
		}
		for (j--,i++; i<m; i++)//前面除了j--让j=n-1之外还有个i++是让i先加一个，不然就回到原来的元素了
		{
			if(B[i][j] == -1)
			{
				B[i][j] = A[k];
				k++;
				//printf("B[%d][%d] = %d.\n",i, j, B[i][j]);
			}
			else break;			
		}
		for (i--,j--; j>=0; j--)//和上面原理类似的
		{
			if(B[i][j] == -1)
			{
				B[i][j] = A[k];
				k++;
				//printf("B[%d][%d] = %d.\n",i, j, B[i][j]);
			}
			else break;			
		}
		for (j++,i--; i>=0; i--)
		{
			if(B[i][j] == -1)
			{
				B[i][j] = A[k];
				k++;
				//printf("B[%d][%d] = %d.\n",i, j, B[i][j]);
			}
			else break;			
		}
	}
	for (i=0; i<m; i++)//输出矩阵
	{
		for(j=0; j<n; j++)
		{
			if (j == n-1) printf("%d\n",B[i][j]);
			else printf("%d ",B[i][j]);
		}
	}
	return 0;
}






