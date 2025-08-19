/**
* @file BstNode.hpp 
* @description Ikili arama agaci dugumu baslik dosyasi
* @course İkinci ogretim A grubu 
* @assignment 2. Odev
* @date 17.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
using namespace std;

class BstNode{
  public:
    BstNode *left;
    BstNode *right;
    char data;
    BstNode(const char& , BstNode *, BstNode *);
};

#endif