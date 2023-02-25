#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Глава 11, упр. 13 сделал, но надо убрать лишний пробел, который создаётся в начале новых данных файла (стр. 460).

vector<string> vs;
vector<string> new_words;

int main()
{
	string rev_word;
	string file_name;
	cin >> file_name;
	ifstream ifs(file_name);
	if (!ifs)
	{
		cerr;
	}

	while (getline(ifs, rev_word))
	{
		string new_word;
		string v_push;
		for (char ch: rev_word)
		{
			if (ch != ' ')
			{
				new_word += ch;
			}
			if (ch == ' ')
			{
				new_words.push_back(new_word);
				new_word.clear();
			}
			
		}
		new_words.push_back(new_word);
		reverse(new_words.begin(), new_words.end());

		for (int i = 0; i < new_words.size(); i++)
		{
			v_push += new_words[i];
			v_push += ' ';
		}
		vs.push_back(v_push);
		v_push == "";
		new_words.clear();
	}
	
	ifs.close();

	ofstream ofs(file_name);
	if (!ofs)
	{
		cerr;
	}

	for (int i = 0; i < vs.size(); i++)
	{
		ofs << vs[i] << endl;
	}
	vs.clear();
}