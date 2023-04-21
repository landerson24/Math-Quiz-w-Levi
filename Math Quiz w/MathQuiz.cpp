#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;

int EasyDifficultyNumberGen() {
	int easyNum = (rand() % 10) + 0;
	return easyNum;
}

int MediumDifficultyNumberGen() {
	int mediumNum = (rand() % 90) + 10;
	return mediumNum;
}

int HardDifficultyNumberGen() {
	int hardNum = (rand() % 199) + -99;
	return hardNum;
}

void sortVectors(vector<string>& userNames, vector<int>& userScores){
    for (int i = 0; i < userScores.size() -1; i++){
        int maxIndex = i;
        for (int j = i + 1; j < userScores.size(); j++) {
            if (userScores.at(j) > userScores.at(maxIndex)) {
                maxIndex = j;
            }
        }
        swap(userScores.at(maxIndex), userScores.at(i));
        swap(userNames.at(maxIndex), userNames.at(i));
    }
}

void unitTest(){
    vector<string> userNamesTest = {"Billy Bob", "Logano", "Levi", "Jimy", "Buster"};
    vector<int> userScoresTest = {8, 10, 6, 5, 9};
    
    vector<string> userNamesTestCorrect = {"Logano", "Buster", "Billy Bob", "Levi", "Jimy"};
    vector<int> userScoresTestCorrect = {10, 9, 8, 6, 5};
    
    sortVectors(userNamesTest, userScoresTest);

    assert(userNamesTest == userNamesTestCorrect && userScoresTest == userScoresTestCorrect);
}

int main() {
    unitTest();
    
	enum DifficultyOptions { D_EASY, D_MEDIUM, D_HARD };
	srand(time(0));
	
	DifficultyOptions difficulty;
	string userChoice;
	string takeAgain;
	
	int randomNum;
	int randomNum2;
	int answer;
	int numCorrect = 0;
	int i = 0;
	
	vector<string> userNames;
	vector<int> userScores;

	difficulty = D_EASY;

	do{
	    cout << "Choose difficulty: Easy, Medium, or Hard" << endl;

	    cin >> userChoice;

        if (userChoice == "Easy" || userChoice == "easy") {
		    difficulty = D_EASY;
		    cout << "Difficulty: Easy" << endl;
	    }
	    else if (userChoice == "Medium" || userChoice == "medium") {
		    difficulty = D_MEDIUM;
		    cout << "Difficulty: Medium" << endl;
	    }
	    else if (userChoice == "Hard" || userChoice == "hard") {
		    difficulty = D_HARD;
		    cout << "Difficulty: Hard" << endl;
	    }
	    else {
	    	cout << "Invalid difficulty" << endl;
	    }

	    for (i = 0; i < 10; i++){
	    	if (difficulty == D_EASY) {
	    		randomNum = EasyDifficultyNumberGen();
	    		randomNum2 = EasyDifficultyNumberGen();
	    		cout << randomNum << " + " << randomNum2 << " = ?" << endl;
	    	}

	    	if (difficulty == D_MEDIUM) {
    			randomNum = MediumDifficultyNumberGen();
    			randomNum2 = MediumDifficultyNumberGen();
    			cout << randomNum << " + " << randomNum2 << " = ?" << endl;
	    	} 

	    	if (difficulty == D_HARD) {
		    	randomNum = HardDifficultyNumberGen();
		    	randomNum2 = HardDifficultyNumberGen();
		    	cout << randomNum << " + " << randomNum2 << " = ?" << endl;
	    	}

	    	cin >> answer;

	    	if (answer == randomNum + randomNum2){
		    	cout << "Correct" << endl;
	    		numCorrect += 1;
	    	}
	    	else {
		    	cout << "Incorrect, try again" << endl;
		    	cout << randomNum << " + " << randomNum2 << " = ?" << endl;
		    	cin  >> answer;
		    	if (answer == randomNum + randomNum2){
		    		cout << "Correct" << endl;
		    		numCorrect += 1;
		    	}
		    	else{
    				cout << "Incorrect, the correct answer was " << randomNum + randomNum2 << endl;
    				cout << "Next question" << endl;
			    }
	    	}
    	}
	
    	if (numCorrect > 0 && numCorrect < 10) {
	    	cout << "You got " << numCorrect << " questions correct!";
        }
    	else if (numCorrect == 10) {
    		cout << "You got them all correct!!";
    	}
    	else {
	    	cout << "You got " << numCorrect << " questions correct :(";
    	}
    	cout << endl;
    	
    	if (numCorrect > 0){
    	    cout << "Please enter your name" << endl;
    	    string userName;
    	    cin >> userName;
    	    cout << endl;
    	    userNames.push_back(userName);
    	    userScores.push_back(numCorrect);
    	    
    	    sortVectors(userNames, userScores);
    	    
    	    numCorrect = 0;
    	}
    	
    	cout << "Would you like to take another Quiz? Type yes or no" << endl;
    	cin >> takeAgain;
    	cout << endl;
    	
	} while (takeAgain != "no" && takeAgain != "No");
	
	cout << "The high scores are..." << endl;
	
	sortVectors(userNames, userScores);
	
	for (i = 0; i < userNames.size(); i++){
	    cout << i + 1 << ". " << userNames.at(i) << " with a score of " << userScores.at(i) << " out of 10!" << endl;
	}

	return 0;
}