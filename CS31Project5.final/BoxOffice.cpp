//
//  BoxOffice.cpp
//  CS31project5
//
//  Created by Ojas Bardiya on 2/27/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include "Ticket.h"
#include "BoxOffice.h"
#include "Project5Helper.h"
using namespace std;


BoxOffice::BoxOffice ()
{
    
}

Ticket BoxOffice::buyTicket( string row, int seat, string event, string venue, Ticket::KIND kind, string daytime)
{
    double price = 0;
    Ticket t(row, seat, event, venue, price, kind, daytime);
    return t;
    
}

Ticket BoxOffice::buyRoyceHallStudentTicket( string row, int seat, string event, Ticket::KIND kind, string daytime)
{
    string venue = "Royce Hall";
    double price = 0;
    Project5Helper helper;
    if (kind == Ticket::KIND::ATHLETICGAME)
    {
        price = 45.00;
        if (helper.startsWithOrchestra(row) == true)
        {
            price = 120.00;
        }
    }
    else if ( kind == Ticket::KIND::MOVIE)
    {
        price = 10.00;
        if (helper.startsWithOrchestra(row) == true)
        {
            price = 20.00;
        }
        
    }
    else if (kind == Ticket::KIND::CONCERT)
    {
        if (helper.startsWithOrchestra(row) == true && helper.endsWithPM(daytime)== true)
        {
            price = 100.00;
        }
        else if ((helper.startsWithOrchestra(row) == true) && (helper.endsWithPM(daytime) == false))
        {
            price = 70.00;
        }
        else if ((helper.startsWithOrchestra(row) == false) && (helper.endsWithPM(daytime) == true))
        {
            price = 35.00;
        }
        else
        {
            price = 20.00;
        }
    }
    else if (kind == Ticket::KIND::OTHER)
    {
        if (helper.startsWithOrchestra(row) == true && helper.endsWithPM(daytime)== true)
        {
            price = 80.00;
        }
        else if ((helper.startsWithOrchestra(row) == true) && (helper.endsWithPM(daytime) == false))
        {
            price = 50.00;
        }
        else if ((helper.startsWithOrchestra(row) == false) && (helper.endsWithPM(daytime) == true))
        {
            price = 25.00;
        }
        else
        {
            price = 10.00;
        }
            
    }
     Ticket t(row, seat, event, venue, price, kind, daytime);
     return t;
}

Ticket BoxOffice::buyRoyceHallStaffTicket( string row, int seat, string event, Ticket::KIND kind, string daytime )
{
    string venue = "Royce Hall";
    double price = 0;
    Project5Helper helper;
    if (kind == Ticket::KIND::ATHLETICGAME)
    {
        price = 55.00;
        if (helper.startsWithOrchestra(row) == true)
        {
            price = 130.00;
        }
    }
    else if ( kind == Ticket::KIND::MOVIE)
    {
        price = 11.25;
        if (helper.startsWithOrchestra(row) == true)
        {
            price = 22.50;
        }
    }
    else if (kind == Ticket::KIND::CONCERT)
    {
        if (helper.startsWithOrchestra(row) == true && helper.endsWithPM(daytime)== true)
        {
            price = 110.00;
        }
        else if ((helper.startsWithOrchestra(row) == true) && (helper.endsWithPM(daytime) == false))
        {
            price = 80.00;
        }
        else if ((helper.startsWithOrchestra(row) == false) && (helper.endsWithPM(daytime) == true))
        {
            price = 45.00;
        }
        else
        {
            price = 30.00;
        }
    }
    else if (kind == Ticket::KIND::OTHER)
    {
        if (helper.startsWithOrchestra(row) == true && helper.endsWithPM(daytime)== true)
        {
            price = 90.00;
        }
        else if ((helper.startsWithOrchestra(row) == true) && (helper.endsWithPM(daytime) == false))
        {
            price = 60.00;
        }
        else if ((helper.startsWithOrchestra(row) == false) && (helper.endsWithPM(daytime) == true))
        {
            price = 35.00;
        }
        else
        {
            price = 20.00;
        }
        
    }
    Ticket t(row, seat, event, venue, price, kind, daytime);
    return t;
}

Ticket BoxOffice::buyRoyceHallTicket( string row, int seat, string event, Ticket::KIND kind, string daytime )
{
    string venue = "Royce Hall";
    double price = 0;
    Project5Helper helper;
    if (kind == Ticket::KIND::ATHLETICGAME)
    {
        price = 75.00;
        if (helper.startsWithOrchestra(row) == true)
        {
            price = 50.00;
        }
    }
    else if ( kind == Ticket::KIND::MOVIE)
    {
        price = 12.50;
        if (helper.startsWithOrchestra(row) == true)
        {
            price = 25.00;
        }
        
    }
    else if (kind == Ticket::KIND::CONCERT)
    {
        if (helper.startsWithOrchestra(row) == true && helper.endsWithPM(daytime)== true)
        {
            price = 130.00;
        }
        else if ((helper.startsWithOrchestra(row) == true) && (helper.endsWithPM(daytime) == false))
        {
            price = 100.00;
        }
        else if ((helper.startsWithOrchestra(row) == false) && (helper.endsWithPM(daytime) == true))
        {
            price = 65.00;
        }
        else
        {
            price = 50.00;
        }
    }
    else if (kind == Ticket::KIND::OTHER)
    {
        if (helper.startsWithOrchestra(row) == true && helper.endsWithPM(daytime)== true)
        {
            price = 110.00;
        }
        else if ((helper.startsWithOrchestra(row) == true) && (helper.endsWithPM(daytime) == false))
        {
            price = 80.00;
        }
        else if ((helper.startsWithOrchestra(row) == false) && (helper.endsWithPM(daytime) == true))
        {
            price = 55.00;
        }
        else
        {
            price = 40.00;
        }
        
    }
    Ticket t(row, seat, event, venue, price, kind, daytime);
    return t;
}



