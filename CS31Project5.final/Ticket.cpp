//
//  main.cpp
//  CS31project5
//
//  Created by Ojas Bardiya on 2/27/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//
#include "Ticket.h"
using namespace std;

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime)
{
    mRow = row;
    mEvent = event;
    mSeat = seat;
    mVenue = venue;
    mKind = kind;
    mDayTime = daytime;
    mPrice = price;
}

string Ticket::getRow()
{
    return (mRow);
}

string Ticket::getEvent()
{
    return (mEvent);
}

string Ticket::getVenue()
{
    return (mVenue);
}

int Ticket::getSeat()
{
    return (mSeat);
}

double Ticket::getPrice()
{
    return (mPrice);
}

Ticket::KIND Ticket::getKind()
{
    return (mKind);
}

string Ticket::getDayTime()
{
    return (mDayTime);
}

void Ticket::setPrice(double price)
{
    mPrice = price;
}









