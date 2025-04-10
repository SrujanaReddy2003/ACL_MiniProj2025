#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
	
	string srcFile, destFile;


	cout<< "Enter the name of file to copy:" ;
	cin>> srcFile;

	cout<< "Enter the name for file copy:";
	cin>> destFile;

	ifstream src(srcFile, ios::binary);
	ofstream dest(destFile, ios::binary);

	dest << src.rdbuf();
	src.close();
	dest.close();


        string command = "gcc "  + destFile +  " -o " +  " out && ./out";

        system(command.c_str());

return 0;

}
