# include <iostream>
using namespace std ;

int main ()
{
    int* parcel = new int ;
    int amount, newParcel;

    cout << "Enter initial number of parcels - " ;
    cin >> *parcel ;

    cout << "Enter number to add - " ;
    cin >> amount ;

    newParcel = *parcel + amount ;

    cout << "Number of parcels initially = " << *parcel ;
    cout << "Amount added - " << amount ;
    cout << "New amount of parcels - " << newParcel ;
    
    delete parcel ;
    parcel = nullptr ;

    return 0 ;

}