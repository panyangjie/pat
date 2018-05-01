//乙级刷了前50题，现在开始刷甲级，争取在8-9月份把PAT甲级考出来
/*
*时间：2018年4月17日20:24:18-2018年4月17日21:02:30
*题目：1042.Shuffling Machine
*分数：20
*编译器：g++
*题目描述：
Shuffling（洗牌） is a procedure used to randomize a deck of playing cards. 
Because standard shuffling techniques are seen as weak, and in order to avoid 
"inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, 
many casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a 
given number of times. It is assumed that the initial status of a card deck is in the following order:
S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker".
 A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is
 j, it means to move the card from position i to position j. For example, suppose we only have 5 cards:
 S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3,
 C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer 
K (<= 20) which is the number of repeat times. Then the next line contains the given order. 
All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the shuffling results in one line. All the cards are separated by a space, 
and there must be no extra space at the end of the line.
Sample Input:

2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47

Sample Output:

S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5

*/
//思路：渣渣英语呀，题目都看了一会···
//这题思路倒是不难，我是先建立了一个原始的顺序数组，然后用一个临时数组用来存放每次变换的数组
#include <iostream>
using namespace std;

int main()
{	
	int n;
	int order[54];
	string temp[54];
	string initOrder[54] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12","S13",
							"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12","H13",
							"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12","C13",
							"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12","D13",
							"J1", "J2"};
	cin>>n;
	for (int i=0; i<54; i++)
	{
		cin>>order[i];	
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<54; j++)
		{
			temp[order[j]-1] = initOrder[j];//temp为变换后的数组，表示temp的第order[j]-1个元素为initOrder[j]
		}
		for (int j=0; j<54; j++)//再把initOrder数组用temp赋值
			initOrder[j] = temp[j];
	}
	for(int i=0; i<54; i++)
	{
		if (i == 53) cout<<initOrder[53];
		else cout<<initOrder[i]<<" ";
	}
		
	return 0;
}


/*
*时间：2018年4月20日11:06:04-2018年4月20日11:32:38
*题目：1046.Shortest Distance
*分数：20
*编译器：g++
*题目描述：
The task is really simple: given N exits on a highway which forms a simple cycle, you are 
supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N 
(in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between 
the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers
 in a line are separated by a space. The second line gives a positive integer M (<=104), 
 with M lines follow, each contains a pair of exit numbers, provided that the exits are 
 numbered from 1 to N. It is guaranteed that the total round trip distance is
 no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance
 between the corresponding given pair of exits.
Sample Input:

5 1 2 4 14 9
3
1 3
2 5
4 1

Sample Output:

3
10
7
*/
//思路：由于是cycle所以路径是有两个方向，称路标从小打到为正方向
//计算正方向的路径，再和总路径减去正方向的路径做对比，哪个小取哪个
//为了防止超时，将路径和做一个组数，表示从1到当前路标下的路径之和
#include <iostream>
using namespace std;
#include <math.h>

int main()
{
	int N, M;
	cin>>N;
	int sum[N+1];
	sum[0] = 0;
	int distance[N];		
	for (int i=0; i<N; i++)
	{
		cin>>distance[i];
		sum[i+1] = sum[i] + distance[i];//sum[i]表示1到i-1的路径之和
	}
	cin>>M;
	int exits[2 * M];
	for (int i=0; i<2*M; i++)
		cin>>exits[i];
	for (int i=0; i<M; i++)
	{
		int a = max(exits[2*i], exits[2*i+1]);
		int b = min(exits[2*i], exits[2*i+1]);
		int temp = sum[a-1] - sum[b-1];//正向路径
		if (temp < sum[N] - temp) cout<<temp<<endl;
		else cout<<sum[N] - temp<<endl;	
	}	
	return 0;
}



