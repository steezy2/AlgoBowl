#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void calculateAdditions(vector<int> valuesToCalculate, vector<vector<int>>& additions, vector<int> calculatedValues);
vector<int> getInputFile(string filename);
void writeToFile(vector<vector<int>> additions);

int main() {
    vector<int> inputfilevector = getInputFile("Algoinput.txt");
    vector<vector<int>> additions;
    additions.clear();
    calculateAdditions(inputfilevector, additions, {1});
    writeToFile(additions);
    return 0;
}


void calculateAdditions(vector<int> valuesToCalculate, vector<vector<int>>& additions, vector<int> calculatedValues){
    if (valuesToCalculate.empty()){
        return;
    }
    bool done = false;
    vector<int> temp;
    temp.clear();
    int maxValue;
    for (int i = 0; i < calculatedValues.size();i++){
        for (int j = 0; j < calculatedValues.size();j++){
            if (calculatedValues[i] + calculatedValues[j] == valuesToCalculate[0]){
                temp = {calculatedValues[i], calculatedValues[j]};
                additions.push_back(temp);
                calculatedValues.push_back(valuesToCalculate[0]);
                valuesToCalculate.erase(valuesToCalculate.begin());
                calculateAdditions(valuesToCalculate, additions , calculatedValues);
                done = true;
                break;
            } else if (i == calculatedValues.size() - 1 && j == calculatedValues.size() - 1){
                for(int i = calculatedValues.size() - 1; i >= 0; i--){
                    if(calculatedValues.at(calculatedValues.size() - 1) + calculatedValues.at(i) < valuesToCalculate[0]){
                        maxValue = calculatedValues.at(i);
                        break;
                    }
                }
                additions.push_back({calculatedValues.at(calculatedValues.size() - 1), maxValue});
                calculatedValues.push_back(calculatedValues.at(calculatedValues.size() - 1) + maxValue);
                i = 0;
                j = 0;
            }
        }
        if(done){
            break;
        }
    }
}

vector<int> getInputFile(string filename) {
    ifstream inputfile (filename);
    string firstline;
    string myText;
    vector<int> inputvec;
    if(inputfile.is_open()){
        //get first line
        getline (inputfile, firstline);
        while (getline (inputfile, myText, ' ')){
            inputvec.push_back(stoi(myText));
        }
    }
    return inputvec;
}

void writeToFile(vector<vector<int>> additions){
    ofstream myFile("output.txt");
    myFile << additions.size() << endl;
    for( vector<int> v : additions){
        for(int i : v){
            myFile << i << " ";
        }
        myFile << endl;
    }
    myFile.close();
}