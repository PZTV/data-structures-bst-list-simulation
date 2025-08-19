/**
* @file Bst.cpp 
* @description Ikili arama agaci kaynak dosyasi
* @course Ikinci ogretim A grubu 
* @assignment 2. Odev
* @date 17.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#include "../include/Bst.hpp"


void Bst::SearchAndAdd(BstNode *&subNode, const char& item){
  if(subNode == NULL) subNode = new BstNode(item,NULL,NULL);
  else if(item < subNode->data)
    SearchAndAdd(subNode->left,item);
  else if(item > subNode->data)
    SearchAndAdd(subNode->right,item);
  else return;
}
bool Bst::Search(BstNode *subNode, const char& item){
  if(subNode->data == item) return true;
  else if(item < subNode->data)
    return Search(subNode->left,item);
  else if(item>subNode->data)
    return Search(subNode->right,item);
  else return false;
}
void Bst::inorder(BstNode *subNode){
  if(subNode != NULL){
    inorder(subNode->left);
    cout<<subNode->data<<" ";
    inorder(subNode->right);
  }
}
void Bst::preorder(BstNode *subNode){
  if(subNode != NULL){
    cout<<subNode->data<<" ";
    preorder(subNode->left);
    preorder(subNode->right);
  }
}
void Bst::postorder(BstNode *subNode){
  if(subNode != NULL){
    postorder(subNode->left);
    postorder(subNode->right);
    cout<<subNode->data<<" ";
  }
}
int Bst::height(BstNode *subNode){
  if(subNode == NULL) return -1;
  return max(height(subNode->left),height(subNode->right))+1;
}
void Bst::printLevel(BstNode *subNode, int counter){
  if(subNode == NULL) return;
  if(counter == 0){
    cout<<subNode->data<<" ";
  }
  else{
    printLevel(subNode->left,counter-1);
    printLevel(subNode->right,counter-1);
  }
}
int Bst::getWidth(){
  int maxWidth = 0;
  for(int i=height();i>0;i--){
    maxWidth+= pow(2,i);
  }
  maxWidth=maxWidth*2+1;
  return maxWidth;
}
void Bst::printSpace(int count){
  for(int i=0;i<count;i++){
    cout<<" ";
  }
}
void Bst::printDot(int count){
  for(int i=0;i<count;i++){
    cout<<".";
  }
}

void Bst::printLevelSpecified(BstNode* subNode, int counter, int spaceCount) {
  if (counter == 0) {
    if (subNode != NULL) cout<<subNode->data;
    else cout<<" ";
    printSpace(spaceCount);
  } 
  else {
    if (subNode != NULL) {
      printLevelSpecified(subNode->left, counter - 1, spaceCount);
      printLevelSpecified(subNode->right, counter - 1, spaceCount);
    } 
    else {
      printLevelSpecified(NULL, counter - 1, spaceCount);
      printLevelSpecified(NULL, counter - 1, spaceCount);
    }
  }
}
void Bst::drawConnections(BstNode* subNode, int counter, int levelSpace,int connectionSpace) {
  if(counter == 0){
    if(subNode != NULL){
      if(subNode->left != NULL && subNode->right != NULL){
        printDot(levelSpace+2);
      }
      else if(subNode->right == NULL && subNode->left != NULL){
        printDot((levelSpace/2)+2);
        printSpace((levelSpace/2)+1);
      }
      else if(subNode->left == NULL && subNode->right != NULL){
        printSpace((levelSpace/2)+1);
        printDot((levelSpace/2)+2);
      }
      else{
        printSpace((levelSpace+2));
      }
      printSpace(connectionSpace);

    }
    else{
      printSpace(levelSpace+2+connectionSpace);
    }
  }
  else {
    if (subNode != NULL) {
      drawConnections(subNode->left, counter - 1, levelSpace, connectionSpace);
      drawConnections(subNode->right, counter - 1, levelSpace, connectionSpace);
    } else {
      drawConnections(NULL, counter - 1, levelSpace, connectionSpace);
      drawConnections(NULL, counter - 1, levelSpace, connectionSpace);
    }
  }
}


bool Bst::SearchAndDelete(BstNode *subNode,const char& item){
  if(subNode == NULL) return false;
  if(subNode->data == item) return DeleteNode(subNode);
  else if(item<subNode->data) 
    return SearchAndDelete(subNode->left,item);
  else 
    return SearchAndDelete(subNode->right,item);
}
bool Bst::DeleteNode(BstNode *&subNode){
  if(subNode != NULL){
    BstNode *p = subNode;
    if(subNode->right == NULL) subNode = subNode->left;
    else if(subNode->left == NULL) subNode = subNode->right;
    else{
      p = subNode->left;
      BstNode *parent = subNode;
      while(p->right != NULL){
        parent = p;
        p = p->right;
      }
      subNode->data = p->data;
      if(parent == subNode) subNode->left = p->left;
      else parent->right = p->left;
    }
    delete p;
    return true;
  }
  else return false;
}
int Bst::calcTotalValue(BstNode* subNode, bool isLeftChild = false) {
  if (subNode == NULL) return 0; 
  int currentValue = isLeftChild ? subNode->data * 2 : subNode->data;
  int leftValue = calcTotalValue(subNode->left, true);  
  int rightValue = calcTotalValue(subNode->right, false);
  return currentValue + leftValue + rightValue;
}
void Bst::mirror(BstNode *subNode){
  if(subNode == NULL) return;
  BstNode *tmp = subNode->left;
  subNode->left = subNode->right;
  subNode->right = tmp;
  mirror(subNode->right);
  mirror(subNode->left);
}
Bst::Bst(){
  root = NULL;
  totalValue = 0;
}
bool Bst::isEmpty() {
  return root==NULL;
}
void Bst::add(const char item){
  SearchAndAdd(root,item);
}
bool Bst::find(const char item){
  return Search(root,item);
}
void Bst::inorder(){
  inorder(root);
}
void Bst::preorder(){
  preorder(root);
}
void Bst::postorder(){
  postorder(root);
}
void Bst::levelorder(){
  int h = height();
  for(int level = 0; level<=h; level++){
    printLevel(root,level);
  }
}
int Bst::height(){
  return height(root);
}
void Bst::deleteValue(char item){
  if(SearchAndDelete(root,item) == false) throw "Item not found";
}
void Bst::setTotalValue(){
  totalValue = calcTotalValue(root);
}

void Bst::printTree(){
  int h = height();
  int levelSpace = getWidth();
  levelSpace = (levelSpace-1)/2;
  int spaceCountForConnections = 0;
  for(int level = 0; level<=h; level++){
    int spaceCountForLevel = pow(2,(h-level)+2)-1;
    printSpace(levelSpace);
    printLevelSpecified(root,level,spaceCountForLevel);
    levelSpace = levelSpace - pow(2,(h-level));
    cout<<endl;
    printSpace(levelSpace);
    drawConnections(root,level,pow(2,(h-level-1)+2)-1,(pow(2,(h-level)+1)-1));
    cout<<endl;
  }
}
int Bst::getTotalValue(){
  return totalValue;
}
void Bst::mirrorTree(){
  mirror(root);
}
void Bst::clear(){
  while(!isEmpty()){
    DeleteNode(root);
  }
}
Bst::~Bst(){
  clear();
}