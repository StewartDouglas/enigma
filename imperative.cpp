/*this file contains the imperative part of the program, i.e. functions*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iterator>
#include<sstream>

using namespace std;

#include"enigma.h"

/*function for errors*/
void error_description(int code) {
  switch(code) {
  case -10: 
    cout << "invalid index (file contains a number that is not between 0 and 25)" << endl;
    exit(-10);
  case -11:
    cout << "non numeric character (in file)" << endl;
    exit(-11);
  case -12:
    cout << "insufficient number of parameters (given in command line)" << endl;
    exit(-12);
  case -13:
    cout << "invalid input character (a non capital letter was input)" << endl;
    exit(-13);
  case -14:
    cout << "impossible plugboard configuration (file attempts to connect a contact with itself or with multiple contacts)" << endl;
    exit(-14);
  case -15:
    cout << "incorrect number of plugboard parameters (should be an even number of them)" << endl;
    exit(-15);
  case -16:
    cout << "invalid rotor mapping (an input is not mapped or an input has multiple mappings" << endl;
    exit(-16);
  case -17:
    cout << "no rotor starting position (insufficient number of starting positions)" << endl;
    exit(-17);
  case -18:
    cout << "invalid reflector mapping (file attempts to connect a contact with itself or with multiple contacts)" << endl;
    exit(-18);
  case -19:
    cout << "incorrect number of reflector parameters (file does not contain exactly 13 pairs of numbers)" << endl;
    exit(-19);
 default:
   cout << "Unknown error" << endl;
    exit(-1);
  }
}


/*checks that shell command (and its associated files) are valid*/
void check(int argc, char **argv)
{
  /*check sufficient number of parameters*/
  if (argc<3)
    error_description(-12);

  cout << "\nnumber of command line parameters is valid" << endl;

  /*if rotors, check that there is a rotor starting positions file*/
  string lastArg = argv[argc-1];
  if (lastArg.compare(lastArg.size() - 4, 4, ".pos") != 0 && argc>3)
    error_description(-17); //no rotor starting position

  cout << "rotor position file detected" << endl;

  /*check that each configuration file is valid: numeric characters, valid index*/
  for (int i=1; i<argc && i<10; i++) {
    char ch;
    ifstream file;
    file.open(argv[i]); 

    cout << "file " << i << " opened" << endl;

    /*check that all characters are numeric, new line, carriage return, tab or space*/
    for (file.get(ch); !file.eof(); file.get(ch)) {
      if ((int) ch < 48 || (int) ch > 57) {
	if (ch != 9 && ch != 10 && ch != 13 && ch != 32) {
	  cout << "in file " << i << ": ";	 
	  error_description(-11);
	}
      }
      file.close();
      cout << "all characters in file " << i << " are numeric" << endl;
    }
  }
}





  
