#include <iostream>
#include <fstream>
#include <string>



using namespace std;


void convertOneNumber(ifstream& inf,ofstream& ouf,int width, int height,int num1, int con1){
	int x;
		
		for (int i = 0; i < height; i++){
		
			for (int j = 0; j < width; j++){
				inf >> x;
				if (x == num1)
					ouf << con1 << " ";
				else
					ouf <<x <<" ";
			}
			ouf << endl;
		}


	return;
}


void convertTwoNumbers(ifstream& inf, ofstream& ouf, int width, int height, int num1,int num2, int con1, int con2){

	int x;

	for (int i = 0; i < height; i++){

		for (int j = 0; j < width; j++){
			inf >> x;
			if (x == num1)
				ouf << con1 << " ";
			else if(x == num2){
				ouf << con2 << " ";
			}
			else
				ouf << x << " ";
		}

		ouf << endl;
	}



	return;
}






int main(){

	string file;

	

	ifstream fin;
	fin.open("env2.cfg");

	ofstream fout("env1.txt");

	int converts, num1, num2, con1, con2, width, height;

	if (!fin){
		cout << "cannot open the file:" << endl;
		return -1;
		
	}	
		
		cout << "enter the size of the map:" << endl;
			cin >> width >> height;
		cout << "how many numbers you want to (1 or 2):" << endl;
			cin >> converts;
		
	
	if (converts == 1){
	
		cout << "enter the number to convert:" << endl;
			cin >> num1;
		cout << "enter the value you want to convert to:" << endl;
			cin >> con1;

			convertOneNumber(fin,fout, width, height, num1, con1);


	}


	else if (converts == 2){

		cout << "enter the first number:" << endl;
			cin >> num1;

		cout << "enter the second number:" << endl;
			cin >> num2;
		
		cout << "enter the values you want to convert to" << endl;
			cin >> con1 >> con2;
			convertTwoNumbers(fin, fout, width, height, num1,num2,con1,con2);
	}


	else{
		return -1;
		
	}


	fin.close();
	fout.close();
	
	return 0;
}

