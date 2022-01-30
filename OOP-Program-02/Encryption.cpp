    #include "Encryption.h"
    #include <iostream>
    #include <string>
    
    
    //Function: Encryption
    //purpose: Constructor
     Encryption::Encryption(){
     }

    //Function: ~Encryption
    //purpose: Destructor
     Encryption::~Encryption(){

     }

    //Function: encrypt
    //input: text to be encode
    //ouput: encoded text/cipher
    //purpose: this takes a in a plain text string and encodes it using the key
    //at which point it return the cipher
    std::string  Encryption::encrypt(std::string plainText){
      int stringLength = plainText.size();
      std::string cipherText = "";
      char charHolder;
      for (int i = 0; i < stringLength; i++){
        charHolder = plainText[i] + key;
          cipherText.append(std::string(1,charHolder));
      }
      return cipherText;

    }

    //Function: decrypt
    //input: cipher to be decoded
    //ouput: returns the plain text decoded cipher
    //purpose: passes in a cipher and decodes it using the key it then returns
    //the plain text of the decoded cipher
    std::string  Encryption::decrypt(std::string cipherText){
    int stringLength = cipherText.size();
      std::string plainText = "";
      char charHolder;
      for (int i = 0; i < stringLength; i++){
        charHolder = cipherText[i] - key;
          plainText.append(std::string(1,charHolder));
      }
      return plainText;
    }

    //Function: getKey
    //ouput: the key
    //purpose: is a getter function for they key
    int  Encryption::getKey(){return key;}

    //Function: setKey
    //input: key to set to
    //purpose: setter function for the key
    void  Encryption::setKey(int keyin){key = keyin;}