/*
*ʱ�䣺2018��4��11��18:43:40-
*��ţ�1003. ��Ҫͨ���� 
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������

������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� 
ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A 
��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ���
��ĸ A ��ɵ��ַ�����
���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�

�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������
������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��
����������

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

���������

YES
YES
YES
YES
NO
NO
NO
NO
*/
//˼·��֮ǰд����ϸע�Ͷ���notepad++��û�ˣ���������B1040��B1035��B1045�Ĵ���Ҳû��
//��дһ��˼·�ɣ���aΪP��ߵ�A�ĸ�����bΪP��T�м��A�ĸ�����cΪT�ұߵ�A�ĸ�����
//�ɷ���������������������c=ba�������ټ���һЩ������Լ�����������粻���г�PAT֮���������ĸ
//ֻ����1��P��T��T��λ��һ����P+1֮��
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
*ʱ�䣺2018��4��11��16:49:54-2018��4��11��17:41:54
*��ţ�1019. ���ֺڶ� 
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������

������һ����λ���ֲ���ȫ��ͬ��4λ����������������Ȱ�4�����ְ��ǵ��������ٰ��ǵݼ�����
Ȼ���õ�1�����ּ���2�����֣����õ�һ���µ����֡�һֱ�ظ������������Ǻܿ��ͣ���С����ֺڶ���
֮�Ƶ�6174��������������Ҳ��Kaprekar������

���磬���Ǵ�6767��ʼ�����õ�

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

�ָ�������4λ�����������д������ʾ����ڶ��Ĺ��̡�

�����ʽ��

�������һ��(0, 10000)�����ڵ�������N��

�����ʽ��

���N��4λ����ȫ��ȣ�����һ���������N - N = 0000�������򽫼����ÿһ����һ���������
ֱ��6174��Ϊ����֣������ʽ��������ע��ÿ�����ְ�4λ����ʽ�����
��������1��

6767

�������1��

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

��������2��

2222

�������2��

2222 - 2222 = 0000
*/
//˼·�������ѵ㵹�ǲ��࣬����ʵ���������������鷳���ر��м���Сbug�ѷ��֣����о���ע����ǰ�油0��
//��printf��ȽϷ���һЩ
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <stdio.h>
bool cmp(int a, int b)//��������
{
	return (a > b);
}

int increase(int a)
{
	vector <int> v(4);//������������ȽϷ��㣬��ʵ����������Ҳ��һ����
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
	if (decrease(num) - increase(num) == 0)//bug1��������ͬ��ʱ�������0000��������0
	{
		printf("%04d - ",decrease(num));
		printf("%04d = ",increase(num));	
		printf("0000\n");
	}
	else if (num == 6174)//bug2��Ϊ6174��ʱ��Ҫ���7641 - 1467 = 6174
	{
		printf("%04d - ",decrease(num));
		printf("%04d = ",increase(num));	
		printf("6174\n");
	}
	else
		while (num != 6174)//�������������ע���²�0�ͷ��ż�ӿո�Ϳ�����
		{
			printf("%04d - ",decrease(num));
			printf("%04d = ",increase(num));	
			printf("%04d\n",decrease(num)-increase(num));
			num = decrease(num)-increase(num);
		}	
	return 0;
}


