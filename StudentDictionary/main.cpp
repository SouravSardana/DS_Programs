#include "Student.h"
#include "Chaining.h"
#include "LinearProbing.h"
#include "DoubleHashing.h"
#include "Dictionary.h"

#include <iostream>

int main() {
    cout<<"How many entries do you wish to enter in total? ";
    int total_size;
    cin>>total_size;
    
    //select hashing function
    cout<<"\nWhich Hashing function do you wanna use? \n1.component_sum() \n2.polynomial_accumulation() \n3.Universal_Hashing()";
    cout<<"\nEnter your choice : ";
    int hashing_choice;
    cin>>hashing_choice;
    while (hashing_choice<1 || hashing_choice>3) {
        cout<<"\nInvalid Choice. Try again!";
        cout<<"\nEnter your choice : ";
        cin>>hashing_choice;
    }
    
    //select collision resolving technique
    cout<<"\nWhich collision resolving technique you wanna use? \n1.Chaining \n2.Linear Probing \n3.Double Hashing";
    cout<<"\nEnter your Choice : ";
    int collision_choice;
    cin>>collision_choice;
    while (collision_choice<1 || collision_choice>3) {
        cout<<"\nInvalid Choice. Try again!";
        cout<<"\nEnter your choice : ";
        cin>>collision_choice;
    }
    
    Dictionary d(total_size);
    
    int entries_left = total_size;
    
    while (1) {
        //User Menu
        cout << "\nMENU: \n1.Insert data into Dictionary. \n2.Delete data from Dictionary. \n3. Search data from dictionary. \n4.Find Average lookups. \n5. Quit.";
        cout<<"\nEnter your Choice: ";
        int op_choice = 4;
        cin>>op_choice;

        switch (op_choice) {
            //Insert into table
            case 1:
                if (entries_left-- >0) {
                    string rollno, name, address, dob;
                    
                    //Input data
                    cout<<"Enter Roll No.: ";
                    cin>>rollno;
                    cout<<"Enter name : ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"Enter Address : ";
                    getline(cin, address);
                    cout<<"Enter date of birth : ";
                    cin>>dob;
                    
                    Student s(rollno, name, address, dob); // create student object
                    cout<<"\n1.Count lookups when inserting. \n2. Continue without lookups. \nEnter your choice: ";
                    int lookup_choice = 1;
//                    cin>>lookup_choice;
                    while (lookup_choice<1 || lookup_choice>2) {
                        cout<<"\nInvalid Choice. Try again!";
                        cout<<"\nEnter your choice : ";
                        cin>>lookup_choice;
                    }
                    
                    //count lookups
                    if (lookup_choice == 1) {
                        cout<<"No. of Lookups : "<<d.insert_c(s, hashing_choice, collision_choice) << "\n";
                    } 
                    //do not count lookups
                    else if (lookup_choice == 2) {
                        d.insert(s, hashing_choice, collision_choice);
                        cout<<"Data Inserted!\n";
                    }
                }
                else {
                    cout<<"\nCannot Insert more items!\n";
                }
                break;

            // Delete from Dictionary
            case 2: {
                cout << "Enter Roll no. to be deleted : ";
                string rollno;
                cin >> rollno;

                cout << "\n1.Count lookups when deleting. \n2. Continue without lookups. \nEnter your choice: ";
                int lookup_choice = 1;
//                cin >> lookup_choice;
                while (lookup_choice < 1 || lookup_choice > 2) {
                    cout << "\nInvalid Choice. Try again!";
                    cout << "\nEnter your choice : ";
                    cin >> lookup_choice;
                }

                //count lookups
                if (lookup_choice == 1) {
                    cout<<"No. of Lookups : "<<d.remove_c(rollno, hashing_choice, collision_choice);
                }
                    //do not count lookups
                else if (lookup_choice == 2) {
                    d.remove(rollno, hashing_choice, collision_choice);
                    cout<<"Data deleted!\n";
                }

                break;
            }
            //search from dictionary
            case 3: {
                cout << "Enter Roll no. to be searched : ";
                string rollno;
                cin >> rollno;

                cout << "\n1.Count lookups when searching. \n2. Continue without lookups. \nEnter your choice: ";
                int lookup_choice = 1;
//                cin >> lookup_choice;
                while (lookup_choice < 1 || lookup_choice > 2) {
                    cout << "\nInvalid Choice. Try again!";
                    cout << "\nEnter your choice : ";
                    cin >> lookup_choice;
                }

                //count lookups
                if (lookup_choice == 1) {
                    cout<<"No. of Lookups : "<<d.search_c(rollno, hashing_choice, collision_choice);
                }
                    //do not count lookups
                else if (lookup_choice == 2) {
                    bool flag = d.search(rollno, hashing_choice, collision_choice);
                    if (flag)
                        cout<<"Value Found!\n";
                    else
                        cout<<"Value not found!\n";
                }
                break;

            }

            case 4:
                cout<<"Average lookups : "<< d.avg_lookups()<< "\n";
                break;

            case 5:
                exit(0);

            default: 
                cout<<"\nInvalid choice! Try again.";
        }
    }
}