# include <iostream>
using namespace std ;

int main () 
{
    int n ;

    cout << "Enter number of players - " ;
    cin >> n ;

    int* player = new int [n] ;

    for (int i = 0 ; i < n ; i++) {
        *(player + i) = 10*i + i*i ;
    }
    
    for (int i = 0 ; i < n ; i++) {
        cout << "Player score = " << *(player + i) ;
    }

    for (int i = 0 ; i < n ; i++) {
        *(player + i) += 10 ;
    }
    
    for (int i = 0 ; i < n ; i++) {
        cout << "New Player score = " << *(player + i) ;
    }

    delete[] player ;
    player = 0 ;

    return 0 ;
}