/*
*ʱ�䣺2018��4��12��08:35:53
*��ţ�1049. ���е�Ƭ�κ�
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������
����һ���������У����ǿ��Դ��н�ȡ����������ļ���������ΪƬ�Ρ����磬��������
{0.1, 0.2, 0.3, 0.4}��������(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) 
(0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) ��10��Ƭ�Ρ�

�������������У����ȫ��Ƭ�ΰ��������е���֮�͡��籾����10��Ƭ���ܺ���
0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0��

�����ʽ��

�����һ�и���һ��������105��������N����ʾ���������ĸ������ڶ��и���N��������1.0��������
�������е���������Կո�ָ���

�����ʽ��

��һ�����������������Ƭ�ΰ�������֮�ͣ���ȷ��С�����2λ��
����������

4
0.1 0.2 0.3 0.4 

���������

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
*17�֣�����һ����û��,Ӧ���Ǿ��Ȳ�����,��д��һ������Ĵ��룬����ͨ��
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
*ʱ�䣺2018��4��12��15:25:44-
*��ţ�1034. ��������������
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������
����Ҫ���д���򣬼���2���������ĺ͡�������̡�

�����ʽ��

������һ���а��ա�a1/b1 a2/b2���ĸ�ʽ��������������ʽ�������������з��Ӻͷ�ĸȫ������
��Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0��

�����ʽ��

�ֱ���4���а��ա�������1 ����� ������2 = ������ĸ�ʽ˳�����2���������ĺ͡�������̡�
ע�������ÿ�������������Ǹ��������������ʽ��k a/b��������k���������֣�a/b�����������֣�
��Ϊ��������������ţ���������ĸΪ0���������Inf������Ŀ��֤��ȷ�������û�г������ͷ�Χ��������
��������1��

2/3 -4/2

�������1��

2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

��������2��

5/3 0/6

�������2��

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
//�������Ҽ������һ���ˣ�д�˰��Сʱ���Ϸ����ˣ���������ȷ��
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
*ʱ�䣺2018��4��13��08:22:04-2018��4��13��08:45:20
*��ţ�1007. �����Բ���
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������
�����Ƕ��� dn Ϊ��dn = pn+1 - pn������ pi �ǵ�i����������Ȼ�� d1=1 �Ҷ���n>1
�� dn ��ż�����������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

�ָ�������������N (< 105)������㲻����N���������������Եĸ�����

�����ʽ��ÿ�������������1����������������������N��

�����ʽ��ÿ���������������ռһ�У�������N���������������Եĸ�����
����������

20

���������

4
*/
//˼·��������Ŀ���Ǻ�ֱ�۵ģ�i��������i+2Ҳ������������һ�������ԣ�����Ҳ������һЩԼ��
//���ⲻ��ֱ��ȥ�������е������ر������ж�������ʱ�򣬶Գ���Ҫ��ƽ������Ȼ�ٶ�̫��
#include <iostream>
using namespace std;
#define Debug false
#include <math.h>
bool isSUSHU(int a)//�ж��Ƿ�Ϊ����
{
	int sqr = (int)sqrt(1.0 * a);//�����и�С���ɣ����ӿ��ٶȣ���Ȼ���һ�������ȥ
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
	for (int i=1; i<num; i+=2)//��Ŀ˵��dn��Ϊż������ô����һ�����������ⲻ�ǳ�ʶ��ɵ���ˣ�
	{						  //����Ҫ����ÿ�����������е����������˾������ˣ�Ҳ���Լӿ�һ�����ٶ�
		if(Debug) cout<<isSUSHU(i);
		if (i != 1 && isSUSHU(i) && isSUSHU(i+2) && i+2<=num)//Ҫ��֤i+2<=num
			sushudui++;
	}
	cout<<sushudui;
	return 0;
}



