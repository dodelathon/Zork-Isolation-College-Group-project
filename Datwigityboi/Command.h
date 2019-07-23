#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
using namespace std;

class Command {
private:
	string commandWord;
	string secondWord;

public:
	Command(string firstWord, string secondWord);
    Command();
	string getCommandWord();
	string getSecondWord();
	bool isUnknown();
	bool hasSecondWord();
    void setCommandWord(string word);
    void setSecondWord(string word);
};

#endif /*COMMAND_H_*/
