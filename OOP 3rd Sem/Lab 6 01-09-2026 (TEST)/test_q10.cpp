# include <iostream>
using namespace std ;

int main () 
{
    int n, search ;

    cout << "Enter number of students - " ;
    cin >> n ;

    int* student_id = new int [n] ;

    for (int i = 0 ; i < n ; i++) {
        *(student_id + i) = i*i + 1 ;
    }
    
    for (int i = 0 ; i < n ; i++) {
        cout << "ID of Student" << i+1 << " = " << *(student_id + i) ;
    }

    cout << "Enter Student ID to search - " ;
    cin >> search ;

    for (int i = 0 ; i < n ; i++) {
        if (search == *(student_id + i)) {
            cout << "ID found" ;
            break ;
        }
        cout << "ID not found" ;
    }

    delete[] student_id ;
    student_id = 0 ;

    return 0 ;
}