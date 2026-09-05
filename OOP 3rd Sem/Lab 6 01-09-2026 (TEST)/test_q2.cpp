# include <iostream>
using namespace std ;

int main ()
{
    int* balance = new int ;
    int amount1, amount2, newBalance1, newBalance2 ;

    cout << "Enter initial amount of balance - " ;
    cin >> *balance ;

    cout << "Enter amount to withdraw - " ;
    cin >> amount1 ;

    if (amount1 > *balance) {
        cout << "Invalid withdrawal amount !" ;
    }

    else {
        newBalance1 = *balance - amount1 ;

        cout << "Initial balance = " << *balance ;
        cout << "Amount added - " << amount1 ;
        cout << "New balance - " << newBalance1 ;
    }

    cout << "Enter amount to deposit - " ;
    cin >> amount2 ;

    newBalance2 = *balance + amount2 ;

    cout << "Initial balance = " << *balance ;
    cout << "Amount added - " << amount2 ;
    cout << "New balance - " << newBalance2 ;
    
    delete balance ;
    balance = nullptr ;

    return 0 ;

}