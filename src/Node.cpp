/**
* @file Node.cpp 
* @description Tek yonlu bagli liste dugumu kaynak dosyasi
* @course Ikinci ogretim A grubu 
* @assignment 2. Odev
* @date 16.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#include "../include/Node.hpp"

Node::Node(Bst *data= new Bst(),Node *next = NULL){
  this->data = data;
  this->next = next;
}
Node::~Node(){
  delete data;
}