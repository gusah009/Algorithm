#include <bits/stdc++.h>
using namespace std ;

int N ;
vector <stack<int>> YARD ;

void read_yard( ) ;
void show_yard( vector <stack<int>> ) ;

int main() {

    read_yard( ) ;
    // show_yard( YARD ) ;
    int high = 0, low = 987654321;
    if (!YARD.empty()) {
      for (int i = 0; i < N; i++)
      {
        high = max(high, (int)YARD[i].size());
        low = min(low, (int)YARD[i].size());
      }
      while(high - low > 1) {
        int maximum = 0;
        pair<int,int> contain = make_pair(0, -1);
        for (int i = 0; i < N; i++)
        {
          if (YARD[i].size() == high) {
            if(contain.first < YARD[i].top() ) {
              contain.first = (int)YARD[i].top();
              contain.second = i;
            }
          }
        }
        YARD[contain.second].pop();
        for (int i = 0; i < N; i++)
        {
          if (YARD[i].size() == low) {
            YARD[i].push(contain.first);
            break;
          }
        }
        high = 0, low = 987654321;
        for (int i = 0; i < N; i++)
        {
          high = max(high, (int)YARD[i].size());
          low = min(low, (int)YARD[i].size());
        }
      }
    }
    show_yard( YARD ) ;
    return(0) ;

} // end of main( )


void read_yard( ) {
    int index, elems, value ;
    cin >> N ;
    stack<int> mystk ;

    for(int i=1 ; i <= N; i++){
        mystk = stack<int>() ;
        cin >> elems ;
        for(int j = 1; j <= elems ; j++) {
            cin >> value ;
            mystk.push( value ) ;
        }
        YARD.push_back( mystk ) ;
    }

} // end of read_yard( )

void show_yard( vector<stack<int>> OUT ){
    int i, val ;
    stack <int> stemp ;
    i=0 ;

    for(auto w : OUT ) {
        stemp = stack<int>()  ;
        while( !w.empty()) { //body
           val = w.top( ) ;
           stemp.push( val ) ;
           w.pop();
        } // end of while( )

        while( !stemp.empty()) { //body
           val = stemp.top( ) ;
           cout<< val  << " " ;
           stemp.pop();
        } // end of while( )
        cout <<"\n" ;

    } // end of for( w )

 } // end of print_yard( )