#include "ModAlphaCypher.h"
// проверка, чтобы строка состояла только из прописных букв

void check(const string& Text, const string& key)
{
    try {
        string cypherText;
        string decryptedText;
        modAlphaCypher cypher(key);
        cypherText = cypher.encrypt(Text);
        decryptedText = cypher.decrypt(cypherText);
        cout<<"key="<<key<<endl;
        cout<<"Encrypted text: "<<cypherText<<endl;
        cout<<"Decrypted text: "<<decryptedText<<endl;
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
    cout<<"Введите ключ: ";
    cin>>key;
    cout<<"Ключ загружен\n";
   
    cout<<"Введите текст: ";
    cin>>text;
    check(text, key);
     cout<<"Для продолжения нажмите 1, для выхода нажмите любой символ отличный от 1: ";
    cin>>operation_key;
    };
    return 0;
}