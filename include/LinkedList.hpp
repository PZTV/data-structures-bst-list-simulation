/**
* @file LinkedList.hpp 
* @description Tek yonlu bagli liste baslik dosyasi
* @course Ikinci ogretim A grubu 
* @assignment 2. Odev
* @date 15.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "Node.hpp"
#include <iomanip>
#include <fstream>

class LinkedList{
  private:
    Node *head;
    int length;
    Node* findPrevByPosition(int);
    Node* findByPosition(int);
    void loadFromFile(const string& filename);

  public:
    LinkedList();
    LinkedList(const string& );
    int size();
    bool isEmpty();
    void add(Bst *);
    void insert(Bst *, int);
    void removeAt(int);
    void clear();
    void display(int, int);
    void navigate();
};


#endif