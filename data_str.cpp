//Nahom Kiros
//CS 202
//Program 2
//11/21/21

#include "list.h"

manager::manager(): zoo_capacity(50), aquarium_capacity(20),
                    bird_seeing_capacity(70) {
    root = NULL;
}
manager::~manager() {
    destructor(root); //calls the destructor method to clear the bst
}
manager::manager(const manager & tocopy) {
    //copy values from tocopy
    zoo_capacity = tocopy.zoo_capacity;
    aquarium_capacity = tocopy.aquarium_capacity;
    bird_seeing_capacity = tocopy.bird_seeing_capacity;
    //sets the root null, if there was anything
    if (root) {
        destructor(root); //clears the BST
    }
    add_event(root, tocopy.root); //adds all the nodes
}
void manager::add_event(int choice) {
    event * temp; //temp event
    if (choice == 1) {
        if (aquarium_capacity > 0) {
            temp = new aquatic;
        } else {
            cout << "AQUARIUM IS FULL TO BOOK" << endl;
            return;
        }
    }
    if (choice == 2) {
        if (bird_seeing_capacity > 0) {
            temp = new birds;

        } else {
            cout << "BIRD SANCTUARY IS FULL TO BOOK" << endl;
            return;
        }
    }
    if (choice == 3) {
        if (zoo_capacity > 0) {
            temp = new zoo;

        } else {
            cout << "ZOO IS FULL TO BOOK" << endl;
            return;
        }
    }
    cin >> * temp;
    if (choice == 1) {
        aquarium_capacity -= temp -> visitors_num();
    } else if (choice == 2) {
        bird_seeing_capacity -= temp -> visitors_num();
    } else if (choice == 3) {
        zoo_capacity -= temp -> visitors_num();
    }
    add_event(root, temp);
}
void manager::add_event(event * & root, event * temp) {

    if (!root) {
        root = temp;
        root -> go_right() = root -> go_left() = NULL;
        return;
    }
    if ( * root < * temp) {
        add_event(root -> go_right(), temp);
    } else {
        add_event(root -> go_left(), temp);
    }
}
void manager::remove_event(int x) {
    if (!root) return;
    else if (root) {
        if (!root -> go_right() && !root -> go_left()) {
            delete root;
            root = NULL;
        }
    }
    root = remove_event(root, x);
}
event * manager::remove_event(event * root, int x) {
    if (root == NULL)
        return root;

    if (root -> get() > x) {
        root -> go_left() = remove_event(root -> go_left(), x);
        return root;
    } else if (root -> get() < x) {
        root -> go_right() = remove_event(root -> go_right(), x);
        return root;
    }

    if (root -> go_left() == NULL) {
        event * temp = root -> go_right();
        delete root;
        return temp;
    } else if (root -> go_right() == NULL) {
        event * temp = root -> go_left();
        delete root;
        return temp;
    }
        // if left and right exists
    else {
        event * successor_root = root;
        // finding the successor
        event * successor = root -> go_right();
        while (successor -> go_left() != NULL) {
            successor_root = successor;
            successor = successor -> go_left();
        }
        if (successor_root != root)
            successor_root -> go_left() = successor -> go_right();
        else
            successor_root -> go_right() = successor -> go_right();
        // Copy Successor Data to root
        root = successor;
        // remove succesor and return root
        delete successor;
        return root;
    }
}

void manager::remove_all() {
    if (!root) return;
    destructor(root); //removes all
}

event * & manager::retrieve(event * & root, int given) {
    if (!root) return root;
    if (root -> get() == given) return root;
    if (root -> get() < given) {
        return retrieve(root -> go_right(), given);
    }
    if (root -> get() > given) {
        return retrieve(root -> go_left(), given);
    }
}

void manager::display() {
    if (!root) {
        cout << "NO EVENT FOUND" << endl;
        return;
    }
    return display(root);
}

void manager::display(event * & root) {
    if (!root) return;
    if (root -> go_left()) {
        display(root -> go_left());
    }
    cout << * root << endl;
    if (root -> go_right()) {
        display(root -> go_right());
    }
}

void manager::display_event(int look) {
    event * current = retrieve(root, look); //the node found
    if (current) {
        cout << "Event found" << endl;
        cout << * current;
    } else {
        cout << "No activity found with the given name" << endl;
    }
}

void manager::destructor(event * & root) {
    if (!root) return;
    destructor(root -> go_left());
    destructor(root -> go_right());
    delete root;
    root = NULL;
}