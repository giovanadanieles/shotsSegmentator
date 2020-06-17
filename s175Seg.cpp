#include <bits/stdc++.h>
using namespace std;

const int N = 7;

void writeNewShots(const pair<string, string> shot[N], ofstream &outputFile, int count){
	int fir[N], sec[N], range[N], rest;

	for(int i = 0; i < count; i++){
		fir[i] = atoi(shot[i].first.c_str());
		sec[i] = atoi(shot[i].second.c_str());
	}

	if(count == 1){
		outputFile << fir[0] << "\t" << sec[0] << endl;
	}
	else if(count == 2){
		range[0] = floor((sec[1] - fir[1]) * 75 / 100);
		rest = floor((sec[1] - fir[1]) * 25 / 100);


		if(range[0] > 25 && rest > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;
			outputFile << sec[0] + range[0] + 1 << "\t" << sec[1] << endl;
		}
		else{
			for(int i = 0; i < count; i++){
				outputFile << fir[i] << "\t" << sec[i] << endl;
			}
		}
	}
	else if(count == 3){
		range[0] = floor((sec[1] - fir[1]) * 75 / 100);
		rest = floor((sec[1] - fir[1]) * 25 / 100);

		if(range[0] > 25 && rest > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;

			outputFile << sec[0] + range[0] + 1 << "\t" << sec[2] << endl;
		}
		else{
			for(int i = 0; i < count; i++){
				outputFile << fir[i] << "\t" << sec[i] << endl;
			}
		}
	}
	else if(count == 4){
		range[0] = floor((sec[1] - fir[1]) * 75 / 100);
		rest = floor((sec[1] - fir[1]) * 25 / 100);

		range[1] = floor(sec[2] - fir[2]);
		range[2] = floor((sec[3] - fir[3]) * 50 / 100);

		if(range[0] > 25 && rest > 25 && range[2] > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;

			outputFile << sec[0] + range[0] + 1 << "\t" <<
						  sec[0] + range[0] + 1 + range[1] + range[2] + rest << endl;

			outputFile << sec[0] + range[0] + 2 + range[1] + range[2] + rest <<
						  "\t" << sec[3] << endl;
		}
		else{
			for(int i = 0; i < count; i++){
				outputFile << fir[i] << "\t" << sec[i] << endl;
			}
		}
	}
	else if(count == 5){
		range[0] = floor((sec[1] - fir[1]) * 75 / 100);
		rest = floor((sec[1] - fir[1]) * 25 / 100);

		range[1] = floor(sec[2] - fir[2]);
		range[2] = floor((sec[3] - fir[3]) * 50 / 100);

		if(range[0] > 25 && rest > 25 && range[2] > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;

			outputFile << sec[0] + range[0] + 1 << "\t" <<
						  sec[0] + range[0] + 1 + rest + range[1] + range[2] << endl;

			outputFile << sec[0] + range[0] + 2 + range[1] + rest + range[2] <<
						  "\t" << sec[4] << endl;
		}
		else{
			for(int i = 0; i < count; i++){
				outputFile << fir[i] << "\t" << sec[i] << endl;
			}
		}
	}
	else if(count == 6){
		range[0] = floor((sec[1] - fir[1]) * 75 / 100);
		rest = floor((sec[1] - fir[1]) * 25 / 100);

		range[1] = floor(sec[2] - fir[2]);
		range[2] = floor((sec[3] - fir[3]) * 50 / 100);
		range[3] = floor(sec[4] - fir[4]);
		range[4] = floor((sec[5] - fir[5]) * 25 / 100);

		if(range[0] > 25 && rest > 25 && range[2] > 25 && range[4] > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;

			outputFile << sec[0] + range[0] + 1 << "\t" <<
						  sec[0] + range[0] + 1 + range[1] + range[2] + rest << endl;

		  	outputFile << sec[0] + range[0] + range[1] + rest + 2 + range[2] <<
			  			  "\t" << sec[0] + range[0] + range[1] + 2 + range[2] * 2 +
			  			  range[3] + rest + range[4] << endl;

			outputFile << sec[0] + range[0] + range[1] + 3 + range[2] * 2 + range[3] +
  						  range[4] + rest << "\t" << sec[5] << endl;
		}
		else{
			for(int i = 0; i < count; i++){
				outputFile << fir[i] << "\t" << sec[i] << endl;
			}
		}
	}
	else if(count == 7){
		range[0] = floor((sec[1] - fir[1]) * 75 / 100);
		rest = floor((sec[1] - fir[1]) * 25 / 100);

		range[1] = floor(sec[2] - fir[2]);
		range[2] = floor((sec[3] - fir[3]) * 50 / 100);
		range[3] = floor(sec[4] - fir[4]);
		range[4] = floor((sec[5] - fir[5]) * 25 / 100);

		if(range[0] > 25 && rest > 25 && range[2] > 25 && range[4] > 25){
			outputFile << fir[0] << "\t" << sec[0] + range[0] << endl;

			outputFile << sec[0] + range[0] + 1 << "\t" <<
						  sec[0] + range[0] + rest + 1 + range[1] + range[2] <<
						  endl;

			outputFile << sec[0] + range[0] + range[1] + rest + 2 + range[2] <<
						  "\t" << sec[0] + range[0] + range[1] + 2 + range[2] * 2 +
						  range[3] + rest + range[4] << endl;

			outputFile << sec[0] + range[0] + range[1] + 3 + range[2] * 2 + range[3] +
			range[4] + rest << "\t" << sec[6] << endl;
		}
		else{
			for(int i = 0; i < count; i++){
				outputFile << fir[i] << "\t" << sec[i] << endl;
			}
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
