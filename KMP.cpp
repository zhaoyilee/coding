/*
���ŵ�����������
ʱ�临�Ӷ�O(m*log(n))
�ռ临�Ӷ�O(n+m)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;

int N;//���鳤��
int n;//i�����ֵ
int m;//j�����ֵ
int p;//ģ��

vector<int> phi(m+1, 0);//phiֵ��phiֵphi[k]Ϊ<=k,����k���ʵ�����������
vector<int> A(n + 1);//A����

void calculate_phi(int num)
{   //����phiֵ,���Ӷ�ΪO(num*log(num))
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
{   //��������A��ֵ
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
	ll sum = 0;//�ۼӵĽ��
	for (int k = 1; ++k; k<= n)//k����[1,n]����gcd(i,j)���п��ܵ�ȡֵ
	{
		int cnt = 0;
		for (int j = k; j <= m; j+=k)//j����[1,m]����Լ��k����ôi��ȡֵ������j/k����
		{
			if (j <= n)//��ʱi,j ���Ա�� j,i ���Գ�2
			{
				cnt += phi[j / k] * 2;
			}
			else
			{
				cnt += phi[j / k];
			}
		}
		--cnt;//��ȥi==j���ظ����
		sum += cnt * A[k];
	}
	printf("%lld\n", sum);
}