/*
*时间：s2018年4月20日12:52:03-2018年4月20日13:18:47
*题目：1065.A+B and C (64bit)
*分数：20
*编译器：g++
*题目描述：
Given three integers A, B and C in [-2^63, 2^63], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test 
cases follow, each consists of a single line containing three integers A, B and C, 
separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false"
 otherwise, where X is the case number (starting from 1).
Sample Input:

3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

Sample Output:

Case #1: false
Case #2: true
Case #3: false
*/
//这题的关键就是long long 类型装不下了怎么处理，long long的范围是[-2^63, 2^63)
//由于A, B and C in [-2^63, 2^63]，所以A+B最大就是2^64，用long long装A，B的话会超出范围
//1、如果A和B都是正数，那么最大值为2^64-2,超出范围之后就为[-2^63， -2]即<0，所以A B 都是正数，和为负数就判断为true（C不可能超出范围一定比A+B小）
//2、如果A和B都是负数，那么最大值为-2^64,超出范围之后就为[0，2^63]即>=0，所以A B 都是负数，和>=0就判断为false（C不可能超出范围一定比A+B小）
//3、其余的按正常情况判断
//以上思路参考《算法笔记》
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	long long num[T][3];
	for (int i=0; i<T; i++)
	{
		cin>>num[i][0]>>num[i][1]>>num[i][2];
		long long  res = num[i][1] + num[i][0]; //很关键，和必须用long long类型，也可以加起来之后强制类型转换
		if (num[i][0]>0 && num[i][1]>0 && res<0) cout<<"Case #"<<i+1<<": true"<<endl;//情况1
		else if (num[i][0]<0 && num[i][1]<0 && res>=0) cout<<"Case #"<<i+1<<": false"<<endl;//情况2
		else if (res > num[i][2]) cout<<"Case #"<<i+1<<": true"<<endl;//情况3
		else cout<<"Case #"<<i+1<<": false"<<endl;
	}
	
	return 0;
}




/*
*时间：2018年4月21日16:41:04-2018年4月21日17:29:25
*题目：1002.A+B for Polynomials 
*分数：25
*编译器：g++
*题目描述：

This time, you are supposed to find A+B where A and B are two polynomials（多项式）.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line 
contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the
 number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents 
 and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as 
the input. Notice that there must be NO extra space at the end of each line. Please be 
accurate to 1 decimal place.
Sample Input

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output

3 2 1.5 1 2.9 0 3.2
*/
//思路：数组的散列思想，数组下表即次数，数组值为这个这个次数的项的系数
#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
int main()
{
	double coe[1010] = {0};
	int M, N;
	cin>>M;
	double polyA[2*M];
	for (int i=0; i<2*M; i++)
		cin>>polyA[i];
	cin>>N;
	double polyB[2*N];
	for (int i=0; i<2*N; i++)
		cin>>polyB[i];
	for (int i=0; i<max(N, M); i++)//将大的数组遍历完全
	{
		if (i < 2 * M) coe[(int)polyA[2*i]] += (double)polyA[2*i+1];//i<2M要注意，不然数组会越界
		if (i < 2 * N) coe[(int)polyB[2*i]] += (double)polyB[2*i+1];//与上面类似
	}
	int len = 0;
	for (int i=0; i<1010; i++)//非零项的个数
	{
		if (coe[i] != 0) len++;
		//cout<<i<<" "<<coe[i]<<endl;
	}
	if (len == 0) cout<<"0";
	else cout<<len<<" ";
	int temp = 0;
	for (int i=1009; i>=0; i--)
	{
		if (temp == len - 1 && coe[i] != 0) printf("%d %.1f", i, coe[i]);//小技巧，表示最后一个输出，输出的格式注意一下
		else if (coe[i] != 0) 
		{
			printf("%d %.1f ", i, coe[i]);
			temp++;
		}	
	}
	return 0;
}


