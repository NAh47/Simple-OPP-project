//Nahom Kiros
//CS 202
//Program 2
//11/21/21

#include "list.h"

void interface(manager & );

int convert(string);

int main() {
    manager my_manager;
    interface(my_manager);
}
void interface(manager & my_manager) {
    cout << "!! WElCOME !!  " << endl;
    bool option_check = false;
    bool loop = false;
    int option = 0;
    while (!loop) {
        while (!option_check) {
            cout << endl << "  MAIN MENU  " << endl;
            cout << " SELECT OPTIONS (1 -6)" << endl;
            cout << " 1) ADD EVENT" << endl;
            cout << " 2) DISPLAY ALL EVENTS" << endl;
            cout << " 3) DISPLAY EVENT BY NAME OF A VISITOR" << endl;
            cout << " 4) REMOVE EVENT BY NAME OF VISITOR" << endl;
            cout << " 5) REMOVE ALL EVENTS" << endl;
            cout << " 6) QUIT" << endl;
            cin >> option;
            cin.ignore(100, '\n');
            option_check = true; //quit the loop if the right valued is entered
            if (option < 1 || option > 6) {
                option_check = false;
            }
        }
        option_check = false;

        switch (option) {
            case 1: { //add actitvty, calls
                int temp = 0;
                cout << endl << "SELECT EVENT (1 -3)" << endl;
                cout << "  1) AQUARIUM" << endl;
                cout << "  2) BIRD SANCTUARY" << endl;
                cout << "  3) ZOO" << endl;
                while (temp < 1 || temp > 3) {
                    cin >> temp;
                    cin.ignore(100, '\n');
                }
                my_manager.add_event(temp);
                break;
            }
            case 2: {
                my_manager.display();
                break;
            }
            case 3: {
                string temp;
                cout << endl << "Enter the name of the ticket buyer" << endl;
                cin >> temp;
                cin.ignore(100, '\n');
                my_manager.display_event(convert(temp));
                break;
            }
            case 4: {
                string temp;
                cout << endl << "Enter the name of the ticket buyer" << endl;
                cin >> temp;
                cin.ignore(100, '\n');

                int ret_no = convert(temp);
                my_manager.remove_event(ret_no);
                break;
            }
            case 5: {

                my_manager.remove_all();
                break;
            }
            case 6: {
                option_check = true;
                loop = true;
                break;
            }
            default:
                break;
        }
    }
}

int convert(string given) {
    int converted;
    for (int i = 0; i < given.size(); ++i) {
        converted += tolower(given[i]);
    }
    return converted;
}