#include <bits/stdc++.h>
using namespace std;

const int N = 2;

void writeNewShots(const pair<string, string> shot[N], ofstream &outputFile, int flag){
	int fir[N], sec[N];

	for(int i = 0; i < N; i++){
		fir[i] = atoi(shot[i].first.c_str());
		sec[i] = atoi(shot[i].second.c_str());
	}

	if(flag == 0){ 
		outputFile << fir[0] << "\t" << sec[0] << endl; 
		outputFile << sec[0] + 1 << "\t" << sec[1] << endl;
	}
	else{
		outputFile << sec[1] + 1 << "\t" << sec[0]  << endl;
	} 
}

void readOriginalShots(ifstream &inputFile, ofstream &outputFile){
	string line;
	int pos, flag = 0;
	pair <string, string> shot[N];

	while(getline(inputFile, line)){
		pos = line.find_first_of('\t');
		shot[0].first = line.substr(0, pos);
		shot[0].second = line.substr(pos+1);

		// Only at the first reading will two shots have to be read
		if(flag == 0){
			getline(inputFile, line);
			pos = line.find_first_of('\t');
			shot[1].first = line.substr(0, pos);
			shot[1].second = line.substr(pos+1);

			writeNewShots(shot, outputFile, flag);
			flag = 1;
		}

		if(flag != 1){
			writeNewShots(shot, outputFile, flag);
			shot[1] = shot[0];
		}

		flag = 3;
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
