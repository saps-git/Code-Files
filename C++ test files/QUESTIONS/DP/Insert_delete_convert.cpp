#include <bits/stdc++.h>
using namespace std;
/*
Algorithm: 

    str1 and str2 be the given strings.
    m and n be their lengths respectively.
    len be the length of the longest common subsequence of str1 and str2
    minimum number of deletions minDel = m – len
    minimum number of Insertions minInsert = n – l
*/
int lcs(string str1, string str2, int m, int n) // Returns length of lcs
{
	int dp[m+1][n+1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i==0 || j==0)
				dp[i][j] = 0;

			else if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}
int main()
{
	string str1 = "heap", str2 = "pea";
    int m = str1.size();
	int n = str2.size();

	int len = lcs(str1, str2, m, n);

	cout << "Minimum number of deletions = " <<(m-len)<< endl;
	cout << "Minimum number of insertions = "<<(n-len)<<endl;
}
