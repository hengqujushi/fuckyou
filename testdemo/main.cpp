//
//  main.cpp
//  testdemo
//
//  Created by li刚 on 15/6/29.
//  Copyright (c) 2015年 zhangyuanyuan. All rights reserved.
//

// initialization of variables
#include <iostream>
#include <stdlib.h>     // Need random(), srandom()
#include <time.h>       // Need time()
#include <vector>       // Need vector
#include <algorithm>    // Need for_each()

using namespace std;

#define VSIZE 24        // Size of vector
vector<long> v(VSIZE);  // Vector object

// Function prototypes
void initialize(long &ri);
void show(const long &ri);
bool isMinus(const long &ri);  // Predicate function

template <class T>
T sum(T a,T b)
{
    return a+b;
}

template <class T,class U>
bool is_equal(T a, U b)
{
    return ( a == b);
}

int main()
{
    int x = sum<int>(2,3);
    double y = sum<double>(2.1,2.7);
    cout << "sum int result :" << x << endl;
    cout << "sum double result :" << y << endl;
    cout << is_equal(10,9.1) << endl;
    cout << is_equal(10,10) << endl;
}

// Set ri to a signed integer value
void initialize(long &ri)
{
    ri = ( random() - (RAND_MAX / 2) );
    //  ri = random();
}

// Display value of ri
void show(const long &ri)
{
    cout << ri << "  ";
}

// Returns true if ri is less than 0
bool isMinus(const long &ri)
{
    return (ri < 0);
}
