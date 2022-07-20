#include <iostream>
#include <string>
using namespace std;

void buildHashTable(ifstream& inFile, HashType<string>& hashTable, int type){
  string word;
    if (inFile.is_open()){
    while(inFile >> word){
      // This for loop was taken from:
      // https://www.geeksforgeeks.org/removing-punctuations-given-string/
      for (int i = 0, len = word.size(); i < len; i++)
      {
        // check whether parsing character is punctuation or not
        if (ispunct(word[i]))
      {
        word.erase(i--, 1);
        len = word.size();
      }
      }
      if(type == 1)
        hashTable.InsertItemLinear(word);
      else
        hashTable.InsertItemQuadratic(word);
    }
  }
}

int main ()
{
  // polynomial hash algorithm:
  string s ("Test string");
  int hash(0), a(33);
  int n = s.length();
  for (int i = 0; i < n; i ++){
	  hash = a * hash + s.at(i);
	  cout<<hash<<' ';
  };

  return 0;
}
