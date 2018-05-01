//�Ҽ�ˢ��ǰ50�⣬���ڿ�ʼˢ�׼�����ȡ��8-9�·ݰ�PAT�׼�������
/*
*ʱ�䣺2018��4��17��20:24:18-2018��4��17��21:02:30
*��Ŀ��1042.Shuffling Machine
*������20
*��������g++
*��Ŀ������
Shuffling��ϴ�ƣ� is a procedure used to randomize a deck of playing cards. 
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
//˼·������Ӣ��ѽ����Ŀ������һ�ᡤ����
//����˼·���ǲ��ѣ������Ƚ�����һ��ԭʼ��˳�����飬Ȼ����һ����ʱ�����������ÿ�α任������
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
			temp[order[j]-1] = initOrder[j];//tempΪ�任������飬��ʾtemp�ĵ�order[j]-1��Ԫ��ΪinitOrder[j]
		}
		for (int j=0; j<54; j++)//�ٰ�initOrder������temp��ֵ
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
*ʱ�䣺2018��4��20��11:06:04-2018��4��20��11:32:38
*��Ŀ��1046.Shortest Distance
*������20
*��������g++
*��Ŀ������
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
//˼·��������cycle����·�������������򣬳�·���С��Ϊ������
//�����������·�����ٺ���·����ȥ�������·�����Աȣ��ĸ�Сȡ�ĸ�
//Ϊ�˷�ֹ��ʱ����·������һ����������ʾ��1����ǰ·���µ�·��֮��
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
		sum[i+1] = sum[i] + distance[i];//sum[i]��ʾ1��i-1��·��֮��
	}
	cin>>M;
	int exits[2 * M];
	for (int i=0; i<2*M; i++)
		cin>>exits[i];
	for (int i=0; i<M; i++)
	{
		int a = max(exits[2*i], exits[2*i+1]);
		int b = min(exits[2*i], exits[2*i+1]);
		int temp = sum[a-1] - sum[b-1];//����·��
		if (temp < sum[N] - temp) cout<<temp<<endl;
		else cout<<sum[N] - temp<<endl;	
	}	
	return 0;
}



/*
*ʱ�䣺s2018��4��20��12:52:03-2018��4��20��13:18:47
*��Ŀ��1065.A+B and C (64bit)
*������20
*��������g++
*��Ŀ������
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
//����Ĺؼ�����long long ����װ��������ô����long long�ķ�Χ��[-2^63, 2^63)
//����A, B and C in [-2^63, 2^63]������A+B������2^64����long longװA��B�Ļ��ᳬ����Χ
//1�����A��B������������ô���ֵΪ2^64-2,������Χ֮���Ϊ[-2^63�� -2]��<0������A B ������������Ϊ�������ж�Ϊtrue��C�����ܳ�����Χһ����A+BС��
//2�����A��B���Ǹ�������ô���ֵΪ-2^64,������Χ֮���Ϊ[0��2^63]��>=0������A B ���Ǹ�������>=0���ж�Ϊfalse��C�����ܳ�����Χһ����A+BС��
//3������İ���������ж�
//����˼·�ο����㷨�ʼǡ�
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
		long long  res = num[i][1] + num[i][0]; //�ܹؼ����ͱ�����long long���ͣ�Ҳ���Լ�����֮��ǿ������ת��
		if (num[i][0]>0 && num[i][1]>0 && res<0) cout<<"Case #"<<i+1<<": true"<<endl;//���1
		else if (num[i][0]<0 && num[i][1]<0 && res>=0) cout<<"Case #"<<i+1<<": false"<<endl;//���2
		else if (res > num[i][2]) cout<<"Case #"<<i+1<<": true"<<endl;//���3
		else cout<<"Case #"<<i+1<<": false"<<endl;
	}
	
	return 0;
}




/*
*ʱ�䣺2018��4��21��16:41:04-2018��4��21��17:29:25
*��Ŀ��1002.A+B for Polynomials 
*������25
*��������g++
*��Ŀ������

This time, you are supposed to find A+B where A and B are two polynomials������ʽ��.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line 
contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the
 number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents 
 and coefficients, respectively. It is given that 1 <= K <= 10��0 <= NK < ... < N2 < N1 <=1000.

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
//˼·�������ɢ��˼�룬�����±�����������ֵΪ���������������ϵ��
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
	for (int i=0; i<max(N, M); i++)//��������������ȫ
	{
		if (i < 2 * M) coe[(int)polyA[2*i]] += (double)polyA[2*i+1];//i<2MҪע�⣬��Ȼ�����Խ��
		if (i < 2 * N) coe[(int)polyB[2*i]] += (double)polyB[2*i+1];//����������
	}
	int len = 0;
	for (int i=0; i<1010; i++)//������ĸ���
	{
		if (coe[i] != 0) len++;
		//cout<<i<<" "<<coe[i]<<endl;
	}
	if (len == 0) cout<<"0";
	else cout<<len<<" ";
	int temp = 0;
	for (int i=1009; i>=0; i--)
	{
		if (temp == len - 1 && coe[i] != 0) printf("%d %.1f", i, coe[i]);//С���ɣ���ʾ���һ�����������ĸ�ʽע��һ��
		else if (coe[i] != 0) 
		{
			printf("%d %.1f ", i, coe[i]);
			temp++;
		}	
	}
	return 0;
}


/*
*ʱ�䣺2018��4��21��20:55:35-2018��4��21��21:03:58
*��Ŀ��1009.Product of Polynomials
*������25
*��������g++
*��Ŀ������
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
//˼·������������һ������Ͼͺ��Ĳ��ָ�һ�¾�OK�ˣ�����Ӹ㶨������ʽ�˷��ķ���
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
	for (int i=0; i<M; i++)//������˸�˫��ѭ����ԭ����Ϊ�ᳬʱ�ģ����ȫ��AC
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
*ʱ�䣺2018��4��22��20:31:13-2018��4��22��20:56:27
*��Ŀ��1011.World Cup Betting
*������20
*��������g++
*��Ŀ������
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

//˼·��ע��С���������λ����������
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
				mark = j; //mark 0��1��2�ֱ��ʾW��T��L
			}
		}	
		if (mark == 0) cout<<"W ";
		else if (mark == 1) cout<<"T ";
		else cout<<"L ";
	}
	//�������봦��
	double Profit = (double)(beilvMax[0] * beilvMax[1] * beilvMax[2] * 0.65 - 1) * 2;//����ӯ��ֵ
	if (Profit*100 - int(Profit*100) >= 0.5) Profit += (double)0.01;//��ΪҪ�Ƚ�С��������λ�Ƿ�����壬һ�㷽����̫�ñȽ�
	printf("%.2f", Profit);                                         //�����Ȱ����Ŵ�100��double���͵��������ȥint���Ϳ��Ƿ����0.5���ɡ�
		
	return 0;
}



/*
*ʱ�䣺2018��4��22��20:57:50-2018��4��22��21:19:56
*��Ŀ��1006.Sign In and Sign Out
*������25
*��������g++
*��Ŀ������
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
//˼·��һ��ʼ�Լ���Ĳ���㣬û����sort������д��д�ŷ���д���鷳�ˣ�������д����sort��cmp�ȽϿ��
//���ݶ�������ֱ�Ƚ�sign in ������ʱ�䰴������һ�Σ����stu[0].ID
//�ٱȽ�sign out �����ʱ�䣬��������һ�Σ����stu[0].ID
#include <iostream>
using namespace std;
#include <string.h>
#include <algorithm>
#include <stdio.h>
struct student//����ÿ���˵�һ���ṹ��
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
		scanf("%d:%d:%d",&stu[i].sign_in[0], &stu[i].sign_in[1], &stu[i].sign_in[2]);//scanf���Ǻ��ã�ǧ��ǵü�&
		scanf("%d:%d:%d",&stu[i].sign_out[0], &stu[i].sign_out[1], &stu[i].sign_out[2]);
	}
	sort(stu, stu+N, cmp_sign_in);//sign in ����
	cout<<stu[0].ID<<" ";
	sort(stu, stu+N, cmp_sign_out);//sign out ����
	cout<<stu[0].ID;
	return 0;
}



/*
*ʱ�䣺2018��4��23��19:57:53-2018��4��23��20:16:37
*��Ŀ��1036.Boys vs Girls
*������25
*��������g++
*��Ŀ������
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
//˼·��������˼·��ûʲô�ѵģ�Ҳûʲô�ر�ĸ�ʽҪ��ֻҪ��΢ϸ��һЩ�Ϳ���
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
	int Fgrade = 0;//��¼Ů����߷�
	int Mgrade = 100;//��¼������ͷ�
	int Fseq = -1;//��¼Ů����߷ֵ�ѧ���ı��
	int Mseq = -1;//��¼������ͷֵ�ѧ���ı��
	for (int i=0; i<N; i++)
	{
		if (stu[i].gender == 'F')
		{
			if (stu[i].grade > Fgrade)//��¼Ů����߷�
			{
				Fgrade = stu[i].grade;
				Fseq = i;
			}
		}
		else//��¼������ͷ� 
		{
			if (stu[i].grade < Mgrade)
			{
				Mgrade = stu[i].grade;
				Mseq = i;
			}
		}
	}
	if (Fseq == -1) cout<<"Absent"<<endl; else cout<<stu[Fseq].name<<" "<<stu[Fseq].ID<<endl;//��Ż���Ϊ-1�Ļ���ʾû�м�¼��Ů������Abeset
	if (Mseq == -1) cout<<"Absent"<<endl; else cout<<stu[Mseq].name<<" "<<stu[Mseq].ID<<endl;
	if (Mseq == -1 || Fseq == -1) cout<<"NA"<<endl; else cout<<stu[Fseq].grade-stu[Mseq].grade<<endl;//����һ���Ա�û�м�¼����ţ���NA
	return 0;
}



/*
*ʱ�䣺2018��4��23��20:28:33-2018��4��23��20:50:20
*��Ŀ��1031.Hello World for U
*������20
*��������g++
*��Ŀ������
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
//˼·��������΢��һ��n1��n2��n3��ֵ�Ϳ����ˣ���Ŀ��˵n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N }
//����n1 = n3 = ��N+2��/3; N+2�Ǳ�ʾ�������������ص��ģ�һ��n1�У�n2�У�ǰ��n1-1���м��n2-2���ո�
#include <iostream>
using namespace std;
#include <string.h>
#define Debug false
int main()
{
	string str;
	cin>>str;
	int len = str.size();
	int n1 = (len+2) / 3;//����n1,n3
	int n3 = n1;
	int n2 = len + 2 - n1 - n3;//����n2����ʵ�ⲿ�ǿ��Բ������ֱ����len - n1 - n2�Ϳ��Եõ�space�ĸ��� 
	int spaceNum = n2 -2;
	if (Debug) cout<<"n1:"<<n1<<" n2:"<<n2<<" n3:"<<n3<<" spaceNum:"<<spaceNum<<endl;//Debug,�������������ǰ����㣬������б�Ҫ
	for (int i=0; i<n1; i++)
	{
		if (i != n1-1)//ǰn-1��
		{
			cout<<str[i];//������еĵ�һ��
			for (int j=0; j<spaceNum; j++)//����м��space
				cout<<" ";
			cout<<str[len-1-i]<<endl;//������е����һ��
		}
		else
			for (int i=n1-1; i<n1+1+spaceNum; i++)//��n1�����⴦�����n1-1��n1+spaceNum��spaceNum+2��Ҳ����n2�����ַ�
				cout<<str[i];	
	}
	
	return 0;
}



/*
*ʱ�䣺2018��4��24��21:14:40-2018��4��24��22:21:13
*��Ŀ��1019.General Palindromic Number
*������20
*��������g++
*��Ŀ������
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
//˼·��һ���ѶȲ������Ŀ����д����������������ʼ׷���ķ�����ȥ�ҽ���ת���ĺ����������²�̫���ף�atoi��linux�¾�û�ж���
//������������ʵʵ�Լ�д����ת�������ˣ��������ﻹ��һ��Ľ���ת������ͳ��16���Ƴ���10����ABCDEF�ˣ�����char���͵ģ�����int���͵�
//�����������Ҫ��int���͵ģ����Ǹ�ע���
#include <iostream>
using namespace std;
#define Debug false
void Ntob(long N, long b, int* buff)//����ת������
{
	int shang = N;
	int res; 
	int i = 0;
	do {//do while();��䰡������������֮�صġ������Ϳ��Լ���һ������Ϊ0��ʱ���������뵽buff��
		res = shang % b;
		shang = shang / b;
		buff[i++] = res;//С���ɣ�ֱ����i++�����Ǻ���i=i+1�ģ�ע���++i������
		if (Debug) cout<<"shang="<<shang<<" res="<<res<<" i="<<i<<" buff[i]="<<buff[i]<<endl;		
	}while (shang);
}
int main()
{
	long N;
	long b;
	cin>>N>>b;
	int buff[100];
	for (int i=0; i<100; i++) buff[i] = -1;//�˷��˼������ж�buff�ĳ����ϣ���ʵ���Լ��ɵ�Ntob������ȥ��
	Ntob(N, b, buff);
	int len = 0;
	if (Debug) for (int i=0; i<100; i++) cout<<buff[i]<<" ";
	while (buff[len] != -1)
		len++;
	if (Debug) cout<<"len="<<len<<endl;
	bool flag = true;
	for (int i=0; i<len/2; i++)//�ж��Ƿ�Ļػ�������ʵ����д��һ��bool���͵ĺ��������ж�
	{
		if (buff[i] != buff[len-1-i])
		{
			flag = false;
			break;
		}
	}
	if (flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for (int i=len-1; i>=0; i--)//���ڽ���ת������Ҫ����
	{
		if (i == 0) cout<<buff[0];
		else cout<<buff[i]<<" ";
	}
	return 0;
}


/*
*ʱ�䣺2018��4��26��22:07:23-2018��4��26��22:31:55
*��Ŀ��1027.Colors in Mars
*������20
*��������g++
*��Ŀ������
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
//˼·���������ͨ�Ľ���ת�������һ���ѵ����Ҫ�Լ�д���ABC����Ȼ���뵽�˼���һ��13���Ƶ�����
//����ö�ٵĻ��о�����߶�һЩ
#include <iostream>
using namespace std;
#include <vector>
char radix13[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};//13���Ƶ�����
void printRadix13(int a)//��ӡ13���Ƶ���
{
	vector<int> v;//Ϊ�˵����ӡ
	int shang = a;
	int res;
	do{
		res = shang % 13;
		shang = shang / 13;
		v.push_back(res);	
	}while(shang);
	if (v[1] == '\0') cout<<"0"<<radix13[v[0]];	//�����һλΪ0�����
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
*ʱ�䣺2018��4��26��22:36:17-2018��4��26��22:43:24
*��Ŀ��1058.A+B in Hogwarts
*������20
*��������g++
*��Ŀ������
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
//˼·������էһ����PAT�Ҽ���������Ǯ��һ�����������⻹������һ�㣬�����������˵�
//�������������£�������Ȼ����������ÿ�λ��ǻ����µ��뷨
#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	int a[3];
	int b[3];
	int c[3];
	int flag = 0;
	scanf("%d.%d.%d %d.%d.%d",&a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);//����scanf
	c[2] = (a[2] + b[2]) % 29;//����λ����
	flag = (a[2] + b[2]) / 29;//�����λ����������
	c[1] = (a[1] + b[1] + flag) % 17;
	flag = (a[1] + b[1] + flag) / 17;
	c[0] = (a[0] + b[0]) + flag;
	cout<<c[0]<<"."<<c[1]<<"."<<c[2];
	
	return 0;
}


/*
*ʱ�䣺2018��4��29��20:30:52-2018��4��29��20:49:21
*��Ŀ��1001.A+B Format
*������20
*��������g++
*��Ŀ������
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
//˼·����sum�ֿ���ÿ��λ�ȽϺô���һ��ʼ��δӸ�λ��ʼÿ��λ���һ�����ſ�ס�ˣ�ӦΪ���Ƕ��ǴӸ�λ��ʼ�������λ��
//���������£��������������λ����3�ı������������һ�����žͿ�����
#include <iostream>
using namespace std;
#include <vector>
int main()
{
	long a;
	long b;
	cin>>a>>b;
	long sum = a + b;
	if (sum < 0)//sumС��0���������������������ȽϷ���
	{
		cout<<"-";
		sum = -sum;
	}
	vector<int> v;
	if (sum == 0) cout<<"0";//sumΪ0�����
	while (sum)//��sum�ֳ�ÿ��λ
	{
		v.push_back(sum % 10);
		sum = sum / 10;
	}
	for(int i=v.size()-1; i>=0; i--)
	{
		cout<<v[i];
		if(i%3 == 0 && i != 0) cout<<",";//λ����3�ı����ĺ����һ������
	}
	return 0;
}





/*
*ʱ�䣺2018��4��29��20:54:07-2018��4��29��21:08:55
*��Ŀ��1005.Spell It Right 
*������20
*��������g++
*��Ŀ������
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
//˼·����һ�����飬���ֶ�Ӧ��Ӧ��Ӣ�ģ��Ѻͷֳ�ÿ��λ���Ӹߵ������ÿ��λ��Ӧ��Ӣ�ľ�ok
#include <iostream>
using namespace std;
#include <string>
#include <vector>
string digChar[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
	string num;//���ַ��������������������
	cin>>num;
	int sum = 0;
	for (int i=0; i<num.size(); i++)//��ÿ��λ������
		sum += num[i] - '0';
	vector<int> v;
	if (sum == 0) cout<<digChar[0];
	while(sum)//������֮����ֳַ�ÿ��int��λ
	{
		v.push_back(sum % 10);
		sum /= 10;
	}
	for (int i=v.size()-1; i>=0; i--)//���ÿ��λ��Ӧ��Ӣ�ģ�ע��һ�����Ҫ�ո�
	{
		if(i == 0) cout<<digChar[v[0]];
		else cout<<digChar[v[i]]<<" ";
	}
	return 0;
}


/*
*ʱ�䣺2018��4��29��21:10:40-2018��4��29��21:39:36
*��Ŀ��1035.Spell It Right 
*������20
*��������g++
*��Ŀ������
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
//˼·����ÿ���������������������Ƿ���1i0O���ĸ��ַ����оͰ��չ���ĵ�
//û��һ������Ҫ�ĵĻ�һ��Ҫע�ⵥ������are��accounts
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
	vector<int> modifiedID;//�Ķ����ı��
	for (int i=0; i<N; i++)
	{
		cin>>usr[i].name>>usr[i].pw;
		int modifiedNum = usr[i].pw.size();
		for (int j=0; j<usr[i].pw.size(); j++)//��ÿ��pw���б���
		{
			//cout<<"modifiedNum: "<<modifiedNum<<endl;
			if (usr[i].pw[j] == '1') usr[i].pw[j] = '@';
			else if(usr[i].pw[j] == 'l') usr[i].pw[j] = 'L';
			else if(usr[i].pw[j] == '0') usr[i].pw[j] = '%';
			else if(usr[i].pw[j] == 'O') usr[i].pw[j] = 'o';
			else modifiedNum--;//�������0��ʾû��һ���ַ���Ҫ�޸ĵ�
		}
		if (modifiedNum) modifiedID.push_back(i);//û�м���0���Ͱ�������ѹ�뵽�Ķ����ı��
	}
	if (modifiedID.size() == 0 && N == 1) cout<<"There is "<<N<<" account and no account is modified"<<endl;//����is��account
	else if (modifiedID.size() == 0 && N >1) cout<<"There are "<<N<<" accounts and no account is modified"<<endl;//ע�ⵥ����ѽ��are��accouts
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
*ʱ�䣺2018��4��30��21:41:49-2018��4��30��22:35:54
*��Ŀ��1077.Kuchiguse  
*������20
*��������g++
*��Ŀ������
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

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix����׺�� of all N lines. 
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
//˼·��������Ŀ���������ǱȽ�����˼�ģ���ʵ����һ������׺���õ�һ���ַ���ȥƥ�����е��ַ�������Ҫ�м����ѵ㣺
//1������Ϊ���ո��char���͵����飬��Ҫע����cin֮���и��س���Ҫ��getchar();ȥ����Ȼ��ÿ��char���͵�������gets(a[i]);�Ϳ�����
//2��Ҫ��¼һ����С�ĳ��ȣ���Ȼ�ᳬ��һ�����ȼ���ƥ�䣬���ܻ�ƥ�䵽'\0'���������׳�ʱ
//3�������鷴������ƥ��ǰ׺���Է�ֹ��ʱ�����һ��ü�һЩ
//4���Լ���һЩС�Ĳ��õ�ϰ�߻����һЩ���Ѳ��ҵĴ��󣬱���������Ӧ������̵��Ǹ��ַ�ȫ��ƥ�����ˣ��Ͳ�����break��ʱ�����sameLenth = i;
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
	getchar();//ȥ��cin�����'\n'�������׺���
	for (int i=0; i<N; i++)
	{
		gets(a[i]);
		if (strlen(a[i]) < minLen) minLen = strlen(a[i]);//�õ�һ����С�ַ����ĳ���
		for (int j=0; j<strlen(a[i])/2; j++)//��ת����
		{
			char temp = a[i][j];
			a[i][j] = a[i][strlen(a[i])-j-1];
			a[i][strlen(a[i])-j-1] = temp;
		}
	}
	int sameLenth = 0;
	bool flag = false;//�Ƿ���û��ƥ���ϵģ���λtrue
	for (int i=0; i<minLen; i++)
	{
		char ch = a[0][i];//�õ�һ���ַ������ַ���ƥ�����е��ַ���
		for (int j=1; j<N; j++)
		{
			if (ch != a[j][i])//û��ƥ���ϵ����
			{
				flag = true;
				break;
			}
		}
		if (flag) break;     //ûƥ���Ͼ�break
		sameLenth++;         //ԭ����д������break��ʱ��ֵsameLenth = i;��ʵ�п��ܻ�flagһֱ����false i.e.��̵��ַ���ȫ��ƥ������
	}
	if (sameLenth == 0) cout<<"nai"<<endl;//ƥ�����Ϊ0�����
	else for (int i=sameLenth-1; i>=0; i--) cout<<a[0][i];
	return 0;
}















