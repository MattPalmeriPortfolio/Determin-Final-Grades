#include <iostream>

struct StudentRecord
{
	int quiz1 = 0;
	int quiz2 = 0;
	int midterm = 0;
	int finalExam = 0;
	int totalScore = 0;
	char letterGrade;
};
int getScore(const int maxScore);
//Prompts user to enter a score for a quiz. If the input >= 0 && input <= maxScore, returns input; else, prompts user to enter a valid input
StudentRecord calculateTotalGrade(StudentRecord record);
//Precondition: record.quiz1, record.quiz2, record.midterm, and record.finalExam are filled with test scores
//Postcondition: calculates record.totalScore based off of the previous scores using the scoring weights. Determines record.letterGrade based on record.totalScore. Returns record.
void outputRecord(StudentRecord record);
//Outputs the values of record to the screen, organized and labeled nicely.
bool promptContinue();
//Please teach me separate compilation already so i never have to copy this fucking function again.

int main()
{
	using namespace std;
	const int QUIZ_MAX = 10, MIDTERM_FINAL_MAX = 100;
	StudentRecord student;
	//begin program
	cout << "Welcome to the matrix, Neo.\nJust kidding, it's a grading program.\n";
	do
	{
		cout << "Quiz 1:\n";
		student.quiz1 = getScore(QUIZ_MAX);
		cout << "Quiz 2:\n";
		student.quiz2 = getScore(QUIZ_MAX);
		cout << "Midterm:\n";
		student.midterm = getScore(MIDTERM_FINAL_MAX);
		cout << "Final:\n";
		student.finalExam = getScore(MIDTERM_FINAL_MAX);
		student = calculateTotalGrade(student);
		outputRecord(student);
	} while (promptContinue());
	return 0;
}

//define functions
//uses <iostream>
int getScore(const int maxScore)
{
	using namespace std;
	bool valid = false;
	int input = -1;
	while (!valid)
	{
		cout << "Enter a score:\n";
		cin >> input;
		if (input >= 0 && input <= maxScore)
		{
			return input;
			valid = true;
		}
		else
			cout << "Invalid input.\n";
	}
	return 0;
}

StudentRecord calculateTotalGrade(StudentRecord record)
{
	record.totalScore = (((record.quiz1 + record.quiz2) / 20.0) * 25) + ((record.midterm / 100.0) * 25) + ((record.finalExam / 100.0) * 50);
	if (record.totalScore >= 90)
		record.letterGrade = 'A';
	else if (record.totalScore >= 80)
		record.letterGrade = 'B';
	else if (record.totalScore >= 70)
		record.letterGrade = 'C';
	else if (record.totalScore >= 60)
		record.letterGrade = 'D';
	else //if record.totalScore < 60
		record.letterGrade = 'F';
	return record;
}
//uses <iostream>
void outputRecord(StudentRecord record)
{
	using namespace std;
	cout << "The record for this student is:\n"
		<< "Quiz 1: " << record.quiz1 << " / 10\n"
		<< "Quiz 2: " << record.quiz2 << " / 10\n"
		<< "Midterm exam: " << record.midterm << " / 100\n"
		<< "Final exam: " << record.finalExam << " / 100\n"
		<< "Final numeric grade: " << record.totalScore << " / 100\n"
		<< "Final letter grade: " << record.letterGrade << endl;
	return;
}
//uses up my patience
bool promptContinue()
{
	char prompt;
	std::cout << "Would you like to continue? y/n\n";
	std::cin >> prompt;
	if (prompt == 'y' || prompt == 'Y')
		return true;
	else
		return false;
}