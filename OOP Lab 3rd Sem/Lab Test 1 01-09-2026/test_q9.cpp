# include <iostream>
using namespace std ;

int main () 
{
    int n, occupied, available ;

    cout << "Enter number of parking slots - " ;
    cin >> n ;

    int* parking_slot = new int [n] ;

    for (int i = 0 ; i < n ; i++) {
        if (i % 2 == 0) {
            *(parking_slot + i) = 1 ;
        }
        else {
            *(parking_slot + i) = 0 ;
        }
    }

    for (int i = 0 ; i < n ; i++) {
        if (*(parking_slot + i)) {
            occupied ++ ;
        }
        if (*(parking_slot + i)) {
            available ++ ;
        }
    }
    
    cout << "Occupied slots = " << occupied ;
    cout << "Available slots = " << available ;


    delete[] parking_slot ;
    parking_slot = 0 ;

    return 0 ;
}