#include <stdio.h> 
#include <stdlib.h>

// insert struct/enum declarations

typedef enum agegroup {infant, children, teen, adult, elderly} AgeGroup;

typedef struct customer{
    
    char* name;
    int memberld;
    AgeGroup ageGroup;
    
}Customer;

// insert the CreateCustomerRecord function

Customer* CreateCustomerRecord (char* name, int id, AgeGroup age){
    
    Customer* newCustomer = malloc(sizeof(Customer));
    newCustomer->memberld = id;
    newCustomer->name = name;
    newCustomer->ageGroup = age;
    
    return newCustomer;
    
}

int  main ()
    
{
    Customer* c;
    c  =   CreateCustomerRecord ("John Chan", 1234, adult);
    printf ("%s %d %d\n" , c->name, c->memberld, c->ageGroup );
    
    return 0; 
    
}