/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Tristen Schwarzenberger
 * Assignment:   EECS-168 Homework1
 * Description:  This program allows the user to input information to ship bananas to their home.
 * Date: 9/23/2016
 *
 ---------------------------------------------------------------------------- */

#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
    int bananas = 0; //Variables
    double cost = 0;
    double markup = 0;
    double discount = 0;
    char type = 'x';
    char color = 'x';
    char exit = 'x';
    const double shipping = 35.50; //Added shipping cost

    std::string city; //Allows users to input shipping information
    std::string state;
    std::string address;
    int zipcode;

    while(exit!= 'y' && exit != 'Y')        //loop for if the user doesn't want to leave
    {
    std::cout<<"\nWelcome to the Banana Stand!"<<"\n";

    std::cout<<"--------------------"<<"\n";
    std::cout<<"Select type of banana:";            //Input for type of banana
    std::cout<<"\n"<<"Regular (r/R) (no markup)";
    std::cout<<"\n"<<"Organic (o/O) (20% markup)";
    std::cout<<"\n"<<"Saturated with Gamma Rays (g/G) (50% markup)";
    std::cout<<"\n"<<"Input your choice: ";
    std::cin>> type;

    while(!(type == 'r' || type =='R' || type =='o' || type == 'O' || type == 'g' || type == 'G') )
    {
      std::cout<<"\nError. Please enter a valid type: ";
      std::cin>>type;
    }

    std::cout<<"\n"<<"--------------------";
    std::cout<<"\n"<<"Select color of banana:";              //Input for color of banana
    std::cout<<"\n"<<"Yellow (y/Y) (no discount)";
    std::cout<<"\n"<<"Green (g/G) (10% discount)";
    std::cout<<"\n"<<"Mixed (m/M) (50% discount)";
    std::cout<<"\n"<<"Input your choice: ";
    std::cin>> color;

    while(!(color == 'y' || color =='Y' || color =='g' || color == 'G' || color == 'm' || color == 'M') )
    {
      std::cout<<"\nError. Please enter a valid color: ";
      std::cin>>color;
    }

    std::cout<<"\n"<<"--------------------"<<std::endl;
    std::cout<<"How many bananas do you want?: "; //Number of bananas
    std::cin>> bananas;

    while(bananas < 1)
    {
      std::cout<<"\nError. Please enter a valid amount of bananas (must have more than 0): ";
      std::cin>>bananas;
    }

    std::cin.ignore(1, '\n');
    std::cout<<"\n"<<"--------------------"<<std::endl;
    std::cout<<"Input your street address: ";   //Shipping information
    std::getline (std::cin,address);
    std::cout<<"\nInput your city: ";
    std::getline (std::cin, city);
    std::cout<<"\nInput your state: ";
    std::cin>>state;
    std::cout<<"\nInput your zip code: ";
    std::cin>>zipcode;

    std::cout<<"\n"<<"--------------------"<<std::endl;
    std::cout<<"\n"<<"Total cost for "<< bananas;
    cost = bananas * 0.03;

	printf(" banana(s) before markups or discounts: $%.2f", cost);	//Converts cost to a money value
    //std::cout<<"$"<< cost <<"\n";

    if (type=='r'|| type=='R') //Calculates markup based on user input
    {
        markup=0;
    }
    else if(type=='o'||type=='O')
    {
        markup = cost * 0.2;
    }
    else if(type=='g' || type=='G')
    {
        markup = cost * 0.5;
    }
    printf("\nTotal markups: $%.2f", markup); //Converts markup to a money value

    if(color == 'y'|| color=='Y')
    {
        discount = 0;
    }
    else if(color == 'g'| color=='G') //Calculates color based on user input
    {
        discount = cost * 0.10;
    }
    else if(color == 'm'|| color=='M')
    {
        discount = cost * 0.50;
    }
    if(state != "KS" && state != "ks" )
    {
        cost = cost + 35.00;
    }
    printf("\nTotal discount: $%.2f", discount); //Converts the discount to a money value
    cost = cost + markup - discount;
    printf("\nTotal cost: $%.2f", cost);
    std::cout<<"\nShipping to:";
    std::cout<<"\n\t"<<address;
    std::cout<<"\n\t"<<city<<", "<<state;
    std::cout<<"\n\t"<<zipcode;

    std::cout<<"\nDo you want to exit? (y/n): ";
    std::cin>>exit;


    }
    std::cout<<"Goodbye!\n";
    return(0);

}
