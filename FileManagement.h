#pragma once
#include <iostream>
#include <string>
/* #include <sys/stat.h> */ // chmod
/* #include <unistd.h>    */// chown
#include <limits.h> // for get the current path...

// if I using windows..
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#endif

using namespace std;



class FileManagement
{
    string command , method , source , destination , filePath;
     int Result;
    private:


public:
friend class Linux; 

//! Create Directory

friend void CreateDirectory(const string& Destination);

//! Move File

void MoveFile()
    {
        cout<<"Source : ";
        cin>>this->source;
        cout<<"Destination : ";
        cin>>this->destination;
        this->command = "mv " + source + " " + destination;

        this->Result = system(this->command.c_str());
        // Check
        if (this->Result == 0) 
        {
            cout << "Successfully moved '" << source << "' to '" << destination << "'.\n";
        } else 
        {
            cerr << "Failed to move '" << source << "' to '" << destination << "'.\n";
        }
    }
//! Copy file

void CopyFile()
    {
        cout<<"Source : ";
        cin>>this->source;
        cout<<"Destination : ";
        cin>>this->destination;
        this->command = "cp " +this->source + " " +this->destination;

        this->Result = system(this->command.c_str());

        // Check
        if (this->Result == 0) 
        {
           cout << "Successfully copied '" << source << "' to '" << destination << "'.\n";
        } else 
        {
           cerr << "Failed to copy '" << source << "' to '" << destination << "'.\n";
        }
    }

//! Remove file

void RemoveFile()
{
        cout<<"file path : ";
        cin>>this->filePath;
        this->command = "rm " + filePath;

        this->Result = system(this->command.c_str());

        // Check
        if (this->Result == 0) 
        {
            cout << "Successfully removed '" << filePath << "'.\n";
        } else 
        {
            cerr << "Failed to remove '" << filePath << "'.\n";
        }
    }

//! Remaove directory

void RemoveDirectory() 
    {
        cout<<"Directory path : ";
        cin>>this->filePath;
        char YesNO;
        bool recursive = false;
        cout<<"delete a directory and its contents (y/n) ? ";
        cin>>YesNO;
        if (YesNO == 'y')
        {
            recursive = true;
        }
        else
        {
            recursive = false;
        }
        this->command = "rm " + string(recursive ? "-r " : "") + this->filePath;

        this->Result = system(this->command.c_str());

        // Check 
        if (this->Result == 0) {
            cout << "Successfully removed '" << this->filePath << "'.\n";
        } else {
            cerr << "Failed to remove '" << this->filePath << "'.\n";
        }
    }



//! Delete unnecessary files

void ClearSystem()
    {
        command = "sudo apt autoremove";
        system(command.c_str());
        command = "sudo apt autoclean";
        system(command.c_str());
        command = "sudo apt clean";
        system(command.c_str());
    }

//? Show file permissons

/* void ShowFilePermissions()
    {   cout<<"File path : ";
        cin>>this->filePath;
        cout << "Current permissions for " << filePath << ": \n";
        command = "ls -l " + filePath;
        system(command.c_str());
    } */

//! Show file permissions

void ShowFilePermissions(const string& FilePath)
    {  
        cout << "Current permissions for " << FilePath << ": \n";
        command = "ls -l " + FilePath;
        system(command.c_str());
    }

//! mangement files


//! set value permissions

int NemPermissons()
{
    string VlaluePerm;

    cout << "\nEnter the new permissions (rwx, xr, r): ";
    cin >> VlaluePerm;

    //Set value
    if (VlaluePerm == "rwx") 
    {
        
        return  777; 
    }
    else if (VlaluePerm == "xr") 
    {
       return 755;
    }
    else if (VlaluePerm == "r") 
    {
        return 644;
    }
    else 
    {
        cout << "Invalid input. Please enter rwx, xr, or r." << endl;
        NemPermissons(); // end function
    }

    return -1;

}



//! Change file permissons
void ChangeFilePermissionsManually()
    {
       // string  A ="sudo -i";
       // system(A.c_str());
       //cout<<"You are running as root now!";
       cout<<"File path : ";
       getline(cin , this->filePath);
       ShowFilePermissions(this->filePath);

  int newPermissions = NemPermissons();
    
  /*  
    int newPermissons;
    string VlaluePerm;
     cout << "\nEnter the new permissions (rwx, xr, r): ";
    cin >> VlaluePerm;

    //Set value
    if (VlaluePerm == "rwx") 
    {
        newPermissions = 777; 
    }
    else if (VlaluePerm == "xr") 
    {
        newPermissions = 755;
    }
    else if (VlaluePerm == "r") 
    {
        newPermissions = 644;
    }
    else 
    {
        cout << "Invalid input. Please enter rwx, xr, or r." << endl;
        return; // end function
    } */


    
    if (chmod(filePath.c_str(), newPermissions) == 0) 
    {
        cout << "Permissions changed successfully for " << this->filePath << endl;
    }
    else 
    {
        cerr<<"Error changing permissions";
    }



//! Change Owner inside ChangeFileManually function
    char ChangeOwner;
    cout << "Do you want to change owner (y/n)? : ";
    cin >> ChangeOwner;
    if (ChangeOwner == 'y') 
    {
        ChangeFileOwner(this->filePath);
    }
      else if (ChangeOwner == 'n') 
    {
        cout << "\nOkay (-;\n";
    } else 
    {
        cerr << "\nWrong choice )-: \n";
    }
}

//! Change file Owner

void ChangeFileOwner(const string& FilePath)
{
        uid_t NewOwner;
        gid_t NewGroup;
        cout << "\nEnter the new owner ID: ";
        cin >> NewOwner;
        cout << "Enter the new group ID: ";
        cin >> NewGroup;
        
        command = "sudo chown " + to_string(NewOwner) + ":" + to_string(NewGroup) + " " + FilePath;
        int chownResult = system(command.c_str());

        if (chownResult == 0) 
        {
            cout << "Owner and group changed successfully for " << FilePath << endl;
        } else 
        {
            cerr<<"Error changing owner/group";
        }

   
}


//! file compress and archive



void CompressTAR()
{
    
    cout<<"Source :";
    cin>>this->source;
    cout<<"Destination :";
    cin>>this->destination;

    this->command = "tar -cvf " + this->destination + " " + this->source;
    cout << "Executing command: " << command << "\n";

    this->Result = system(command.c_str());

     if (Result != 0)
      {
        cerr << "Failed to execute: " << command << "\n";
    } else 
    {
        cout << "Compression/Archiving successful using tar .\n";
    }
}

void CompressGZIP()
{
    
    cout<<"Source :";
    cin>>this->source;
    cout<<"Destination :";
    cin>>this->destination;

    this->command = "gizp -c " + this->source + " > " + this->destination;
    cout << "Executing command: " << command << "\n";

    this->Result = system(command.c_str());

     if (Result != 0)
      {
        cerr << "Failed to execute: " << command << "\n";
    } else 
    {
        cout << "Compression/Archiving successful using gzip .\n";
    }
}

void CompressZIP()
{
    
    cout<<"Source :";
    cin>>this->source;
    cout<<"Destination :";
    cin>>this->destination;

    this->command = "zip -r " + this->destination + " " + this->source;
    cout << "Executing command: " << command << "\n";

    this->Result = system(command.c_str());

     if (Result != 0)
      {
        cerr << "Failed to execute: " << command << "\n";
    } else 
    {
        cout << "Compression/Archiving successful using zip .\n";
    }
}


//! Uncompress files


//? Uncompress gzip  

void UncompressGZIP()
{
    cout << "Compressed File (Source) : ";
    cin >> this->source;
    cout << "Destination Folder : ";
    cin >> this->destination;

    this->command = "gunzip -c " + this->source + " > " + this->destination + "/" + this->source.substr(0, this->source.find_last_of('.'));
    cout << "Executing command: " << command << "\n";
    this->Result = system(command.c_str());

    if (Result != 0)
    {
        cerr << "Failed to execute: " << command << "\n";
    }
    else
    {
        cout << "Decompression successful using gunzip.\n";
    }
}

//?  Uncopress zip

void UncompressZIP()
{
    cout << "ZIP File (Source) : ";
    cin >> this->source;
    cout << "Destination Folder : ";
    cin >> this->destination;

    this->command = "unzip " + this->source + " -d " + this->destination;
    cout << "Executing command: " << command << "\n";
    this->Result = system(command.c_str());

    if (Result != 0)
    {
        cerr << "Failed to execute: " << command << "\n";
    }
    else
    {
        cout << "Uncompression successful using unzip.\n";
    }
}

//? Uncopress tar

void UncompressTAR()
{
    cout << "TAR File (Source) : ";
    cin >> this->source;
    cout << "Destination Folder : ";
    cin >> this->destination;

    this->command = "tar -xvf " + this->source + " -C " + this->destination;
    cout << "Executing command: " << command << "\n";
    this->Result = system(command.c_str());

    if (Result != 0)
    {
        cerr << "Failed to execute: " << command << "\n";
    }
    else
    {
        cout << "Uncompression/Extraction successful using tar.\n";
    }
}

//! I got this function form AI
string getCurrentWorkingDirectory() 
{
    char cwd[PATH_MAX]; // Array to store the path   /* #define PATH_MAX        4096	/* # chars in a path name including nul  */
    if (getcwd(cwd, sizeof(cwd)) != nullptr) 
    {
        return string(cwd);
    } else 
    {
        return "Error getting current path";
    }
}



  void changeAndDisplayDirectory(string& destination) 
       {
           if (chdir(destination.c_str()) != 0) 
           {
               cerr << "Failed to change directory to '" << destination << ".\n";
               return;
           }

       }





};

void CreateDirectory(const string& Destination) 
   {
       /*  cout<<"Enter the Destination : ";
        cin>>this->destination; */
        string command;
        int Result;
        command = "mkdir -p " + Destination;
        Result = system(command.c_str());
        // Check
        if (Result == 0) 
        {
            cout << "Directory '" << Destination << "' created successfully.\n";
        } else 
        {
            cerr << "Failed to create directory '" << Destination << "'.\n";
        }
    }