/*
*时间：2018年4月21日20:55:35-2018年4月21日21:03:58
*题目：1009.Product of Polynomials
*分数：25
*编译器：g++
*题目描述：
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line
 contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the 
 number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents
 and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format
 as the input. Notice that there must be NO extra space at the end of each line. Please be 
 accurate up to 1 decimal place.
Sample Input

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output

3 3 3.6 2 6.0 1 1.6
*/
//思路：这题在上面一题基础上就核心部分改一下就OK了，五分钟搞定，多项式乘法的法则
#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
int main()
{
	double coe[2010] = {0};
	int M, N;
	cin>>M;
	double polyA[2*M];
	for (int i=0; i<2*M; i++)
		cin>>polyA[i];
	cin>>N;
	double polyB[2*N];
	for (int i=0; i<2*N; i++)
		cin>>polyB[i];
	for (int i=0; i<M; i++)//这里搞了个双层循环，原来以为会超时的，结果全部AC
	{
		for (int j=0; j<N; j++)
		{
			coe[(int)polyA[2*i]+(int)polyB[2*j]] += (double)(polyA[2*i+1] * polyB[2*j+1]);
		}
	}
	int len = 0;
	for (int i=0; i<2010; i++)
	{
		if (coe[i] != 0) len++;
		//cout<<i<<" "<<coe[i]<<endl;
	}
	if (len == 0) cout<<"0";
	else cout<<len<<" ";
	int temp = 0;
	for (int i=2009; i>=0; i--)
	{
		if (temp == len - 1 && coe[i] != 0) printf("%d %.1f", i, coe[i]);
		else if (coe[i] != 0) 
		{
			printf("%d %.1f ", i, coe[i]);
			temp++;
		}	
	}
	return 0;
}


/*
*时间：2018年4月22日20:31:13-2018年4月22日20:56:27
*题目：1011.World Cup Betting
*分数：20
*编译器：g++
*题目描述：
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players
 from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting
 their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. 
Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an
 odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:

 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1

To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans,
 then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input

Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct
 odds corresponding to W, T and L.

Output

For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and 
the number must be separated by one space.
Sample Input

1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1

Sample Output

T T W 37.98
*/

//思路：注意小数点后保留两位，四舍五入
#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	double profit[3][3];
	double beilvMax[3] = {0};
	for (int i=0; i<3; i++)
	{
		int mark = 0;
		cin>>profit[i][0]>>profit[i][1]>>profit[i][2];
		for (int j=0; j<3; j++)
		{
			if(profit[i][j] > beilvMax[i])
			{
				beilvMax[i] = profit[i][j];
				mark = j; //mark 0、1、2分别表示W、T、L
			}
		}	
		if (mark == 0) cout<<"W ";
		else if (mark == 1) cout<<"T ";
		else cout<<"L ";
	}
	//四舍五入处理
	double Profit = (double)(beilvMax[0] * beilvMax[1] * beilvMax[2] * 0.65 - 1) * 2;//计算盈利值
	if (Profit*100 - int(Profit*100) >= 0.5) Profit += (double)0.01;//因为要比较小数点后第三位是否大于五，一般方法不太好比较
	printf("%.2f", Profit);                                         //我是先把数放大100，double类型的这个数减去int类型看是否大于0.5即可。
		
	return 0;
}



