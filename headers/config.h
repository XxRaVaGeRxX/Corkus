#ifndef CORKUS_CONFIG_H
#define CORKUS_CONFIG_H

#include <string>

using namespace std;

struct Config {

    string dAuthor = "Unknown";
    string dVersion = "1.0.0";
    string dWebsite = "https://your-website.com";
    string dDesc = "My cool mod project.";
    string dDisName = "Cool Mod Name";
    string dName = "MyCoolMod";
    string output_filename = "ModInfo.xml";
    bool show_welcome_message = true;
    bool pause_after_completion = true;
    bool auto_generate_config = true;

};

Config loadConfig();

void genDefault();

void showLoad();

const Config& getConfig();

#endif
