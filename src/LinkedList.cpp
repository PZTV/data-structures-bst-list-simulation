/**
* @file LinkedList.cpp 
* @description Tek yonlu bagli liste kaynak dosyasi
* @course Ikinci ogretim A grubu 
* @assignment 2. Odev
* @date 16.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#include "../include/LinkedList.hpp"

Node* LinkedList::findPrevByPosition(int index){
  if(index<0 || index> length) throw "Index out of range";
  int position = 0;
  Node *itr = head;
  for(;itr!=NULL;itr = itr->next,position++){
    if(index==position) return itr;
  }
  return NULL;
}
Node* LinkedList::findByPosition(int index){
  if(index<0 || index>=length) throw "Index out of range";
  Node *tmp = head->next;
  for(int i=0;i<index;i++){
    tmp = tmp->next; 
  }
  return tmp;
}
void LinkedList::loadFromFile(const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("File could not be opened");
  }

  string line;
  while (std::getline(file, line)) {
    Bst* agac = new Bst();
    for (char ch : line) {
        agac->add(ch);
    }
    add(agac);
  }

  file.close();
}
LinkedList::LinkedList(){
  head = new Node(NULL,NULL);
  length = 0;
}
LinkedList::LinkedList(const string& filename){
  head = new Node(NULL,NULL);
  length = 0;
  loadFromFile(filename);
}
int LinkedList::size(){
  return length;
}
bool LinkedList::isEmpty(){
  return length==0;
}
void LinkedList::add(Bst *item){
  insert(item,length);
}
void LinkedList::insert(Bst *item, int index){
  if(index<0 || index>length) throw "Index out of range";
  Node *tmp = findPrevByPosition(index);
  item->setTotalValue();
  tmp->next = new Node(item,tmp->next);
  length++;
}
void LinkedList::removeAt(int index){
  if(index<0 || index>=length) throw "Index out of range";
  Node *p = findPrevByPosition(index);
  Node *r = p->next;
  p->next = p->next->next;
  delete r;
  length--;
}
void LinkedList::clear(){
  while(!isEmpty()){
    removeAt(0);
  }
}


void LinkedList::display(int start, int cursor) {
  int end = min(start + 10, length);
  Node *tmp = findByPosition(start);
  // Seperator line
  for (int i = start; i < end; i++) {
    cout << "................. " ;
  }
  cout<<endl;
  // First row: Node addresses
  Node *current = tmp;
  for (int i = start; i < end; i++) {
    unsigned long long address = (unsigned long long)current;
    cout << "." << setw(15) << left << address%10000 << ". ";
    current = current->next;
  }
  cout << endl;

  // Seperator line
  for (int i = start; i < end; i++) {
    cout << "................. " ;
  }
  cout<<endl;

  // Second row: Node data
  current = tmp;
  for (int i = start; i < end; i++) {
    cout << "." << setw(15)<<right<< current->data->getTotalValue() << ". ";
    current = current->next;
  }
  cout << endl;
  // Seperator line
  for (int i = start; i < end; i++) {
    cout << "................. " ;
  }
  cout << endl;
  // Third row: Next node addresses
  current = tmp;
  for (int i = start; i < end; i++) {
    unsigned long long address = (unsigned long long)current->next;
    cout << "." << setw(15) << left << address%10000 << ". ";
    current = current->next;
  }
  cout << endl;
  // Seperator line
  for (int i = start; i < end; i++) {
    cout << "................. " ;
  }
  cout<<endl;
  // Cursor row
  for (int i = start; i < end; i++) {
    if (i == cursor) {
        cout << "^^^^^^^^^^^^^^^^^";
    } else {
        cout << "                  ";
    }
  }
  cout << endl<<endl<<endl<<endl<<endl;
  current = findByPosition(cursor);
  current->data->printTree();
}

void LinkedList::navigate() {
  int cursor = 0;
  int start = 0;
  while (true) {
    system("CLS"); 
    display(start, cursor);
    cout << "Enter 'a' to move left, 'd' to move right, 's' to delete tree, 'w' to mirror the tree(q to quit): ";
    char input;
    cin >> input;
    if (input == 'q') break;
    if (input == 'd') {
        cursor++;
        if (cursor >= start + 10) {
            start += 10;
        }
        if (cursor >= length) {
            cursor = length - 1;
        }
    } 
    else if (input == 'a') {
      cursor--;
      if (cursor < 0) {
          cursor = 0;
      }
      else if (cursor < start) {
          start -= 10;
      }
    }
    else if(input == 's'){
      if (!isEmpty()) {
        removeAt(cursor);
        if (cursor >= length) {
          if(cursor%10 == 0){
            start -= 10;
          }
          cursor = length - 1;
        }
        if (cursor < 0) {
          cursor = 0;
        }
      }
    }
    else if(input=='w'){
      if(!isEmpty()){
        Node *current = findByPosition(cursor);
        current->data->mirrorTree();
      }
    }
    if(length == 0){
      cout<<"Program durduruluyor..."<<endl;
      break;
    }
  }
}