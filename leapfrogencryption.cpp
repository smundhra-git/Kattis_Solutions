#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Count_Dashes(const string& s, int start, int length, int dir){
  int count = 0;
  int pos = start;
  while(count < length && pos >=0 && pos<s.size()){
    if(s[pos] == '-'){
      count++;
    }
    if(count < length)
      pos=pos+dir;
  }
  return pos;
}


int Count_Non_Dashes(const string& s, int start, int length, int dir){
  int count = 0;
  int pos = start;
  while(count < length && pos >=0 && pos<s.size()){
    if(s[pos] != '-'){
      count++;
    }
    if(count < length)
      pos=pos+dir;
  }
  return pos;
}
string Decrypt(const string& s, const string& key){
  string ciphertext = s;
 

  // step 2 convert the letters of the key to digits
  vector<int> key_digits(key.size());
  for(int i = 0; i < key.size(); i++){
    key_digits[i] = key[i]-'a'+2;
  }
  
  // set up ciphertext to be the same length as plaintext
  string plaintext;
  
  int e_pos = 0;
  int orig_pos = 0;
  int key_pos = 0;
  bool done = false;
  int dir = 1;
  int dashes_filled = 0;
  while(key_pos < key.size()){
    //   cout << "Plaintext, key_pos = " << key_pos << ": " << plaintext << endl;
    e_pos = Count_Non_Dashes(ciphertext, e_pos, key_digits[key_pos], dir);
    if(e_pos >=0 && e_pos < ciphertext.size()){
      plaintext = plaintext + ciphertext[e_pos];
      ciphertext[e_pos] = '-';
      orig_pos++;
    }
    else{
      // next key digit
      key_pos++;
      if(dir == 1){
	e_pos = ciphertext.size()-1;
	dir = -1;
      }
      else{
	dir = 1;
	e_pos = 0;
      }
    }
  }
  // when we are done with key positions, copy the rest of the plaintext
  while(e_pos >=0 && e_pos < ciphertext.size()){
    if(ciphertext[e_pos] != '-'){
      plaintext = plaintext+ ciphertext[e_pos];
    
    }
      e_pos = e_pos + dir;
  }
  return plaintext;
}
string Encrypt(const string& s, const string& key){
  string stripped;
  // step 1: remove all non-alphabetic characters and lowercase-ify
  for(int i = 0; i < s.size(); i++){
    if(isalpha(s[i]))
      stripped = stripped + (char)tolower(s[i]);
  }
  //  cout << "Stripped: " << stripped << endl;
  // step 2 convert the letters of the key to digits
  vector<int> key_digits(key.size());
  for(int i = 0; i < key.size(); i++){
    key_digits[i] = key[i]-'a'+2;
  }
  // set up ciphertext to be the same length as plaintext
  string ciphertext;
  for(int i = 0; i < stripped.size(); i++){
    ciphertext = ciphertext +  '-';
  }
  int e_pos = 0;
  int orig_pos = 0;
  int key_pos = 0;
  bool done = false;
  int dir = 1;
  int dashes_filled = 0;
  while(key_pos < key.size()){
    //  cout << "Ciphertext, key_pos = " << key_pos << ": " << ciphertext << endl;
    e_pos = Count_Dashes(ciphertext, e_pos, key_digits[key_pos], dir);
    if(e_pos >=0 && e_pos < ciphertext.size()){
      ciphertext[e_pos] = stripped[orig_pos];
      orig_pos++;
    }
    else{
      // next key digit
      key_pos++;
      if(dir == 1){
	e_pos = ciphertext.size()-1;
	dir = -1;
      }
      else{
	dir = 1;
	e_pos = 0;
      }
    }
  }
  // when we are done with key positions, copy the rest of the plaintext
  while(e_pos >=0 && e_pos < ciphertext.size()){
    if(ciphertext[e_pos] == '-'){
      ciphertext[e_pos] = stripped[orig_pos];
      orig_pos++;
    }
      e_pos = e_pos + dir;
  }
  return ciphertext;
}
   
int main(){
  char job;
  string key;
  cin >> job;
  cin >> key;
  cin.get();

  string code;
  getline(cin, code);
  if(job == 'E')
    cout << Encrypt(code, key);
  else
    cout << Decrypt(code, key);
  return 0;
}