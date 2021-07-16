/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

using namespace std;

int Answer;

int main(int argc, char** argv)
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
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
		////////////////////////////////////////////////////////////////////////////////////////////
    int N;
    int arr[100000];
    int group[100000];
    int group_num = 0;

    cin >> N;
    FOR(n, N) {
      cin >> arr[n];
      group[n] = INF;
    }

    FOR(n, N) {
      if (group[n] == INF) {
        int curr = n;
        while (curr < N) {
          if (group[curr] != INF) {
            group_num--;
            break;
          }
          group[curr] = group_num;
          curr += arr[curr];
        }
        group_num++;
      }
    }
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << group_num << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}