#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <stdexcept>


using namespace std;

template <class T>
class database {
    
    public:
        
        database() {};

        int getID(const T& x);
        T& getData(const int& x);
        void insert(const T& x);
        void remove(const T&x);
        string printAllValues();
        bool search(const int& index);

    private:

        unordered_map<int, T> db;

};

template<class T>
int database<T>::getID(const T &x){
    hash<T> hashFunction1;
    return hashFunction1(x) % db.size();
}

template<class T>
T& database<T>::getData(const int &x){
    return db.at(x);
}

template<class T>

void database<T>::insert(const T &x){
    hash<T> hashFunction1;
    hash<T> hashFunction2;
    cout<<"INSIDE INSERT FUNCTION"<<endl;
    int id = hashFunction1(x) % db.size();      
    cout<<"custom ID created"<<endl;

    //if a collision has occured this will generate a new ID and
    //and insert it into the database at that new value
    if(search(id)== true){
        cout<<"collision detected"<<endl;
        id = hashFunction1(x) % db.size() + hashFunction2(x) % db.size();
        db[id]  = x;

    }else{
        cout<<"no collision detected"<<endl;
        db[id] = x; 
    }


}

template<class T>
void database<T>::remove(const T &x){
    if(search(x) == false){
        cout << "Item not found" << endl;
        return;
    }
    db.erase(x);

    return;
}

template<class T>
string database<T>::printAllValues(){
    string result = "";

    for (auto& item : db) {
        cout << "Key: " << item.first << " Value: " << item.second << endl;
    }

    return result;
}

template<class T>
bool database<T>::search(const int &index){
    // Check if index exists in the database
    auto it = db.find(index);
    
    // If it points to db.end(), index does not exist in db
    if (it == db.end()) {
        return false;
    }

    return true;
}

#endif
