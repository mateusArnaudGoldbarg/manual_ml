/*
Title: iris.cpp
Description: iris file of the project: Iris predictions using pre trained Artificial Neural Network model
Author: Mateus Arnaud Goldbarg
Date: 07/16/2022
*/

#include <iostream>
#include "iris.hpp"
#include <string>

using namespace std;

int Iris::ID = 0;

int Iris::getID(){
	return my_ID;
}

void Iris::displayAttributes(){
	cout << "ID: " << my_ID <<"->";
	cout << "Sepal Length: " << SepalLengthCm << "cm" <<"\t";
	cout << "Sepal Width: " << SepalWidthCm << "cm" <<"\t";
	cout << "Petal Length: " << PetalLengthCm << "cm" <<"\t";
	cout << "Petal Width: " << PetalWidthCm << "cm" <<"\t";
	cout << "Specie: " << Specie <<endl;
}

float *Iris::arrayAttributes(){
	float *p = new float[4];
	p[0] = SepalLengthCm;
	p[1] = SepalWidthCm;
	p[2] = PetalLengthCm;
	p[3] = PetalWidthCm;
	return p;
}

void Iris::setSpecie(std::string specie){
	Specie=specie;
}
