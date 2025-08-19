/**
* @file Node.hpp 
* @description Tek yonlu bagli liste dugumu baslik dosyasi
* @course İkinci ogretim A grubu 
* @assignment 2. Odev
* @date 15.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include "Bst.hpp"
using namespace std;


class Node{
  public:
    Node* next;
    Bst *data;
    Node(Bst *,Node *);
    ~Node();
};




#endif