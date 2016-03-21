#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
struct student_records
{
	string student_name;
	double get_average();
	int quiz1;
	int quiz2;
	int exam1;
	int exam2;
	int final;
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
	
	
	cout << students[0].student_name;

	for (int i = 0; i < 6; i++)
	{
		cout << "Student name: " << students[i].student_name << endl;
		cout << "Quiz 1: " << students[i].quiz1 << endl;
		cout << "Quiz 2: " << students[i].quiz2 << endl;
		cout << "Exam 1: " << students[i].exam1 << endl;
		cout << "Exam 2: " << students[i].exam2  << endl;
		cout << "Final grade: " << students[i].get_average() << "\n" << endl;
	};
	

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
	double two_quizGrade = (quiz1 + quiz2) * 0.25;
	double final_grade = final_examGrade + midterm_examGrade + two_quizGrade;
	return final_grade;
}
