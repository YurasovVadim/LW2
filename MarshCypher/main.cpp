#include "Marsh.h"

void check(const string& Text, const string& key)
{
    try {
        string cypherText;
        string decryptedText;
        if (key.empty())
            throw cypher_error("Empty key");
        if (stoi(key) > 0) {
            modMarshCypher cypher(stoi(key));
            cypherText = cypher.encrypt(Text);
            decryptedText = cypher.decrypt(cypherText);
            cout<<"key="<<key<<endl;
            cout<<"Encrypted text: "<<cypherText<<endl;
            cout<<"Decrypted text: "<<decryptedText<<endl;
        } else
            throw cypher_error(std::string("Invalid key ")+key);
    } catch (const cypher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
    cout<<""<<endl;
}


int main()
{
    
    string key;
    string text;
    unsigned operation_key=1;
    while (operation_key==1)
{
    cout<<"Введенный ключ: ";
    cin>>key;
        cout<<"Ключ загружен\n";
       cout<<"Введенный текст: ";
            cin>>text;
            check(text, key);
        cout<<"Для запуска программы заново введите 1, для остановки ввдеите значение, отличное от 1: ";
    cin>>operation_key;
    }
    return 0;
}