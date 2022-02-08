#pragma once

#include "tgbot/tgbot.h"

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <memory>

class Data
{
public:
	Data(const std::string& _tkn) :
		token(std::string(_tkn)),
        run(true)
	{
	}

public:
	std::string& Token() { return token; }
    bool& Run() { return run; }
    void SetRun(bool value) { run = value; }

private:
	std::string token;
    bool run;

};

std::string getFirstLineFromFile(const std::string& fileName) {
    std::fstream infile(fileName, std::ios::in);
    std::string line;

    while (std::getline(infile, line))
    {
        return line;
    }

    return "";
}