#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

#include "../Code/headers/config.h"
#include "../Code/headers/quickmenu.h"

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

    cout << " </> Enter Mod Name </>  ";
    getline(cin, mod.name);
    if (mod.name.empty()) {
        mod.name = config.dName;
    }

    cout << "\n </> Enter Display Name </>  ";
    getline(cin, mod.dName);
    if (mod.dName.empty()) {
        mod.dName = config.dDisName;
    }

    cout << "\n </> Enter Description </>  ";
    getline(cin, mod.desc);
    if (mod.desc.empty()) {
        mod.desc = config.dDesc;
    }

    cout << "\n </> Enter Author </>  ";
    getline(cin, mod.author);
    if (mod.author.empty()) {
        mod.author = config.dAuthor;
    }

    cout << "\n </> Enter Version </>  ";
    getline(cin, mod.version);
    if (mod.version.empty()) {
        mod.version = config.dVersion;
    }

    cout << "\n </> Enter Website </>  ";
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
        if (std::filesystem::exists("user.config")) {
            cout << "\n </> FILENAME </> {(user.config)} >>> ModInfo.xml </> \n";
            cout << " </> PATH </> " << std::filesystem::absolute(fileName) << " </> " << std::endl;
            cout << " </> Created Successfully, Corkus will now exit </> \n";
        }
        else if (std::filesystem::exists("corkus.config")) {
            cout << "\n </> FILENAME </> {(corkus.config)} >>> ModInfo.xml </> \n";
            cout << " </> PATH </> " << std::filesystem::absolute(fileName) << " </> " << std::endl;
            cout << " </> Created Successfully, Corkus will now exit </> \n";
        }
        else {
            std::cerr << " </> | </> Error: Unable to create ModInfo.xml! See Errors in Corkus wiki </> | </> \n";
            return;
        }
    }
}

void initMsg() {    // Start Msg
    using std::this_thread::sleep_for;
    using std::chrono::milliseconds;

    cout << "\n";


cout << R"(     ██████╗ ██████╗ ██████╗ ██╗  ██╗██╗   ██╗███████╗
    ██╔════╝██╔═══██╗██╔══██╗██║ ██╔╝██║   ██║██╔════╝
    ██║     ██║   ██║██████╔╝█████╔╝ ██║   ██║███████╗
    ██║     ██║   ██║██╔══██╗██╔═██╗ ██║   ██║╚════██║
    ╚██████╗╚██████╔╝██║  ██║██║  ██╗╚██████╔╝███████║
    ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝ )"<< std::endl;
    cout << "\n </> Corkus </> Pop The Cork On Your Mods!! </> ";
    cout << "\n </> Made By: </> RavagerStudio </> ©2026 GPL-3.0 </> \n";
    sleep_for(3s);

    cout << "\n </>  </> Everything Looks Good! </>  </> \n";
    cout << " </> Welcome to Corkus 1.2.2! </> \n";
    cout << " </> A CLI app for creating a ModInfo.xml </> \n";
    cout << " </> For more information visit the GitHub page </> \n";
    cout << " </> https://github.com/XxRaVaGeRxX/Corkus </> \n";
    cout << " </> Pausing for Link visibility </> \n";
    sleep_for(6s);
    cout << " </> Thank you for using the app! </> \n";
    cout << " </> ### TURN OFF SLOW INTRO IN USER.CONFIG ### </> ";
    cout << "\n </> Corkus Is Ready </> \n\n";

}


int main() {
    const Config config = loadConfig();
    if (config.show_welcome_message) {
        initMsg();
    } else {
        cout << "\n </> Welcome Skipped  </> \n"
                "\n";
    }
    SkipMenu();

    const ModInfo mod = getInfo(config);

    const string fileName = config.output_filename;
    writeFile(fileName, mod);

    return 0;
}
