#include <string>
#include <iostream>
#include "ui.hpp"
#include "HashMap.hpp"

namespace
{
    bool validate(std::string &line, unsigned int num)
    {
        unsigned int wordCount = 0;
        char prev = '\0';

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ' && prev != ' ')
            {
                wordCount++;
            }
            prev = line[i];
        }

        if (wordCount == num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string getWord(std::string &line)
    {
        std::string word = "";

        char prev = '\0';
        for (int i = 1; i < line.length(); i++)
        {
            if (line[i] == ' ' && prev != ' ')
            {
                line = line.substr(i, line.length() - i);
                return word;
            }
            else
            {
                word += line[i];
            }
            prev = line[i];
        }
        return word;
    }
}

HashMap hm;
bool debug = false;

void create()
{
    std::string line;
    std::getline(std::cin, line);

    if (validate(line, 2))
    {
        std::string username = getWord(line);
        std::string password = getWord(line);
        std::cout << username << ", " << password << std::endl;
        if (!hm.contains(username))
        {
            hm.add(username, password);
            std::cout << "CREATED" << std::endl;
        }
        else
        {
            std::cout << "EXISTS" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void login()
{
    std::string line;
    std::getline(std::cin, line);

    if (validate(line, 2))
    {
        std::string username = getWord(line);
        std::string password = getWord(line);
        if (hm.contains(username))
        {
            if (hm.value(username) == password)
            {
                std::cout << "SUCCEEDED" << std::endl;
            }
            else
            {
                std::cout << "FAILED" << std::endl;
            }
        }
        else
        {
            std::cout << "FAILED" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void remove()
{
    std::string line;
    std::getline(std::cin, line);

    if (validate(line, 1))
    {
        std::string username = getWord(line);
        if (hm.contains(username))
        {
            hm.remove(username);
            std::cout << "REMOVED" << std::endl;
        }
        else
        {
            std::cout << "NONEXISTENT" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void clear()
{
    hm.clear();
    std::cout << "CLEARED" << std::endl;
}

void debugOn()
{
    if (debug == false)
    {
        debug = true;
        std::cout << "ON NOW" << std::endl;
    }
    else
    {
        std::cout << "ON ALREADY" << std::endl;
    }
}

void debugOff()
{
    if (debug == true)
    {
        debug = false;
        std::cout << "OFF NOW" << std::endl;
    }
    else
    {
        std::cout << "OFF ALREADY" << std::endl;
    }
}

void debugSwitch()
{
    std::string line;
    std::getline(std::cin, line);

    if (validate(line, 1))
    {
        std::string usage = getWord(line);
        if (usage == "ON")
        {
            debugOn();
        }
        else if (usage == "OFF")
        {
            debugOff();
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void printBucketCount()
{
    std::string line;
    std::getline(std::cin, line);

    if (validate(line, 1))
    {
        std::string usage = getWord(line);
        if (usage == "COUNT")
        {
            if (debug == true)
            {
                std::cout << hm.bucketCount() << std::endl;
            }
            else
            {
                std::cout << "INVALID" << std::endl;
            }
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void printLoadFactor()
{
    std::string line;
    std::getline(std::cin, line);

    if (validate(line, 1))
    {
        std::string usage = getWord(line);
        if (usage == "FACTOR")
        {
            if (debug == true)
            {
                std::cout << hm.loadFactor() << std::endl;
            }
            else
            {
                std::cout << "INVALID" << std::endl;
            }
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void printMaxBucketSize()
{
    std::string line;
    std::getline(std::cin, line);

    if (validate(line, 2))
    {
        std::string usage1 = getWord(line);
        std::string usage2 = getWord(line);
        if (usage1 == "BUCKET" && usage2 == "SIZE")
        {
            if (debug == true)
            {
                std::cout << hm.maxBucketSize() << std::endl;
            }
            else
            {
                std::cout << "INVALID" << std::endl;
            }
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}
