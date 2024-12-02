#pragma once
#include <iostream>
#include <string>


using namespace std;

class Network
{

private:
string command , hostname , user;
int Result;

public:
friend class Linux;

//! Display network interfaces (ifconfig)
void ShowNetworkInterfaces() 
    {
        this->command = "ifconfig";
        this->Result = system(this->command.c_str());
        if (this->Result != 0) {
            cerr << "Failed to display network interfaces.\n";
        }
    }

//! Ping a host
 void PingHost() 
    {  
        cout<<"Enter the IP or Host name :";
        getline(cin , this->hostname); 
        this->command = "ping -c 4 " + this->hostname;  // Ping 4 times
        this->Result = system(this->command.c_str());
        if (this->Result != 0)
        {
            cerr << "Failed to ping " << hostname << ".\n";
        }
    }

//! Routing table

void ShowRoutingTable()
 {
        this->command = "route -n"; 
        cout << "Routing table : \n";
        this->Result = system(this->command.c_str());

        if (this->Result != 0) 
        {
            cerr << "Failed to display the routing table.\n";
        }
    }

//! Displaying listening TCP and UDP ports

void ShowListeningPorts() 
{
        this->command = "ss -tuln";
        cout << "Displaying listening TCP and UDP ports...\n";
        this->Result = system(this->command.c_str());

        if (this->Result != 0) 
        {
            cerr << "Failed to execute the command: " << this->command << "\n";
        }
    }

//! Display network connections (netstat)
/* void ShowNetworkConnections() //!old
    {
        this->command = "netstat -tuln";
        this->Result = system(this->command.c_str());
        if (this->Result != 0) {
            cerr << "Failed to display network connections.\n";
        }
    } */


//! Securely connect to a remote server (SSH)
void SSHConnect() 
    {
        cout<<"Enter username : ";
        getline(cin , this->user);
        cout<<"Enter the hostname : ";
        getline(cin , this->hostname);
        this->command = "gnome-terminal -- ssh " + this->user + "@" + this->hostname;
        this->Result = system(this->command.c_str());
        if (this->Result != 0)
        {
            cerr << "Failed to connect via SSH.\n";
        }
    }

//! Command to connect to the Wi-Fi network using nmcli
void ConnectWiFi() 
    {
        
        cout<<"Network name: ";
        getline(cin , this->hostname);
        cout<<"Password :";
        getline(cin , this->user); // for password (-;
        this->command = "nmcli dev wifi connect \"" + this->hostname + "\" password \"" + this->user + "\"";
        this->Result = system(this->command.c_str());
        
        if (this->Result == 0) 
        {
            cout << "Successfully connected to Wi-Fi network: " << this->hostname << "\n";
        } else 
        {
            cerr << "Failed to connect to Wi-Fi network: " << this->hostname << "\n";
            
        }
    }
//! display my network
void ShowMyNetwork()
    {
        this->Result = system("nmcli connection show --active");
        if (this->Result != 0)
        {
            system("sudo apt install network-manager");
            ShowMyNetwork();
        }
    }


};