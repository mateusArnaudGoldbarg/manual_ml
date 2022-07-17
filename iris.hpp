/*
Title: iris.hpp
Description: iris header file of the project: Iris predictions using pre trained Artificial Neural Network model
Author: Mateus Arnaud Goldbarg
Date: 07/16/2022
*/

#ifndef IRIS_HPP
#define IRIS_HPP
#include <string>
#include <memory>

class Iris{
	private:
		static int ID;
		int my_ID;
	
		float SepalLengthCm;
		float SepalWidthCm;
		float PetalLengthCm;
		float PetalWidthCm;
		std::string Specie;
	public:
		
		Iris(float SepalLengthCm_ = 0, float SepalWidthCm_ = 0, float PetalLengthCm_ = 0, float PetalWidthCm_ = 0){
			SepalLengthCm = SepalLengthCm_;
			SepalWidthCm = SepalWidthCm_;
			PetalLengthCm = PetalLengthCm_;
			PetalWidthCm = PetalWidthCm_;
			Specie = "unkown";
			
			my_ID = ID++;
		}
		
		int getID();
		
		void displayAttributes();
		
		float * arrayAttributes();
		
		void setSpecie(std::string specie);
};

#endif
