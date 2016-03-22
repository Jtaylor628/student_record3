#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
struct student_records
{
	double get_average();
	char calc_letter_grade();
	void output_info();
	//void score_output();


	string student_name;
	int quiz1;
	int quiz2;
	int exam1;
	int exam2;
	
	string letter;

	

};
int main() {

	student_records student1;
	student_records student2;
	student_records student3;
	student_records student4;
	student_records student5;
	student_records student6;

	vector <student_records> students;
	students.push_back(student1);
	students.push_back(student2);
	students.push_back(student3);
	students.push_back(student4);
	students.push_back(student5);
	students.push_back(student6);

	ifstream in_stream;
	ofstream out_stream;

	in_stream.open("studentrecords.txt");
	if (in_stream.fail())
	{

		cout << "Input file opening failed.\n";
	}

	string a;
	int count = 0;
	int line = 0;
	while (!in_stream.eof()) {

		in_stream >> a;
		int begin = 0;
		count = 0;

		for (int j = 0; j < a.size(); j++)
		{

			if (a[j] == ',' || j == a.size() - 1)
			{

				switch (count)
				{
				case 0:
					students[line].student_name = a.substr(0, j);
					break;
				case 1:
					students[line].quiz1 = stoi(a.substr(begin, j));
					break;
				case 2:
					students[line].quiz2 = stoi(a.substr(begin, j));
					break;
				case 3:
					students[line].exam1 = stoi(a.substr(begin, j));
					break;
				case 4:
					students[line].exam2 = stoi(a.substr(begin));
					break;
				default:
					break;
				}
				count++;             
				begin = j + 1;
			}
		}
		line++;

	};
	
	
	



	for (int i = 0; i < 6; i++)
	{
		students[i].output_info();
	}

	/*string a;
	in_stream >> a;
	cout << a;*/



	in_stream.close();
	out_stream.close();

	return 0;

}

 double student_records::get_average()
{
	double final_examGrade = exam2 * 0.5;
	double midterm_examGrade = exam1 * 0.25;
	double quiz1_percent = quiz1;
	double quiz2_percent = quiz2;
	double two_quizGrade = ((quiz1 + quiz2) / 20.0) * 100;
	double result;
	result = final_examGrade + midterm_examGrade + 0.25 * two_quizGrade;
	return result;
	
}

char student_records::calc_letter_grade()
{
	if (get_average() > 90)
		return 'A';
	else if (get_average() >= 80)
		return 'B';
	else if (get_average() >= 70)
		return 'C';
	else if (get_average() >= 60)
		return 'D';
	else
		return 'F';
	
}

void student_records::output_info()
{
	cout << "Student name: " << student_name << endl;
	cout << "Quiz 1: " << quiz1 << endl;
	cout << "Quiz 2: " << quiz2 << endl;
	cout << "Exam 1: " << exam1 << endl;
	cout << "Exam 2: " << exam2 << endl;
	cout << "Final grade: " << get_average() << endl;
	cout << "Letter grade: " << calc_letter_grade() << "\n" << endl;
}
