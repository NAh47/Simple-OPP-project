//Nahom Kiros
//CS 202
//Program 2
//11/21/21

/*tFor this program, I have created a system that will organize multiple events. In this program, I have tried
 * to perform most of the topics we have covered throughout the term.  polymorphism, dynamic binding, and operator
 * overloading and inheritance are some things I have tried to show in this program.  The program contains 5 classes.
 * The first class is the base class “event”. This class contains several operators overloaded and a display function
 * to display the list of visitors and a virtual display that will be overridden in the derived class, and for
 * data members, it has a vector of string for visitors name, id, and ticket buyer’s name to differentiate from other
 * events, and estimated duration and it will manage the details of the event. It also contains left and right pointers.
 * Therefore, it will be used as a node.
 * In this program, 3 classes are derived from the event class. These classes are “zoo”, “aquarium” and “bird sanctuary”.
 * Naturally, It would not make any sense to allow a client to change anything from a zoo. Therefore these classes are
 * built preset and have 3 methods such as the overloaded extraction and insertion operator and a display function to
 * display the list of animals.*/
#include <iostream>

#include <cstring>

#include <cctype>

#include <vector>

#include <algorithm>

using namespace std;

//details about the event will be handled by the event class
class event {
public:
    event();

    ~event();

    event(const event & to_copy);

    friend ostream & operator << (ostream & out,
                                  const event & );

    friend istream & operator >> (istream & inp, event & );
    //dsiplay for list of visitors
    void display_this(ostream & ) const;
    //virtual to display list of animals
    virtual void display(ostream & ) const;
    //inequality operators for strings
    event operator + (const string name_to_add); // adds name to visitors list

    event & operator += (const string name_to_add); // adds name to visitors list

    event operator - (const string name_to_remove); //removes a name from the visitors list

    event & operator -= (const string name_to_remove); // removes a name from the visitors list

    int get(); //id

    int read_in(istream & in ); //returns number of visitors, used to set capacity

    event & operator = (event & to_copy); //assignment operator
    event & operator += (event & to_copy);
    void assign_helper(event & , int & ); //helps set the vector

    int remove_visitor(const string, int & ); //removes visitor
    int visitors_num(); //number of visitors
    event * & go_left(); //traverse left
    event * & go_right(); //traverse right
    //inequality operators for event obj
    bool operator < (const event & to_compare);

    bool operator != (const event & to_compare);

    bool operator <= (const event & to_compare);

    bool operator >= (const event & to_compare);

    bool operator > (const event & to_compare);

    bool operator == (const event & to_compare);
    //inequality operators for integers
    bool operator != (const int to_compare);
    bool operator == (const int to_compare);

    bool operator < (const int to_compare);

    bool operator <= (const int to_compare);

    bool operator >= (const int to_compare);

    bool operator > (const int to_compare);

protected:
    event * left;
    event * right;
    vector < string > visitors; //name of visitors
    int id; //will be set by the manager when created, will be used to compare events in the BST
    int duration; //EVENT DURATION
    char * ticket_buyer; //used as a value to determine tree balance
};

//preset classes will be accessed using the void pointer in the node
//preset class
class zoo: public event {
public: friend ostream & operator << (ostream & out,
                                      const zoo & );

    friend istream & operator >> (istream & inp, zoo & );

    void display(ostream & ) const; //display list of animals, overriding

protected: vector < string > animal_list = {
            "Lions",
            "Wolves",
            "Elephants",
            "Snakes",
            "Lizards",
            "Monkeys",
            "Jaguars"
    };
};
//preset class

class birds: public event {
public: friend ostream & operator << (ostream & out,
                                      const birds & );

    friend istream & operator >> (istream & inp, birds & );

    void display(ostream & ) const; //display list of animals, overriding

protected: vector < string > bird_list = {
            "Pigeons",
            "Penguins",
            "Herons",
            "Cuckoos",
            "Swifts",
            "Owls",
            "Hummingbirds"
    };
};
//preset class

class aquatic: public event {
public: friend ostream & operator << (ostream & out,
                                      const aquatic & );

    friend istream & operator >> (istream & inp, aquatic & );

    void display(ostream & ) const; //display list of animals, overriding

protected: vector < string > aquatic_animals {
            "Sharks",
            "Dolphins",
            "Starfish",
            "Seals",
            "Squids",
            "Sponges",
            "Octopus"
    };
};
//==============================================================================================

class manager {
public:
    manager(); //constructor
    ~manager(); //destructor
    manager(const manager & tocopy); //CC
    void add_event(int); //adds event

    void remove_event(int choice); //
    event * remove_event(event * root, int x); //Removes by ticket buyer name converted to int
    void remove_all(); //Removes all
    event * & retrieve(event * & root, int given); //It is used by remove and display event methods
    void display(); //Display all

    void display_event(int); //display using ticket buyer name converted to sum of elements of the string
private:
    void display(event * & root); //display recursive
    void add_event(event * & , event * ); //add event recursive
    void destructor(event * & ); //clears the tree
    event * root; //tree
    int zoo_capacity;
    int aquarium_capacity;
    int bird_seeing_capacity;
};