/*
*时间：2018年4月22日20:57:50-2018年4月22日21:19:56
*题目：1006.Sign In and Sign Out
*分数：25
*编译器：g++
*题目描述：
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who 
signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked 
and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, 
which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time

where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID
 numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person,
 and there are no two persons sign in or out at the same moment.
Sample Input:

3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:

SC3021234 CS301133
*/
//思路：一开始自己想的不简便，没有用sort函数，写着写着发现写的麻烦了，还不如写两个sort的cmp比较快捷
//数据读进来后分别比较sign in 的最早时间按升序排一次，输出stu[0].ID
//再比较sign out 的最迟时间，按降序排一次，输出stu[0].ID
#include <iostream>
using namespace std;
#include <string.h>
#include <algorithm>
#include <stdio.h>
struct student//定义每个人的一个结构体
{
	string ID;
	int sign_in[3];
	int sign_out[3];
};
bool cmp_sign_in(student a, student b)//unlock time cmp
{
	if (a.sign_in[0] != b.sign_in[0]) return (a.sign_in[0] < b.sign_in[0]);
	else if (a.sign_in[1] != b.sign_in[1]) return (a.sign_in[1] < b.sign_in[1]);
	else return (a.sign_in[2] < b.sign_in[2]);	
}
bool cmp_sign_out(student a, student b)//lock time cmp
{
	if (a.sign_out[0] != b.sign_out[0]) return (a.sign_out[0] > b.sign_out[0]);
	else if (a.sign_out[1] != b.sign_out[1]) return (a.sign_out[1] > b.sign_out[1]);
	else return (a.sign_out[2] > b.sign_out[2]);	
}
int main()
{
	int N;
	cin>>N;
	student stu[N];
	for (int i=0; i<N; i++)
	{
		cin>>stu[i].ID;
		scanf("%d:%d:%d",&stu[i].sign_in[0], &stu[i].sign_in[1], &stu[i].sign_in[2]);//scanf就是好用，千万记得加&
		scanf("%d:%d:%d",&stu[i].sign_out[0], &stu[i].sign_out[1], &stu[i].sign_out[2]);
	}
	sort(stu, stu+N, cmp_sign_in);//sign in 升序
	cout<<stu[0].ID<<" ";
	sort(stu, stu+N, cmp_sign_out);//sign out 降序
	cout<<stu[0].ID;
	return 0;
}



/*
*时间：2018年4月23日19:57:53-2018年4月23日20:16:37
*题目：1036.Boys vs Girls
*分数：25
*编译器：g++
*题目描述：
This time you are asked to tell the difference between the lowest grade of all the male students 
and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student 
information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are 
strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer
 between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, 
and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. 
If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

Sample Output 1:

Mary EE990830
Joe Math990112
6

Sample Input 2:

1
Jean M AA980920 60

Sample Output 2:

Absent
Jean AA980920
NA
*/
//思路：这题在思路上没什么难的，也没什么特别的格式要求，只要稍微细心一些就可以
#include <iostream>
using namespace std;
#include <string.h>
struct student{
	string name;
	char gender;
	string ID;
	int grade;
};
int main()
{
	int N;
	cin>>N;
	student stu[N];
	for (int i=0; i<N; i++)
	{
		cin>>stu[i].name>>stu[i].gender>>stu[i].ID>>stu[i].grade;
	}
	int Fgrade = 0;//记录女生最高分
	int Mgrade = 100;//记录男生最低分
	int Fseq = -1;//记录女生最高分的学生的编号
	int Mseq = -1;//记录男生最低分的学生的编号
	for (int i=0; i<N; i++)
	{
		if (stu[i].gender == 'F')
		{
			if (stu[i].grade > Fgrade)//记录女生最高分
			{
				Fgrade = stu[i].grade;
				Fseq = i;
			}
		}
		else//记录男生最低分 
		{
			if (stu[i].grade < Mgrade)
			{
				Mgrade = stu[i].grade;
				Mseq = i;
			}
		}
	}
	if (Fseq == -1) cout<<"Absent"<<endl; else cout<<stu[Fseq].name<<" "<<stu[Fseq].ID<<endl;//编号还是为-1的话表示没有记录到女生，则Abeset
	if (Mseq == -1) cout<<"Absent"<<endl; else cout<<stu[Mseq].name<<" "<<stu[Mseq].ID<<endl;
	if (Mseq == -1 || Fseq == -1) cout<<"NA"<<endl; else cout<<stu[Fseq].grade-stu[Mseq].grade<<endl;//任意一个性别没有记录到编号，则NA
	return 0;
}



