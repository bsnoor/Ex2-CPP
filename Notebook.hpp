#include <iostream>
#include <string>
#include <map>
#include "Direction.hpp"
#include <stdexcept>
using ariel::Direction;
using namespace std;
 namespace ariel
{
    const  int c_length =100;
    class Notebook {
        public :
          map<unsigned int,std::map<unsigned int,char>> m;
          Notebook(){};
         // Notebook (std::string t= "new tile ");
          void write(unsigned int i ,  unsigned int j ,unsigned int c, Direction d,  string const &ad);
         static string read(unsigned int i ,  unsigned int j,  unsigned int c , Direction d , unsigned int l);
          void erase (unsigned int i , unsigned int j,  unsigned int  c , Direction d , unsigned int l);
          void show(unsigned int i);
       



    };
}