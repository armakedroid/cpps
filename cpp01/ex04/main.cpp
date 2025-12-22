#include <iostream>
#include <fstream>

using std::string;
using std::getline;
using std::find;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv)
{
	if (argc != 4)
		return (cout<<"Error! Give arguments in this format`\n<filename> <string1> <string2>"<<endl, 1);

	ifstream file1(argv[1]);
	if (!file1.is_open())
		return (cout<<"Error! Can't open file"<<endl, 1);
		
	string newfile = argv[1];
	newfile += ".replace";
	ofstream poghos(newfile.c_str());
	if (!poghos.is_open())
		return (cout<<"Error! Can't open file"<<endl, 1);
	
	string fileStr;
	while (getline(file1, fileStr))
	{
		int k = fileStr.find(argv[2]);
		if (k != -1)
		{
			string newstr = "";
			string strs[2] = {argv[2], argv[3]};
			int lens[2] = {(int)strs[0].length(), (int)strs[1].length()};
			for (int i = 0; i < (int)fileStr.length(); i++)
			{
				if (i < k || k == -1)
				{
					newstr += fileStr[i];
				}
				else
				{
					for (int j = 0; j < lens[1]; j++)
						newstr += strs[1][j];
					i += lens[0] - 1;
					k = fileStr.find(argv[2], k + 1);
				}
			}
			poghos<<newstr<<endl;
		}
		else
			poghos<<fileStr<<endl;
	}
}