/**
* @file BstNode.cpp 
* @description Ikili arama agaci dugumu kaynak dosyasi
* @course Ikinci ogretim A grubu 
* @assignment 2. Odev
* @date 17.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#include "../include/BstNode.hpp"

BstNode::BstNode(const char& data = char(), BstNode *left = NULL, BstNode *right = NULL){
  this->left = left;
  this->right = right;
  this->data = data;      
}