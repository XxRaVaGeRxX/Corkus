#include <iostream>
#include <string>
#include <fstream>

#include "config.h"

using std::string;
using std::cin;
using std::cout;
using std::getline;


struct ModInfo {
    string name;
    string dName;
    string desc;
    string author;
    string version;
    string website;
};

ModInfo getInfo(const Config& config) {
    ModInfo mod;

    cout << "Enter Mod Name: ";
    getline(cin, mod.name);
    if (mod.name.empty()) {
        mod.name = config.default_name;
    }

    cout << "\nEnter Display Name: ";
    getline(cin, mod.dName);
    if (mod.dName.empty()) {
        mod.dName = config.default_dname;
    }

    cout << "\nEnter Description: ";
    getline(cin, mod.desc);
    if (mod.desc.empty()) {
        mod.desc = config.default_desc;
    }

    cout << "\nEnter Author: ";
    getline(cin, mod.author);
    if (mod.author.empty()) {
        mod.author = config.default_author;
    }

    cout << "\nEnter Version: ";
    getline(cin, mod.version);
    if (mod.version.empty()) {
        mod.version = config.default_version;
    }

    cout << "\nEnter Website: ";
    getline(cin, mod.website);
    if (mod.website.empty()) {
        mod.website = config.default_website;
    }

    return mod;
}

void writefile(const string& fileName, const ModInfo& mod) {

    if (std::ofstream xmlFile(fileName); xmlFile.is_open()) {
        xmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        xmlFile << "<ModInfo>\n";
        xmlFile << "    <Name value=\"" << mod.name << "\" />\n";
        xmlFile << "    <DisplayName value=\"" << mod.dName << "\" />\n";
        xmlFile << "    <Description value=\"" << mod.desc << "\" />\n";
        xmlFile << "    <Author value=\"" << mod.author << "\" />\n";
        xmlFile << "    <Version value=\"" << mod.version << "\" />\n";
        xmlFile << "    <Website value=\"" << mod.website << "\" />\n";
        xmlFile << "</ModInfo>\n";

        xmlFile.close();
        cout << "\nModInfo.xml file created successfully!\n";
    }
    else {
        std::cerr << "Error: Unable to create ModInfo.xml! See Errors.md\n";
        return;
    }
};

void initMsg() {    // Start Msg

    cout << "Welcome to Corkus!\n";
    cout << "A CLI app for creating a ModInfo.xml\n";
    cout << "Thank you for using the app!\n";
    cout << "Ready to begin? Press any key to continue..." << std::endl;
    cin.get();

};


int main() {
    const Config config = loadConfig();
    
    if (config.show_welcome_message) {
        initMsg();
    } else {
        cout << "Skipping welcome message.\n";
    }

    const ModInfo mod = getInfo(config);

    const string fileName = config.output_filename;
    writefile(fileName, mod);

    return 0;
}
