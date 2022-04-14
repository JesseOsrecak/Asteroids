#include "collission_test.h"
#include "../helper.h"

void collission_box_test()
{
    CollissionBox base = CollissionBox(0,0,2,2);
    cout<< "Initiating Test Suite for Collision Boxes: " <<endl;
    // Test A
    cout << "Test A1: " << print_result(collission_check(base, CollissionBox(1.5, 0,3,3))) << " expected: true " << endl;
    cout << "Test A2: " << print_result(collission_check(base, CollissionBox(-1.5,0,3,3))) << " expected: true " << endl;

    // Test B
    cout << "Test B1: " << print_result(collission_check(base, CollissionBox(0.5,0,1,1))) << " expected: true " << endl;
    cout << "Test B2: " << print_result(collission_check(base, CollissionBox(-0.5,0,1,1))) << " expected: true " << endl;

    // Test C
    cout << "Test C1: " << print_result(collission_check(base, CollissionBox(0,1.5,3,3))) << " expected: true " << endl;
    cout << "Test C2: " << print_result(collission_check(base, CollissionBox(0,-1.5,3,3))) << " expected: true " << endl;

    // Test D
    cout << "Test D1: " << print_result(collission_check(base, CollissionBox(0,0.5,3,3))) << " expected: true " << endl;
    cout << "Test D2: " << print_result(collission_check(base, CollissionBox(0,-0.5,3,3))) << " expected: true " << endl;

    // Test E
    cout << "Test E: " << print_result(collission_check(base, CollissionBox(0,0,3,3))) << " expected: true " << endl;

    // Test F
    cout << "Test F: " << print_result(collission_check(base, CollissionBox(0,0,1,1))) << " expected: true " << endl;

    // Test G
    cout << "Test G1: " << print_result(collission_check(base, CollissionBox(4,0,1,1))) << " expected: false " << endl;
    cout << "Test G2: " << print_result(collission_check(base, CollissionBox(-4,0,1,1))) << " expected: false " << endl;

    // Test H 
    cout << "Test H1: " << print_result(collission_check(base, CollissionBox(0,4,1,1))) << " expected: false " << endl;
    cout << "Test H2: " << print_result(collission_check(base, CollissionBox(0,-4,1,1))) << " expected: false " << endl;

    // Test I 
    cout << "Test I: " << print_result(collission_check(base, CollissionBox(0,0,1,3))) << " expected: true " << endl;

    // Test J
    cout << "Test J: " << print_result(collission_check(base, CollissionBox(0,0,3,1))) << " expected: true " << endl;

    // Test K
    cout << "Test K1: " << print_result(collission_check(CollissionBox(3,0,1,1), base)) << " expected: false " << endl;
    cout << "Test K2: " << print_result(collission_check(CollissionBox(-3,0,1,1), base)) << " expected: false " << endl;

    // Test L
    cout << "Test L1: " << print_result(collission_check(CollissionBox(0,3,1,1), base)) << " expected: false " << endl;
    cout << "Test L2: " << print_result(collission_check(CollissionBox(0,-3,1,1), base)) << " expected: false " << endl;

    // Test M
    cout << "Test M1: " << print_result(collission_check(base, CollissionBox(2,-2,2,2))) << " expected: true " << endl;

    // Test N
    cout << "Test N: " << print_result(collission_check(base, CollissionBox(2,2,2,2))) << " expected: true " << endl;

    // Test O
    cout << "Test O: " << print_result(collission_check(base, CollissionBox(-2,-2,2,2))) << " expected: true " << endl;

    // Test P
    cout << "Test P: " << print_result(collission_check(base, CollissionBox(-2,2,2,2))) << " expected: true " << endl;

    // Test Q
    cout << "Test Q: " << print_result(collission_check(base, CollissionBox(1,2,8,1))) << " expected: true " << endl;

    // Test R
    cout << "Test R: " << print_result(collission_check(base, CollissionBox(3,0,1,8))) << " expected: true " << endl;

}


string print_result(bool result)
{
    if(result == false)
        return "false ";
    else
        return "true ";

}