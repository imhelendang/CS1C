#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main() {
    
    char key;
    int result;
    int count = 0;

    cin >> key;
    while(key != 'q') {
        switch(key) {
            case '0':
                // store 
                cout << key;
                count++;
                break;

            case '1':
                // store
                cout << key;
                count++;
                break;

            case 'c':
                system("clear");
                break;

            case 'E':
                // Call processing buffer
                cout << "->" << result;
                break;

            default:
                // ignore
                break;
        }
        cin >> key;
    }
    

    return 0;
}