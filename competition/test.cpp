#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <variant>
// Error code
#define _LACK_INPUT_ 1
#define _INVALID_INPUTS_ 2
#define _QUANTITY_OVERFLOW_ 3
#define _NO_CONTENT_ 4
namespace filesys = std::filesystem;
#define iter_REC recursive_directory_iterator // recursive_directory_iterator
#define iter_DIR directory_iterator           // directory_iterator

void __Check_Inputs(int argc, char *argv[], std::string &file_Extension, std::string &directory_Path, std::string &if_search_subdirectories)
{
    if (argc < 2)
    {
        std::cerr << "ERROR: At least ONE file extension! (And optionally, ONE specified path, while default is the current.) " << std::endl;
        exit(_LACK_INPUT_); // RETURN CODE 1
        system("pause");
    }
    if (argc > 4)
    {
        std::cerr << "ERROR: Unnecessary inputs! " << std::endl;
        exit(_INVALID_INPUTS_); // RETURN CODE 2
        system("pause");
    }
    if (file_Extension[0] != '.')
    {
        std::cerr << "ERROR: Invalid file extension! " << std::endl;
        exit(_INVALID_INPUTS_); // RETURN CODE 2
        system("pause");
    }
    if (!filesys::exists(directory_Path))
    {
        std::cerr << "ERROR: Directory not found! " << std::endl;
        exit(_INVALID_INPUTS_); // RETURN CODE 2
        system("pause");
    }
}

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

bool __Confirm_Subdirectories(const filesys::path &p)
{
    if (__Has_Subdirectories(p))
    {
        int attempts = 3;
        for (; attempts > 0; --attempts)
        {
            char if_search_Subdirectories;
            std::cout << "Subdirectories found." << std::endl;
            std::cout << "Search in subdirectories? [Y/N]: " << std::endl;
            std::cin >> if_search_Subdirectories;

            if (if_search_Subdirectories == 'Y' || if_search_Subdirectories == 'y')
            {
                std::cout << "Subdirectories included." << std::endl;
                std::cout << "Searching ..." << std::endl;
                return true;
            }
            else if (if_search_Subdirectories == 'N' || if_search_Subdirectories == 'n')
            {
                std::cout << "Subdirectories excluded." << std::endl;
                std::cout << "Searching ..." << std::endl;
                return false;
            }
            else
            {
                std::cerr << "ERROR: Invalid input! " << std::endl;
                std::cerr << "Remaining " << attempts << " try: " << std::endl;
            }
        }
        if (attempts == 0)
        {
            std::cerr << "ERROR: Too many invalid inputs! " << std::endl;
            std::cout << "Subdirectories excluded." << std::endl;
            return false;
        }
    }
    return false;
}

template <typename T>
void __Log(T &_LOG_)
{
    // _LOG_
    // Normal error log & warn & continue.
    // No permission error log & warn & continue.
    // Fatal error log & exit.
    // Filename log.
    // Enter subdirectories log.
    // TYPE:
    // [DATE | TIME | POSITION | FILENAME | '.']
    // [DATE | TIME | POSITION | FILENAME | '.' | ERROR CODE | SUGGESTED SOLUTION]
}

int main(int argc, char *argv[])
{
    std::string file_Extension = argv[1];
    std::string directory_Path = argv[2];
    std::string if_search_subdirectories = argv[3];

    __Check_Inputs(argc, argv, file_Extension, directory_Path, if_search_subdirectories);

    // Confirm if search subdirectories.
    bool search_Subdirectories = false;
    if (if_search_subdirectories == "N" || "n")
    {
        search_Subdirectories = false;
    }
    else if (if_search_subdirectories == "Y" || "y")
    {
        search_Subdirectories = __Has_Subdirectories(directory_Path);
        if (!search_Subdirectories)
        {
            std::cerr << "ERROR: No subdirectories found! " << std::endl;
            std::cout << "Searching current directory..." << std::endl;
        }
    }
    else
    {
        search_Subdirectories = __Confirm_Subdirectories(directory_Path);
    }

    // Count lines.
    size_t total_Lines = 0;
    std::variant<filesys::iter_REC, filesys::iter_DIR> search_Scope;
    if (search_Subdirectories)
        search_Scope = filesys::iter_REC(directory_Path);
    else
        search_Scope = filesys::iter_DIR(directory_Path);
    std::visit([&](auto &&arg)
               {
        for (const auto &entry : arg)
        {
            if (entry.path().extension() == file_Extension)
            {
                std::ifstream file(entry.path());
                std::string line;
                while (getline(file, line))
                {
                    total_Lines += 1;
                }
            }
        } },
               search_Scope);
    if (total_Lines == 0)
    {
        std::cerr << "ERROR: No content found in " << file_Extension << " files at " << directory_Path << " with subdirectories. " << std::endl;
        return _NO_CONTENT_; // RETURN CODE 4
        system("pause");
    }

    if (total_Lines < 0)
    {
        std::cerr << "ERROR: LINES QUANTITY OVERFLOW! " << std::endl;
        return _QUANTITY_OVERFLOW_; // RETURN CODE 3
        system("pause");
    }

    std::cout << "Total lines: " << total_Lines << std::endl;
    system("pause");
}

// TODO:
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
// Add log function.
// RE-Define program behavior, make log tool easily get the information of [TIME&DATE], [BEHAVIOR], [ERROR CODE], [ERROR MESSAGE], [ERROR LINE], [ERROR FILE], [ERROR FUNCTION], [ERROR TYPE], [ERROR DESCRIPTION], [ERROR SOLUTION], [ERROR LOG], etc.
// Multithreading & asynchronous optimization.