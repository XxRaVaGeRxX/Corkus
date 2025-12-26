#include <iostream>
#include <string>

#include "../headers/quickmenu.h"
#include "../headers/config.h"
#include "../headers/main.h"

using std::cout;






bool userInput(const std::string& question) {

    std::string input;

    cout << question << " (y/n): ";
    getline(std::cin, input);

    if (!input.empty()) {
        input[0] = static_cast<char>(tolower(static_cast<unsigned char>(input[0])));
    }

    return input == "y" || input == "yes" || input == "Y" || input == "Yes" || input == "YES";
}

void SkipMenu() {

    if (userInput("</>Do you already have your user.config?</>")) {

        const Config config = loadConfig();
        const ModInfo mod = getInfoFromConfig(config);

        writeFile(config.output_filename, mod);

        cout << "</>Corkus has finished processing. EXITING...</>\n" << std::endl;
        exit(0);
    }

    cout << "\n\n</>Starting CLI setup process...</>\n" << std::endl;
    makeCustomConfig();
}

void makeCustomConfig() {

    if (userInput("</>Do you want to generate a user config file (y) OR continue with guided setup(n)?</>")) {

        genCustom();

        cout << "\n</> ### CONFIGURATION FILE GENERATED ### </>\n" << std::endl;

        cout << "</>Corkus has finished. EXITING...</>\n" << std::endl;

        exit(0);
    }

    else cout << "\n</>Skipping Custom Config Generation</>\n" << std::endl;
    cout << "\n</>Continuing with guided setup...</>\n" << std::endl;

}
