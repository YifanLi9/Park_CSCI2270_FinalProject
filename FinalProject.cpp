// Seungjeong Park
// CSCI 2270 Hoegniman
// Final Project

#include <iostream>
#include "ItemTree.h"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    ItemTree Item;
    
    ifstream infile;
    infile.open(argv[1]);
    string line;
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            int commaPos1 = line.find(',');
            string item = line.substr(0, commaPos1);
            
            int price = stoi(line.substr(commaPos1+1));
            
            Item.addItemNode(item, price);
        }
        
        infile.close();
    }
    
    int input;
    while (input != 9)
    {
        Item.meun();
        cin >> input;
        cin.ignore(10000,'\n');
        switch (input) {
            case 1:
            {
                string item;
                cout << "What item are you trying to sell:" << endl;
                getline(cin, item);
                
                int price;
                cout << "For what price are you expecting?:" << endl;
                cin >> price;
                
                Item.addItemNode(item, price);
                break;
            }
                
            case 2:
            {
                string itemDelete;
                cout << "What's item that is sold already?:" << endl;
                getline(cin, itemDelete);
                
                Item.deleteItemNode(itemDelete);
                break;
            }
                
                
            case 3:
            {
                string itemFind;
                cout << "What item are you trying to search?:" << endl;
                getline(cin, itemFind);
                
                Item.findItem(itemFind);
                break;
            }
                
            case 4:
            {
                cout << Item.countItemNodes() << " items remain unsold" << endl;
                break;
                
            }
                
            case 5:
            {
                Item.printInOrder();
                break;
            }
                
            case 6:
            {
                Item.printPreOrder();
                break;
            }
                
            case 7:
            {
                Item.printPostOrder();
                break;
            }
                
            case 8:
            {
                Item.printSold();
                break;
            }
            case 9:
                break;
        }
        
        cout << "Quit" << endl;
    }
    return 0;
}
