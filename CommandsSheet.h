#include <iostream>
#include <string>

using namespace std;

class Commands
{
private:
    string CommandsSheet;
    Commands* NextCommands;

public:
    // Friend functions for access to private members
    friend void Values();
    friend void PrintCommands(Commands* commands);
};

void PrintCommands(Commands* commands)
{
    while (commands != NULL)
    {
        cout << commands->CommandsSheet << endl << endl;
        commands = commands->NextCommands;
    }
}

void Values()
{
    // Create Commands objects
    Commands* Sys = new Commands();
    Commands* File = new Commands();
    Commands* PS = new Commands();
    Commands* Net = new Commands();
    Commands* WD = new Commands();
    Commands* Apt = new Commands();
    Commands* Flathub = new Commands();
    Commands* Wine = new Commands();
    Commands* Proton = new Commands();
    Commands* TGPT = new Commands();

    // Populate commands
    Sys->CommandsSheet = "1-update 2-upgrade 3-update && upgrade 4-memory 5-cpu 6-pci 7-usb 8-add user 9-remove user 10-root";
    Sys->NextCommands = File;
    File->CommandsSheet = "11-where is me 12-new d 13-move f 14-copy f 15-remove d 16-remove f 17-clean 18-show per 19-ch per 20-ch owner 21-tar 22-gzip 23-zip 24-unzip 25-ungzip 26-untar";
    File->NextCommands = PS;
    PS->CommandsSheet = "27-what is happening";
    PS->NextCommands = Net;
    Net->CommandsSheet = "28-net int 29-ping 30-routing table 31-ports 32-ssh 33-connect 34-my network";
    Net->NextCommands = WD;
    WD->CommandsSheet = "35-down";
    WD->NextCommands = Apt;
    Apt->CommandsSheet = "36-apt";
    Apt->NextCommands = Flathub;
    Flathub->CommandsSheet = "37-flathub";
    Flathub->NextCommands = Wine;
    Wine->CommandsSheet = "38-install wine 39-run exe 40-wine GUI";
    Wine->NextCommands = Proton;
    Proton->CommandsSheet = "41-run steam 42-install steam 43-install proton 44-proton config";
    Proton->NextCommands = TGPT;
    TGPT->CommandsSheet = "45-remove ai 46- i want to learn c++  -- if you want improve this program when you are running it, Type \"improve\"";
    TGPT->NextCommands = NULL;

    // Print commands
    PrintCommands(Sys);

    // Cleanup memory
    Commands* current = Sys;
    while (current != NULL)
    {
        Commands* next = current->NextCommands;
        delete current;
        current = next;
    }

     /*

      instead of 

      delete Sys;      
      delete File;
      delete PS;
      delete Net;
      delete WD;
      delete Apt;
      delete Flathub;
      delete Wine;
      delete Proton;
      delete TGPT;

     */ 


}

