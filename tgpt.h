#include <iostream>
#include <string>


using namespace std;

class tgpt
{
    private:
    
    string Command, subcommand , COMMAND;
    int Result , result;

    public:

    int cloneTGPT()
    {
        //! You can change the path... and remember you can not use tgpt if you do not store this file in this path, for a first time only..
        this->Result = system("cd ~/CommandsLine && git clone https://github.com/aandrew-me/tgpt.git");
        if (this->Result != 0)
        {
            this->Result = installGIT();
            this->result = cloneTGPT();
            if (this->Result == 0 && this->result == 0)
            {
                return 0;
            }
            else 
            {
                return -1;
            }
        }
        else
        {
            cout<<"Done.\n";
            return 0;
        }
    }  


//! git from apt
    int installGIT()
    {
        this->Result = system("sudo apt install git");
        return this->Result;
    }

    //! intall terminal tgpt and give him excute permision..


    int installTGPT()
    {
           this->Result = system("cd ~/CommandsLine/tgpt && chmod +x ./install && ./install");
           return this->Result;
    }


//! All functions above I used them here ..

    void runTGPTsteps()
    {
        this->Result = installTGPT();
        if (this->Result == 0)
        {
            cout<<"Instelled tgpt on your computer, Enjoy!\n";
        }   
        else
        {
            cout<<"We'll downloading tgpt from github\n";
            this->Result = cloneTGPT();
            if (this->Result != 0)
            {
                cerr<<"Check your internet connection..\n";
                cloneTGPT();
            }
            else
            {
                runTGPTsteps();
            }
        }
    }

//! for remove terminal gpt

    void RemoveTGPT()
    {
        system("sudo rm /usr/local/bin/tgpt");
    }

    int TGPT(const string& Command)
    {
        string  Header = "tgpt \"give me a answer only without anything I do not need it, Or if my command incorrect, so send to me the correct command only, ";
        this->COMMAND = Header + Command +"\"";
        this->Result = system(this->COMMAND.c_str());
        return this->Result;
    }
      
};

/* 
this->Result =  system(this->Command.c_str());
                if (this->Result != 0)
                {/
                    char answer;
                    string  caption = "tgpt \"give me a answer only without anything I do not need it, Or if my command incorrect, so send to me the correct command only, ";
                    cout<<"Do you whan ask AI (y/n) ? \n";
                    cin>>answer;
                    if (answer == 'y')
                    {   string COMMAND;
                        COMMAND = caption + this->Command + "\"";
                        this->Result  =  system(COMMAND.c_str());

                        if (this->Result != 0)
                        {
                            this->subcommand = "git clone https://github.com/aandrew-me/tgpt.git";
                            this->Result = system(this->subcommand.c_str());
                            if (this->Result != 0)
                            {
                                system("sudo apt install git");
                                system(this->subcommand.c_str());
                            }
                            else
                            {
                                cerr<<"Check your internet connection type \"connect\" to connect to a network \nOr connect with Haider Bassem to solve this problem !";
                            }
                        }

                    }


                }
    } */