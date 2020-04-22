#include <bits/stdc++.h>
using namespace std;

void writeNewShots(const pair<string, string> &shot, ofstream &outputFile){
	int fir = atoi(shot.first.c_str());
	int sec = atoi(shot.second.c_str());

	int range = floor((sec - fir) * 50 / 100);

	if(range > 10){
		outputFile << fir << "\t" << fir + range << endl;
		outputFile << fir + range + 1 << "\t" << sec << endl;
	}
	else{
		outputFile << fir << "\t" << sec << endl;
	}
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

	if(!inputFile){
		cout << "Error" << endl;

		return -1;
	}
	else{
        ofstream outputFile("fragShots.csv");

		readOriginalShots(inputFile, outputFile);

		inputFile.close();
		outputFile.close();
	}

	return 0;
}
