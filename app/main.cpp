#include <iostream> 
#include "HashMap.hpp" 
#include "ui.hpp"

int main()
{
    while (true)
    {
        std::string cmd; 
        std::cin >> cmd;

        if (cmd == "CREATE")
        {
            create(); 
        }
        else if (cmd == "LOGIN")
        {
            login();
        }
        else if (cmd == "REMOVE")
        {
            remove(); 
        }
        else if (cmd == "CLEAR") 
        {
            clear(); 
        }
        else if (cmd == "QUIT")
        {
            std::cout << "GOODBYE" << std::endl; 
            return 0; 
        }
        else if (cmd == "DEBUG")
        {
            debugSwitch(); 
        }
        else if (cmd == "BUCKET") 
        {
            printBucketCount(); 
        }
        else if (cmd == "LOAD") 
        {
            printLoadFactor(); 
        }
        else if (cmd == "MAX") 
        {
            printMaxBucketSize(); 
        }
        else
        {
            std::cout << "INVALID" << std::endl; 
        }
    }
    

    return 0;
}

