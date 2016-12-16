#include<iostream>
#include<string>

using namespace std;

const int MAX_LEN = 1000005;

int suffix[MAX_LEN];

void GetSuffix(string s)
{
	suffix[0] = -1;
	suffix[1] = 0;

	int k = 0;
	for (int i = 2; i <= s.length(); i++)
	{
		while (k >= 0 && s[k] != s[i - 1])
			k = suffix[k];
		suffix[i] = ++k;
	}
}


int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.compare(".") == 0)
		{
			break;
		}
		memset(suffix, 0, MAX_LEN);
		GetSuffix(str);

		int ans;
		int len = str.length();
		if (len % (len - suffix[len]))
		{
			ans = 1;
		}
		else
		{
			ans = len / (len - suffix[len]);
		}
		cout << ans << endl;
	}
	return 0;
}

