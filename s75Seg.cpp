#include <bits/stdc++.h>
using namespace std;

const int N = 4;

void writeNewShots(const pair<string, string> shot[N], ofstream &outputFile, int count){
	int fir[N], sec[N], range[N];

	for(int i = 0; i < count; i++){
		fir[i] = atoi(shot[i].first.c_str());
		sec[i] = atoi(shot[i].second.c_str());
	}

	range[0] = floor((sec[0] - fir[0]) * 75 / 100);
	outputFile << fir[0] << "\t" << fir[0] + range[0] << endl;

	if(count >= 2){
		range[1] = floor((sec[1] - fir[1]) * 50 / 100);
		outputFile << fir[0] + range[0] + 1 << "\t" << fir[1] + range[1] << endl;


		if(count >= 3){
			range[2] = floor((sec[2] - fir[2]) * 25 / 100);
			outputFile << fir[1] + range[1] + 1 << "\t" << fir[2] + range[2] << endl;
		}

		if(count == 4){
			outputFile << fir[2] + range[2] + 1 << "\t" << sec[3] << endl;
		}
	}
}

void readOriginalShots(ifstream &inputFile, ofstream &outputFile){
	string line;
	int pos, count;
	pair <string, string> shot[N];

	while(getline(inputFile, line)){

		pos = line.find_first_of('\t');
		shot[0].first = line.substr(0, pos);
		shot[0].second = line.substr(pos+1);

		count = 1;

		for(int i = 1; i <= 3; i++){
			if(getline(inputFile, line)){
				pos = line.find_first_of('\t');
				shot[i].first = line.substr(0, pos);
				shot[i].second = line.substr(pos+1);

				count++;
			}
		} 

		writeNewShots(shot, outputFile, count);
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
