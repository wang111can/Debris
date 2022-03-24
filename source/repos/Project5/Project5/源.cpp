

//#include<ctime>
#include"class.h"
#include<cmath>
#include<exception>
	void revse(char *l1,int len)
	{

		
		int left = 1;
		int right = len;
		if (left >= len)
			return;
		while (left < right)
		{
			char tmp = l1[left];
			l1[left] = l1[right];
			l1[right] = tmp;
			left++;
			right--;
		}
		left = 0;
		right = len;
		while (left < right)
		{
			char tmp = l1[left];
			l1[left] = l1[right];
			l1[right] = tmp;
			left++;
			right--;
		}


}
	int str(char* l1, char* l2)
	{
		int cot = strlen(l1);
		int len = cot - 1;
		while (cot--)
		{
			revse(l1, len);
			if (strcmp(l1, l2) == 0)
			{
				return 1;
			}
		}
		return 0;
	}	
	struct SO {
		char name[10];

	};
	void Swap(char*x,char*y,int sz)
	{
		for (int i = 0; i < sz; i++)
		{
			char tmp = *(x+i);
			*(x+i) = *(y+i);
			*(y+i) = tmp;
		}

}
	int tmp(const void* x, const void* y)
	{
		return strcmp((char*)x,(char*)y);
}


	void My_Sort(void* arr, int size, int typsz, int (*p)(const void* x, const void* y))
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (p((char*)arr+j*typsz,(char *)arr+(j+1)*typsz)>0)
				{
					Swap((char*)arr + j * typsz, (char*)arr + (j + 1) * typsz, typsz);
				}
			}
		}
}



	void test()
	{
		string arr[3] = { "ABC","abc","ABB" };
		My_Sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), tmp);
		for (auto x : arr)
			cout << x << " ";
	}
	
int main()
{
	string l1 = "1245";
	cout << l1.capacity();
	for (int i = 0; i < 28; i++)
	{
		l1 += i;
	}
	cout <<endl<< l1.size();


}


//
//#include <iostream>
//#include <string>
//#include <cctype>
//#include <ctime>
//#include <cstdlib>
//
//	using namespace std;
//
//	const int NUM = 26;
//
//	const string wordlist[NUM] = {
//		"apiary", "beetle", "cereal", "danger", "ensign", "florid",
//		"health", "insult", "jackal", "keeper", "loaner", "manage",
//		"nonce",  "onset",  "plaid",  "quilt",  "remote", "stolid",
//		"train",  "useful", "valid",  "whence", "xenon",  "yearn",
//		"zippy"
//	};
//
//	int main(void)
//	{
//		char play;
//
//		srand(time(0));
//		cout << "Will you play a word game? <y/n>";
//		cin >> play;
//		play = tolower(play);
//
//		while (play == 'y')
//		{
//			string target = wordlist[rand() % NUM];
//			int length = target.length();
//			string attempt(length, '-');
//			string badchars;
//			int guesses = 6;
//			cout << "Guess my secret word, it has " << length << " length letter, and you guess one letter at a time. You get " << guesses << " wrong guesses" << endl;
//
//			cout << attempt << endl;
//			while (guesses > 0 && attempt != target)
//			{
//				char letter;
//				cout << "Guess a letter: ";
//				cin >> letter;
//				if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
//				{
//					cout << "You have already guessed that, try again." << endl;
//					continue;
//				}
//				int loc = target.find(letter);
//				if (loc == string::npos)
//				{
//					cout << "Oh, bad guess!" << endl;
//					guesses--;
//					badchars += letter;
//				}
//				else
//				{
//					cout << "Good guess!" << endl;
//					attempt[loc] = letter;
//					loc = target.find(letter, loc + 1);
//					while (loc != string::npos)
//					{
//						attempt[loc] = letter;
//						loc = target.find(letter, loc + 1);
//					}
//				}
//				cout << "Your word: " << attempt << endl;
//				if (attempt != target)
//				{
//					if (badchars.length() > 0)
//						cout << "Bad choices: " << badchars << endl;
//					cout << guesses << " bad guesses left!" << endl;
//				}
//			}
//			if (guesses > 0 || attempt == target)
//				cout << "That is right!" << endl;
//			else
//			{
//				cout << "Sorry, the word is " << target << ", will you play another time?<y/n>";
//				cin >> play;
//				play = tolower(play);
//			}
//
//		}
//
//		return 0;
//	}


	/*char arr[] = "556";
	int a = atoi(arr);
	int cot = 0;
	int ox = 0;
	while (a)
	{
		ox +=+ (a % 10 )* (pow(8, cot));
		cot++;
		a /= 10;
	}
	cout << ox;*/
/*int cot = 21 * 3-2;
	int A = 5;
	int B = 6;
	int C = 7;
	for (int i = 1; i <= 21; i++)
	{
		if (C * i % B * i == 0 || C * i % A * i == 0 || B * i % A * i == 0)
		{
			cot--;
		}
	
	}

	cout << cot;
	*/


//舰队开炮

//蛇形数组
//int main()
//{
//	int arr[100][100];
//	int n;
//	cin >> n;
//	int mun = 1;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i, z = 0; j >= 0; j--, z++)
//		{
//			arr[j][z] = mun++;
//		}
//
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i; j++)
//			cout << arr[i][j] << ' ';
//		cout << endl;
//	}
//}