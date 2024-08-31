#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class Address {
private:
    std::string city;
    std::string street;
    std::string house;
    std::string flat;
public:
    Address(std::string city, std::string street, std::string house, std::string flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    };
  
   

    std::string get_output_address() {

        return city + ", " + street + ", " + house + ", " + flat;
    }
};

std::string* create_arr(int address_count) {
    std::string* arr = new std::string[address_count]{};
    return arr;
}



int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
     SetConsoleOutputCP(1251);
    
    std::ifstream infile("in.txt");
    std::string city;
    std::string street;
    std::string house;
    std::string flat;
    int address_count = 0;
    infile >> address_count;
   std::string* ad = create_arr(address_count); // массив для хранения адресов, 

   for (int i = 0; i < address_count; i++) {
        infile >> city >> street >> house >> flat;
        Address adress(city, street, house, flat);
        ad[i] = adress.get_output_address();

    }


    std::ofstream outfile("out.txt");
    outfile << address_count << std::endl;
    for (int i = 0; i < address_count; i++) {
        outfile << ad[i] << std::endl;
    }
    delete[] ad;
    infile.close();
}
