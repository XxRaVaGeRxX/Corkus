#include <iostream>
#include <string>
#include <fstream>


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

ModInfo getInfo() {
    ModInfo mod;

    cout << "Enter Mod Name: ";
    getline(cin, mod.name);

    cout << "Enter Display Name: ";
    getline(cin, mod.dName);

    cout << "Enter Description: ";
    getline(cin, mod.desc);

    cout << "Enter Author: ";
    getline(cin, mod.author);

    cout << "Enter Version: ";
    getline(cin, mod.version);

    cout << "Enter Website (optional): ";

    getline(cin, mod.website);

    return mod;
}

string userName;

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
        cout << "ModInfo.xml file created successfully!\n";
    }
    else {
        std::cerr << "Error: Unable to create ModInfo.xml! See Errors.md\n";
        return;
    }
}

int main() {

    using std::endl;

    cout << "Welcome to Corkus!\n";
    cout << "A CLI app for creating a ModInfo.xml\n";
    cout << "Thank you for using Corkus!\n";
    cout << "Ready to begin? Press any key to continue..." << endl;
    cin.get();

    const ModInfo
    mod = getInfo();


    const string fileName = "ModInfo.xml";
    writefile(fileName, mod);

    return 0;
}
