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

struct BSTreeNode{
    int value;
    BSTreeNode *left;
    BSTreeNode *right;
};

void reverseTree(BSTreeNode* p);
void addTreeNode(BSTreeNode* &p, int value);
void printLDR(BSTreeNode* p);

int main(){
    BSTreeNode* head = NULL;
    int input = 0;
    while(true){
        cout << input;
        if(input != -1){
            addTreeNode(head, input);
        }
        else
            break;
    }
    cout<<"before reverse:"<<endl;
    printLDR(head);
    cout<<"after reverse:"<<endl;
    reverseTree(head);
    printLDR(head);
}

void addTreeNode(BSTreeNode* &p, int value){
    if(p == NULL){
        BSTreeNode* tmp = new BSTreeNode();
        tmp->value = value;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    else{
        if(value <= p->value){
            addTreeNode(p->left, value);
        }
        else{
            addTreeNode(p->right, value);
        }
    }
}

void printLDR(BSTreeNode* p){
    if (p == NULL){
        return;
    }
    printLDR(p->left);
    cout<<p->value<<endl;
    printLDR(p->right);
}

void reverseTree(BSTreeNode* p){
    if (p == NULL){
        return;
    }
    BSTreeNode* tmp = p->left;
    p->left = p->right;
    p->right = tmp;
    reverseTree(p->left);
    reverseTree(p->right);
}
