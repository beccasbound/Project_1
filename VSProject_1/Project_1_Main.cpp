#include <iostream>
#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "UserInterface.h"
#include"Assignment.h"
#include<fstream>

using namespace std;

int main() {

    
    Assignment_Book my_assignments;
    my_assignments.load("tester.txt");
    UserInterface menu(my_assignments);
    menu.main();
    system("pause");
	
}