/*
*ʱ�䣺2018��4��13��21:29:16-2018��4��13��21:46:57
*��ţ�1013. ������
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������
��Pi��ʾ��i�����������θ�����������M <= N <= 104�������PM��PN������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�
����������

5 27

���������

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
//˼·��������жϷ�����֮ǰ�ǲ��ģ��ж�������ʱ��ļ��ɡ�
//���ǰѵ�һ������N��������ѹ����һ������������±��ڼ���������
//֮��ѵ�M������N��������ӡ��������
#include <iostream>
using namespace std;
#define Debug false
#include <math.h>
#include <vector>
bool isSUSHU(int a)//�ж��Ƿ�Ϊ����
{
	int sqr = (int)sqrt(1.0 * a);//�����и�С���ɣ����ӿ��ٶȣ���Ȼ���һ�������ȥ
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
	vector<int> v;//װ����������
	int num = 0;
	int i = 2;
	while(num != N)//��1��ʼÿ��ÿ�����ж��Ƿ�Ϊ�������ǵĻ���ѹ����������Ȼ���Դ�1=1��ʼ��i+=2�����
	{
		if(Debug) cout<<isSUSHU(i);
		if (isSUSHU(i))
		{
			v.push_back(i);//�ж�Ϊ������ѹ������
			num++;//��ǰ�ǵ�num������
		}	
		i++;	
	}		
	for (int i=M, j=1; i<=N; i++)//�����������ȻҪ��������ĸ�ʽ
	{
		if (i == N) 
		{
			cout<<v[N-1];//��i��������Ӧ���±���i-1
			break;//���һ�������֮�������ѭ������øպ��ǵ�ʮ��������س���
		}
		else if (j%10 == 0) cout<<v[i-1]<<endl;//ÿʮ��Ҫ�ӻس�������ĩβ�����пո�
		else cout<<v[i-1]<<" ";
		j++;
	}
	return 0;
}



/*
*ʱ�䣺2018��4��13��21:57:15-2018��4��13��22:22:33
*��ţ�B1017. A����B
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������
����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��
ʹ��A = B * Q + R������

�����ʽ��

������1�������θ���A��B���м���1�ո�ָ���

�����ʽ��

��1�����������Q��R���м���1�ո�ָ���
����������

123456789050987654321 7

���������

17636684150141093474 3

*/
//˼·�����⻹��д�ıȽ�����ģ���20�����ҵĴ�������һ������40���д�������⣬����һ��AC
//��Сѧѧ���ĳ������򣬶��ڱ������ĸ�λ��ʼ���γ��Գ�������������Ǹ�λ���ȽϺô���
//������������*10+��һλ�����ٳ��Գ�����ֱ��������ÿһλ������
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
	vector<int> v;//��������̵Ľ��
	int left = 0;
	for(int i=0; i<lenA; i++)
	{
		v.push_back((left * 10 + (A[i] - '0')) / B);//ÿһλ���˵Ľ��ѹ������
		left = (left * 10 + (A[i] - '0')) % B;//����֮�������
	}
	int len = v.size();
	for (int i=0; i<len; i++)
	{
		if(i==0 && v[0] == 0 && len > 1) continue;//�����һλΪ0�������̵Ľ�β����1λ����������һλ
		else if (i==0 && v[0] == 0 && len == 1) cout<<"0";//����̾�Ϊ0��������񲻼�Ҳû��ϵŶ
		else cout<<v[i];
	}
	cout<<" "<<left;//�ո��������ӡ�ȽϷ��㣬�ٴ�ӡ����
	return 0;
}		


/*
*ʱ�䣺2018��4��14��18:27:19-2018��4��14��19:45:47
*��ţ�B1044. ��������
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������
����������13���Ƽ����ģ�

�����˵�0�������˳�Ϊtret��
����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
�����˽���λ�Ժ��12����λ���ֱַ��Ϊ��
tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou�� 

��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����
Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��

�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ�
�����ǻ����ġ�

�����ʽ��

��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�
����������

4
29
5
elo nov
tam

���������

hel mar
may
115
13
*/
//˼·:������Ҫ������һ�����ֵ������ĺͻ����ĵ����ֵ�ӳ��
//num��str�ıȽϼ򵥣�ֱ�����±��Ӧ�Ϳ����ˣ�str��num�Ļ���map<string, num>
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
void mapInit()//169��ӳ���ϵ
{
	for (int i=0; i<13; i++)//����ĳһλΪ0��������ڶ�λ�������������Ϊ1λ������
	{
		num2str[i] = unitDigtal[i];
		str2num[num2str[i]] = i;
		num2str[i*13] = tenDigtal[i];
		str2num[num2str[i*13]] = i * 13;
	}
	for (int i =1; i<13; i++)//���Ϊ��λ������
	{
		for (int j=1; j<13; j++)
		{
			num2str[i*13+j] = tenDigtal[i] + " " + unitDigtal[j];
			str2num[num2str[i*13+j]] = i*13+j;
		}
	}
}
int a2i(string a)//д��һ���ַ�����int���͵�ת��
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
	scanf("%d%*c", &T); //%*��������ͱ�ʾ����������ͣ�����Ӧ�������������س���
	while(T--)
	{
		string str;
		getline(cin, str);//���ڱ����ո�
		if (Debug) cout<<str<<endl;
		if (str[0] >= '0' && str[0] <= '9')//����ת��Ϊ������
		{
			cout<<num2str[a2i(str)]<<endl;
		}
			
		else cout<<str2num[str]<<endl;//������ת��Ϊ����
	}
	
	return 0;
}


