#include <bits/stdc++.h>
using namespace std;

const int N = 3;

void writeNewScene(const pair<int, int> scene, ofstream &outputFile){
    outputFile << scene.first << "," << scene.second << endl;
}

void translate(ifstream &shotsOL, ifstream &shotsOR, ifstream &shotsM,
               ifstream &sSeg, ofstream &outputFile){

	string line;
    int posShotO = 1, dist, pos, count = 0, count2 = 0, nLines = 0,
        flag = 0, flag2 = 0;
    long posPont;
    pair <int, int> cenaInicial, shotOriginal, shotModif, cenaFinal;

    // Contando numero de cenas existentes
    while(getline(shotsOL, line)){
        nLines++;
    }
    shotsOL.clear();
    shotsOL.seekg(0, shotsOL.beg);

	while(getline(sSeg, line)){
        // Primeiro passo: pegar o índice de início e de fim do sSeg
		pos = line.find_first_of(',');
		cenaInicial.first = atoi(line.substr(0, pos).c_str());
		cenaInicial.second = atoi(line.substr(pos+1).c_str());

        // Segundo passo: pegar os frames correspondentes ao índice de início e
        //de fim do sSeg

        // Salvando o frame de início da cenaInicial, encontrado na tomada modificada
        for(; posShotO <= cenaInicial.first; posShotO++){
            getline(shotsM, line);

            if(posShotO == cenaInicial.first){
                pos = line.find_first_of('\t');
                shotOriginal.first = atoi(line.substr(0, pos).c_str());
            }
        }


        // Salvando o frame de fim da cenaInicial, encontrado na tomada modificada
        if(cenaInicial.first != cenaInicial.second){
            for(; posShotO <= cenaInicial.second; posShotO++){
                getline(shotsM, line);

                if(posShotO == cenaInicial.second){
                    pos = line.find_first_of('\t');

                    shotOriginal.second = atoi(line.substr(pos+1).c_str());
                }
            }
        }
        else{
            shotOriginal.second = atoi(line.substr(pos+1).c_str());
        }

        // Terceiro passo: encontrar frames mais próximos dos frames de inicio
        //e fim modificados no arquivo de shots original
         dist = numeric_limits<int>::max();
         // Arrumando frame inicio
         while(true){
            posPont = shotsOL.tellg(); //Marcando a posição antes da leitura
            getline(shotsOL, line);
            count++;

            pos = line.find_first_of('\t');
    		shotModif.first = atoi(line.substr(0, pos).c_str());

            //cout << "OriginalE: " << shotOriginal.first << " ModificadaE: " << shotModif.first << endl;

            if(abs(shotModif.first - shotOriginal.first) <= dist){
                dist = abs(shotModif.first - shotOriginal.first);

                cenaFinal.first = count;

                if(count > nLines) flag = 1;
            }
            else{
                shotsOL.seekg(posPont, shotsOL.beg);
                count--;

                break;
            }

            if(shotsOL.peek() == EOF) break;
         }

          dist = numeric_limits<int>::max();
         // Arrumando frame fim
         while(true){
            posPont = shotsOR.tellg(); //Marcando a posição antes da leitura
            getline(shotsOR, line);
            count2++;

            pos = line.find_first_of('\t');
            shotModif.second = atoi(line.substr(pos+1).c_str());

            //cout << "OriginalD: " << shotOriginal.second << " ModificadaD: " << shotModif.second << endl;
            if(abs(shotModif.second - shotOriginal.second) <= dist){
                dist = abs(shotModif.second - shotOriginal.second);

                cenaFinal.second = count2;

                if(count2 > nLines) flag2 = 1;
            }
            else{
                shotsOR.seekg(posPont, shotsOR.beg);
                count2--;

                break;
            }

            if(shotsOR.peek() == EOF) break;
        }

        if(flag == 0 && flag2 == 0) writeNewScene(cenaFinal, outputFile);
    }
}

int main(int argc, char* const argv[]){
    if(argc != 4){
        cout << "Modo de uso: ./prog <ARQUIVO DE SHOTS ORIGINAL> <ARQUIVO DE SHOTS SEGMENTADO> <ARQUIVO DE CENAS RESULTANTE DA SEGMENTAÇÃO>" << endl;

        return 1;
    }
    else{

    	string shO = argv[1];
        string shM = argv[2];
        string cS = argv[3];

        // Definindo nome do arquivo final
        string outputName;

        int i;
        while(argv[3][i] != '.' || argv[3][i+1] != 'c'){
            outputName += argv[3][i];

            i++;
        }

        outputName += "_translate.csv";

    	ifstream shotsOL( shO.c_str() );
        ifstream shotsOR( shO.c_str() );
        ifstream shotsM( shM.c_str() );
        ifstream sSeg( cS.c_str() );

    	if(!shotsOL || !shotsOR || !shotsM || !sSeg){
    		cout << "Error" << endl;

    		return -1;
    	}
    	else{
            ofstream outputFile("sSegAj.csv");

    		translate(shotsOL, shotsOR, shotsM, sSeg, outputFile);

    		shotsOL.close();
            shotsOR.close();
            shotsM.close();
            sSeg.close();
    		outputFile.close();
    	}
    }

	return 0;
}
