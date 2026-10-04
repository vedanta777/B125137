# include <iostream>
using namespace std ;

int main () 
{
    int* book_shelf = new int [6] ;

    for (int i = 0 ; i < 6 ; i++) {
        *(book_shelf + i) = 10*i + i*i ;
    }
    
    for (int i = 0 ; i < 6 ; i++) {
        cout << "Book ID = " << *(book_shelf + i) ;
        cout << "Adress of Book ID Pointer - " << book_shelf + i ;
    }

    delete[] book_shelf ;
    book_shelf = 0 ;

    return 0 ;
}