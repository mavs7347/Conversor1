#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class Converter {
    private:
        int decimal = 0;
        string binary = "";
    public:
        void setDecimal(int _decimal) {
            this->decimal = _decimal;
            decimalBinary(this->decimal);
            cout << "\nDecimal to Hexadecimal" << endl;
            hexadecimal(this->decimal);
        }
        void decimalBinary(int _decimal) {
            if(_decimal==0 || _decimal==1) {
                cout << _decimal << "   ";
            }
            else {
                cout << _decimal%2 << "   ";
                decimalBinary(_decimal/2);
            }
        }
        void binaryDecimal(string binary) {
            this->binary = binary;
            int pot = 0;
            for (int c = binary.size()-1; c >= 0; c--)
            {
                if (this->binary[c] == '1') {
                    this->decimal += pow(2, pot);
                }
                pot++;
            }
            cout << "\nBinary to Decimal" << endl;
            cout << this->decimal << endl;
            cout << "\nDecimal to Hexadecimal" << endl;
            hexadecimal(this->decimal);
        }
        void hexadecimal(int _decimal) {
            if (_decimal < 10) {
                cout << _decimal;
            }
            else if (_decimal >= 10 && _decimal <= 15) {
                cout << char(_decimal+55);
            }
            else {
                hexadecimal(_decimal/16);
                if (_decimal%16 >= 10 && _decimal%16 <= 15) {
                    cout << char(_decimal%16+55);
                }
                else {
                    cout << _decimal%16;
                }
            }
        }
};
class Menu {
    private:
        char opt;
        int nDecimal;
        char nBinary[10];
    public:
        Menu() {
            opt = ' ';
            nDecimal = 0;
        }
        void run() {
            char opt;
            do {
                system("cls");
                cout << "Choose an option:" << endl;
                cout << "1.- Convert decimal" << endl;
                cout << "2.- Convert binary" << endl;
                cin >> opt;
                
                Converter translator;

                switch (opt)
                {
                    case '1':
                        cout << "Enter a decimal number:" << endl;
                        cin >> nDecimal;
                        cout << "\nDecimal to Binary" << endl;
                        cout << "1   2   4   8  16  32  64 128 256 512" << endl;
                        translator.setDecimal(nDecimal);
                        break;
                    case '2':
                        cout << "Enter a binary number:" << endl;
                        cin >> nBinary;
                        translator.binaryDecimal(nBinary);
                        break;
                    default:
                        break;
                }
                
                cout << "\n\nEnter 'p' to exit, other to restart:" << endl;
                cin >> opt;
            } while (opt != 'p');
        }
};
int main() {
    Menu menu;
    menu.run();
    return 0;
}