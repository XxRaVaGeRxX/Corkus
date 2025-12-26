#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>

#include "../headers/config.h"
#include "../headers/quickmenu.h"

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

ModInfo getInfoFromConfig(const Config& config) {
    ModInfo mod;
    mod.name = config.dName;
    mod.dName = config.dDisName;
    mod.desc = config.dDesc;
    mod.author = config.dAuthor;
    mod.version = config.dVersion;
    mod.website = config.dWebsite;

    return mod;

}

ModInfo getInfo(const Config& config) {
    ModInfo mod;

    cout << "</>Enter Mod Name</> ";
    getline(cin, mod.name);
    if (mod.name.empty()) {
        mod.name = config.dName;
    }

    cout << "\n</>Enter Display Name</> ";
    getline(cin, mod.dName);
    if (mod.dName.empty()) {
        mod.dName = config.dDisName;
    }

    cout << "\n</>Enter Description</> ";
    getline(cin, mod.desc);
    if (mod.desc.empty()) {
        mod.desc = config.dDesc;
    }

    cout << "\n</>Enter Author</> ";
    getline(cin, mod.author);
    if (mod.author.empty()) {
        mod.author = config.dAuthor;
    }

    cout << "\n</>Enter Version</> ";
    getline(cin, mod.version);
    if (mod.version.empty()) {
        mod.version = config.dVersion;
    }

    cout << "\n</>Enter Website</> ";
    getline(cin, mod.website);
    if (mod.website.empty()) {
        mod.website = config.dWebsite;
    }

    return mod;
}

void writeFile(const string& fileName, const ModInfo& mod) {

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
        cout << "Location: " << std::filesystem::absolute(fileName) << std::endl;
    }
    else {
        std::cerr << "</>|</>Error: Unable to create ModInfo.xml! See Errors in Corkus wiki</>|</>\n";
        return;
    }
};

void initMsg() {    // Start Msg
    cout << "\n";


cout << R"(     ██████╗ ██████╗ ██████╗ ██╗  ██╗██╗   ██╗███████╗
    ██╔════╝██╔═══██╗██╔══██╗██║ ██╔╝██║   ██║██╔════╝
    ██║     ██║   ██║██████╔╝█████╔╝ ██║   ██║███████╗
    ██║     ██║   ██║██╔══██╗██╔═██╗ ██║   ██║╚════██║
    ╚██████╗╚██████╔╝██║  ██║██║  ██╗╚██████╔╝███████║
    ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝ )"<< std::endl;
    this_thread::sleep_for(1200ms);



    cout << "\n</></>Everything Looks Good!</></>\n";
    cout << "\n</>Welcome to Corkus 1.2.1!</>\n\n";
    cout << "</>A CLI app for creating a ModInfo.xml</>\n\n";
    cout << "</>Thank you for using the app!</>\n\n";
    cout << "</>\nCorkus Is Ready</>\n" << std::endl;

}


int main() {
    const Config config = loadConfig();
    if (config.show_welcome_message) {
        initMsg();
    } else {
        cout << "</>Skipping Welcome Message</>"
                "\n";
    }
    SkipMenu();

    const ModInfo mod = getInfo(config);

    const string fileName = config.output_filename;
    writeFile(fileName, mod);

    return 0;
}
