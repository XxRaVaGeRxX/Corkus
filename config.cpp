#include <fstream>
#include <string>
#include <map>
#include <filesystem>
#include "config.h"
#include <iostream>

using std::string;

void genDefault() {
    const string configFile = "corkus.config";
    
    std::ofstream file(configFile);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to create config file!\n";
        return;
    }
    
    file << "# Corkus Config File\n";
    file << "# A Quick Guide\n";
    file << "# true or false for the boolean values\n";
    file << "# what you put here will be used as input\n";
    file << "# if you want to simply click 'Corkus' & generate\n";
    file << "# Lines starting with # are commented out\n\n";
    
    file << "# Default values for modlet creation\n";
    file << "default_name=MyCoolMod\n";
    file << "default_dname=Cool Mod Name\n";
    file << "default_desc=My Cool Mod Project\n";
    file << "default_author=YourNameHere\n";
    file << "default_version=1.0.0\n";
    file << "default_website=https://your-website.com\n\n";
    
    file << "# Output settings (leave default for 7dtd)\n";
    file << "output_filename=ModInfo.xml\n\n";
    
    file << "# Application behavior\n";
    file << "show_welcome_message=true\n";
    file << "pause_after_completion=true\n";
    file << "auto_generate_config=true (Turn Off To Maintain Custom Settings)\n";
    
    file.close();
    std::cout << "Generated default config file: corkus.config\n";
}

Config loadConfig() {
    Config config;
    const string configFile = "corkus.config";

    std::ifstream file(configFile);
    if (!file.is_open()) {
        std::cout << "Config file not found.\n";
        
        // Auto-generate if enabled by default
        if (config.auto_generate_config) {
            std::cout << "Generating default config file...\n";
            genDefault();
        } else {
            std::cout << "Using built-in defaults.\n";
        }
        
        return config;
    }

    string line;
    while (getline(file, line)) {

        if (line.empty() || line[0] == '#') continue;

        size_t pos = line.find('=');
        if (pos == string::npos) continue;

        string key = line.substr(0, pos);
        string value = line.substr(pos + 1);

        while (!key.empty() && (key.back() == ' ' || key.back() == '\t')) key.pop_back();
        while (!value.empty() && (value.front() == ' ' || value.front() == '\t')) value.erase(0, 1);

        if (key == "default_author") config.default_author = value;
        else if (key == "default_version") config.default_version = value;
        else if (key == "default_website") config.default_website = value;
        else if (key == "default_name") config.default_name = value;
        else if (key == "default_dname") config.default_dname = value;
        else if (key == "default_desc") config.default_desc = value;
        else if (key == "output_filename") config.output_filename = value;
        else if (key == "show_welcome_message") config.show_welcome_message = (value == "true");
        else if (key == "pause_after_completion") config.pause_after_completion = (value == "true");
        else if (key == "auto_generate_config") config.auto_generate_config = (value == "true");

    }

    file.close();

    return config;
}
