#include <iostream>
#include <iterator>
#include <string>
#include <direct.h>
#define taskname "FINDK1"
#define gentestnaem "gen_FINDK1"
#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <dirent.h>

using namespace std;

const int Left = 1;
const int Right = 1;
const int Total = Right - Left + 1;
const int folderIdxLength = 3;

// true: gen_FINDK1 da dung freopen("FINDK1.inp", "w", stdout).
// false: generator dung cout, can chuyen huong stdout sang file .inp.
const bool GENERATOR_USES_FILE_IO = true;

string find_current_path(){
    char* cwd = _getcwd(0, 0);
    if(!cwd) throw runtime_error("Cannot get current directory");
    string working_directory(cwd);
    free(cwd);
    return working_directory;
}

string curr_path = find_current_path();

string index(int i){
    string idx = to_string(i);
    while(idx.size() < folderIdxLength) idx = "0" + idx;
    return idx;
}

void Create(const char *path){
    if(!CreateDirectoryA(path, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
        throw runtime_error(string("Cannot create folder: ") + path);
}
void CreateFolders(int startTest, int endTest){
    string folder_name;
    string suffix = curr_path + "\\TEST";
    for(int i = startTest; i <= endTest; i++){
        folder_name = suffix + index(i);
        Create(folder_name.c_str());
    }
}

bool valid_task_name(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), [](unsigned char c){
        return isalnum(c) || c == '_' || c == '-';
    });
}

void Create_inp_file(int i, string taskfile){
    string inpfile = taskfile + ".inp";
    DeleteFileA(inpfile.c_str());

    string generatorfile = "gen_" + taskfile + ".exe";
    string command = generatorfile;
    if(!GENERATOR_USES_FILE_IO) command += " > " + inpfile;
    if(system(command.c_str()) != 0 || GetFileAttributesA(inpfile.c_str()) == INVALID_FILE_ATTRIBUTES)
        throw runtime_error("Generator failed to create " + inpfile);

    string outfile = curr_path + "\\TEST" + index(i) + "\\" + inpfile;
    if(!CopyFileA(inpfile.c_str(), outfile.c_str(), FALSE))
        throw runtime_error("Cannot copy input to " + outfile);
}

void Create_out_file(int i, string taskfile){
    string inpfile = taskfile + ".inp";
    string outname = taskfile + ".out";
    DeleteFileA(outname.c_str());

    // Ho tro ca cin/cout va freopen(taskname".inp"/".out") trong solution.
    string command = taskfile + ".exe < " + inpfile + " > " + outname;
    if(system(command.c_str()) != 0 || GetFileAttributesA(outname.c_str()) == INVALID_FILE_ATTRIBUTES)
        throw runtime_error("Solution failed to create " + outname);

    string outfile = curr_path + "\\TEST" + index(i) + "\\" + outname;
    if(!CopyFileA(outname.c_str(), outfile.c_str(), FALSE))
        throw runtime_error("Cannot copy output to " + outfile);
}

void CopyINF_OUT(int startTest, int endTest, string taskfile){
    for(int i = startTest; i <= endTest; i++){
        Create_inp_file(i, taskfile);
        Create_out_file(i, taskfile);
        cerr << (i - startTest + 1) * 100 / (endTest - startTest + 1) << "%\n";
    }
}

int main(){
    string taskfile;
    int startTest, endTest;

    cerr << "Input taskname: "; cin >> taskfile;
    cerr << "Input startTest: "; cin >> startTest;
    cerr << "Input endTest: "; cin >> endTest;

    if(!valid_task_name(taskfile) || startTest < 1 || endTest < startTest){
        cerr << "Invalid task name or test range!\n";
        return 1;
    }
    try {
        CreateFolders(startTest, endTest);
        CopyINF_OUT(startTest, endTest, taskfile);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}
