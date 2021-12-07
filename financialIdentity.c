

//
//  financialIdentity.c
//  financialLiteracy.c
//
//  Created by Ben Stager on 11/30/21.
//
#include <stdio.h>
#include "financialIdentity.h"
#include <math.h>
//struct financialIdentity *f1{

//}

//struct financialIdentity *nfl{
    
//}
// savingsPlacement method, updates the persons savings to be compounded yearly,
// based on year count
// Each time function is called, year compounded increases by 1
// This implements the compound interest formula y(t) = I * (1+r)^t
void savingsPlacement(struct financialIdentity *person, double interestRate){
    person->savings = 5000;
    person->savings = person->savings *(interestRate+1);
}

// Still a rough draft, but the persons debt is subtracted by their pay amount
// until it goes below 0, or until it is all payed off
// The loop can loop 12 times but will break when the debt is less than 0, or in
// other words when its payed off
void debt(struct financialIdentity *person, double interestRate, double add1pay){
    while (person->debt > 0){
        for (int i = 0; i < 12; i++){
            person->debt -= add1pay;
            person->yearsWithDebt += 1;
        }
    }
}

// The rent function implements a simple algorithm, if the person has enough money
//in checking to pay their rent, it is simply subtracted and then updated
// Else if the person does not have enough in their checking, their checking goes
// to 0 to pay what they have and then the remaining amount is payed using the savings
// and updated
void rent(struct financialIdentity *person, double rentAmount){
    double rentAmt = rentAmount * 12;
    person->yearsRented = 1;
    double remainder = rentAmt - person->checking;
    
    if (person->checking >= 950){
        person->checking -= rentAmt;
    }else{
        person->checking = 0;
        person->savings -= remainder;
    }
    person->yearsRented += 1;
}
