//Nahom Kiros
//CS 202
//Program 2
//11/21/21

#include "list.h"

event::event(): id(0), duration(0) {
    left = NULL;
    right = NULL;
    ticket_buyer = NULL;
}

event::~event() {
    left = NULL;
    right = NULL;
    delete[] ticket_buyer;
    ticket_buyer = NULL;
    id = 0;
}

event::event(const event & to_copy) {
    left = NULL;
    right = NULL;
    id = to_copy.id;
    duration = to_copy.duration;
    ticket_buyer = new char[strlen(to_copy.ticket_buyer) + 1];
    strcpy(ticket_buyer, to_copy.ticket_buyer);
}

istream & operator >> (istream & in , event & name) {
    name.read_in( in );
    return in;
}

ostream & operator << (ostream & out,
                       const event & name) {
    name.display_this(out); //calls base class display method for visitors
    name.display(out); //calls derived class display method for list of animals
    return out;
}

event * & event::go_left() {
    return left;
}

event * & event::go_right() {
    return right;
}

void event::display_this(ostream & out) const {
    out << endl << "Visitors list:" << endl;
    for (int i = 0; i < visitors.size(); ++i) {
        out << "Visitor " << i + 1 << ":" << visitors[i] << endl;
    }
    cout << "Estimated duration:  " << duration / 60 << " Hr " << duration % 60 << " mins" << endl;
    cout << "Visit ID :" << id << endl;
}

void event::display(ostream & out) const {
    //virtual function
}

int event::read_in(istream & in ) {
    int size = 0;
    string temp;
    char * ticket_temp = new char[100];
    cout << "enter number of visitors" << endl;
    cin >> size;
    cout << "Enter Name of ticket buyer " << endl;
    cin >> ticket_temp;
    cin.ignore(100, '\n');
    ticket_buyer = new char[strlen(ticket_temp) + 1];
    strcpy(ticket_buyer, ticket_temp);
    cout << "Enter Name of Visitors" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "Visitor " << i + 1 << ":";
        cin >> temp;
        visitors.push_back(temp);
    }
    cout << endl << "Enter estimated duration in minutes" << endl;
    cin >> duration;
    //sets Id to the sum of ASCII code of each element.
    for (int i = 0; i < strlen(ticket_buyer); ++i) {
        id += tolower(ticket_buyer[i]);
    }
    return size;
}

event event::operator + (const string name_to_add) {
    event temp;
    temp.visitors.push_back(name_to_add);
    return temp;
}

event & event::operator += (const string name_to_add) {
    visitors.push_back(name_to_add);
    return *this;
}

event event::operator - (const string name_to_remove) {
    event temp;
    int locate = 0;
    locate = remove_visitor(name_to_remove, locate);
    temp.visitors[locate].erase();
    return temp;
}

int event::remove_visitor(const string to_remove, int & locate) {
    if (to_remove == visitors[locate]) {
        return locate;
    }
    remove_visitor(to_remove, ++locate);
    return locate;
}

event & event::operator -= (const string name_to_remove) {
    int locate = 0;
    locate = remove_visitor(name_to_remove, locate);
    visitors.erase(visitors.begin() + locate - 1);
    return *this;
}
//copys
event & event::operator = (event & to_copy) {
    if ( * this == to_copy) return *this;
    if (id != 0) {
        id = to_copy.id;
    }
    if (duration != 0) {
        duration = to_copy.duration;
    }
    ticket_buyer = new char[strlen(to_copy.ticket_buyer) + 1];
    strcpy(ticket_buyer, to_copy.ticket_buyer);
    int count = 0;
    assign_helper(to_copy, count);
    return *this;
}

int event::get() {
    return id;
}

void event::assign_helper(event & to_copy, int & count) {
    if (count == to_copy.visitors.size()) return;
    visitors.push_back(to_copy.visitors[count]);
    assign_helper(to_copy, ++count);

}

bool event::operator < (const event & to_compare) {
    if (id < to_compare.id) {
        return true;
    } else {
        return false;
    }
}
event & event::operator += (event & to_copy) {
    id = to_copy.id;
    duration = to_copy.duration;
    ticket_buyer = new char[strlen(to_copy.ticket_buyer) + 1];
    strcpy(ticket_buyer, to_copy.ticket_buyer);
    int count = 0;
    assign_helper(to_copy, count);
    return *this;
}
bool event::operator <= (const event & to_compare) {
    if (id <= to_compare.id) {
        return true;
    } else {
        return false;
    }
}

bool event::operator >= (const event & to_compare) {
    if (id >= to_compare.id) {
        return true;
    } else {
        return false;
    }
}

bool event::operator > (const event & to_compare) {
    if (id > to_compare.id) {
        return true;
    } else {
        return false;
    }
}

bool event::operator == (const event & to_compare) {
    if (id > to_compare.id) {
        return true;
    } else {
        return false;
    }
}

bool event::operator != (const event & to_compare) {
    if (id != to_compare.id) {
        return true;
    } else {
        return false;
    }
}

// in equalities for int

bool event::operator < (const int to_compare) {
    if (id < to_compare) {
        return true;
    } else {
        return false;
    }
}

bool event::operator <= (const int to_compare) {
    if (id <= to_compare) {
        return true;
    } else {
        return false;
    }
}

bool event::operator >= (const int to_compare) {
    if (id >= to_compare) {
        return true;
    } else {
        return false;
    }
}

bool event::operator > (const int to_compare) {
    if (id > to_compare) {
        return true;
    } else {
        return false;
    }
}

bool event::operator == (const int to_compare) {
    if (id > to_compare) {
        return true;
    } else {
        return false;
    }
}

bool event::operator != (const int to_compare) {
    if (id != to_compare) {
        return true;
    } else {
        return false;
    }
}

int event::visitors_num() {
    return visitors.size();
}

//============================================================

ostream & operator << (ostream & out,
                       const zoo & animal) {
    animal.display(out);
    return out;
}

void zoo::display(ostream & out) const {
    //event::display(out);
    cout << endl << "WELCOME TO THE ZOO" << endl;
    out << endl << "Animals available to visit :" << endl;
    for (int i = 0; i < animal_list.size(); ++i) {
        out << i + 1 << "). " << animal_list[i] << '\t';
    }
    cout << endl;
}

ostream & operator << (ostream & out,
                       const aquatic & animal) {
    animal.display(out);
    return out;
}

void aquatic::display(ostream & out) const {
    //event::display(out);
    cout << endl << "WELCOME TO THE AQUARIUM" << endl;
    out << "Animals available to visit :" << endl;
    for (int i = 0; i < aquatic_animals.size(); ++i) {
        out << i + 1 << "). " << aquatic_animals[i] << '\t';
    }
}

ostream & operator << (ostream & out,
                       const birds & animal) {
    animal.display(out);
    return out;
}

void birds::display(ostream & out) const {
    //event::display(out);
    cout << endl << "WELCOME TO THE BIRD SANCTUARY" << endl;
    out << "Animals available to visit :" << endl;
    for (int i = 0; i < bird_list.size(); ++i) {
        out << i + 1 << "). " << bird_list[i] << '\t';
    }
}