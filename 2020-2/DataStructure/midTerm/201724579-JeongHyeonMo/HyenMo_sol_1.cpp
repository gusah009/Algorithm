#include <bits/stdc++.h>
#include <stdio.h>
using namespace std ;

void print_2dvec( vector<vector<int>> T){
  cout << T.size() << "\n";
   for(auto A : T ) {
     cout << A.size() << " ";
        for(auto w : A ) {
            cout << w << " ";
        }
        cout << "\n";
   }
} // end of print_2dvec()

void read_2dvec(  vector<vector<int>> &T){
    int Lines, Elems, w ;
    T.clear();

    cin >> Lines ; 
    for(int i=1 ; i <= Lines ; i ++){
        cin >> Elems ;  
            vector<int> One = vector<int> () ;
              for( int j=1 ; j <= Elems ; j ++){
                    cin >> w ; 
                    One.push_back( w ) ; 
              }
        T.push_back( One ) ;
    }
} // end of read_2dvec( )

void rotate(vector< vector<int> > &T){
    vector <int> len;
    vector <int> vec1d;
    vector< vector<int> > D;
    bool state = false;
    for (auto it1 = T.begin(); it1 != T.end(); it1++) {
        len.push_back(it1->size());
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            vec1d.push_back(*it2);
        }
    }
    for (int i = 0; i < len.size(); i++) {
        if (len[i] != 0) {
            len[i]--;
            if (i != 0) {
                len[i-1]++;
            }
            if (i == 0) {
              state = true;
            }
        }
    }
    if (!vec1d.empty()) {
      if (state) {
        len[len.size() - 1]++;
        int tmp = vec1d[0];
        for (int i = 1; i < vec1d.size(); i++) {
            vec1d[i-1] = vec1d[i];
        }
        vec1d[vec1d.size() - 1] = tmp;
      }
    }
    D.resize(len.size());
    auto it = vec1d.begin();
    for (int i = 0; i < len.size(); i++) {
        for (int j = 0; j < len[i]; j++) {
            D[i].push_back(*it);
            it++;
        }
    }
    print_2dvec(D);
}

int main() {
    vector < vector<int> > D ;

    read_2dvec( D ) ;
    rotate( D ) ;

   return 0;
}
