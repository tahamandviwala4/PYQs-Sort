#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
// Chapter class
class chapter
{
private:
public:
	int chapter_number;
	int no_of_keywords;
	string name;
	vector<string> keywords;
	vector<int> questions;

	// Constructor
	chapter(){};
	chapter(int chapter_number, string name)
	{
		this->chapter_number = chapter_number;
		this->name = name;
	};

	// Function to take chapter name and keywords as input
	void input_chapters(int n, chapter *chapters)
	{
		for (int i = 0; i < n; i++)
		{
			string templine;
			getline(cin, templine);
			if (templine.empty())
			{
				break;
			}
			else
			{
				chapters[i].name = templine;
				getline(cin, templine);
				chapters[i].no_of_keywords = word_counter(templine);
				word_seperater(templine, chapters[i].keywords);
			}
		}
		cout << "Input Successful" << endl;
	}

	// Function to count no. of keywords
	int word_counter(string str)
	{
		stringstream s(str);
		string word;
		int count = 0;
		while (s >> word)
		{
			count++;
		}

		return count;
	}

	// Function to seperate keywords
	void word_seperater(string input_keywords, vector<string> &words)
	{
		stringstream ss(input_keywords);
		string word;

		// Extract words using the stringstream
		while (ss >> word)
		{
			words.push_back(word);
		}
	}

	// Function to print the values stored in chapter class
	void print_chapters(int n, chapter *chapters)
	{
		cout << "Entered Print Chapter function" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << chapters[i].name << endl;
			cout << chapters[i].no_of_keywords << endl;
			for (int j = 0; j < chapters[i].no_of_keywords; j++)
			{
				cout << chapters[i].keywords[j] << " ";
			}
			cout << "\n"
				 << endl;
		}
	}
};

// Question class
class questions : public chapter
{
private:
public:
	int marks;
	string question_string;
	// string paper_identifier;

	// Constructor
	questions(){};
	questions(string question_string, int chapter, int marks)
	{
		this->question_string = question_string;
		this->chapter_number = chapter;
		this->marks = marks;
		// this->paper_identifier = paper_identifier;
	};

	// Function to take input questions
	questions *input_questions(int no_of_questions, questions *arr)
	{
		for (int i = 0; i < no_of_questions; i++)
		{
			// Store questions into the array of class questions
			getline(cin, arr[i].question_string);
			// Store marks in to array of class questions
			arr[i].marks = arr[i].question_string[arr[i].question_string.length() - 2] - '0';
			// Formatting string
			arr[i].question_string.erase(arr[i].question_string.length() - 3, arr[i].question_string.length());
			arr[i].question_string.erase(0, 3);
		}
		cout << "Input quesiton" << endl;
		return arr;
	}

	// Function to print questions
	void print_questions(int no_of_questions, questions *arr)
	{
		string identifier = "S23";
		for (int i = 0; i < no_of_questions; i++)
		{
			cout << "- " << arr[i].question_string << "(" << identifier << "-" << arr[i].marks << ")" << endl;
		}
	}
};

// Function to print elements of vector
void print_vector(vector<int> extra_question)
{
	for (int i = 0; i < extra_question.size(); i++)
	{
		cout << extra_question[i] << endl;
	}
}

// Function to store indexes of question array if the keyword matches
void question_identifier(questions *qarr, int question_count, chapter *chapter_array, int chapter_count, vector<int> &extra_questions)
{
	for (int i = 0; i < question_count; i++)
	{
		bool found = false;
		for (int j = 0; j < chapter_count; j++)
		{
			for (int k = 0; k < chapter_array[j].no_of_keywords; k++)
			{
				int index = qarr[i].question_string.find(chapter_array[j].keywords[k]);
				if (index != -1 && !found)
				{
					chapter_array[j].questions.push_back(i);
					found = true;
					// cout << "question no " << i + 1 << " of chapter " << j + 1 << " with keyword : " << chapter_array[j].keywords[k] << endl;
				}
				// cout << chapter_array[j].keywords[k] << endl;
			}
		}
		if (!found)
		{
			extra_questions.push_back(i);
			// cout << "question not found" << endl;
		}
	}
}

// Function to print questions chapter wise
void print_sorted_pyq(questions *qarr, int question_count, chapter *chapter_array, int chapter_count, vector<int> &extra_questions, string identifier)
{
	question_identifier(qarr, question_count, chapter_array, chapter_count, extra_questions);
	for (int i = 0; i < chapter_count; i++)
	{
		cout << "## Ch-" << i + 1 << " " << chapter_array[i].name << endl;
		for (int j = 0; j < chapter_array[i].questions.size(); j++)
		{
			cout << "-" << qarr[chapter_array[i].questions[j]].question_string << "(" << qarr[chapter_array[i].questions[j]].marks << "-" << identifier
				 << ")" << endl;
		}
		cout << endl;
	}
	cout << "## Extras" << endl;
	for (int i = 0; i < extra_questions.size(); i++)
	{
		cout << "-" << qarr[extra_questions[i]].question_string << "(" << qarr[extra_questions[i]].marks << "-" << identifier
			 << ")" << endl;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// Variable Declaration
	int questions_count = 24, no_of_chapters = 7;
	questions questions[30];
	chapter chapter[15];
	vector<int> extra_questions;

	// Functions calls
	chapter[0].input_chapters(no_of_chapters, chapter);
	questions[0].input_questions(questions_count, questions);
	// chapter[0].print_chapters(no_of_chapters, chapter);
	// questions[0].print_questions(questions_count, questions);

	print_sorted_pyq(questions, questions_count, chapter, no_of_chapters, extra_questions, "W21");
	return 0;
}