/*
*时间：2018年4月23日20:28:33-2018年4月23日20:50:20
*题目：1031.Hello World for U
*分数：20
*编译器：g++
*题目描述：
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example,
 "helloworld" can be printed as:
h  d
e  l
l  r
lowo

That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1
 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical 
 line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that
 n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.

Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters
 in a line. The string contains no white space.

Output Specification:

For each test case, print the input string in the shape of U as specified in the description.
Sample Input:

helloworld!

Sample Output:

h   !
e   d
l   l
lowor
*/
//思路：这题稍微算一下n1、n2、n3的值就可以了，题目里说n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N }
//于是n1 = n3 = （N+2）/3; N+2是表示有两个角上是重叠的，一共n1行，n2列，前面n1-1行中间加n2-2个空格
#include <iostream>
using namespace std;
#include <string.h>
#define Debug false
int main()
{
	string str;
	cin>>str;
	int len = str.size();
	int n1 = (len+2) / 3;//计算n1,n3
	int n3 = n1;
	int n2 = len + 2 - n1 - n3;//计算n2，其实这部是可以不用算的直接用len - n1 - n2就可以得到space的个数 
	int spaceNum = n2 -2;
	if (Debug) cout<<"n1:"<<n1<<" n2:"<<n2<<" n3:"<<n3<<" spaceNum:"<<spaceNum<<endl;//Debug,基本有问题就在前面计算，这个很有必要
	for (int i=0; i<n1; i++)
	{
		if (i != n1-1)//前n-1行
		{
			cout<<str[i];//先输出行的第一个
			for (int j=0; j<spaceNum; j++)//输出中间的space
				cout<<" ";
			cout<<str[len-1-i]<<endl;//再输出行的最后一个
		}
		else
			for (int i=n1-1; i<n1+1+spaceNum; i++)//第n1行特殊处理，输出n1-1到n1+spaceNum共spaceNum+2（也就是n2）个字符
				cout<<str[i];	
	}
	
	return 0;
}