/*
*ʱ�䣺2018��4��14��19:48:52-2018��4��14��20:14:21
*��ţ�B1025. ��ת����
*���ԣ�C++ (g++ 4.7.2)
*������25
*��Ŀ������
����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת��
���磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4�����KΪ4��
�����Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)��
�Լ�������K(<=N)����Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��
����������

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

���������

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
//˼·��������������v1��v2��v1����ÿtrans��node��node������뵽v2��
//������v2����
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
		for (int i=0; i<pnum; i++)//���ڱ����ҵ���һ��node��������һ��˫��ѭ�������Ƴ�ʱ�ˣ�
		{
			if(pnext == node[i].head)
			{
				v1.push_back(node[i]);
				pnext = node[i].next;
				break;
			}			
		}
		if (v1.size() == trans)//ÿtrans��node��v1�е�node����ŵ�v2��
		{
			for ( int i=v1.size()-1; i>=0; i--)
				v2.push_back(v1[i]);
			v1.clear();//��������v1��������node
		}
	}
	for ( int i=0; i<v1.size(); i++)//��ʣ�µ�node������뵽v2��
		v2.push_back(v1[i]);
	for (int i=0; i<v2.size(); i++) //���������Ķ���ͷ��ַ����һ����ͷ��ַ����һ����β��ַ����û�иı�node��β��ַ
	{								//���һ����ַһ����-1���������
		if (i == v2.size()-1) printf("%05d %d -1\n", v2[i].head, v2[i].num);
		else printf("%05d %d %05d\n", v2[i].head, v2[i].num, v2[i+1].head);
	}
				
	return 0;
}


/*
*��������һֱ��ʱ���ȷ�һ�ţ�Ӧ����˫��ѭ��������
*/


/*
*ʱ�䣺2018��4��14��22:09:00
*��ţ�B1010. һԪ����ʽ��
*���ԣ�C++ (g++ 4.7.2)
*������25
*��Ŀ������
��ƺ�����һԪ����ʽ�ĵ�������ע��xn��nΪ��������һ�׵���Ϊn*xn-1����

�����ʽ����ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000����������
���ּ��Կո�ָ���

�����ʽ������������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ���
����β�����ж���ո�ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����
����������

3 4 -5 2 6 1 -2 0

���������

12 3 -10 1 6 0
*/
//˼·����������Ѱ����ֻ��ע���������ʽ��һЩ��������ͺã���Ȼ�һ���һ����û��
#include <iostream>
using namespace std;
#include <stdio.h>
#define Debug false
int main()
{
	int i = 0;
	int num[999999];//���ﵽ�׶��ٸ���Ҳ�����������������
	if (Debug)cout<<"begin";
	while (1)//������س�Ϊֹ��¼����ֵ�ļ���һ��Ҫ�ǵ�
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
		if (num[i+2] == '\0' && num[i+1] == 0) break;//�����кü������������������һλ����0�κ����һλ��0��֮��ģ����и�bugû�ҵ�
		else if (num[i+2] == '\0' && num[i+1] != 0) cout<<num[i]*num[i+1]<<" "<<num[i+1]-1;
		else cout<<num[i]*num[i+1]<<" "<<num[i+1]-1;
		if (num[i+4] != '\0' || num[i+3] != 0) cout<<" ";
		i += 2;
	}
	return 0;
}

/*
*���һ����û��
*/


/*
*ʱ�䣺2018��4��15��15:26:26-2018��4��15��16:07:04
*��ţ�B1022. D���Ƶ�A+B
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������

���������Ǹ�10��������A��B(<=230-1)�����A+B��D (1 < D <= 10)��������

�����ʽ��

������һ�������θ���3������A��B��D��

�����ʽ��

���A+B��D��������
����������

123 456 8

���������

1103
*/
//����ûʲô�ѵ㣬���ǰ��ս���ת���Ĺ�ʽд�ɴ����ok��
//����������
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
	for (int i=lenV-1; i>=0; i--)//�����������
	{
		cout<<v[i];
	}
	return 0;
}


