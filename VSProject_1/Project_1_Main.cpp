#include <iostream>
#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "UserInterface.h"
#include"Assignment.h"
#include<fstream>

using namespace std;

int main() {

    /*
    Assignment_Book my_assignments;
    my_assignments.load("assignments.txt");
    UserInterface menu(my_assignments);
    menu.main();
    */

	/*UserInterface menu;
	menu.main();
*/
	Assignment h;
	ifstream fin;
	ofstream fout;
	
	fin.open("tester.txt");
	fout.open("output.txt");
	fin >> h;
	fout << h;
	
}