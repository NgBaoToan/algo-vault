#include <iostream>
#include <iterator>
#include <string>
#include <unistd.h>
#define taskname "FINDK1"
#define gentestnaem "gen_FINDK1"
#include <bits/stdc++.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <dirent.h>

using namespace std;
namespace fs = std::filesystem;

const int Left = 1;
const int Right = 1;
const int Total = Right - Left + 1;
const int folderIdxLength = 3;

// true: gen_FINDK1 da dung freopen("FINDK1.inp", "w", stdout).
// false: generator dung cout, can chuyen huong stdout sang file .inp.
const bool GENERATOR_USES_FILE_IO = true;

string find_current_path(){
    return fs::current_path().string();
}

string curr_path = find_current_path();

string index(int i){
    string idx = to_string(i);
    while(idx.size() < folderIdxLength) idx = "0" + idx;
    return idx;
}

void Create(const char *path){ fs::create_directories(path); }
void CreateFolders(int startTest, int endTest){
    string folder_name;
    string suffix = curr_path + "/TEST";
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
    fs::remove(inpfile); // Khong de file cu che giau loi generator.

    string generatorfile = "./gen_" + taskfile;
    string command = generatorfile;
    if(!GENERATOR_USES_FILE_IO) command += " > " + inpfile;
    if(system(command.c_str()) != 0 || !fs::exists(inpfile))
        throw runtime_error("Generator failed to create " + inpfile);

    string outfile = curr_path + "/TEST" + index(i) + "/" + inpfile;
    fs::copy_file(inpfile, outfile, fs::copy_options::overwrite_existing);
}

void Create_out_file(int i, string taskfile){
    string inpfile = taskfile + ".inp";
    string outname = taskfile + ".out";
    fs::remove(outname);

    // Ho tro ca cin/cout va freopen(taskname".inp"/".out") trong solution.
    string solutionfile = "./" + taskfile;
    string command = solutionfile + " < " + inpfile + " > " + outname;
    if(system(command.c_str()) != 0 || !fs::exists(outname))
        throw runtime_error("Solution failed to create " + outname);

    string outfile = curr_path + "/TEST" + index(i) + "/" + outname;
    fs::copy_file(outname, outfile, fs::copy_options::overwrite_existing);
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
