/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

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
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, K, M;
    // vector < vector<bool> > is_poss(1500);
    int is_poss[1500][1500] = {0};
    cin >> N >> K >> M;
    vector< pair<int, int> > horizon(K);
    vector< int > horizon2[2000];
    vector< int > horizon3[1500];
    vector< pair<int, int> > ans(M);
    for (int k = 0; k < K; k++) {
      cin >> horizon[k].first >> horizon[k].second;
    }
    for (int m = 0; m < M; m++) {
      cin >> ans[m].first >> ans[m].second;
    }
    
    int moving;
    for (int n = 0; n < N; n++) {
      moving = n + 1;
      for (int k = 0; k < K; k++) {
        if (horizon[k].first == moving) {
          horizon2[k].push_back(moving);
          horizon3[n+1].push_back(k);
          moving = horizon[k].second;
        } else if (horizon[k].second == moving) {
          horizon2[k].push_back(moving);
          horizon3[n+1].push_back(k);
          moving = horizon[k].first;
        }
      }
    }

    // for (int k = 0; k < K; k++) {
    //   if (horizon2[k].size() != 1) {
    //     cout << "k: " << k << " size: " << horizon2[k].size() << "\n";
    //   }
    // }
    for (int n = 0; n < N; n++) {
      for (int n = 0; n < N; n++) {

      }
    }
    for (int m = 0; m < M; m++) {

    }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}