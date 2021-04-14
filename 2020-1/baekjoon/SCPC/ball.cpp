/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <math.h>
using namespace std;

double Answer;

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
		double PI = 3.14159265359;
    int R, S, E, N;
    double l[1000], r[1000], h[1000];
    cin >> R >> S >> E;
    cin >> N;
    for (int n = 0; n < N; n++) {
      cin >> l[n] >> r[n] >> h[n];
    }

    Answer += l[0] - S - R;
    for (int n = 0; n < N; n++) {
      Answer += (r[n] - l[n]);
      if (h[n] >= R) { 
        Answer += (h[n] - R)*2;
        Answer += PI * R;
      } else {
        Answer += 2*acos((R-h[n])/R)*R;
        Answer += 2*(R - sqrt(pow(R,2)-pow((R-h[n]),2)));
      }

      if (n != N - 1) {
        Answer += (l[n + 1] - r[n] - 2*R);
      }
    }
    Answer += E - r[N - 1] - R;

    cout << fixed;
    cout.precision(9);
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}