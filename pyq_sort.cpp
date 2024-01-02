#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class chapter
{
private:
public:
	int chapter_number;
	int no_of_keywords;
	string name;
	vector<string> keywords;

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

class questions : public chapter
{
private:
public:
	int marks;
	// string paper_identifier;
	string question_string;

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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// Variable Declaration
	int questions_count = 24, no_of_chapters = 6;
	questions arr[30];
	chapter chapter[no_of_chapters];

	arr[0].input_questions(questions_count, arr);
	arr[0].print_questions(questions_count, arr);
	cout << "\n"
		 << endl;
	chapter[0].input_chapters(no_of_chapters, chapter);
	chapter[0].print_chapters(no_of_chapters, chapter);
	return 0;
}