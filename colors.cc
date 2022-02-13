#include<cstdio>
#include<unistd.h>
#include<iostream>
#include<sstream>
using namespace std;

enum class ansi_color_code: int {
    RESET           =   0,
    BLACK           =   30,
    RED             =   31,
    GREEN           =   32,
    YELLOW          =   33,
    BLUE            =   34,
    MAGENTA         =   35,
    CYAN            =   36,
    WHITE           =   37,
    BG_BLACK        =   40,
    BG_RED          =   41,
    BG_GREEN        =   42,
    BG_YELLOW       =   43,
    BG_BLUE         =   44,
    BG_MAGENTA      =   45,
    BG_CYAN         =   46,
    BG_WHITE        =   47
};



string getCode(ansi_color_code color) {
    stringstream code;
    code << "\x1B[" << static_cast<int>(color) << "m";
    return code.str();
}

int main(int argc, char **argv) {
    int c;

    while((c = getopt(argc, argv, "h:l")) != -1) {
        if(c == 'h') { 
            printf("Calling for help..\n");
        }else {
            cout << getCode(ansi_color_code::YELLOW)                 
                 << "[+] Starting in listen mode on port 8080" 
                 << getCode(ansi_color_code::RESET)
                 << endl;
            cout << "Is it still red ??" << endl;
        }
    }
    return 0;
}