#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;

enum DifficultyOptions { D_EASY, D_MEDIUM, D_HARD };

int numCorrect = 0;
vector<string> userNames;
vector<int> userScores;

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

void sortVectors() {
	for (int i = 0; i < userScores.size() - 1; i++) {
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

void highScores() {
	cout << "The high scores are..." << endl;

	sortVectors();

	for (int i = 0; i < userNames.size(); i++) {
		cout << i + 1 << ". " << userNames.at(i) << " with a score of " << userScores.at(i) << " out of 10!" << endl;
	}
}

void getUserName() {
	cout << "Please enter your name" << endl;
	string userName;
	cin >> userName;
	cout << endl;
	userNames.push_back(userName);
	userScores.push_back(numCorrect);
	numCorrect = 0;
}

void displayNumCorrect() {
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
}

void findUserDifficulty(DifficultyOptions& difficulty) {
	cout << "Choose difficulty: Easy, Medium, or Hard" << endl;
	string userChoice;
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
	cout << endl;
}

bool takeAgain(string againString) {
	cout << endl;
	if (againString == "no" || againString == "No" || againString == "NO") {
		return false;
	}
	return true;
}

void unitTest(){
	string unitString;
	unitString = "yes";
	assert(takeAgain(unitString) == true);
	unitString = "no";
	assert(takeAgain(unitString) == false);
}

void correctAnswerForSub(int answer, int randomNum, int randomNum2) {
	if (answer == randomNum - randomNum2) {
		cout << "Correct" << endl;
		numCorrect += 1;
	}
	else {
		cout << "Incorrect, try again" << endl;
		cout << randomNum << " - " << randomNum2 << " = ?" << endl;
		cin >> answer;
		if (answer == randomNum - randomNum2) {
			cout << "Correct" << endl;
			numCorrect += 1;
		}
		else {
			cout << "Incorrect, the correct answer was " << randomNum + randomNum2 << endl;
			cout << "Next question" << endl;
		}
	}
}

void correctAnswerForAdd(int answer, int randomNum, int randomNum2) {
	if (answer == randomNum + randomNum2) {
		cout << "Correct" << endl;
		numCorrect += 1;
	}
	else {
		cout << "Incorrect, try again" << endl;
		cout << randomNum << " + " << randomNum2 << " = ?" << endl;
		cin >> answer;
		if (answer == randomNum + randomNum2) {
			cout << "Correct" << endl;
			numCorrect += 1;
		}
		else {
			cout << "Incorrect, the correct answer was " << randomNum + randomNum2 << endl;
			cout << "Next question" << endl;
		}
	}
}

void subDifficultyQuestions(DifficultyOptions difficulty) {
	int randomNum;
	int randomNum2;

	if (difficulty == D_EASY) {
		randomNum = EasyDifficultyNumberGen();
		randomNum2 = EasyDifficultyNumberGen();
	}
	if (difficulty == D_MEDIUM) {
		randomNum = MediumDifficultyNumberGen();
		randomNum2 = MediumDifficultyNumberGen();
	}
	if (difficulty == D_HARD) {
		randomNum = EasyDifficultyNumberGen();
		randomNum2 = EasyDifficultyNumberGen();
	}

	cout << randomNum << " - " << randomNum2 << " = ?" << endl;

	int answer;
	cin >> answer;

	correctAnswerForSub(answer, randomNum, randomNum2);
}

void subtractionQuiz() {
	DifficultyOptions difficulty = D_EASY;
	string takeAgainString;

	do {
		findUserDifficulty(difficulty);

		for (int i = 0; i < 10; i++) {
			subDifficultyQuestions(difficulty);
		}
		cout << endl;
		displayNumCorrect();

		if (numCorrect > 0) {
			getUserName();
		}
		
		cout << "Would you like to take another Quiz? Type yes or no" << endl;
		cin >> takeAgainString;
	} while (takeAgain(takeAgainString));
}

void additionDifficultyQuestions(DifficultyOptions difficulty) {
	int randomNum;
	int randomNum2;

	if (difficulty == D_EASY) {
		randomNum = EasyDifficultyNumberGen();
		randomNum2 = EasyDifficultyNumberGen();
	}
	if (difficulty == D_MEDIUM) {
		randomNum = MediumDifficultyNumberGen();
		randomNum2 = MediumDifficultyNumberGen();
	}
	if (difficulty == D_HARD) {
		randomNum = EasyDifficultyNumberGen();
		randomNum2 = EasyDifficultyNumberGen();
	}

	cout << randomNum << " + " << randomNum2 << " = ?" << endl;

	int answer;
	cin >> answer;

	correctAnswerForAdd(answer, randomNum, randomNum2);
}

void additionQuiz() {
	DifficultyOptions difficulty = D_EASY;
	string takeAgainString;

	do {
		findUserDifficulty(difficulty);

		for (int i = 0; i < 10; i++) {
			additionDifficultyQuestions(difficulty);
		}
		cout << endl;
		displayNumCorrect();

		if (numCorrect > 0) {
			getUserName();
		}

		cout << "Would you like to take another Quiz? Type yes or no" << endl;
		cin >> takeAgainString;
	} while (takeAgain(takeAgainString));
}

void correctAnswerForMult(int answer, int randomNum, int randomNum2) {
	if (answer == randomNum * randomNum2) {
		cout << "Correct" << endl;
		numCorrect += 1;
	}
	else {
		cout << "Incorrect, try again" << endl;
		cout << randomNum << " * " << randomNum2 << " = ?" << endl;
		cin >> answer;
		if (answer == randomNum * randomNum2) {
			cout << "Correct" << endl;
			numCorrect += 1;
		}
		else {
			cout << "Incorrect, the correct answer was " << randomNum + randomNum2 << endl;
			cout << "Next question" << endl;
		}
	}
}

void multDifficultyQuestions(DifficultyOptions difficulty) {
	int randomNum;
	int randomNum2;

	if (difficulty == D_EASY) {
		randomNum = EasyDifficultyNumberGen();
		randomNum2 = EasyDifficultyNumberGen();
	}
	if (difficulty == D_MEDIUM) {
		randomNum = MediumDifficultyNumberGen();
		randomNum2 = MediumDifficultyNumberGen();
	}
	if (difficulty == D_HARD) {
		randomNum = EasyDifficultyNumberGen();
		randomNum2 = EasyDifficultyNumberGen();
	}

	cout << randomNum << " * " << randomNum2 << " = ?" << endl;

	int answer;
	cin >> answer;

	correctAnswerForMult(answer, randomNum, randomNum2);
}

void multQuiz() {
	DifficultyOptions difficulty = D_EASY;
	string takeAgainString;

	do {
		findUserDifficulty(difficulty);

		for (int i = 0; i < 10; i++) {
			multDifficultyQuestions(difficulty);
		}
		cout << endl;
		displayNumCorrect();

		if (numCorrect > 0) {
			getUserName();
		}
		
		cout << "Would you like to take another Quiz? Type yes or no" << endl;
		cin >> takeAgainString;
	} while (takeAgain(takeAgainString));
}

void correctAnswerForDiv(int answer, int randomNum, int randomNum2) {
	if (answer == randomNum / randomNum2) {
		cout << "Correct" << endl;
		numCorrect += 1;
	}
	else {
		cout << "Incorrect, try again" << endl;
		cout << randomNum << " / " << randomNum2 << " = ?" << endl;
		cin >> answer;
		if (answer == randomNum / randomNum2) {
			cout << "Correct" << endl;
			numCorrect += 1;
		}
		else {
			cout << "Incorrect, the correct answer was " << randomNum + randomNum2 << endl;
			cout << "Next question" << endl;
		}
	}
}

void divDifficultyQuestions(DifficultyOptions difficulty) {
	int randomNum;
	int randomNum2;

	if (difficulty == D_EASY) {
		randomNum = EasyDifficultyNumberGen();
		randomNum2 = EasyDifficultyNumberGen();
		while (randomNum2 == 0 || randomNum <= randomNum2 || !(randomNum % randomNum2 == 0) ) {
			randomNum = EasyDifficultyNumberGen();
			randomNum2 = EasyDifficultyNumberGen();
		}
	}
	if (difficulty == D_MEDIUM) {
		randomNum = MediumDifficultyNumberGen();
		randomNum2 = MediumDifficultyNumberGen();
		while (randomNum2 == 0 || randomNum <= randomNum2 || !(randomNum % randomNum2 == 0) ) {
			randomNum = MediumDifficultyNumberGen();
			randomNum2 = MediumDifficultyNumberGen();
		}
	}
	if (difficulty == D_HARD) {
		randomNum = HardDifficultyNumberGen();
		randomNum2 = HardDifficultyNumberGen();
		while (randomNum2 == 0 || randomNum <= randomNum2 || !(randomNum % randomNum2 == 0) ) {
			randomNum = HardDifficultyNumberGen();
			randomNum2 = HardDifficultyNumberGen();
		}
	}

	cout << randomNum << " / " << randomNum2 << " = ?" << endl;

	int answer;
	cin >> answer;

	correctAnswerForDiv(answer, randomNum, randomNum2);
}

void divisionQuiz() {
	DifficultyOptions difficulty = D_EASY;
	string takeAgainString;
	cout << "All answers will be integers: Round down if answer contains a decimal." << endl;
	do {
		findUserDifficulty(difficulty);

		for (int i = 0; i < 10; i++) {
			divDifficultyQuestions(difficulty);
		}
		cout << endl;
		displayNumCorrect();

		if (numCorrect > 0) {
			getUserName();
		}
		
		cout << "Would you like to take another Quiz? Type yes or no" << endl;
		cin >> takeAgainString;
	} while (takeAgain(takeAgainString));
}

int main() {
	unitTest();
	srand(time(0));
	string quizType;

	cout << "Choose a type of quiz: Addition, Subtraction, Multiplication, or Division" << endl;
	cin >> quizType;
	cout << "Type: " << quizType << endl;
	if (quizType == "addition" || quizType == "Addition") {
		additionQuiz();
	}
	if (quizType == "subtraction" || quizType == "Subtraction") {
		subtractionQuiz();
	}
	if (quizType == "multiplication" || quizType == "Multiplication") {
		multQuiz();
	}
	if (quizType == "division" || quizType == "Division") {
		divisionQuiz();
	}

	highScores();

	return 0;
}
