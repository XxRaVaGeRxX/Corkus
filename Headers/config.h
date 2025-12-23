#ifndef CORKUS_CONFIG_H
#define CORKUS_CONFIG_H

#include <string>

using namespace std;

struct Config {

    string default_author = "Unknown";
    string default_version = "1.0.0";
    string default_website = "https://your-website.com";
    string default_desc = "My cool mod project.";
    string default_dname = "Cool Mod Name";
    string default_name = "MyCoolMod";
    string output_filename = "ModInfo.xml";
    bool show_welcome_message = true;
    bool pause_after_completion = true;
    bool auto_generate_config = true;

};

Config loadConfig();

void genDefault();

const Config& getConfig();

#endif
