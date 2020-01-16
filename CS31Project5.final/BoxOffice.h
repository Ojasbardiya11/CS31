//
//  BoxOffice.hpp
//  CS31project5
//
//  Created by Ojas Bardiya on 2/27/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#ifndef BoxOffice_h
#define BoxOffice_h

#include "Ticket.h"

using namespace std;

class BoxOffice
{
    public:
    BoxOffice ();
    // member functions
    Ticket buyTicket( string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStudentTicket( string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStaffTicket( string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallTicket( string row, int seat, string event, Ticket::KIND kind, string daytime );
};

#endif /* BoxOffice_hpp */
