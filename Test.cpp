#include "Notebook.hpp"
#include"Direction.hpp"
#include <iostream>
#include <string>
#include <map>
#include "doctest.h"
using namespace std;
using namespace ariel;
const  int lenght_row = 100;
  Notebook notebook;
TEST_CASE("GOOD"){

    
     notebook.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, "abcd");
     CHECK(notebook.read(100,100 ,50 ,Direction::Horizontal,4) == "abcd");
    notebook.erase(/*page=*/100, /*row=*/99, /*column=*/51, Direction::Vertical, /*length=*/3);
    CHECK(notebook.read(100,99,51,Direction::Vertical,3)=="~~~");
    notebook.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Vertical, "abcd");
     CHECK(notebook.read(100,100 ,50 ,Direction::Vertical,4) == "abcd");
     CHECK(notebook.read(0,0,0,Direction::Horizontal,4)=="~~~~");
     CHECK(notebook.read(0,0,0,Direction::Vertical,4)=="~~~~");  
     notebook.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
     CHECK(notebook.read(100,99 ,52 ,Direction::Vertical,3) == "xyz");

}
TEST_CASE("BAD"){
     CHECK_THROWS(notebook.write(/*page=*/0, /*row=*/0, /*column=*/99, Direction::Horizontal, "abcd"));
     CHECK_THROWS(notebook.write(/*page=*/0, /*row=*/99, /*column=*/0, Direction::Vertical, "abcd"));
     CHECK_THROWS(notebook.erase(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Horizontal, 3));
     CHECK_THROWS(notebook.erase(/*page=*/0, /*row=*/15, /*column=*/0, Direction::Vertical, 4));
     CHECK_THROWS(notebook.read(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Vertical, 1));
     CHECK_THROWS(notebook.erase(/*page=*/8,/*row=*/6, /*column=*/0, Direction::Horizontal,4));
     CHECK_THROWS(notebook.erase(/*page=*/7, /*row=*/0, /*column=*/0, Direction::Vertical, 3));
     CHECK_THROWS(notebook.erase(/*page=*/0, /*row=*/0, /*column=*/9, Direction::Horizontal, 4));
     CHECK_THROWS(notebook.erase(/*page=*/0, /*row=*/7, /*column=*/0, Direction::Vertical, 1));
     CHECK_THROWS(notebook.erase(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Horizontal, 6));
     CHECK_THROWS(notebook.write(/*page=*/15, /*row=*/0, /*column=*/0, Direction::Horizontal, "sba"));
     CHECK_THROWS(notebook.write(/*page=*/0, /*row=*/64, /*column=*/100, Direction::Vertical, "~~~"));
     CHECK_THROWS(notebook.write(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Vertical, "~"));
     CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/0, /*column=*/16, Direction::Vertical, " "));

    



}

