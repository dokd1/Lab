#include <iostream>
#include "BST.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
    binaryTree<int> avl;
    int choice;
    int value;
    string file_Name;
    fstream Data_file;

    cout << "Enter the file name (W/O File Format): ";
    cin >> file_Name;
    file_Name = file_Name + ".txt";
    Data_file.open(file_Name,ios::in);

    if (Data_file.fail())
    {
        do
        {
            cout << endl;
            cout << "The file you are trying to open failed" << endl;
            cout << "Enter the file name again: ";
            cin >> file_Name;
            file_Name = file_Name + ".txt";
            Data_file.open(file_Name, ios::in); 							//tries to open the file until it successfully doesn't open
        } while (Data_file.fail());
    }




    //Prompts for user inputs
    do {
        cout << "1) Insert a value in the Binary Tree" << endl;
        cout << "2) Find a value" << endl;
        cout << "3) Size" << endl;
        cout << "4) Get All Ascending" << endl;
        cout << "5) Get All Descending" << endl;
        cout <<"6) Remove value from tree" << endl;
        cout << "7) Exit" << endl;
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            cout << endl;
            root = avl.insert(root,value);
        }
        else if (choice == 2) {
            if (root == NULL) {
                cout << "TREE IS EMPTY" << endl;
                cout << endl;
            }
            else {
                cout << "Enter value to find: ";
                cin >> value;
                if (avl.find(root,value) == NULL) {
                    cout <<"Value was not found." << endl;
                    cout << "Please insert the word: ";
                    cin >> value;
                    root = avl.insert(root,value);
                    cout << endl;
                    cout << endl;
                }
                else {
                    cout << "The count for the word is ";
                    avl.find(root,value);
                    cout << endl;
                }
            }
        }
        else if (choice == 3) {
            int size;
            size = avl.size(root);
            cout << "Size of tree: " << size << endl;
            cout << endl;
        }
        else if (choice == 4) {
            if (root == NULL) {
                cout << "TREE IS EMPTY" << endl;
                cout << endl;
            }
            else {
                cout << "Tree in Ascending Order: " << endl;
                avl.getAllAscending(root);
                cout << endl;
                cout << endl;
            }
        }
        else if (choice == 5) {
            if (root == NULL) {
                cout << "TREE IS EMPTY" << endl;
                cout << endl;
            }
            else {
                cout << "Tree in Descending Order: " << endl;
                avl.getAllDescending(root);
                cout << endl;
                cout << endl;
            }
        }
        else if (choice == 6) {
            if (root == NULL) {
                cout << "TREE IS EMPTY" << endl;
                cout << endl;
            }
            else {
            cout << "Enter value to remove from tree: ";
            cin >> value;
            cout << endl;
            avl.remove(value, root);
            }
        }
        else if (choice <= 0 || choice > 7) {
            cout << endl;
            cout << "INVALID INPUT, PLEASE TRY AGAIN" << endl;
            choice = 1;
        }
    } while(choice < 7);

   return 0;
}
