#pragma once
#include <iostream>
#include<string>

using namespace std;

class ProcessManagement
{

private:
    int Result;
    string command;
public:
friend class Linux;


/* //! show what's happening in your device 
void ShowProcesses()
{
    this->command = "top";      
    this->Result =system(this->command.c_str());
    if (this->Result != 0)
    {
        cerr << "Failed to execute 'what happening'.\n";
    }
}
 */


//! Smart what happening
void ShowProcesses() 
{
    this->command = "which htop";
    this->Result = system(this->command.c_str());
    system("clear");
    if (this->Result == 0)
    {

        this->command = "gnome-terminal -- htop";      
        system(this->command.c_str());


    }



     else   if (this->Result != 0) 

        {
            std::cerr << "Do you want to install 1-htop or use an 2-alternative?: ";
            std::cin >> this->command;

            if (this->command == "1") 
            {
                this->command = "sudo apt install htop -y";
                this->Result = system(this->command.c_str());

                if (this->Result == 0) 
                {
                    ShowProcesses();  
                } else 
                {
                    cerr << "Failed to install 'htop'.\n";
                }
            } 
            else if (this->command == "2") 
            {
                this->command = "   gnome-terminal -- top";      
                this->Result = system(this->command.c_str());

                if (this->Result != 0) 
                {
                    std::cerr << "Failed to execute 'top'.\n";
                }
            } 
            else 
            {
                cerr << "Invalid choice! Please enter 1 or 2.\n";
            }
        }
    }



};