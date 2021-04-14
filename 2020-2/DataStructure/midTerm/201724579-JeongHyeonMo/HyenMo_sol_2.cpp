#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int N, Elems, value ; 
vector<int> fat;
int point_ij[7][2] ;

void print_fat( ){

  int row = 0 ;
  cout << "\n Elems = " << Elems << "\n" ;

  for(int i=0 ; i< Elems ; i++ ){
     cout << setw(3) << fat[i] ; 
  } // end of for( )

} // end of print_fat( )

void read_fat() {
    // int mi, mj ;
    cin >> N;
    Elems = 3*N - 2 ;
    for(int i = 0 ; i < Elems; i++){
        int tmp;
        cin >> tmp;
        fat.push_back(tmp);
    }
    print_fat();
    // for(int i=1 ; i <= 6; i++){
    //     cin >> mi >> mj ;
    //     point_ij[i][0] = mi ;
    //     point_ij[i][1] = mj ;
    // }

} // end of read_fat( )

void check_fat(){ 
    for(int k=1 ; k <= 6; k++){
        int a = point_ij[k][0];
        int b = point_ij[k][1];
        if (a > 0 && b > 0 && a <= N && b <= N) {
          if (a + 1 == b) {
              cout << fat[a - 1] << "\n";
          } else if (a == b) {
              cout << fat[a + N - 2] << "\n";
          } else if (a == b + 1) {
              cout << fat[b + N * 2 - 2] << "\n";
          } else {
            cout << "0\n";
          }
        } else {
          cout << "Error\n";
        }
    }

} // end of check_fat( )


int main() {
    read_fat() ;
    // check_fat() ; 
    return 0;
} // end of main( )