/*
*时间：2018年4月24日21:14:40-2018年4月24日22:21:13
*题目：1019.General Palindromic Number
*分数：20
*编译器：g++
*题目描述：
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 
1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied 
to the natural numbers in any numeral system. Consider a number N > 0 in base b >= 2, where it is written in standard 
notation with k+1 digits ai as the sum of (aibi) for i from 0 to k. Here, as usual, 0 <= ai < b for all i and ak is non-zero. 
Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 in any base and is also palindromic by definition.

Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

Input Specification:

Each input file contains one test case. Each case consists of two non-negative numbers N and b, where 0 <= N <= 10^9 is the decimal 
number and 2 <= b <= 10^9 is the base. The numbers are separated by a space.

Output Specification:

For each test case, first print in one line "Yes" if N is a palindromic number in base b, or "No" if not. Then in the next line, 
print N as the number in base b in the form "ak ak-1 ... a0". Notice that there must be no extra space at the end of output.
Sample Input 1:

27 2

Sample Output 1:

Yes
1 1 0 1 1

Sample Input 2:

121 5

Sample Output 2:

No
4 4 1
*/
//思路：一个难度不大的题目给我写成这样···，开始追求快的方法，去找进制转换的函数，试了下不太靠谱，atoi在linux下就没有定义
//后来还是老老实实自己写进制转换函数了，而且这里还是一般的进制转换，像传统的16进制超出10就是ABCDEF了，就是char类型的，不是int类型的
//而这里就是需要用int类型的，这是个注意点
#include <iostream>
using namespace std;
#define Debug false
void Ntob(long N, long b, int* buff)//进制转换函数
{
	int shang = N;
	int res; 
	int i = 0;
	do {//do while();语句啊，还是有用武之地的。这样就可以减少一步当商为0的时候余数加入到buff中
		res = shang % b;
		shang = shang / b;
		buff[i++] = res;//小技巧，直接用i++这里是后算i=i+1的，注意和++i的区别
		if (Debug) cout<<"shang="<<shang<<" res="<<res<<" i="<<i<<" buff[i]="<<buff[i]<<endl;		
	}while (shang);
}
int main()
{
	long N;
	long b;
	cin>>N>>b;
	int buff[100];
	for (int i=0; i<100; i++) buff[i] = -1;//浪费了几行在判断buff的长度上，其实可以集成到Ntob函数中去的
	Ntob(N, b, buff);
	int len = 0;
	if (Debug) for (int i=0; i<100; i++) cout<<buff[i]<<" ";
	while (buff[len] != -1)
		len++;
	if (Debug) cout<<"len="<<len<<endl;
	bool flag = true;
	for (int i=0; i<len/2; i++)//判断是否的回环数，其实可以写成一个bool类型的函数来做判断
	{
		if (buff[i] != buff[len-1-i])
		{
			flag = false;
			break;
		}
	}
	if (flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for (int i=len-1; i>=0; i--)//由于进制转换后是要倒序
	{
		if (i == 0) cout<<buff[0];
		else cout<<buff[i]<<" ";
	}
	return 0;
}


/*
*时间：2018年4月26日22:07:23-2018年4月26日22:31:55
*题目：1027.Colors in Mars
*分数：20
*编译器：g++
*题目描述：
People in Mars represent the colors in their computers in a similar way as the Earth people. 
That is, a color is represented by a 6-digit number, where the first 2 digits are for Red,
 the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that 
 they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168),
 you are supposed to output their Mars RGB values.

Input

Each input file contains one test case which occupies a line containing the three decimal color values.

Output

For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit
 number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.
Sample Input

15 43 71

Sample Output

#123456
*/
//思路：这题比普通的进制转换题多了一点难点就是要自己写输出ABC，自然就想到了简历一个13进制的数组
//好像枚举的话感觉会更高端一些
#include <iostream>
using namespace std;
#include <vector>
char radix13[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};//13进制的数组
void printRadix13(int a)//打印13进制的数
{
	vector<int> v;//为了倒序打印
	int shang = a;
	int res;
	do{
		res = shang % 13;
		shang = shang / 13;
		v.push_back(res);	
	}while(shang);
	if (v[1] == '\0') cout<<"0"<<radix13[v[0]];	//处理第一位为0的情况
	else cout<<radix13[v[1]]<<radix13[v[0]];
}
int main()
{
	int a, b, c;
	cin>>a>>b>>c;
	cout<<"#";
	printRadix13(a);
	printRadix13(b);
	printRadix13(c);
	return 0;
}

/*
*时间：2018年4月26日22:36:17-2018年4月26日22:43:24
*题目：1058.A+B in Hogwarts
*分数：20
*编译器：g++
*题目描述：
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- 
as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle,
 it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form 
 of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.
Sample Input:

3.2.1 10.16.27

Sample Output:

14.1.28
*/
//思路：这题乍一看和PAT乙级的那题找钱的一样，不过这题还更简单了一点，本来不想做了的
//后来还是试了下，发现虽然做过，但是每次还是会有新的想法
#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	int a[3];
	int b[3];
	int c[3];
	int flag = 0;
	scanf("%d.%d.%d %d.%d.%d",&a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);//大赞scanf
	c[2] = (a[2] + b[2]) % 29;//第三位计算
	flag = (a[2] + b[2]) / 29;//计算进位，下面类似
	c[1] = (a[1] + b[1] + flag) % 17;
	flag = (a[1] + b[1] + flag) / 17;
	c[0] = (a[0] + b[0]) + flag;
	cout<<c[0]<<"."<<c[1]<<"."<<c[2];
	
	return 0;
}


