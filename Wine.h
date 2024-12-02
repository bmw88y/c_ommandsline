#pragma once
#include <iostream>
#include "System.h"
#include "W-Download.h"

using namespace std;

class System;
class WDownload;
class Wine 
{
private:

    string command , exeFilePath;
    int result;

public:

 friend class Linux;    
 friend void DownloadFileWgetORCurl(const string& url) ; //! friend function form class WDownload
 friend void UpdatePackage();  //! friend function to update package 



    //!add 32-bit architecture support
    void AddArchitecture32() 
    {
        cout << "Enabling 32-bit architecture..." << endl;
        this->command = "sudo dpkg --add-architecture i386";
        this->result = system(this->command.c_str());
        if (this->result != 0) 
        {
            cerr << "Failed to enable 32-bit architecture." << endl;
        }
    }



    //! add WineHQ repository
    void AddWineRepo() 
    {
        cout << "Adding WineHQ key..." << endl;
      //!!!!
        DownloadFileWgetORCurl("-qO - https://dl.winehq.org/wine-builds/Release.key | sudo apt-key add -"); //! friend function form class WDownload
        this->result = system(this->command.c_str());
        if (this->result != 0) 
        {
            cerr << "Failed to add WineHQ key." << endl;
            return;
        }

        cout << "Adding WineHQ repository..." << endl;
        this->command = "sudo add-apt-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ focal main'";
        this->result = system(this->command.c_str());
        if (this->result != 0) 
        {
            cerr << "Failed to add WineHQ repository." << endl;
        }
    }
    

    //! install Wine (stable version)
    void InstallWine() 
    {
        cout << "Installing Wine..." << endl;
        this->command = "sudo apt install --install-recommends winehq-stable";
        this->result = system(this->command.c_str());
        if (this->result != 0) 
        {
            cerr << "Failed to install Wine." << endl;
        }
    }

    //! verify the installation of Wine
    void VerifyInstallation() 
    {
        cout << "Verifying Wine installation..." << endl;
        this->command = "wine --version";
        this->result = system(this->command.c_str());
        if (this->result != 0) 
        {
            cerr << "Failed to verify Wine installation." << endl;
        }
    }
 

    //!run the entire Wine installation process
    void InstallWineSteps()
     {
        
        AddArchitecture32();
        AddWineRepo();
        UpdatePackage(); //!friend function
        InstallWine();
        VerifyInstallation();
    }

    //todo-- install/run a .exe file using Wine
    void InstallExeUsingWine() 
    {
        cout << "Enter the full path to the .exe file : ";
        cin >> exeFilePath; 

        command = "wine \"" + exeFilePath + "\"";

        cout << "Running the installer for: " << exeFilePath << endl;

        result = system(command.c_str());

        // Check
        if (result != 0) 
        {
            cerr << "\n\n\n\nFailed to run the .exe file using Wine. Please check the file path or Wine installation.\n\n\n" << endl;
            InstallWineSteps();
            InstallExeUsingWine();
        } else 
        {
            cout << ".exe file ran successfully with Wine." << endl;
        }
    }


//! Wine Program manager Install/Remove apps
 void WineProgManageGUI() 
 {
        cout << "Wine's program manager  \'GUI\' /-: \n";
        this->result = system("wine uninstaller");

        if (this->result != 0) 
        {
            cerr << "Error: Unable to show installed applications. Ensure Wine is installed and configured properly.\n";
            /* InstallWineSteps(); */
        }
    }
};

