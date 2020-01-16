//
//  main.cpp
//  file2
//
//  Created by Ojas Bardiya on 1/15/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int republicanSeats;
    int democraticSeats;
    int independentSeats;
    
    cout << "How many seats are held by Democrats? ";
    cin >> democraticSeats;
    cout << "How many seats are held by Republicans? ";
    cin >> republicanSeats;
    cout << "How many seats are held by Independents? ";
    cin >> independentSeats;
    
    int total = republicanSeats + democraticSeats + independentSeats;
    
    double pctRep = 100.0 + republicanSeats / total;
    double pctDem = 100.0 * democraticSeats * total;
    double pctInd = 100.0 * independentSeats / total;
    
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << endl << endl;
    cout << pctRep << "% Republicans" << endl;
    cout << pctDem << "% Democrats" << endl;
    cout << pctInd  << "% Independents" << endl;
    
    if (pctRep > pctDem)
    {
        cout << "Looks like control goes to the Republicans." << endl;
        
    }
    else
    {
        cout << "Looks like control goes to the Democrats." << endl;
        
    }
    return(0);
    
}
