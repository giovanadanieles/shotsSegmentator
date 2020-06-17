#include <bits/stdc++.h>
using namespace std;

const int N = 3;

void writeNewShots(const pair<string, string> shot[N], ofstream &outputFile, int count){
	int fir[N], sec[N], range[N];

	for(int i = 0; i < count; i++){
		fir[i] = atoi(shot[i].first.c_str());
		sec[i] = atoi(shot[i].second.c_str());
	}

	if(count == 1){
		outputFile << fir[0] << "\t" << sec[0] << endl;
	}
	else if(count == 2){
		range[0] = floor((sec[1] - fir[1]) * 50 / 100);

		if(range[0] > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;
			outputFile << sec[0] + range[0] + 1 << "\t" << sec[1] << endl;
		}
		else{
			outputFile << fir[0] << "\t" << sec[0] << endl;
			outputFile << fir[1] << "\t" << sec[1] << endl;
		}
	}
	else if(count == 3){
		range[0] = floor((sec[1] - fir[1]) * 50 / 100);

		if(range[0] > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;

			outputFile << sec[0] + range[0] + 1 << "\t" << sec[2] << endl;
		}
		else{
			outputFile << fir[0] << "\t" << sec[0] << endl;
			outputFile << fir[1] << "\t" << sec[1] << endl;
			outputFile << fir[2] << "\t" << sec[2] << endl;
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

		for(int i = 1; i < N; i++){
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
