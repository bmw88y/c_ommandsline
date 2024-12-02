#pragma once
#include <iostream>
#include <string>

using namespace std;

class Flathub 
{
private:
    friend class Linux;
    string command;
    string appName;
    int Result;


public:

//! Install an app from Flathub
void InstallApp() 
    {
        cout << "Enter the Flatpak app ID to install (e.g., org.telegram.desktop , com.visualstudio.code): ";
        cin >> this->appName;
        this->command = "flatpak install -y flathub " + this->appName;
        this->Result = system(this->command.c_str());
        
        if (this->Result != 0) 
        {
            cerr << "Failed to execute: " << appName << endl;
        }
        
    }

//! Show flatpak app IDs
void ShowFlatpakAppIDs() 
    {
        this->command = "flatpak list --app --columns=application"; 
        cout<<"Displaying installed Flatpak applications...\n";
        this->Result = system(this->command.c_str());
        if (this->Result != 0) 
        {
            cerr << "Failed to execute the command: " << this->command << "\n";
        }
    }

//! Remove an app installed via Flatpak
void RemoveApp() 
    {
        ShowFlatpakAppIDs();
        cout << "\nEnter the Flatpak app ID to remove: ";
        cin >> this->appName;

        this->command = "flatpak uninstall -y " + this->appName;
        system(this->command.c_str()); 
        cout<<endl;
    }

//! Search for an app on Flathub
void SearchApp() 
    {
        cout << "Enter a keyword to search for Flatpak apps: ";
        cin >> this->appName;

        this->command = "flatpak search " + this->appName;
        system(this->command.c_str());
    }

//! Update all Flatpak apps
void UpdateApps() 
    {
        this->command = "flatpak update -y";
        cout << "Updating all Flatpak apps...\n";
        system(this->command.c_str());
    }

//! List installed Flatpak apps
void ListInstalledApps() 
    {
        this->command = "flatpak list";
        cout << "Listing installed Flatpak apps...\n";
        system(this->command.c_str());
        cout<<endl;
    }

};
