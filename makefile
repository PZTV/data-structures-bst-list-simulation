hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/BstNode.o -c ./src/BstNode.cpp
	g++ -I ./include/ -o ./lib/Bst.o -c ./src/Bst.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./bin/Main ./lib/BstNode.o ./lib/Bst.o ./lib/Node.o ./lib/LinkedList.o ./src/Main.cpp
calistir:
	cls
	./bin/Main