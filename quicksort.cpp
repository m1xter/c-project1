#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>


#include "quicksort.h";


using namespace std;




int  particion(vector<producto>&array,int inicio,int final){
	
	producto pivot = array[final];
	int i = inicio -1,j;
	
	for ( j = inicio; j <= final -1;j++){
		if(strcmp(array[j].getdescripcion(), pivot.getdescripcion()) < 0){
			i++;
			producto temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			
		}
	}
	i++;
			producto temp = array[i];
			array[i] = array[final];
			array[final] = temp;
	
	
	return i;
}



void qs(vector<producto>&array,int inicio,int final){
	
	if(final <= inicio) return;
	
	int pivot = particion(array,inicio,final);
	qs(array,inicio,pivot-1); //left
	qs(array,pivot+1,final);  //right
	
}

