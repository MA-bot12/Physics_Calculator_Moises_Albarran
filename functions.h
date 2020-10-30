#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
//#include <stdtlib>
#include "Input_Validation_Extended.h"

using namespace std;

void menu();
void userOption(string);
void motionMenu();
void motionOption(string);
double velocity(double, double);
double acceleration(double, double);
double firstMotion(double, double, double);
double secondMotion(double, double, double);
double thirdMotion(double, double, double);
double mertonLaw(double, double);
double newtonSecondLaw(double, double);
double weight(double, double);
double momentum(double, double);

void menu()
{
  cout << "\nMENU" << endl;
  cout << "A: Velocity" << endl;
  cout << "B: Acceleration" << endl;
  cout << "C: Motion" << endl;
  cout << "D: Newton's Second Law" << endl;
  cout << "E: Weight (Earth)" << endl;
  cout << "F: Momentum" << endl;
  cout << "Q: Quit Program" << endl;
  cout << "X: Clear Screen" << endl; 
}

void userOption(string option)
{
  double num1, num2 ,num3;
  double result; 
  string unit1, unit2;

  num1 = 0.0;
  num2 = 0.0;
  num3 = 0.0;
  result = 0.0;
  unit1 = " ";
  unit2 = " ";

  if(option == "A" || option == "a")
  {
    cout << "\nVelocity Calculation" << endl;
    cout << "Velocity = Displacement / Time" << endl;

    cout << "Please enter the Displacement unit measure: ";
    unit1 = validateString(unit1);
    cout << "Please enter the Time unit measure: ";
    unit2 = validateString(unit2);

    cout << "Please enter the Displacement: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Time: ";
    num2 = validateDouble(num2);

    result = velocity(num1, num2);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << "/" << unit2 << endl;
  } 
  else if(option == "B" || option == "b")
  {
    cout << "\nAcceleration Calculation" << endl;
    cout << "Acceleration = Change in Velocity / Time Taken" << endl;

    cout << "Please enter the Velocity unit measure: ";
    unit1 = validateString(unit1);
    cout << "Please enter the Time unit measure: ";
    unit2 = validateString(unit2);

    cout << "Please enter the Velocity: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Time: ";
    num2 = validateDouble(num2);

    result = acceleration(num1, num2);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << "/" << unit2 << endl;

  }
  else if(option == "C" || option == "c")
  {
    string userChoice;

    do
    {
      motionMenu();
      userChoice = validateString(userChoice);

      motionOption(userChoice);

    } while(userChoice != "E" && userChoice != "e");

  }
  else if(option == "D" || option == "d")
  {
    cout << "\nNewton's Second Law Calculation" << endl;
    cout << "Force = Mass * Acceleration" << endl;

    cout << "Please enter the Mass unit measure: ";
    unit1 = validateString(unit1);
    cout << "Please enter the Acceleration unit measure: ";
    unit2 = validateString(unit2);

    cout << "Please enter the Mass: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Acceleration: ";
    num2 = validateDouble(num2);

    result = newtonSecondLaw(num1, num2);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << "N = " << setprecision(5) << num1 << unit1 << " " << setprecision(5) << num2 << unit2 << endl;
  }
  else if(option == "E" || option == "e")
  {
    cout << "\nWeight Calculation" << endl;
    cout << "Weight = Mass * Gravity" << endl;

    cout << "Please enter the Weight unit measure: ";
    unit1 = validateString(unit1);

    cout << "Please enter the Mass: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Gravity: ";
    num2 = validateDouble(num2);

    result = weight(num1, num2);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << endl;
  }
  else if(option == "F" || option == "f")
  {
    cout << "\nMomentum Calculation" << endl;
    cout << "Momentum = Mass * Velocity" << endl;

    cout << "Please enter the Momentum unit measure: ";
    unit1 = validateString(unit1);

    cout << "Please enter the Mass: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Velocity: ";
    num2 = validateDouble(num2);

    result = momentum(num1, num2);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << endl;
  }
  else if(option == "Q" || option == "q")
  {
    cout << "Goodbye!" << endl;
  }
  else if(option == "X" || option == "x")
  {
    system("clear");
  }
  else
  {
    cout << "Invalid Input!" << endl;
  }
}

