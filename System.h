#pragma once
#include <iostream>
#include <string>




// Forward declaration of the Wine class to avoid circular dependency
class Wine;

using namespace std;

class System
{
private:
    string command, username;
    int Result;

public:
friend class Linux;

//! Update the packages
    void Update()
    {
        this->command = "sudo apt update";
        this->Result = system(this->command.c_str());
            if (this->Result == 0) 
            {
        cout << "System updated successfully.\n";
        } else 
        {
        cerr << "Failed to update the system.\n";
        }
    }
//! Upgrade the system
void Upgrade()
    {
            this->command = "sudo apt upgrade";
            this->Result = system(this->command.c_str());
            if (this->Result == 0) 
            {
            cout << "System upgraded successfully.\n";
            } else 
            {
            cerr << "Failed to upgrade the system.\n";
            }
    }
    // Declare friend function
    friend void UpdatePackage();

    //! RAM and Hard Disk usage
    void MemoryUsage() 
    {
        cout << "\nHard Disk\n\n";
        this->command = "df -h";
        system(this->command.c_str());
        cout << "\nRAM usage\n";
        this->command = "free -h";
        system(this->command.c_str());
    }

    //! CPU Architecture
    void CPUinfo() 
    {
        this->command = "lscpu";
        system(this->command.c_str());
    }

    //! Input & Output Devices
    void PCIinfo() 
    {
        this->command = "lspci";
        system(this->command.c_str());
    }

    //! USB Ports
    void USBinfo() 
    {
        this->command = "lsusb";
        system(this->command.c_str());
    }

    //! User Management: Add User
    void AddUser() 
    {
        cout << "User name: ";
        cin >> this->username;
        this->command = "sudo useradd -m " + this->username;
        this->Result = system(this->command.c_str());

        if (this->Result == 0) {
            cout << "User '" << this->username << "' created successfully.\n";
        } else {
            cerr << "Failed to create user '" << this->username << "'.\n";
        }
    }

    //! User Management: Remove User
    void RemoveUser() 
    {
        cout << "User name: ";
        cin >> this->username;
        this->command = "sudo userdel -r " + this->username;
        this->Result = system(this->command.c_str());

        if (this->Result == 0) {
            cout << "User '" << this->username << "' removed successfully.\n";
        } else {
            cerr << "Failed to remove user '" << this->username << "'.\n";
        }
    }





    //!  root !
    //TODO-- root !


    void root()
    {
        system("gnome-terminal -- sudo -i");
    }
};

// Friend function definition
void UpdatePackage() 
{
    System S;
    S.Update();
    S.Upgrade();
}