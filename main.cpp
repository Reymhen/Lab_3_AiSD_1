#include <iostream>
#include "Tree.h"

using namespace std;

void print_bft(Tree* heap) {
    Iterator* iter = heap->create_bft_iterator();
    while (iter->has_next()) {
        cout << iter->next() << ' ';
    }
    cout << '\n';
}
void print_dft(Tree* heap) {
    Iterator* iter = heap->create_dft_iterator();
    while (iter->has_next()) {
        cout << iter->next() << ' ';
    }
    cout << '\n';
}

int main()
{
   
        Tree MyTree;
        cout << "Create a tree" << endl;
        MyTree.insert(10);
        MyTree.insert(5);
        MyTree.insert(7);
        MyTree.insert(2);
        MyTree.insert(9);
        cout << "Implementing Breadth-first traversal of a binary tree" << endl;
        print_bft(&MyTree);
        cout << "Implementing Depth-first traversal of a binary tree" << endl;
        print_dft(&MyTree);
        cout << "Add elements to the tree" << endl;
        MyTree.insert(15);
        MyTree.insert(20);
        MyTree.insert(12);
        MyTree.insert(22);
        MyTree.insert(25);
       

        cout<< "Implementing Breadth-first traversal of a binary tree" <<endl;
      print_bft(&MyTree); 
      cout << "Implementing Depth-first traversal of a binary tree" << endl;
        print_dft(&MyTree);

        cout << "Check if there is an element 10 in the tree: \n0 he is not \n1 he is \n";
        cout << MyTree.contains(10) << endl;
        cout << "remove element 10 \n";
        MyTree.remove(10);
        cout << "Check if there is an element 10 in the tree: \n0 he is not \n1 he is \n";
        cout << MyTree.contains(10) << endl;

   
    
}