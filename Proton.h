#include <iostream>
#include <string> 
#include "System.h"
#include "FileManagement.h"


using namespace std;

class System;
class FileManagement;
class Linux;

class Proton 
{
    int result;
public:
    friend class Linux;
    friend void UpdatePackage();//!class System
    friend void CreateDirectory(const string& Destination);//! calss File Management

    int RunSteam()
    {
        this->result = system("flatpak run com.valvesoftware.Steam");
        if (this->result == 0)
        { 
           return 0;
        }
        else if(this->result != 0)
        {
            this->result = system("steam");
            if (this->result == 0)
            {
                return 0;
            }
            
        }   
        else 
        {
                 return -1;
        }
        return -1;
    }

    // install Steam
    void InstallSteam()
    {

        this->result = this->RunSteam();
        if (this->result != 0)
        {
            
            cout << "Installing Steam via apt.." << endl;
            
            this->result = system("sudo apt install -y steam");
            if (result != 0)
            {
                cerr << "Failed to install Steam using apt ." << endl;
            }
                
            
        }
    }

    // Function to provide instructions for enabling Proton in Steam
    void ConfigureProton() 
    {
        cout << "\nProton setup completed! Follow these steps to enable Proton in Steam:\n";
        cout << "1. Open Steam and log in with your account.\n";
        cout << "2. Go to Steam > Settings > Compatibility.\n";
        cout << "3. Check 'Enable Steam Play for supported titles'.\n";
        cout << "4. (Optional) Check 'Enable Steam Play for all other titles'.\n";
        cout << "5. Select the desired Proton version from the dropdown."<<endl ;
    }

    

    //! install proton
    void installProton() 
    {
        UpdatePackage();//!friend function 
        InstallSteam();
        CreateDirectory("~/.steam/root/compatibilitytools.d");//! friend function
        ConfigureProton();
    }
};
