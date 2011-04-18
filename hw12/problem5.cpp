/*********************
* hw12-5 extracredit
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    node() :  key_value(0), left(NULL), right(NULL) {};
    //move constructor problem5
    node(node&& other){
        key_value = move(other.key_value);
        left = move(other.left);
        right = move(other.right);
        delete &other;
    }
    //move assignment problem5
    node& operator=(node&& other){
        key_value = move(other.key_value);
        left = move(other.left);
        right = move(other.right);
        delete &other;
        return *this;
    }
    int key_value;
    node *left;
    node *right;
};

class btree
{
public:
    btree();
    ~btree();
    //move constructor problem5
    //btree(btree&& other);

    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void print(); //for test
    node *root;
private:
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void print(node *leaf); //for test
    void mtree(node *leaf_s, node* leaf_d); //problem5
};

btree::btree()
{
    root = NULL;
}

void btree::insert(int key, node *leaf)
{
    if(key < leaf->key_value){
        if(leaf->left != NULL)
            insert(key, leaf->left);
        else{
            leaf->left = new node();
            leaf->left->key_value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(key > leaf->key_value){
        if(leaf->right != NULL)
            insert(key, leaf->right);
        else{
            leaf->right = new node();
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }else{}
}

node *btree::search(int key, node *leaf)
{
    if(leaf != NULL){
        if(key == leaf->key_value)
            return leaf;
        if(key <  leaf->key_value)
            return search(key, leaf->left);
        if(key > leaf->key_value)
            return search(key, leaf->right);
    }else
        return NULL;
}

void btree::destroy_tree(node *leaf)
{
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key)
{
    if(root != NULL)
        insert(key, root);
    else{
        root = new node();
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *btree::search(int key)
{
    return search(key, root);
}

void btree::destroy_tree()
{
    destroy_tree(root);
}

//for test
void btree::print()
{
    print(root);
}

void btree::print(node *leaf)
{
    if(leaf->left != NULL)
        print(leaf->left);
    if(leaf->right != NULL)
        print(leaf->right);
    cout << leaf->key_value << " ";
    if(leaf == root)
        cout << endl;
}

//move constructor problem5
void btree::mtree(node *leaf_s, node* leaf_d)
{
    leaf_d = move(leaf_s);
    if(leaf_s->left != NULL)
        mtree(leaf_s->left, leaf_d->left);
    if(leaf_s->right != NULL)
        mtree(leaf_s->right, leaf_d->right);
}

btree::btree(btree&& other)
{
    mtree(root, other.root);
    other.destroy_tree();
}

int main()
{
    btree *t = new btree();
    t->insert(1);
    t->insert(4);
    t->insert(3);
    t->insert(0);
    t->insert(6);
    t->insert(5);
    cout << "tree t: ";
    t->print();
    cout << "tree g: ";
    btree *g(move(t));
    g->print();
    
    return 0;
}