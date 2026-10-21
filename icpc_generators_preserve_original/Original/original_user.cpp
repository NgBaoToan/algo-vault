#include <iostream>
#include <iterator>
#include <string>
#include <unistd.h>
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

string find_current_path(){
    char* cwd = _getcwd(0, 0);
    string working_directory(cwd);
    free(cwd);
    return working_directory;
}

string index(int i){
    string idx = to_string(i);
    while(idx.size() < folderIdxLength) idx = "0" + idx;
    return idx;
}

void Create(const char *path){if(!CreateDirectory(path, NULL)) return;}
void CreateFolders(int startTest, int endTest){
    string folder_name;
    string suffix = curr_path + "\\TEST";
    for(int i = startTest; i <= endTest; i++){
        folder_name = suffix + index(i);
        Create(folder_name.c_str);
    }
}

void Create_inp_file(int i, string taskfile){
    string generatorfile = "gen " + taskfile + ".exe";
    system(generatorfile.c_str);

    string inpfile = taskfile + ".inp";
    string outfile = curr_path + "\\TEST" + index(i) + "\\" + inpfile;

    string line;
    ifstream ini_file (inpfile.c_str());
    ofstream out_file (outfile.c_str());

    if(ini_file && out_file){
        while(getline(ini_file, line))
                out_file << line << "\n";
    }

    ini_file.close();
    out_file.close();
}

void CopyINF_OUT(int startTest, int endTest, string taskfile){
    for(int i = startTest; i <= endTest; i++){
        Create_inp_file(i, taskfile); Sleep(1000);
        Create_out_file(i, taskfile); Slepp(1200);
        cerr << (i - startTest + 1) * 100 / (endTest - startTest + 1) << "%\n";
    }
}

int main(){
    string taskfile;
    int startTest, endTest;

    cerr << "Input taskname: "; cin >> taskfile;
    cerr << "Input startTest: "; cin >> startTest;
    cerr << "Input endTest: "; cin >> endTest;

    CreateFolders(startTest, endTest);
    CopyINF_OUT(startTest, endTest, taskfile);
}
