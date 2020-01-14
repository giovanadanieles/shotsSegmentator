#include <bits/stdc++.h>
using namespace std;

void writeNewShots(const pair<string, string> &shot, ofstream &outputFile){
	int fir = atoi(shot.first.c_str());
	int sec = atoi(shot.second.c_str());

	int interval = floor((sec - fir) * 33 / 100);

	outputFile << fir << "\t" << fir + interval << endl;
	outputFile << fir + interval + 1 << "\t" << fir + interval * 2 + 1 << endl;
	outputFile << fir + interval * 2 + 2 << "\t" << sec << endl;
}

void readOriginalShots(ifstream &inputFile, ofstream &outputFile){
	string line;
	int pos;
	pair <string, string> shot;

	while(getline(inputFile, line)){
		pos = line.find_first_of('\t');
		shot.first = line.substr(0, pos);
		shot.second = line.substr(pos+1);

		writeNewShots(shot, outputFile);
	}
}

int main(){
	string filename; cin >> filename;

	ifstream inputFile( filename.c_str() );
	ofstream outputFile("fragShots.csv");

	if(!inputFile){
		cout << "Error" << endl;
		return -1;
	}
	else{
		readOriginalShots(inputFile, outputFile);

		inputFile.close();
		outputFile.close();
	}

	return 0;
}