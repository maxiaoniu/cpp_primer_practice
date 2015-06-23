#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
struct Person;
std::istream &read(std::istream &in, Person &person);
struct Person {
    Person() = default;
    Person(const std::string &name, const std::string &address):name(name),address(address){}
    Person(std::istream &in){read(in,*this);}

    std::string  getName() const{
        return name;
    }
    std::string getAddress() const{
        return address;
    }
    std::string name;
    std::string address;
};

std::istream &read(std::istream &in, Person &person)
{
    in>>person.name>>person.address;
    return in;
}
std::ostream &print(std::ostream &out, Person &person)
{
    out<<person.name<<" "<< person.address;
    return out;
}

#endif // PERSON_H

