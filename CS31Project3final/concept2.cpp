//
//  concept2.cpp
//  cs31proj3
//
//  Created by Ojas Bardiya on 2/9/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int number(string s, int& startingposition) // number function

{
    
    int result = 0;
    while ((startingposition < s.length()) &&  isspace( s.at( startingposition ))) // consumes whitespace
    {
        startingposition = startingposition + 1;
    }
    
    if (startingposition < s.length())
    {
        
        if (s.at( startingposition ) >= '1' && s.at( startingposition ) <= '9') // makes sure first digit is between 1 to 9
            
        {
            while (startingposition < s.length() && s.at( startingposition ) >= '0' && s.at( startingposition ) <= '9')
                
            {
                int value = s.at( startingposition ) - '0';
                result = (result * 10) + value;
                startingposition = startingposition + 1;
                
            }
        }
        else if (s.at( startingposition ) == ':') // to make sure starting with a ':' is considered valid
        {
            result = -5;
        }
        
        else
        {
            result = -1;
        }
        
    }
    else
    {
        result = -1;
    }
    return(result);
    
}

bool isValidRowerString(string rowerString) // function to determine if string entered is valid or not
{
    int startingpos = 0;
    bool value = true;
    if ( rowerString.length() == 0)
    {
        value = false;
        return (value);
    }
    
    int isheartbeattrue = 0;
    int isdistancetrue = 0;
    int isstrokestrue = 0;
    int secondsplace2 = 0;
    int issecondstrue = 0;
    int issecstrue = 0;
    int isminutestrue = number(rowerString, startingpos); // initializing the variables
    if (isminutestrue == -1)
    {
        value = false;
        return (value);
    }
    else if ( isminutestrue == -5) // considers the case when string begins with ':' after the whitespace
    {
        startingpos = startingpos + 1;
        
        if (rowerString.at(startingpos) == '0') // makes sure 0 is considered valid after the colon
        {
            startingpos = startingpos + 1;  //       // proceeds to the next character
            secondsplace2 = number(rowerString, startingpos);
            if (secondsplace2 >= 10) // makes sure it does not exceed two digits
            {
                value = false;
                return (value);
            }
            if (rowerString.at(startingpos) != ' ') // makes sure no other character than a whitespace is entered after the number of seconds is read
            {
                value = false;
                return (value);
                
            }
        }
        if ((rowerString.at(startingpos) >= '1') && (rowerString.at(startingpos) <= '9'))
        {
            issecondstrue = number(rowerString, startingpos);
            if (issecondstrue == -1)
            {
                value = false;
                return (value);
            }
            if ((issecondstrue < 10) || issecondstrue >59) // determines whether no. of seconds is within given range
            {
                value = false;
                return (value);
            }
            if (rowerString.at(startingpos) != ' ') // determines no character other than a whitespace is present after the no. of seconds is read
            {
                value = false;
                return (value);
            }
            
        }
        isstrokestrue = number(rowerString, startingpos);  // variable used to make sure strokes/minute is entered correctly
        if ((isstrokestrue < 1) || (isstrokestrue > 999)) // determines if it is within the correct range
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) != ' ')
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) == ' ')   // nested ip loop to make sure " s/m " is entered correctly
        {
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != 's')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != '/')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != 'm')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != ' ')
            {
                value = false;
                return (value);
            }
            
        }
        isdistancetrue = number(rowerString, startingpos);  // variable used to determine if distance is entered correctly
        if (isdistancetrue < 1) // determines if range is entered correctly
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) != ' ')
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) == ' ') // nested if loop to determine whether " m " is entered correctly
        {
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != 'm')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != ' ')
            {
                value = false;
                return (value);
            }
        }
        isheartbeattrue = number(rowerString, startingpos); // variable used to determine if heartbeat is entered correctly
        if ( (isheartbeattrue < 1) || (isheartbeattrue > 999)) // determines whether it is within given range
        {
            value = false;
            return (value);
        }
        if (startingpos < rowerString.length())
        {
            value = false;
            return (value);
        }
    }
    
    else if ( (isminutestrue != -1) && (isminutestrue != -5) ) // in case the string starts with a number
    {
        
        if ( (isminutestrue <= 0) || (isminutestrue > 59)) // to confirm if range is satisified for number of minutes
        {
            value = false;
            return (value);
        }
        if ( rowerString.at(startingpos) != ':') // to make sure only integers are entered and are followed only by a colon with no space in between
        {
            value = false;
            return (value);
        }
        if ( rowerString.at(startingpos) == ':') // string is true upto this point
        {
            startingpos = startingpos + 1;
            if ((rowerString.at(startingpos) >= '1') && (rowerString.at(startingpos) <= '9'))
            {
                issecstrue = number(rowerString, startingpos);
                {
                    if ((issecstrue < 10) || (issecstrue >59)) // determines if range is correct and number of seconds is 2 digits
                    {
                        value = false;
                        return (value);
                    }
                    if (rowerString.at(startingpos) != ' ')
                    {
                        value = false;
                        return (value);
                    }
                }
                
            }
            else if (rowerString.at(startingpos) == '0') // makes sure :0 is considered to be a correct start
            {
                startingpos = startingpos + 1; //
                issecstrue = number(rowerString, startingpos);
                if ( issecstrue >= 10) // determines if seconds is within range and only 2 digits
                {
                    value = false;
                    return (value);
                }
                if (rowerString.at(startingpos) != ' ')
                {
                    value = false;
                    return (value);
                }
            }
            else
            {
                value = false;
                return (value);
            }
        }
        isstrokestrue = number(rowerString, startingpos); // variable used to determine if no. of strokes is enetred correctly
        if ((isstrokestrue < 1) || (isstrokestrue > 999)) // strokes/minutes is within given range
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) != ' ') // makes sure only 1 space in between number ans "s/m"
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) == ' ') // nested if loop to make sure " s/m " is entered correctly
        {
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != 's')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != '/')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != 'm')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != ' ')
            {
                value = false;
                return (value);
            }
            
        }
        isdistancetrue = number(rowerString, startingpos); // makes sure distance is entered correctly
        if (isdistancetrue < 1)
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) != ' ') // makes sure only 1 space between number and "m"
        {
            value = false;
            return (value);
        }
        if (rowerString.at(startingpos) == ' ') // nested if loop to make sure " m " is entered correctly
        {
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != 'm')
            {
                value = false;
                return (value);
            }
            startingpos = startingpos + 1;
            if (rowerString.at(startingpos) != ' ')
            {
                value = false;
                return (value);
            }
        }
        isheartbeattrue = number(rowerString, startingpos); // makes sure if heartbeat is entered correctly
        if ( (isheartbeattrue < 1) || (isheartbeattrue > 999)) //heartbeat is within given range
        {
            value = false;
            return (value);
        }
        if (startingpos < rowerString.length()) // no characters after number is entered
        {
            value = false;
            return (value);
        }
        
        
    }
    
    return (value);
}

