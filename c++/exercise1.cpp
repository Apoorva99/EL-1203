////////////////////////////////////////////////////////////////////////////////////////
//  ▄████▄   ▄▄▄       ▄████▄   ██░ ██ ▓█████  ███▄ ▄███▓▓█████ 
// ▒██▀ ▀█  ▒████▄    ▒██▀ ▀█  ▓██░ ██▒▓█   ▀ ▓██▒▀█▀ ██▒▓█   ▀ 
// ▒▓█    ▄ ▒██  ▀█▄  ▒▓█    ▄ ▒██▀▀██░▒███   ▓██    ▓██░▒███   
// ▒▓▓▄ ▄██▒░██▄▄▄▄██ ▒▓▓▄ ▄██▒░▓█ ░██ ▒▓█  ▄ ▒██    ▒██ ▒▓█  ▄ 
// ▒ ▓███▀ ░ ▓█   ▓██▒▒ ▓███▀ ░░▓█▒░██▓░▒████▒▒██▒   ░██▒░▒████▒
// ░ ░▒ ▒  ░ ▒▒   ▓▒█░░ ░▒ ▒  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░   ░  ░░░ ▒░ ░
//   ░  ▒     ▒   ▒▒ ░  ░  ▒    ▒ ░▒░ ░ ░ ░  ░░  ░      ░ ░ ░  ░
// ░          ░   ▒   ░         ░  ░░ ░   ░   ░      ░      ░   
// ░ ░            ░  ░░ ░       ░  ░  ░   ░  ░       ░      ░  ░
// ░                  ░                                         
//
// Create a cache class able to store 5 keys within.
// Values must be arranged from the most recently used key to least recently used key.
//
// Assume the data to cache is the following array:
//
// ["A", "B", "C", "D", "E", "F", "G", "H", "I"]
//
// Assume at a given point the internal cache state is (key-value representation):
//
// [1:"A", 4:"D", 6:"F", 2:"B", 9:"I"]
//
// In case the next call is via key "6" (cache hit) the cache should return "F" without
// accessing the data array. The cache state changes as follows:
//
// [6:"F", 1:"A", 4:"D", 2:"B", 9:"I"]
//
// In case the next call is "8" (cache miss) the cache should retrieve "H" from the data
// array, return it and change its state as follows:
//
// [8:"H", 6:"F", 1:"A", 4:"D", 2:"B"]
//
// Bonus: make the cache able to act on a underlying data array containing ANY data type
//
// Bonus 2: abstract the cache in order to accept C and std arrays and std vectors as
//          underlying data structures
// 
////////////////////////////////////////////////////////////////////////////////////////

// Implemented LRU (Least Recently Used) Cache Class Template in C++.
// using double linked list and unordered_map;
// each node in the linked list contains data members of key and value;
// hash map contains pairs of key and pointer to node;
// after accessing an existing key, move the node to the front of double linked list, update the map
// if the key not in the cache, delete the tail of double linked list, add a new node to the front, update the map

#include "double_list.hpp"
#include "LRU_Cache.hpp"
using namespace std;
#include <string>



int main() {
  cout<<"Input the state of cache";
  LRU::LRUCache<int, char> cache(5);
  char ch;
  for (int i = 1; i <= 5; ++i){
    cin >> ch;
    cache.push(i, ch);
  }
  cout<<"Cheking whether element is there or not";
  cout << cache.hasKey(4);
  
}
