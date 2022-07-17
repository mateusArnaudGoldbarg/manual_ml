/*
Title: model.cpp
Description: model file of the project: Iris predictions using pre trained Artificial Neural Network model
Author: Mateus Arnaud Goldbarg
Date: 07/16/2022
*/
#include <iostream>
#include "model.hpp"
#include <string>
#include <math.h>

using namespace std;

void Model::getWeights(){
	cout << "Dense1:kernel" <<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<10;j++){
			cout << dense1[i] [j] <<"  ";
		}
		cout<<endl; 
	}
	cout<<endl;
	cout<<"Dense1:bias"<<endl;
	for(int i = 0;i < 10; i++){
		cout <<bias1[i];
	}
	cout<<"\n\n";
	
	cout << "Dense2:kernel" <<endl;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout << dense2[i] [j] <<"  ";
		}
		cout<<endl; 
	}
	cout<<endl;
	cout<<"Dense2:bias"<<endl;
	for(int i = 0;i < 10; i++){
		cout <<bias2[i];
	}
	cout<<"\n\n";
	
	cout << "Dense3:kernel" <<endl;
	for(int i=0;i<10;i++){
		for(int j=0;j<3;j++){
			cout << dense3[i] [j] <<"  ";
		}
		cout<<endl; 
	}
	cout<<endl;
	cout<<"Dense3:bias"<<endl;
	for(int i = 0;i < 3; i++){
		cout <<bias3[i];
	}
	cout<<"\n\n";
}

std::string Model::predict(float input[], int verbose){
	
	//neurons
    	float n1[10] = {0,0,0,0,0,0,0,0,0,0};
    	float n2[10] = {0,0,0,0,0,0,0,0,0,0};
    	float n3[10] = {0,0,0};
    
    	//forward
    	//first layer
    	for(int i=0;i<4;i++){
        	for(int j=0;j<10;j++){
            		n1[j] += input[i]*dense1[i][j];
        	}
    	}
    
    	//add bias
    	for(int i=0;i<10;i++){
        	n1[i]+=bias1[i];
    	}
    
    	//Relu
    	for(int i=0;i<10;i++){
        	if(n1[i]<0){
            		n1[i] = 0;
        	}
    	}
    
    	//second layer
    	for(int i=0;i<10;i++){
        	for(int j=0;j<10;j++){
            		n2[j] += n1[i]*dense2[i][j];
        	}
    	}

    	//add bias
    	for(int i=0;i<10;i++){
        	n2[i]+=bias2[i];
    	}
    
    	//Relu
    	for(int i=0;i<10;i++){
        	if(n2[i]<0){
            		n2[i] =0;
        	}
    	}
    
    	//output layer
    	for(int i=0;i<3;i++){
        	for(int j=0;j<10;j++){
            		n3[i] += n2[j]*dense3[j][i];
        	}
    	}
    
    	//add bias
    	for(int i=0;i<3;i++){
        	n3[i]+=bias3[i];
    	}
    
    	//softmax
    	float p1 = exp(n3[0])/(exp(n3[0])+exp(n3[1])+exp(n3[2]));
    	float p2 = exp(n3[1])/(exp(n3[0])+exp(n3[1])+exp(n3[2]));
    	float p3 = exp(n3[2])/(exp(n3[0])+exp(n3[1])+exp(n3[2]));
    	
    	if(verbose==1){
    		cout<<"probabilities: "<<endl;
		cout<<"Iris-setosa: "<<p1*100<<"%"<<endl;
		cout<<"Iris-versicolor: "<<p2*100<<"%"<<endl;
		cout<<"Iris-virginica: "<<p3*100<<"%"<<endl;
    	}
    	
    	std::string pred = "";
	if(p3>p1 && p3>p2){
		pred = "Iris-virginica";
		//cout<<"Iris-virginica"<<endl;
    	}
    	if(p1>p2 && p1>p3){
    		pred = "Iris-setosa";
        	//cout <<"Iris-setosa"<<endl;
    	}
    	if(p2>p1 && p2>p3){
    		pred = "Iris-versicolor";
        	//cout <<"Iris-versicolor"<<endl;
    	}
    	
    	return pred;
    	
}