int elapsedMinutes(string rowerString)
{
    int start = 0;
    int minspassed =0;
    bool val1 = isValidRowerString(rowerString);
    if (val1 == true)
    {
        minspassed = number(rowerString, start);
        if ( minspassed == -5)
        {
            minspassed = 0;
        }
    }
    else
    {
        return -1;
    }
    return (minspassed);
}

int elapsedSeconds(string rowerString)
{
    int secondspassed = 0;
    int start = 0;
    int minspassed = 0;
    bool val2 = isValidRowerString(rowerString);
    if (val2 == true)
    {
        minspassed = number(rowerString, start);
        if (minspassed == -5)
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1; //
                secondspassed = number(rowerString, start);
            }
            else
            {
                secondspassed = number(rowerString, start);
            }
        }
        else
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1;
            }
            secondspassed = number(rowerString, start);
        }
        
    }
    else
    {
        return -1;
    }
    return (secondspassed);
}

int strokesPerMinute(string rowerString)
{
    int minspassed = 0;
    int secondspassed = 0;
    int strokespermin = 0;
    int start = 0;
    bool val3 = isValidRowerString(rowerString);
    if ( val3 == true)
    {
        minspassed = number(rowerString, start);
        if (minspassed == -5)
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1;
            }
            secondspassed = number(rowerString, start);
            strokespermin = number(rowerString, start);
        }
        else
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1;
            }
            secondspassed = number(rowerString, start);
            strokespermin = number(rowerString, start);
        }
    }
    else
    {
        return -1;
    }
    return (strokespermin);
    
}

int totalDistance(string rowerString)
{
    int start = 0;
    int secondspassed = 0;
    int minspassed = 0;
    int strokespermin = 0;
    int distance = 0;
    bool val4 = isValidRowerString(rowerString);
    if (val4 == true)
    {
        minspassed = number(rowerString, start);
        if ( minspassed == -5)
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1;
                secondspassed = number(rowerString, start);
                strokespermin = number(rowerString, start);
                start = start + 5;
                distance = number(rowerString, start);
            }
            else
            {
                secondspassed = number(rowerString, start);
                strokespermin = number(rowerString, start);
                start = start + 5;
                distance = number(rowerString, start);
            }
                
        }
        else
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1;
            }
            
                secondspassed = number(rowerString, start);
                strokespermin = number(rowerString, start);
                start = start + 5;
                distance = number(rowerString, start);
        }
    }
    else
    {
        return -1;
    }
    return (distance);
}

int heartRate(string rowerString)
{
    int start = 0;
    int secondspassed = 0;
    int minspassed = 0;
    int strokespermin = 0;
    int distance = 0;
    int heartbeat = 0;
    bool val4 = isValidRowerString(rowerString);
    if (val4 == true)
    {
        minspassed = number(rowerString, start);
        if ( minspassed == -5)
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1;
                secondspassed = number(rowerString, start);
                strokespermin = number(rowerString, start);
                start = start + 5;
                distance = number(rowerString, start);
                start = start + 3;
                heartbeat = number(rowerString, start);
            }
            else
            {
                secondspassed = number(rowerString, start);
                strokespermin = number(rowerString, start);
                start = start + 5;
                distance = number(rowerString, start);
                start = start + 3;
                heartbeat = number(rowerString, start);
            }
            
        }
        else
        {
            start = start + 1;
            if (rowerString.at(start) == '0')
            {
                start = start + 1;
            }
            
            secondspassed = number(rowerString, start);
            strokespermin = number(rowerString, start);
            start = start + 5;
            distance = number(rowerString, start);
            start = start +3;
            heartbeat = number(rowerString, start);
        }
    }
    else
    {
        return -1;
    }
    return (heartbeat);
}

int main()
{   string y;
    int desiredval = 0;
    cerr << "Enter a string: ";
    getline(cin, y);
    desiredval = heartRate(y);
    cerr << desiredval << endl;
return 0;
    
}

