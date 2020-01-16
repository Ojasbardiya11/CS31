//
//  mealplan.cpp
//  Proj2
//
//  Created by Ojas Bardiya on 1/23/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.

#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string purchase_1, meal_1, category_1, reply_1 ;         // declaring variables as strings
    
    cout << "Ticket or BruinCard?"<< " ";
    getline(cin, purchase_1);                              // getline used to make sure empty space is an error
    if (purchase_1 == "Ticket")
    {
        cout << "Breakfast, Lunch or Dinner?" << " ";
        getline(cin, meal_1);
        
        if ( meal_1 == "Breakfast")                       // if loop nested within if loop to determine price according to meal choice
            cout << "Thank you for eating at UCLA today.  Your meal cost is $12.50." << "\n";
        else if ( meal_1 == "Lunch")
            cout << "Thank you for eating at UCLA today.  Your meal cost is $14.50." << "\n";
        else if ( meal_1 == "Dinner")
            cout << "Thank you for eating at UCLA today.  Your meal cost is $17.00." << "\n";
        else
            cout << "The meal value must either be Breakfast, Lunch or Dinner."<< "\n";
    }
   
    else if ( purchase_1 == "BruinCard")
    {
        cout << "Breakfast, Lunch or Dinner?" << " ";
        getline(cin, meal_1);
        cout << "Student or Staff?" << " ";
        getline(cin, category_1);
     {
        if ( (meal_1 == "Breakfast") && (category_1 == "Staff")) // if loop nested within if loop to determine price according to choice of meal
        {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << "\n";
            
        }
        else if ( (meal_1 == "Lunch") && (category_1 == "Staff"))
        {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << "\n";
        
        }
        else if ( (meal_1 == "Dinner") && (category_1 == "Staff"))
        {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $14.75." << "\n";
            
        }
        else if (((meal_1 == "Breakfast") || (meal_1 == "Lunch") || (meal_1 == "Dinner")) && (category_1 == "Student")) // determines whether a valid input is entered for meal value and type value
        {
            cout << "Resident?" << " ";
            getline(cin, reply_1) ;
            
        
         
                if ( meal_1 == "Breakfast" && reply_1 == "Yes")   // if loop nested within if loop nested within if loop to determine payment according to resident value
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $9.75." << "\n";
        
            }
                else if ( meal_1 == "Breakfast" && reply_1 == "No")
            {
            
                cout << "Thank you for eating at UCLA today.  Your meal cost is $10.00." << "\n";
            }
                else if ( meal_1 == "Lunch" && reply_1 == "Yes")
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25" << "\n";
           
            }
                else if ( meal_1 == "Lunch" && reply_1 == "No")
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $11.75." << "\n";
                
            }
                else if ( meal_1 == "Dinner" && reply_1 == "Yes")
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $12.25." << "\n";
            }
                else if  (meal_1 == "Dinner" && reply_1 == "No")
            {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << "\n";
                
            }
                else if ( (reply_1 != "Yes") && (reply_1 != "No")) // error message if resident value is not Yes/No
            {
                cout << "The resident value must either be Yes or No" << "\n";
            }
         
        }
        else if ( (meal_1 != "Breakfast") && (meal_1 != "Lunch") && (meal_1 != "Dinner")) // error message for meal type is displayed first if both meal value and type value input are errors
        {
            cout  << "The meal value must either be Breakfast, Lunch or Dinner."<< "\n";
            
        }
        else if ( (category_1 != "Student") && (category_1 != "Staff") )
        {
            cout << "The type value must either be Student or Staff."<< "\n";
            
        }
        
     }
    }
    
    else
    {
        cout << "The kind value must either be Ticket or BruinCard." << "\n"; // in case the kind value is neither Ticket nor Bruincard all blocks of code are skipped and this message is displayed
        
    }
return 0;
}


