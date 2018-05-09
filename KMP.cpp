/*
美团点评编程题题解
时间复杂度O(m*log(n))
空间复杂度O(n+m)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;

int N;//数组长度
int n;//i的最大值
int m;//j的最大值
int p;//模数

vector<int> phi(m+1, 0);//phi值表，phi值phi[k]为<=k,并与k互质的正整数个数
vector<int> A(n + 1);//A数组

void calculate_phi(int num)
{   //计算phi值,复杂度为O(num*log(num))
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= num; ++i)
	{
		for (int j = i; j <= num; j += i)
		{
			if (phi[j] == 0)phi[j] = j;
			phi[j] = (ll)phi[j] * (i - 1) / i;
		}
	}
}

void calculate_A(int num)
{   //计算数组A的值
	A[1] = p;
	int tmp = 153 % p;
	for (int i = 2; i <= num; ++i)
	{
		A[i] = (i%p)*tmp % p;
	}
}

int main()
{
	scanf("%d%d%d%d", &N, &n, &m, &p);
	if (n > m)swap(n, m);
	calculate_phi(m);
	A.resize(n + 1);
	calculate_A(n + 1);
	ll sum = 0;//累加的结果
	for (int k = 1; ++k; k<= n)//k属于[1,n]代表gcd(i,j)所有可能的取值
	{
		int cnt = 0;
		for (int j = k; j <= m; j+=k)//j属于[1,m]含有约数k，那么i的取值必须与j/k互质
		{
			if (j <= n)//此时i,j 可以变成 j,i 所以乘2
			{
				cnt += phi[j / k] * 2;
			}
			else
			{
				cnt += phi[j / k];
			}
		}
		--cnt;//除去i==j的重复情况
		sum += cnt * A[k];
	}
	printf("%lld\n", sum);
}