#include "database.h"

#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <stdexcept>
#include <chrono>


using namespace std;


int main(){
    cout<< "Welcome to Database Creator!"<<endl<<endl;
    string decision;
    while(true){

        cout<<"What datatype would you like your database to store?"<<endl;
        cout<< "If youa'd like to quit, press: 'Q' or 'q'."<<endl;
        cout<< "Your options are: strings (enter as: string), integers( enter as: int), and doubles (enter as: double) ";
        cin>> decision;

        if(decision == "string" || decision == "String" ||decision == "STRING"){


            database<string> str;

            cout<< endl << "Creating your database... "<< endl;

            //this_thread::sleep_for(chrono::seconds(2));

            cout<< endl << endl <<"Your database has been created!"<<endl;
    
        }

        
        else if(decision == "int" || decision =="Int" || decision =="INT"){
            database<int> integer;

            cout<< endl << "Creating your database... "<< endl;

            //this_thread::sleep_for(chrono::seconds(2));

            cout<< endl << endl <<"Your database has been created!"<<endl;

        }
        
        else if(decision == "double" || decision =="Double" || decision =="DOUBLE"){
            database<double> db;

            cout<< endl << "Creating your database... "<< endl;

            //this_thread::sleep_for(chrono::seconds(2));

            cout<< endl << endl <<"Your database has been created!"<<endl;

        }
        
        else if(decision == "Q" || decision == "q"){
            break;
        }

        else{
            cout<<"Error: Invalid response... Please Try again"<<endl<<endl<<endl;
        }

    }
    
    



    return 0;
}

