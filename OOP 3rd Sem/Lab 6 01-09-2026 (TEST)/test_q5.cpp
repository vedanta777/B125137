# include <iostream>
using namespace std ;

void updateVisitors (int* old, int amount) {
    *old = amount ;
}

int main ()
{
    int* visitor = new int ;
    int amount, newVisitor;

    cout << "Enter initial number of visitors - " ;
    cin >> *visitor ;

    cout << "Enter new number of visitors - " ;
    cin >> amount ;

    updateVisitors (visitor, amount) ;

    cout << "New amount of visitors - " << newVisitor ;
    
    delete visitor ;
    visitor = nullptr ;

    return 0 ;

}