/*
*ʱ�䣺2018��4��15��16:08:17-2018��4��15��16:33:46
*��ţ�B1037. �ڻ����ִ�����Ǯ
*���ԣ�C(gcc 4.7.2)
*������20
*��Ŀ������
������ǹ����������ԣ����֪��ħ�����������Լ��Ļ���ϵͳ ���� ���纣����߹����ģ�
��ʮ�߸�������(Sickle)��һ����¡(Galleon)����ʮ�Ÿ�����(Knut)��һ�����ɣ������ס�
�����ڣ���������Ӧ���ļ�ǮP����ʵ����ǮA�����������дһ��������������Ӧ�ñ��ҵ���Ǯ��

�����ʽ��

������1���зֱ����P��A����ʽΪ��Galleon.Sickle.Knut���������1���ո�ָ���
����Galleon��[0, 107]�����ڵ�������Sickle��[0, 17)�����ڵ�������Knut��[0, 29)�����ڵ�������

�����ʽ��

��һ������������ͬ���ĸ�ʽ�������Ӧ�ñ��ҵ���Ǯ�������û����Ǯ����ô�����Ӧ���Ǹ�����
��������1��

10.16.27 14.1.28

�������1��

3.2.1

��������2��

14.1.28 10.16.27

�������2��

-3.2.1
*/
//˼·������˼·�Ϻ���Ҳûʲô�ѵ㣬�������ж�һ���Ǹ���Ǯ�໹����Ҫ��Ǯ�࣬
//���Ǯ��������Ӧ����ȥ�Լ��е�Ǯ�ټ�һ��-�žͺ�
#include <stdio.h>

int main()
{
	int Galleon1, Sickle1, Knut1;//�۸�
	int Galleon2, Sickle2, Knut2;//�Լ���money
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
*ʱ�䣺2018��4��15��15:26:26-2018��4��15��16:07:04
*��ţ�B1050. ��������
*���ԣ�C++ (g++ 4.7.2)
*������20
*��Ŀ������
����Ҫ�󽫸�����N�����������ǵ�����˳�����롰�������󡱡���ν���������󡱣�
��ָ�����Ͻǵ�1�����ӿ�ʼ����˳ʱ������������䡣Ҫ�����Ĺ�ģΪm��n�У�
����������m*n����N��m>=n����m-nȡ���п���ֵ�е���Сֵ��

�����ʽ��

�����ڵ�1���и���һ��������N����2�и���N�����������������������ֲ�����104��
���������Կո�ָ���

�����ʽ��

�����������ÿ��n�����֣���m�С�����������1���ո�ָ�����ĩ�����ж���ո�
����������

12
37 76 20 98 76 42 53 95 60 81 58 93

���������

98 95 93
42 37 81
53 20 76
58 60 76
*/
//˼·���Ҿ������⻹����һ������ս�ģ�������̸̸˼·
//��һ���ѵ㣬����һ��N����ҵ���ֵ��С��m��n���ҿ�ʼ���뷨�Ƕ�ÿ��m�����õ�n����¼��ֵ��ȡ��С��һ�ԣ��ⲿ�ִ���Ҳ����
//������������Լ�����Ҳ���Ǻܺã���Ȼ��ʱ�ˣ�Ȼ�������ϵķ��������ҵ����ڵ��ڸ���N����С������Ȼ���������
//�ҵ��ĵ�һ�����Ա�N������m����
//�ڶ����ѵ㣬��ν���������������ֵ��
//�ҵķ����ġ���������˳���ÿһ��������û�б���ֵ��Ԫ�ؽ��н���ֵ
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
	m = ceil(1.0 * sqrt(N));//N��Ѱ��m��n
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
	sort (A, A+N, cmp);//����
	int B[m][n];
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
			B[i][j] = -1;//�ȱ��Ϊ��ֵ��Ԫ��Ϊ-1��֮�����Ԫ��ֻ����-1�Ÿ�ֵ����Ȼ��break
	}
	int i = -1;//������ֵҪ���������ʹ��
	int j = -1;
	int k = 0;
	while (k <= N-1)
	{
		for (i++,j++; j<n; j++)//��ʱ��j��ӵ�n������ѭ����������һ��Ҫ��j--��ʹ��j=n-1
		{
			if(B[i][j] == -1)
			{
				B[i][j] = A[k];
				k++;
				//printf("B[%d][%d] = %d.\n",i, j, B[i][j]);
			}
			else break;			
		}
		for (j--,i++; i<m; i++)//ǰ�����j--��j=n-1֮�⻹�и�i++����i�ȼ�һ������Ȼ�ͻص�ԭ����Ԫ����
		{
			if(B[i][j] == -1)
			{
				B[i][j] = A[k];
				k++;
				//printf("B[%d][%d] = %d.\n",i, j, B[i][j]);
			}
			else break;			
		}
		for (i--,j--; j>=0; j--)//������ԭ�����Ƶ�
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
	for (i=0; i<m; i++)//�������
	{
		for(j=0; j<n; j++)
		{
			if (j == n-1) printf("%d\n",B[i][j]);
			else printf("%d ",B[i][j]);
		}
	}
	return 0;
}






