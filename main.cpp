/*
Title: main.cpp
Description: main file of the project: Iris predictions using pre trained Artificial Neural Network model
Author: Mateus Arnaud Goldbarg
Date: 07/16/2022
*/
#include <iostream>
#include <string>
#include <list>
#include "iris.hpp"
#include "model.hpp"
#include <algorithm>
#include <numeric>

using namespace std;

void addFlower(list<Iris>& flowers){
	float SepalLengthCm;
	float SepalWidthCm;
	float PetalLengthCm;
	float PetalWidthCm;
	
	cout<< "Write all attributes separated by spaces in format [Sepal Length, Sepal Width, Petal Length, Petal Width]"<<endl;
	cout<< "example: 5.7 2.6 3.5 1.0"<<endl;
	cin>>SepalLengthCm;
	cin>>SepalWidthCm;
	cin>>PetalLengthCm;
	cin>>PetalWidthCm;
	
	Iris f(SepalLengthCm,SepalWidthCm,PetalLengthCm,PetalWidthCm);
	
	flowers.push_back(f);
	
}

list<Iris>::iterator find_by_ID(list<Iris>& flowers, int ID){
	list<Iris>::iterator it;
	for (it = flowers.begin(); it != flowers.end(); it++){
		if (it->getID() == ID){
			return it;
		}
	}
	return it;
}


void display_flowers(list<Iris>& flowers)
{	
	for_each(flowers.begin(), flowers.end(),[](auto& flowers) {
        	flowers.displayAttributes();
        }
    	);
}

void predict_flowers(list<Iris>& flowers, int verbose, Model model)
{	
	for_each(flowers.begin(), flowers.end(),[&verbose, &model](auto& flowers) {
		//Model model = Model();
		float *p;
            	p = flowers.arrayAttributes();
            	cout <<"Predictions for ID: " <<flowers.getID() <<endl;
            	std::string pred = model.predict(p,verbose);
            	cout<< pred<<endl;
            	flowers.setSpecie(pred);
        }
    	);
}

int main(){
	cout<<"Welcome!"<<endl;
	cout<<"CLASSIFY IRIS USING MACHINE LEARNING PRE-TRAINED MODEL INITIALIZED\n"<<endl;
	list<Iris> flowers;
  	list<Iris>::iterator it;
  	int id_;
	Model model = Model();
	int opt;
	
	while(1){
		cout<<endl;
		
		cout<<"Choose an option: "<<endl;
		cout<<"0. Finish program"<<endl;
		cout<<"1. Add flower"<<endl;
		cout<<"2. Get flower attributes by ID"<<endl;
		cout<<"3. Get all flowers attributes"<<endl;
		cout<<"4. Predict flowers"<<endl;
		cout<<"5. Get model weights"<<endl;
		
		cout<<"Your option: ";
		cin >> opt;
		cout<<endl;
		
		if (opt==0){
			cout<<"Bye Bye!!"<<endl;
			return 0;
		}
		
		else if (opt==1){
			addFlower(flowers);
		}
		else if (opt==2){
			cout << "Enter the ID of the flower to find: ";
			cin >> id_;
			it = find_by_ID(flowers, id_);
			if(it != flowers.end()){
				cout << "Found flower: \n\n";
				it->displayAttributes();
			}
			else{
				cout << "Flower not found.\n";
			}
		}
		else if (opt==3){
			display_flowers(flowers);
		}
		else if (opt==4){
			int verbose;
			cout<<"Choose a verbose [0 to show nothing 1 to show predictions(%)]: ";
			cin >> verbose;
			cout<<endl;
			predict_flowers(flowers,verbose,model);
		}
		else if (opt==5){	
			model.getWeights();
		}
		else{
			cout <<"Invalid command. Try again"<<endl;
		}
		
	}
}
