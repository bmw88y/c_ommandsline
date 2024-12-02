#pragma once
#include <iostream>
#include <string>


using namespace std;

class apt
{
private:
string command;
string appName;
int Result;

public:

        friend class Linux;
//! Install a package using apt
void InstallApp()
    {
        cout << "Enter the app name to install: ";
        cin >> this->appName;
        if (this->appName != "end")
        {
        this->command = "sudo apt install " + this->appName;
        this->Result = system(this->command.c_str());

        if (this->Result != 0)
        {
            cerr << "Failed to install " << appName << " using apt.\n";
        }
        else
        {
            cout << appName << " installed successfully (-: \n";
        }
        }
        return;
    }

//! Remove a package using apt
void RemoveApp()
    {
        cout << "Enter the app name to remove: ";
        cin >> this->appName;

        if (this->appName != "end")
        {
        this->command = "sudo apt remove -y " + this->appName;
        this->Result = system(this->command.c_str());

        if (this->Result != 0)
        {
            cerr << "Failed to remove " << appName << " using apt.\n";
        }
        else
        {
            cout << appName << " removed successfully (-; \n";
        }
        }
        return;
    }

//! Search for a package using apt
void SearchApp()
    {

        cout << "Enter the app name to search: -><-";
        cin >> this->appName;

        if (this->appName != "end")
        {

        this->command = "apt search " + this->appName;
        this->Result = system(this->command.c_str());

        if (this->Result != 0)
        {
            cerr << "Failed to search for " << appName << ")-\"\n";
        }
        }
        return;
    }
    
};