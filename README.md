# BST ve Bağlı Liste Ödevi

Bu proje **Veri Yapıları** dersi kapsamında hazırlanmıştır. Amaç, **İkili Arama Ağacı (Binary Search Tree - BST)** ve **tek yönlü bağlı liste (singly linked list)** yapılarını kullanarak temel veri yapıları kavramlarını uygulamaktır.  

## 📌 Proje Açıklaması
- Girdi dosyasındaki her satırdan bir **BST** oluşturulur.  
- Oluşturulan her BST, **tek yönlü bağlı liste** içerisinde saklanır.  
- Kullanıcı, program üzerinde çeşitli işlemler yapabilir:
  - **a/d tuşları** → listede ağaçlar arasında gezinme  
  - **s tuşu** → ilgili düğümü (ağacı) silme  
  - **w tuşu** → mevcut ağacı aynalama (mirror)  
  - **ASCII tabanlı hesaplama** → karakterlerin ASCII değerleri ile işlem yapılması  

## 📂 Klasör Yapısı
- `src/` → Kaynak dosyalar (.cpp)  
- `include/` → Başlık dosyaları (.h)  
- `lib/` → Derlenmiş nesne dosyaları (.o)  
- `bin/` → Çalıştırılabilir dosyalar (.exe)  
- `doc/` → Ödev raporu (PDF)  
- `makefile` → Derleme talimatı  

## ⚙️ Kullanım
Projeyi derlemek için:  
```bash
mingw32-make
