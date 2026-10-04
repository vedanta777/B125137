# include <iostream>
using namespace std ;

int get_max (int* arr, int n) {
    int max = *arr ;
    for (int i = 0 ; i < n ; i++) {
        if (*(arr+i) > max) {
            max = *(arr+i) ;
        }
    }
    return max ;
}

int main () 
{
    int* grocery_bag = new int [7] ;

    for (int i = 0 ; i < 7 ; i++) {
        *(grocery_bag + i) = 10*i + i*i ;
    }
    
    for (int i = 0 ; i < 7 ; i++) {
        cout << "Price= " << *(grocery_bag + i) ;
    }

    get_max (grocery_bag, 7) ;

    delete[] grocery_bag ;
    grocery_bag = 0 ;

    return 0 ;
}