double velocity(double ds, double dt)
{
  double v;

  v = ds / dt;

  return v; 
}

double acceleration(double dv, double dt)
{
  double a;

  a = dv / dt;

  return a;
}

void motionMenu()
{
  cout << "\nMotion Menu" << endl;
  cout << "A: First Equation of Motion v = v0 + at" << endl;
  cout << "B: Second Equation of Motion s = s0 + v0t + 1/2at^2" << endl;
  cout << "C: Third Equation of Motion v^2 = v0^2 + 2a(s - s0)" << endl;
  cout << "D: Merton Rule v = 1/2(v + v0)" << endl;
  cout << "E: Return to Main Menu" << endl;
}

void motionOption(string choice)
{
  double num1, num2, num3;
  double result;
  string unit1;

  num1 = 0.0;
  num2 = 0.0;
  num3 = 0.0;
  result = 0.0;
  unit1 = " ";

  if(choice == "A" || choice == "a")
  {
    cout << "\nFirst Equation of Motion" << endl;
    cout << "Final Velocity = Intial Velocity + (Acceleration * Time)" << endl;

    cout << "Please enter the Final Velocity unit measure: ";
    unit1 = validateString(unit1);

    cout << "Please enter the Intial Velocity: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Acceleration: ";
    num2 = validateDouble(num2);
    cout << "Please enter the Time: ";
    num3 = validateDouble(num3);

    result = firstMotion(num1, num2, num3);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << endl;
  }
  else if(choice == "B" || choice == "b")
  {
    cout << "\nSecond Equation of Motion" << endl;
    cout << "Displacement = (Intial Velocity * Time) + 1/2(Acceleration * Time)^2" << endl;

    cout << "Please enter the Displacement unit measure: ";
    unit1 = validateString(unit1);

    cout << "Please enter the Intial Velocity: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Acceleration: ";
    num2 = validateDouble(num2);
    cout << "Please enter the Time: ";
    num3 = validateDouble(num3);

    result = secondMotion(num1, num2, num3);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << endl;
  }
  else if(choice == "C" || choice == "c")
  {
    cout << "\nThird Equation of Motion" << endl;
    cout << "Velocity^2 = Intial Velocity^2 + 2(Acceleration * Displacement" << endl;

    cout << "Please enter the Velocity unit measure: ";
    unit1 = validateString(unit1);

    cout << "Please enter the Intial Velocity: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Acceleration: ";
    num2 = validateDouble(num2);
    cout << "Please enter the Displacement: ";
    num3 = validateDouble(num3);

    result = thirdMotion(num1, num2, num3);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << endl;
  }
  else if(choice == "D" || choice == "d")
  {
    cout << "\nMerton Rule" << endl;
    cout << "Average Velocity = 1/2(Final Velocity + Initial Velocity)" << endl;

    cout << "Please enter the Velocity unit measure: ";
    unit1 = validateString(unit1);

    cout << "Please enter the Final Velocity: ";
    num1 = validateDouble(num1);
    cout << "Please enter the Intial Velocity: ";
    num2 = validateDouble(num2);

    result = mertonLaw(num1, num2);

    cout << "Result..." << endl;
    cout << setprecision(5) << result << unit1 << endl;   
  }
  else if(choice == "E" || choice == "e")
  {
    cout << "Returning to Main Menu..." << endl;
  }
  else
  {
    cout << "Invalid Input!" << endl;
  }
}

double firstMotion(double v1, double a, double t)
{
  double v;

  v = v1 + (a * t);

  return v;
}

double secondMotion(double v1, double a, double t)
{
  double d;

  d = (v1 * t) + ((.5 * (a * t)) * (.5 * (a * t)));

  return d;
}

double thirdMotion(double v1, double a, double d)
{
  double v;

  v = v1 + (2 * (a * d));

  return v;
}

double mertonLaw(double v2, double v1)
{
  double v;

  v = .5 * (v2 + v1);

  return v; 
}

double newtonSecondLaw(double m, double a)
{
  double n;

  n = m * a;

  return n;
}

double weight(double m, double g)
{
  double w;

  w = m * g;

  return w; 
}

double momentum(double m, double v)
{
  double p;

  p = m * v;

  return p;
}
#endif