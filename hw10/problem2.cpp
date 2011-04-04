#include <iostream>
#include <string>
using namespace std;

struct node
{
    node() {}
    node(string q, string a, node *y, node *n) : question(q), animal(a), yAns(y), nAns(n) {}
    string question, animal;
    node *yAns, *nAns;
};

node *treeInit()
{
    node *root, *yLeaf, *nLeaf;
    
    nLeaf = new node("Is your animal a ", "dog", NULL, NULL);
    yLeaf = new node("Is your animal a ", "whale", NULL, NULL);
    root = new node("Does your animal only live in water", "", yLeaf, nLeaf);
    
    return root;
}

int main()
{
    node *curNode = treeInit();
    node *root = curNode;
    node *lastNode;
    string str;
    int flag = 0, game = 1;
    while(game){
        cout << "********************Game Start********************" << endl;
        while(curNode != NULL){
            cout << curNode->question << curNode->animal << " (Yes/No)? ";
            getline(cin, str);
            if(str.compare("Yes") == 0){
                lastNode = curNode;
                curNode = curNode->yAns;
                flag = 1;
            }else if(str.compare("No") == 0){
                lastNode = curNode;
                curNode = curNode->nAns;
                flag = 0;
            }else{
                cout << "- Only accept Yes/No (case sensitive)" << endl;
            }
        }
        if(flag == 1){
            cout << "Woohoo you were thinking of " << lastNode->animal << "!" << endl;
        }
        if(flag == 0){
            cout << "What's your animal: ";
            getline(cin, str);
            node *newYLeaf = new node("Is your animal a ", str, NULL, NULL);
            node *newNLeaf = new node(lastNode->question, lastNode->animal, NULL, NULL);
            cout << "Give a new question to distinguish these two animals('Yes' for your animal): " << endl;
            getline(cin, str);
            lastNode->question = str;
            lastNode->animal = "";
            lastNode->yAns = newYLeaf;
            lastNode->nAns = newNLeaf;
        }
        cout << "Do you want to continue? (Yes/No) ";
        getline(cin, str);
        if(str.compare("Yes") == 0){
            game = 1;
        }else{
            game = 0;
        }
        curNode = root;
    }
    
    return 0;
}