/*
*时间：2018年4月29日20:30:52-2018年4月29日20:49:21
*题目：1001.A+B Format
*分数：20
*编译器：g++
*题目描述：
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into 
groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a,
 b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
Sample Input

-1000000 9

Sample Output

-999,991
*/
//思路：将sum分开成每个位比较好处理，一开始如何从个位开始每三位输出一个逗号卡住了，应为我们都是从高位开始输出到低位的
//后来想了下，从总体的来看，位数在3的倍数的数后面跟一个逗号就可以了
#include <iostream>
using namespace std;
#include <vector>
int main()
{
	long a;
	long b;
	cin>>a>>b;
	long sum = a + b;
	if (sum < 0)//sum小于0的情况，都用正数来处理比较方便
	{
		cout<<"-";
		sum = -sum;
	}
	vector<int> v;
	if (sum == 0) cout<<"0";//sum为0的情况
	while (sum)//把sum分成每个位
	{
		v.push_back(sum % 10);
		sum = sum / 10;
	}
	for(int i=v.size()-1; i>=0; i--)
	{
		cout<<v[i];
		if(i%3 == 0 && i != 0) cout<<",";//位数在3的倍数的后面加一个逗号
	}
	return 0;
}





/*
*时间：2018年4月29日20:54:07-2018年4月29日21:08:55
*题目：1005.Spell It Right 
*分数：20
*编译器：g++
*题目描述：
Given a non-negative integer N, your task is to compute the sum of all the digits of N, 
and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space
 between two consecutive words, but no extra space at the end of a line.
Sample Input:

12345

Sample Output:

one five
*/
//思路：建一个数组，数字对应相应的英文，把和分成每个位，从高到低输出每个位对应的英文就ok
#include <iostream>
using namespace std;
#include <string>
#include <vector>
string digChar[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
	string num;//用字符类型来处理输入的数字
	cin>>num;
	int sum = 0;
	for (int i=0; i<num.size(); i++)//将每个位加起来
		sum += num[i] - '0';
	vector<int> v;
	if (sum == 0) cout<<digChar[0];
	while(sum)//加起来之后的又分成每个int的位
	{
		v.push_back(sum % 10);
		sum /= 10;
	}
	for (int i=v.size()-1; i>=0; i--)//输出每个位对应的英文，注意一下最后不要空格
	{
		if(i == 0) cout<<digChar[v[0]];
		else cout<<digChar[v[i]]<<" ";
	}
	return 0;
}


/*
*时间：2018年4月29日21:10:40-2018年4月29日21:39:36
*题目：1035.Spell It Right 
*分数：20
*编译器：g++
*题目描述：
To prepare for PAT, the judge sometimes has to generate random passwords for the users. 
The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase),
 or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, 
 l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge,
 and to help the juge modify the confusing passwords.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N (<= 1000), followed by N lines of accounts. 
Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.

Output Specification:

For each test case, first print the number M of accounts that have been modified, then print in the following M lines 
the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts 
must be printed in the same order as they are read in. If no account is modified, print in one line
 "There are N accounts and no account is modified" where N is the total number of accounts. However, 
 if N is one, you must print "There is 1 account and no account is modified" instead.

Sample Input 1:

3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

Sample Output 1:

2
Team000002 RLsp%dfa
Team000001 R@spodfa

Sample Input 2:

1
team110 abcdefg332

Sample Output 2:

There is 1 account and no account is modified

Sample Input 3:

2
team110 abcdefg222
team220 abcdefg333

Sample Output 3:

There are 2 accounts and no account is modified
*/
//思路：对每个输入的密码遍历，看看是否有1i0O这四个字符，有就按照规则改掉
//没有一个是需要改的话一定要注意单复数的are和accounts
#include <iostream>
using namespace std;
#include <vector>
#include <string>
struct user{
	string name;
	string pw;
};
int main()
{
	int N;
	cin>>N;
	user usr[N];
	vector<int> modifiedID;//改动过的编号
	for (int i=0; i<N; i++)
	{
		cin>>usr[i].name>>usr[i].pw;
		int modifiedNum = usr[i].pw.size();
		for (int j=0; j<usr[i].pw.size(); j++)//对每个pw进行遍历
		{
			//cout<<"modifiedNum: "<<modifiedNum<<endl;
			if (usr[i].pw[j] == '1') usr[i].pw[j] = '@';
			else if(usr[i].pw[j] == 'l') usr[i].pw[j] = 'L';
			else if(usr[i].pw[j] == '0') usr[i].pw[j] = '%';
			else if(usr[i].pw[j] == 'O') usr[i].pw[j] = 'o';
			else modifiedNum--;//如果减到0表示没有一个字符需要修改的
		}
		if (modifiedNum) modifiedID.push_back(i);//没有减到0，就把这个编号压入到改动过的编号
	}
	if (modifiedID.size() == 0 && N == 1) cout<<"There is "<<N<<" account and no account is modified"<<endl;//单数is和account
	else if (modifiedID.size() == 0 && N >1) cout<<"There are "<<N<<" accounts and no account is modified"<<endl;//注意单复数呀，are和accouts
	else {
		cout<<modifiedID.size()<<endl;
		for(int i=0; i<modifiedID.size(); i++)
		{
			cout<<usr[modifiedID[i]].name<<" "<<usr[modifiedID[i]].pw<<endl;
		}
	}
	return 0;
}


