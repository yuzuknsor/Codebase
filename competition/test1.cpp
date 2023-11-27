#include <bits/stdc++.h>
// 定位系统标头？标头在哪？
#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
#define _ERROR_LACK_INPUT_ 1
#define _ERROR_INVALID_INPUTS_ 2
#define _ERROR_QUANTITY_OVERFLOW_ 3
#define _ERROR_NO_CONTENT_ 4
#define _ERROR_EXISTENCE_DIRECTORY_ 5

using namespace std;
namespace filesys = filesystem;

bool __Has_Subdirectories(const filesys::path &p)
{
    if (!filesys::is_directory(p))
    {
        return false;
    }
    for (filesys::directory_entry const &entry : filesys::directory_iterator(p))
    {
        if (filesys::is_directory(entry))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "ERROR: At least ONE file extension! (And optionally, ONE specified path, while default is the current.)" << endl;
        return _ERROR_LACK_INPUT_; // RETURN CODE 1
        system("pause");
    }
    if (argc > 3)
    {
        cerr << "ERROR: Unnecessary inputs! " << endl;
        return _ERROR_INVALID_INPUTS_; // RETURN CODE 2
        system("pause");
    }

    size_t total_Lines = 0;
    string directory_Path = argv[2];
    string file_Extension = argv[1];
    /*
        if(file_Extension.empty())
        {
            cerr << "ERROR: File extension not found! " << endl;
            return _ERROR_LACK_INPUT_; // RETURN CODE 1
            system("pause");
        }
    */
    if (directory_Path.empty())
    {
        directory_Path = filesys::current_path();
    }
    if (!filesys::exists(directory_Path))
    {
        cerr << "ERROR: Directory not found! " << endl;
        return _ERROR_EXISTENCE_DIRECTORY_; // RETURN CODE 5
        system("pause");
    }

    bool search_Subdirectories = false;
    if (__Has_Subdirectories(directory_Path))
    {
        int attempts = 0;
        while (attempts < 3)
        {
            char if_search_Subdirectories;
            cout << "Search subdirectories? [Y/N]: " << endl;
            cin >> if_search_Subdirectories;

            if (if_search_Subdirectories == 'Y' || if_search_Subdirectories == 'y')
            {
                cout << "Searching (with subdirectories) ..." << endl;
                break;
            }
            else if (if_search_Subdirectories == 'N' || if_search_Subdirectories == 'n')
            {
                cout << "Searching ..." << endl;
                search_Subdirectories = true;
                break;
            }
            else
            {
                attempts++;
                cerr << "ERROR: Invalid input! " << endl;
            }
        }
        if (attempts == 3)
        {
            cerr << "ERROR: Too many invalid inputs! " << endl;
            return _ERROR_INVALID_INPUTS_; // RETURN CODE 2
            system("pause");
        }
    }
    else
    {
        cout << "Searching ..." << endl;
    }

    if (search_Subdirectories)
    {
        for (filesys::directory_entry const &entry : filesys::recursive_directory_iterator(directory_Path))
        {
            if (entry.path().extension() == file_Extension)
            {
                ifstream file(entry.path());
                string line;
                while (getline(file, line))
                {
                    total_Lines++;
                }
            }
        }
        if (total_Lines == 0)
        {
            cerr << "ERROR: No content found in " << file_Extension << " files at " << directory_Path << " with subdirectories. " << endl;
            return _ERROR_NO_CONTENT_; // RETURN CODE 4
            system("pause");
        }
    }
    else
    {
        for (filesys::directory_entry const &entry : filesys::directory_iterator(directory_Path))
        {
            if (entry.path().extension() == file_Extension)
            {
                ifstream file(entry.path());
                string line;
                while (getline(file, line))
                {
                    total_Lines++;
                }
            }
        }
        if (total_Lines == 0)
        {
            cerr << "ERROR: No content found in " << file_Extension << " files at " << directory_Path << ". " << endl;
            return _ERROR_NO_CONTENT_; // RETURN CODE 4
            system("pause");
        }
    }
    if (total_Lines < 0)
    {
        cerr << "ERROR: LINES QUANTITY OVERFLOW! " << endl;
        return _ERROR_QUANTITY_OVERFLOW_; // RETURN CODE 3
        system("pause");
    }

    cout << "Total lines: " << total_Lines << endl;
    system("pause");
}

// TODO:
// Avoid using "using namespace" globally.
// Add command option of searching subdirectories.
// Functionize the code.
// Rewrite the error code.
// Add file extension check & warns.
/*
    std::filesystem::path directory_Path = "your_directory_path_here";
    std::filesystem::perms p = std::filesystem::status(directory_Path).permissions();

    if ((p & std::filesystem::perms::owner_read) == std::filesystem::perms::none ||
        (p & std::filesystem::perms::group_read) == std::filesystem::perms::none ||
        (p & std::filesystem::perms::others_read) == std::filesystem::perms::none)
    {
        std::cerr << "ERROR: No permission to read directory " << directory_Path << std::endl;
        return _ERROR_NO_PERMISSION_; // RETURN CODE 5
    }
*/
// Add file number & name check & output.
// Add permission check.
// Use CMAKE multi -file programming.
// Add to github repository as an opensource project.