#define  _CRT_SECURE_NO_WARNINGS 1
#include<string> 
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<iterator>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<set>
#include<map>
#include<cctype>
#include<functional>
#include<list>
using namespace std;




int main()
{
	
	long long n;
	cin >> n;
	vector<long long> num;
	for (long long i = 1; i*i <= n; i++)
	{
		if (n % i == 0)
			num.push_back(i);
		if (n / i != i)
			num.push_back(n / i);

	}
	long long  count = 0;
	for (auto i : num)
		for (auto b : num)
			for (auto c : num)
			{
				if (i * b * c == n)
					count++;
			}

	cout << count;



	//cout << 256 * 1024 * 1024 *8 / 32;
	//int n;
	//cin >> n;
	//int tmp = 1;
	//int z = 1;
	//int count = 0;
	//int flag = 0;
	//while (1)
	//{
	//	tmp = z;
	//	
	//	while (tmp)
	//	{
	//		if (tmp % 10 == 1)
	//			count++;
	//		if (count == n)
	//		{
	//			flag = 1;

	//			break;
	//		}
	//		tmp /= 10;
	//	}
	//	if (flag)
	//	{
	//		cout << z;
	//		break;
	//	}
	//	z++;




	//}


}