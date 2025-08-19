/**
* @file Main.cpp 
* @description Programin calistigi ana kaynak dosyasi
* @course Ikinci ogretim A grubu 
* @assignment 2. Odev
* @date 22.12.2024
* @author Omer Akkiyal omer.akkiyal@ogr.sakarya.edu.tr
*/

#include "../include/LinkedList.hpp"
#include <iostream>
#include <stdexcept>

int main() {
  try {
    LinkedList* agaclar = new LinkedList("agaclar.txt");
    agaclar->navigate();
    delete agaclar;
  } catch (const exception& e) {
    cerr << "Bir hata oluştu: " << e.what() << std::endl;
  } catch (...) {
    cerr << "Beklenmeyen bir hata oluştu!" << std::endl;
  }
  return 0;
}
