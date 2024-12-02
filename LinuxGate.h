#include <iostream>
#include <string>
#include <cstdlib>
#include "System.h"
#include "FileManagement.h"
#include "ProcessManagement.h"
#include "W-Download.h"
#include "Network.h"
#include "apt.h"
#include "flathub.h"
#include "Proton.h"
#include "Wine.h"
#include "tgpt.h"
#include "CommandsSheet.h"

using namespace std;

class Linux : private tgpt
{


    private:
    string Command ; 
    string subcommand, Param , end; 
    int Result;

    
    
    
  

    public:


    Linux()
    {
        this->Result= system("clear");
        if (this->Result != 0)
        {
            this->Result = system("cls");
            if (this->Result == 0)
            {
                
                cout<<"You're on windows\nType \"end\" for stop running..\n";
                
                this->Result = system("wsl sudo apt update && sudo apt install -y git &&  git clone https://github.com/bmw88y/CommandsLine.git");
                if (this->Result != 0)
                {
                
                system("Get-AppxPackage -allusers *ubuntu*");
                const char* command = R"(Add-AppxPackage -Register "C:\Program Files\WindowsApps\CanonicalGroupLimited.Ubuntu_20.04.1.0_x64__79rhkp1fndgsc\AppxManifest.xml" -DisableDevelopmentMode)";
                system(command);  
                system("wsl sudo apt update && sudo apt install -y git &&  git clone https://github.com/bmw88y/CommandsLine.git");\
                
                }
                else
                {
                    cout<<"Upuntu is running..."<<endl;
                }

                
              
               
            }
        }
        else
        {
            cout<<"welcome to Linux \nType \"end\" for stop running..\n";
        }



         
        /* string newcom = file.getCurrentWorkingDirectory() + " && cd .. "; */

        /* this->Command = "chmod -R 777 " + file.getCurrentWorkingDirectory()  + " && cd -"; */
    /*     cout<<this->Command<<endl;
        
        system(this->Command.c_str());
    */
    }   



    friend void UpdatePackage();
    System sys; 
    FileManagement file;
    ProcessManagement ps;
    WDownload DWon;
    Network net;
    apt APT;
    Flathub flat;
    Wine WINE;
    Proton PROTON;