/*
*时间：2018年4月30日21:41:49-2018年4月30日22:35:54
*题目：1077.Kuchiguse  
*分数：20
*编译器：g++
*题目描述：
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can
 be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often
 exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often
 used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N 
file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix（后缀） of all N lines. 
If there is no such suffix, write "nai".
Sample Input 1:

3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

Sample Output 1:

nyan~

Sample Input 2:

3
Itai!
Ninjinnwaiyada T_T
T_T

Sample Output 2:

nai
*/
//思路：这题题目看起来还是比较有意思的，其实是算一个最大后缀。用第一个字符串去匹配所有的字符串。主要有几个难点：
//1、输入为带空格的char类型的数组，还要注意下cin之后有个回车需要用getchar();去掉，然后每个char类型的数组用gets(a[i]);就可以啦
//2、要记录一个最小的长度，不然会超出一个长度继续匹配，可能会匹配到'\0'，而且容易超时
//3、将数组反过来再匹配前缀可以防止超时，而且会变得简单一些
//4、自己的一些小的不好的习惯会产生一些很难查找的错误，比如第五个点应该是最短的那个字符全部匹配上了，就不能再break的时候输出sameLenth = i;
#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
int main()
{
	int N;
	cin>>N;
	char a[N][256];
	int minLen = 256;
	getchar();//去掉cin后面的'\n'，很容易忽略
	for (int i=0; i<N; i++)
	{
		gets(a[i]);
		if (strlen(a[i]) < minLen) minLen = strlen(a[i]);//得到一个最小字符串的长度
		for (int j=0; j<strlen(a[i])/2; j++)//反转数组
		{
			char temp = a[i][j];
			a[i][j] = a[i][strlen(a[i])-j-1];
			a[i][strlen(a[i])-j-1] = temp;
		}
	}
	int sameLenth = 0;
	bool flag = false;//是否有没有匹配上的，置位true
	for (int i=0; i<minLen; i++)
	{
		char ch = a[0][i];//用第一个字符串的字符来匹配所有的字符串
		for (int j=1; j<N; j++)
		{
			if (ch != a[j][i])//没有匹配上的情况
			{
				flag = true;
				break;
			}
		}
		if (flag) break;     //没匹配上就break
		sameLenth++;         //原来我写的是在break的时候赋值sameLenth = i;其实有可能会flag一直都是false i.e.最短的字符串全部匹配上啦
	}
	if (sameLenth == 0) cout<<"nai"<<endl;//匹配个数为0的情况
	else for (int i=sameLenth-1; i>=0; i--) cout<<a[0][i];
	return 0;
}















