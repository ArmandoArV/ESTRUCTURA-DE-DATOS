/*
 Created by Armando on 30/11/2022.
*/

// carnegietech.org
#include<iostream>
#include<fstream>
#include "Store.h"
using namespace std;
#define USAGE  argv[0]
int main(int  argc, char *argv[])  {
    cout << "Welcome to our online store!" << endl;
    if (argc > 1)  {
        cerr << USAGE << endl;
        return  EXIT_FAILURE;
    }
    char  file_name[12];
    cerr << "Enter products file name:  " << flush;
    cin >> file_name;
    Store  store(file_name);
    if (store.is_open())  {
        istream *in;
        cerr << "Enter transactions file name (\"-\" for standard input):  " <<
             flush;
        cin >> file_name;
        if (file_name == "-")  {
            in = &cin;
        }
        else
        {in = new  ifstream(file_name);
            if (!in  ) {
                cerr << "ERROR:  Failed to open file...aborting." << endl;
                return  EXIT_FAILURE;
            }
        }
        string  customer_name;
        string  command;
        int  quantity;
        string  product_name;
        string  junk;  // to clear a junk line
        while ((*in >> customer_name >> command).good())  {
            if (command == Store::SHOWCART || command == Store::CHECKOUT)  {
                store.process_cart(customer_name, command);
            }
            else
            if (command == Store::BUYS || command == Store::RETURNS)  {
                if ((*in >> quantity >> product_name).good())  {
                    store.process_cart(customer_name, command, quantity,
                                       product_name);
                }
                else  {
                    if (!in->bad())  {
                        cerr << "Input error...skipping line" << endl;
                        in->clear();
                        *in >> junk;
                    }
                    else  {
                        cerr << "Input error...cannot
                        recover...aborting." << endl;
                        system("pause");
                        return  EXIT_FAILURE;
                    }
                }
            }
            else  {
                cerr << "Illegal command \"" << command <<
                     "\"...skipping line." << endl;
                *in >> junk;
            }
        }
        if (in->eof())  {
            store.close(cout);
            system("pause");
            return  EXIT_SUCCESS;
        }
        else  {
            cerr << "Input error...cannot recover...aborting." << endl;
            system("pause");
            return  EXIT_FAILURE;
        }
    }
    else  {
        cerr << "Store remains empty...exiting." << endl;
        system("pause");
        return  EXIT_FAILURE;
    }
    system("pause");
}Ï