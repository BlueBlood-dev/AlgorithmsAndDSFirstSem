#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

#define MODULO 65535
using namespace std;

int getIndexCommand(vector<pair<string, int>> labels, string label) {
    for (auto &i: labels)
        if (i.first == label)
            return i.second;
}

int main() {
    ifstream in("quack.in");
    ofstream out("quack.out");

    queue<int> mathPart;
    vector<int> registers(26);
    vector<string> commands;
    vector<pair<string, int>> label;
    string command;
    while (in >> command) {
        commands.push_back(command);
    }
    //make pairs label --- i
    for (int i = 0; i < commands.size(); i++)
        if (commands[i][0] == ':') {
            label.emplace_back(commands[i].substr(1), i);
        }

    for (int i = 0; i < commands.size(); ++i) {
        command = commands[i];
        if (isdigit(command[0])) {
            mathPart.push(stoi(command));
        } else if (command[0] == '+') {
            int value1 = mathPart.front();
            mathPart.pop();
            int value2 = mathPart.front();
            mathPart.pop();
            mathPart.push((value1 + value2) & MODULO);
        } else if (command[0] == '-') {
            int value1 = mathPart.front();
            mathPart.pop();
            int value2 = mathPart.front();
            mathPart.pop();
            mathPart.push((value1 - value2) & MODULO);
        } else if (command[0] == '%') {
            int value1 = mathPart.front();
            mathPart.pop();
            int value2 = mathPart.front();
            mathPart.pop();
            if (!value2)
                mathPart.push(0);
            else
                mathPart.push((value1 % value2) & (MODULO));
        } else if (command[0] == '/') {
            int value1 = mathPart.front();
            mathPart.pop();
            int value2 = mathPart.front();
            mathPart.pop();
            if (!value2)
                mathPart.push(0);
            else
                mathPart.push((value1 / value2) & (MODULO));
        } else if (command[0] == '*') {
            int value1 = mathPart.front();
            mathPart.pop();
            int value2 = mathPart.front();
            mathPart.pop();
            mathPart.push((value1 * value2) & MODULO);
        } else if (command[0] == '>') {
            registers[command[1] - 'a'] = mathPart.front();
            mathPart.pop();
        } else if (command[0] == '<') {
            mathPart.push(registers[command[1] - 'a']);
        } else if (command[0] == 'P') {
            if (command.length() == 1) {
                out << mathPart.front() << "\n";
                mathPart.pop();
            } else {
                out << registers[command[1] - 'a'] << "\n";
            }
        } else if (command[0] == 'C') {
            if (command.length() == 1) {
                out << char(mathPart.front() % 256);
                mathPart.pop();
            } else {
                out << char(registers[command[1] - 'a'] % 256);
            }
        } else if (command[0] == ':') {
            continue;
        } else if (command[0] == 'J') {
            i = getIndexCommand(label, command.substr(1));
        } else if (command[0] == 'Z') {
            if (!registers[command[1] - 'a'])
                i = getIndexCommand(label, command.substr(2));
        } else if (command[0] == 'E') {
            if (registers[command[1] - 'a'] ==
                registers[command[2] - 'a'])
                i = getIndexCommand(label, command.substr(3));
        } else if (command[0] == 'G') {
            if (registers[command[1] - 'a'] >
                registers[command[2] - 'a'])
                i = getIndexCommand(label, command.substr(3));

        } else if (command[0] == 'Q') {
            break;
        }
    }
}