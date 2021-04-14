/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int N, K, L;
bool mine[50001] = {0};
long long int poss[50001][102] = {0};
int REMAIN = 1000000009;
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N >> K >> L;
		for (int l = 0; l < L; l++) {
			int index;
			cin >> index;
			mine[index] = true;
		}

		for (int n = 1; n <= N; n++) {
			if (mine[n] == true) {
				continue;
			}
			for (int k = 1; k <= K; k++) {
				if (n - k < 0) {
					break;
				}
				if (n == k) {
					poss[n][k] += 1;
				}
				poss[n][k] += poss[n-k][101] - poss[n-k][k];
				poss[n][101] += poss[n][k];
				poss[n][101] %= REMAIN;
			}
				// cout << n <<  " poss: " << poss[n][101] << "\n";
		}
		
		Answer = poss[N][101];
		for (int n = 1; n <= N; n++) {
		    mine[n] = 0;
		    for (int k = 1; k <= K; k++) {
		        poss[n][k] = 0;
		    }
				poss[n][101] = 0;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}