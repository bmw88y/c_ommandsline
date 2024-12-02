#pragma once
#include <iostream>
#include <string>



using namespace std;
class WDownload
{
private:
friend class Linux;


public:

     
//! Download files using wget or curl
friend void DownloadFileWgetORCurl(const string& url);

    
};

void DownloadFileWgetORCurl(const string& url ) 
    {
        string command;
        int Result;        
    //TODO Download using wget
        command = "wget " + url;
        Result = system(command.c_str());
        if (Result != 0) 
        {
            cerr << "Failed to download file from " << url << " using wget.\n\nI'll try using culr \n";
    //TODO Try to download use curl
            command = "curl -O " + url;
            Result = system(command.c_str());
             if (Result != 0) 
             {
                cerr << "Failed to download file from " << url << " using curl.\n";
             }
        }
    }
