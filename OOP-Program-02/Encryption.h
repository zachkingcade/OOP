#include <string>

class Encryption
{
    //private
    int key; //key used to encode text

public:
    //Function: Encryption
    //purpose: Constructor
    Encryption();

    //Function: ~Encryption
    //purpose: Destructor
    ~Encryption();

    //Function: encrypt
    //input: text to be encode
    //ouput: encoded text/cipher
    //purpose: this takes a in a plain text string and encodes it using the key
    //at which point it return the cipher
    std::string encrypt(std::string);

    //Function: decrypt
    //input: cipher to be decoded
    //ouput: returns the plain text decoded cipher
    //purpose: passes in a cipher and decodes it using the key it then returns
    //the plain text of the decoded cipher
    std::string decrypt(std::string);

    //Function: getKey
    //ouput: the key
    //purpose: is a getter function for they key
    int getKey();

    //Function: setKey
    //input: key to set to
    //purpose: setter function for the key
    void setKey(int);
};