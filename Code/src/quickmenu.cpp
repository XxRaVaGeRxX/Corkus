#include <iostream>
#include <string>
#include <filesystem>

#include "../Code/headers/quickmenu.h"
#include "../Code/headers/config.h"
#include "../Code/headers/main.h"

using std::cout;






bool userInput(const std::string& question) {

    std::string input;

    cout << question << " (y/n): ";
    getline(std::cin, input);

    if (!input.empty()) {
        input[0] = static_cast<char>(tolower(static_cast<unsigned char>(input[0])));
    }

    return input == "y" || input == "yy" || input == "yes" || input == "Y" || input == "Yes" || input == "YES";
}

void SkipMenu() {

    if (userInput(" </> Do you already have your user.config prepared? </>")) {

        const Config config = loadConfig();
        const ModInfo mod = getInfoFromConfig(config);

        writeFile(config.output_filename, mod);

        cout << "\n </> Corkus has finished processing. EXITING... </>" << std::endl;
        exit(0);
    }

    cout << " DevNote: There is a basic overwrite protection for user.config </> \n\n";
    makeCustomConfig();
}

void makeCustomConfig() {
    if (userInput(" </> Do you want to generate a user.config(y)? OR continue with guided setup(n)? </>")) {

        if (genCustom()) {
            cout << "\n </>  ### CONFIGURATION FILE GENERATED ###  </> \n" << std::endl;
            cout << "\n </> EXITING... </> \n" << std::endl;
            exit(0);
        }

    }
    else {
          cout << "\n </> Continuing... </> \n" << std::endl;
          cout << "\n </> Skipping Config Generation </> \n" << std::endl;
          return;
    }

    const Config config = loadConfig();
    const ModInfo mod = getInfoFromConfig(config);
    const string fileName = config.output_filename;
    writeFile(fileName, mod);

    exit(0);
}
