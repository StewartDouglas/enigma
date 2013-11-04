#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#include"enigma.h"
#include"classes.cpp"

int main(int argc, char **argv) 
{
  check(argc, argv);

  char continu = 'y';
  const int nb_rotors = argc - 3;

  /*initialisation: declare objects and assign them to config files specified on command line.
    reach here iif there are no errors.*/
  Plugboard pb; //Plugboard pb(argv[1]);
  Reflector rf; //Reflector rf(argv[2])
  Rotor *rotor;
  for (int i=0; i<nb_rotors; i++)
    rotor= new Rotor;  //rotor[i] = new Rotor(argv[i-3]);

  pb.print(); rf.print(); 
  for (int i=0; i<nb_rotors; i++)
    rotor[i].print();

  while(continu=='y') {

    /*get input from command line, checking char by char that it is correct*/
    getInput();


    cout << "again? ";
    cin >> continu;
  }
  delete [] rotor;
  return 0;
}