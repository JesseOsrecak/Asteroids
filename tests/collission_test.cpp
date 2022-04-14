#include "collission_test.h"
#include "../helper.h"

void collission_box_test()
{
    cout<< "Initiating Test Suite for Collision Boxes: " <<endl;
    CollissionBox base = CollissionBox(0,0,2,2);
    CollissionBox other = CollissionBox(1.5, 0,3,3);
    
    // Test A
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test A1: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test A1: PASSED" <<endl;
    }
    other = CollissionBox(-1.5,0,3,3);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test A2: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test A2: PASSED" <<endl;
    }
    
    

    // Test B
    other = CollissionBox(0.5,0,1,1);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test B1: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test B1: PASSED" <<endl;
    }
    other = CollissionBox(-0.5,0,1,1);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test B2: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test B2: PASSED" <<endl;
    }
    
    
    
    
    

    // Test C
    other = CollissionBox(0,1.5,3,3);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test C1: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test C1: PASSED" <<endl;
    }
    other = CollissionBox(0,-1.5,3,3);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test C2: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test C2: PASSED" <<endl;
    }
    
    

    // Test D
    other = CollissionBox(0,0.5,3,3);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test D1: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test D1: PASSED" <<endl;
    }
    other = CollissionBox(0,-0.5,3,3);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test D2: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test D2: PASSED" <<endl;
    }
   
    

    // Test E
    other = CollissionBox(0,0,3,3);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test E: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test E1: PASSED" <<endl;
    }
    

    // Test F
    other = CollissionBox(0,0,1,1);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test F: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test F1: PASSED" <<endl;
    }
    

    // Test G
    other = CollissionBox(4,0,1,1);
    if (check(true,collission_check(base,other))==true)
    {
        cout << "Test G1: " << print_result(collission_check(base, other)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test G1: PASSED" <<endl;
    }
    other =  CollissionBox(-4,0,1,1);
    if (check(true,collission_check(base,other))==true)
    {
        cout << "Test G2: " << print_result(collission_check(base,other)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test G2: PASSED" <<endl;
    }
    
    

    // Test H 
    other = CollissionBox(0,4,1,1);
    if (check(true,collission_check(base,other))==true)
    {
        cout << "Test H1: " << print_result(collission_check(base, other)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test H1: PASSED" <<endl;
    }
    other = CollissionBox(0,-4,1,1);
    if (check(true,collission_check(base,other))==true)
    {
        cout << "Test H2: " << print_result(collission_check(base, other)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test H2: PASSED" <<endl;
    }
    
    

    // Test I 
    other = CollissionBox(0,0,3,1);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test I: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test I1: PASSED" <<endl;
    }
    

    // Test J
    other = CollissionBox(0,0,1,3);
    if (check(true,collission_check(base,other))==false)
    {
       cout << "Test J: " << print_result(collission_check(base, other)) << " expected: true " << endl; 
    }
    else
    {
        cout << "Test J1: PASSED" <<endl;
    }
    

    // Test K
    other = CollissionBox(3,0,1,1);
    if (check(true,collission_check(base,other))==true)
    {
        cout << "Test K1: " << print_result(collission_check(other, base)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test K1: PASSED" <<endl;
    }
    other = CollissionBox(-3,0,1,1);
    if (check(true,collission_check(base,other))==true)
    {
        cout << "Test K2: " << print_result(collission_check(other, base)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test K2: PASSED" <<endl;
    }
    
    

    // Test L
    other = CollissionBox(0,3,1,1);
    if (check(true,collission_check(base,other))==true)
    {
         cout << "Test L1: " << print_result(collission_check(other , base)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test L1: PASSED" <<endl;
    }
    other = CollissionBox(0,-3,1,1);
    if (check(true,collission_check(base,other))==true)
    {
        cout << "Test L2: " << print_result(collission_check(other, base)) << " expected: false " << endl;
    }
    else
    {
        cout << "Test L2: PASSED" <<endl;
    }
   
    

    // Test M
    other = CollissionBox(2,-2,2,2);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test M1: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test M1: PASSED" <<endl;
    }
    

    // Test N
    other = CollissionBox(2,2,2,2);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test N: " << print_result(collission_check(base, other)) << " expected: true " << endl;

    }
    else
    {
        cout << "Test N1: PASSED" <<endl;
    }
    
    // Test O
    other = CollissionBox(-2,-2,2,2);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test O: " << print_result(collission_check(base, other)) << " expected: true " << endl;
    }
    else
    {
        cout << "Test O1: PASSED" <<endl;
    }
    

    // Test P
    other = CollissionBox(-2,2,2,2);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test P: " << print_result(collission_check(base, other)) << " expected: true " << endl; 
    }
    else
    {
        cout << "Test P1: PASSED" <<endl;
    }
    

    // Test Q
    other = CollissionBox(1,2,1,8);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test Q: " << print_result(collission_check(base, other)) << " expected: true " << endl;

    }
    else
    {
        cout << "Test Q1: PASSED" <<endl;
    }
    
    // Test R
    other =  CollissionBox(3,0,8,1);
    if (check(true,collission_check(base,other))==false)
    {
        cout << "Test R: " << print_result(collission_check(base,other)) << " expected: true " << endl;

    }
    else
    {
        cout << "Test R1: PASSED" <<endl;
    }
    
}


string print_result(bool result)
{
    if(result == false)
        return "false ";
    else
        return "true ";

}

bool check(bool expected, bool actual)
{
    if(expected == actual)
    {
        return true;
    }
    else
    {
        return false;
    }
}