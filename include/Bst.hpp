/**
* @file Bst.hpp 
* @description Ikili arama agaci baslik dosyasi
* @course Ikinci ogretim A grubu 
* @assignment 2. Odev
* @date 17.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#ifndef BST_HPP
#define BST_HPP
#include "BstNode.hpp"
#include <cmath>
#include <iomanip>
#include <string>
class Bst{
  private:
    BstNode *root;
    int totalValue; 
    void SearchAndAdd(BstNode *&, const char& );
    bool Search(BstNode *, const char& );
    void inorder(BstNode *);
    void preorder(BstNode *);
    void postorder(BstNode *);
    int height(BstNode *);
    void printLevel(BstNode *, int );
    int getWidth();
    void printSpace(int);
    void printDot(int);

    void printLevelSpecified(BstNode*,int,int);
    void drawConnections(BstNode*,int,int,int);


    bool SearchAndDelete(BstNode *,const char&);
    bool DeleteNode(BstNode *&);
    int calcTotalValue(BstNode* , bool);
    void mirror(BstNode *);
  public:
    Bst();
    bool isEmpty();
    void add(const char);
    bool find(const char );
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    int height();
    void deleteValue(char );
    void setTotalValue();
    void printTree();
    int getTotalValue();
    void mirrorTree();
    void clear();
    ~Bst();
};
#endif