    void LinuxGate()
    {
        do
        {
           cout<<"LinuxGate:~$"<<file.getCurrentWorkingDirectory()<<"$ ";
          /*  cin.ignore(); */
           getline(cin , this->Command);
        /*    cin>>this->Command; */

        
            if (this->Command.substr(0,2) == "cd")
            {
                this->subcommand = this->Command.substr(3);
                file.changeAndDisplayDirectory(this->subcommand);
            }



           /* else if (this->Command == "cd")
              {
                 this->subcommand = this->Command + " -e";
                 file.changeAndDisplayDirectory(this->subcommand);
              }
              */

             /*    this->subcommand = this->Command.substr(2);
                system(this->Command.c_str());
                cout<<"you're at "<<this->subcommand<<endl;
                cout<<this->Command<<endl; */

/*                 this->subcommand = file.getCurrentWorkingDirectory(); */
               /*  system(this->Command.c_str()); */
/*                 cout<<"you're at "<<this->subcommand<<endl; */



            
                  


           //! Class System
           else if (this->Command == "update")
           {
            sys.Update();
           }
           else if (this->Command == "upgrade")
           {
            sys.Upgrade();
           }
           else if (this->Command == "update && upgrade" || this->Command == "update&&upgrade")
           {
            UpdatePackage();
           }
           else if (this->Command == "memory")
           {
            sys.MemoryUsage();
           }
           else if (this->Command == "cpu")
           {
            sys.CPUinfo();
           }
           else if (this->Command == "pci")
           {
            sys.PCIinfo();
           }
           else if (this->Command == "usb")
           {
            sys.USBinfo();
           }
           else if (this->Command == "add user")
           {
            sys.AddUser();
           }
           else if (this->Command == "remove user")
           {
            sys.RemoveUser();
           }
    else if (this->Command == "root")
       {
          sys.root();
           }



            //! Class File Management

           
            else if (this->Command == "where is me")
            {
                cout<<"you're at"<<file.getCurrentWorkingDirectory();
            }
            else if (this->Command == "new d")
            {
                cout<<"Enter the Destination and file name :";
                cin>>this->Param;
                CreateDirectory(Param);
            }
            else if (this->Command == "move f")
            {
                file.MoveFile();
            }
            else if (this->Command == "copy f")
            {
                file.CopyFile();
            }
            else if (this->Command == "remove d")
            {
                file.RemoveDirectory();
            }
            else if (this->Command == "remove f")
            {
                file.RemoveFile();
            }
            else if (this->Command == "clean")
            {
                file.ClearSystem();
            }
            else if (this->Command == "show per")
            {
                cout<<"Enter the full path :";
                cin>>this->Param;
                file.ShowFilePermissions(Param);
            }
            else if (this->Command == "ch per")
            {
                file.ChangeFilePermissionsManually();
            }
            else if (this->Command == "ch owner")
            {
                cout<<"Enter the full path: ";
                cin>>this->Param;
                file.ChangeFileOwner(Param);
            }
            else if (this->Command == "tar")
            {
                file.CompressTAR();
            }
            else if (this->Command == "gzip")
            {
                file.CompressGZIP();
            }
            else if (this->Command == "zip")
            {
                file.CompressZIP();
            }
            else if (this->Command == "unzip")
            {
                file.UncompressZIP();
            }
            else if (this->Command == "ungzip")
            {
                file.UncompressGZIP();
            }
            else if (this->Command == "untar")
            {
                file.UncompressTAR();
            }



            //!class Process Management


            else if (this->Command == "what is happening")
            {
                ps.ShowProcesses();
            }


            //! Class Network

            else if (this->Command == "net int")
            {
                net.ShowNetworkInterfaces();
            }
            else if (this->Command == "ping")
            {
                net.PingHost();
            }
            else if (this->Command == "routing table")
            {
                net.ShowRoutingTable();
            }
            else if (this->Command == "ports")
            {
                net.ShowListeningPorts();
            }
            else if (this->Command == "ssh")
            {
                net.SSHConnect();
            }
            else if (this->Command == "connect")
            {
                net.ConnectWiFi();
            }
            else if (this->Command == "my network")
            {
                net.ShowMyNetwork();
            }


            //! Class WDownload

            else if (this->Command == "down")
            {
                cout<<"Enter the URL : ";
                cin>>this->Param;
                DownloadFileWgetORCurl(Param);
            }


            //! Class apt
            else if (this->Command == "apt")
            {
                string aptcommand;
                do 
                {
                    cout<<"1-install or 2-remove or 3-search or Type \"end\" for exti\n";
                    cout<<"LinuxGate:~$"<<file.getCurrentWorkingDirectory()<<"$ ";
                    cin>>aptcommand;
                    if (aptcommand == "install" || aptcommand == "1")
                    {
                        APT.InstallApp();
                    }
                    else if (aptcommand == " remove" || aptcommand == "2")
                    {
                        APT.RemoveApp();
                    }
                    else if (aptcommand == "search" || aptcommand == "3")
                    {
                        APT.SearchApp();
                    }
                   
                    else if (aptcommand == "end")
                    {

                    }
                    else
                    {
                        cerr<<"Invalid choice! Try again\n";
                        cerr<<"or no, Type \"end\"\n";
                    }
                }while (aptcommand != "end");
               
            }



            //! Class Flathub

            else if (this->Command == "flathub")
            {
                string flatcommand;
                do 

                {
                    cout<<"1-install or 2-remove or 3-search 4-IDsApps 5-update 6-list apps or Type \"end\" for exti\n";
                    cout<<"LinuxGate:~$"<<file.getCurrentWorkingDirectory()<<"$ ";
                    getline(cin , flatcommand);
                    if (flatcommand == "install" || flatcommand == "1")
                    {
                        flat.InstallApp();
                    }
                    else if (flatcommand == " remove" || flatcommand == "2")
                    {
                        flat.RemoveApp();
                    }
                    else if (flatcommand == "search" || flatcommand == "3")
                    {
                        flat.SearchApp();
                    }
                    else if (flatcommand == "IDsApps" || flatcommand == "4")
                    {
                        flat.ShowFlatpakAppIDs();
                    }
                    else if (flatcommand == "update" || "5")
                    {
                        flat.UpdateApps();
                    }
                    else if (flatcommand == "list apps" || "6")
                    {
                        flat.ListInstalledApps();
                    }
                    else if (flatcommand == "end")
                    {
                        
                    }
                    else
                    {
                        cerr<<"Invalid choice! Try again\n";
                        cerr<<"or no, Type \"end\"\n";
                   
                    }
                    
                }while (flatcommand != "end");
            }

            //! Class wine

            else if (this->Command == "install wine")
            {
                WINE.InstallWineSteps();
            }
            else if (this->Command == "run exe")
            {
                WINE.InstallExeUsingWine();
            }
            else if (this->Command == "wine GUI")
            {
                WINE.WineProgManageGUI();
            }
            
            //! Class Proton

            else if (this->Command == "run steam")
            {
                PROTON.RunSteam();
            }
            else if (this->Command == "install steam")
            {
                PROTON.InstallSteam();
            }
            else if (this->Command == "install proton")
            {
                PROTON.installProton();
            }
            else if (this->Command == "proton config")
            {
                PROTON.ConfigureProton();
            }
            //!

            else if (this->Command == "cd")
            {

            }
            else if (this->Command == "end")
            {

            }

            else if (this->Command == "improve")
            {
                cout<<"Any file ? :";
                system("ls");
                char karrar;
                getline(cin , this->subcommand);
                string color = "clear && echo -e \"\e[41m\"";
                cout<<"\nAre you Karrar Haithem (y/n)?";
                cin>>karrar;
                system("echo -e \"\e[0m\"");

                if (karrar == 'y')
                {
                    this->Command = "gnome-terminal -- nvim " + this-> subcommand;
                    system(this->Command.c_str());
                }
                else
                {
                    this->Command = "gnome-terminal -- nano " + this-> subcommand;
                    system(this->Command.c_str());
                }
                    

                
               /*  getline(cin , this->subcommand);
                this->Command = "gnome-terminal -- nano " + this->subcommand;
                system(this->Command.c_str()); */
            }
 //! class tgpt
            else if (this->Command == "remove ai")
            {
                RemoveTGPT();
            }


            //! class Commands sheet
            else if (this->Command == "commands")
            {
                Values();
            }


            //! learn c++

            else if (this->Command == "i want to learn c++")
            {
                system("xdg-open https://www.youtube.com/@CodeSimulation");
            }

           
            else
            {
                

                this->Result = system(this->Command.c_str());

                if (this->Result != 0)
                {
                   this->Result = TGPT( this->Command );
                   if (this->Result != 0)
                   {
                    char answer;
                    cout<<"Do you want install tgpt (y/n)?";
                    cin>>answer;
                    if(answer == 'y')
                    {
                       runTGPTsteps(); 
                    }
                    else
                    {
                        cout<<"Okay |-:\n";
                    }

                    
                   } 
                }
                



            }



        } while (this->Command != "end");
        
    }

};

