#include "hash_table.h"

int main(void) {
  HashTable<string, int, float> *myHashTable = new HashTable<string, int, float>(10);
  cout << "HASH TABLE SIZE IS: " << myHashTable->get_size() << endl;
  myHashTable->insert("cloth", 100);
  myHashTable->insert("cloth", 200);
  myHashTable->insert("cloth", 300);
  myHashTable->insert("cloth", 400);
  cout << myHashTable->hash("cloth") << endl;
  myHashTable->insert("cloths", 200);
  myHashTable->insert("aloth", 300);
  myHashTable->insert("bloth", 600);
  myHashTable->insert("xloth", 500);
  myHashTable->insert("rloth", 600);
  myHashTable->insert("tloth", 220);
  cout << "\n" << endl;
  cout << myHashTable->hash("cloth") << endl;

  myHashTable->insert("yloth", 330);
  myHashTable->insert("uloth", 440);
  myHashTable->insert("troth", 225);
  myHashTable->insert("yqoth", 335);
  myHashTable->insert("ufoth", 445);
  myHashTable->insert("ufarh", 745);
  LinkedList<string, int, float> *myStorage = myHashTable->get_bucket(myHashTable->hash("cloth"));
  cout << "HASH TABLE ITEM ENTERED KEY SHOULD BE: " << myStorage->get_head()->data.key << endl;
  cout << "HASH TABLE ITEM ENTERED VALUE SHOULD BE: " << myStorage->get_head()->data.value << endl;

  cout << myHashTable->hash("cloth") << endl;

  try {
    auto removedData = myHashTable->remove("cloth")->data;
    cout << "REMOVED KEY IS: " << removedData.key << endl;
    cout << "REMOVED VAL IS: " << removedData.value << endl;
  } catch (const runtime_error& error) {
    cout << error.what() << endl;
  }

  auto cloth_found = myHashTable->contains("cloth");
  try {
    cout << "HT CONTAINS `cloth`?: " << cloth_found << endl;
  } catch (const runtime_error& error) {
    throw error;
  }

  auto yloth_found = myHashTable->contains("yloth");

  try {
    cout << "HT CONTAINS `yloth`?: " << yloth_found << endl;
  } catch (const runtime_error& error) {
    cout << error.what() << endl;
  }
  myHashTable->~HashTable();
  myHashTable = NULL;
  return 0;
}
