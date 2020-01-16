//
//  Header.h
//  CS31project5
//
//  Created by Ojas Bardiya on 2/27/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#ifndef Ticket_h
#define Ticket_h

#include <string>
#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>
using namespace std;

class Ticket
{
    public:
    enum KIND {ATHLETICGAME, CONCERT, MOVIE, OTHER};
    //constructor
    Ticket (string row, int seat, string event, string venue, double price, KIND kind, string daytime);
    
    //member functions
    //accessors
    string getRow();
    string getEvent();
    string getVenue();
    int getSeat();
    double getPrice();
    KIND getKind();
    string getDayTime();
    //mutators
    void setPrice (double price);
    
    // member variables
    private:
    string mRow;
    string mEvent;
    string mVenue;
    KIND mKind;
    double mPrice;
    int mSeat;
    string mDayTime;
};


#endif /* Header_h */
