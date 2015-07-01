//
//  test.cpp
//  testdemo
//
//  Created by li刚 on 15/7/1.
//  Copyright (c) 2015年 zhangyuanyuan. All rights reserved.
//

#include "test.h"
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

int main()
{
    srandom( time(NULL) );  // Seed random generator
    
    for_each(v.begin(), v.end(), initialize);//调用普通函数
    cout << "Vector of signed long integers" << endl;
    for_each(v.begin(), v.end(), show);
    cout << endl;
    
    
    
    // Use predicate function to count negative values
    //
    int count = 0;
    vector<long>::iterator p;
    p = find_if(v.begin(), v.end(), isMinus);//调用断言函数
    while (p != v.end()) {
        count++;
        p = find_if(p + 1, v.end(), isMinus);
    }
    cout << "Number of values: " << VSIZE << endl;
    cout << "Negative values : " << count << endl;
    
    vector<int> x;
    vector<int> y;
    x.push_back(3);
    x.push_back(4);
    y.push_back(3);
    y.push_back(2);
    vector<int> result;
    
    //cout << *set_union(x.begin(), x.end(), y.begin(), y.end(), result.begin()) <<endl;
    //for_each(result.begin(), result.end(), show);
    return 0;
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
