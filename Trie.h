#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include <map>
/*
 * A4: Refactoring and Testing
 * CS 3505
 * David Clark (u1225394), Zachary Atherton (u1023217)
 * 
 * 
 * This class uses a Trie data structure to encode a set of words.
 * 
 * Each node in the trie implicitly represents a string
 * derived from the sequence of branches leading to the node.
 * 
 * Relatedly, each branch in the Trie represents a letter appended to the node's string,
 * so the children of a given node will be a continuation of the string.
 * 
 * A node may or may not represent a complete word.
 * 
 * Each Trie can be thought of as a header node to some sub-trie,
 * or as a child of some larger Trie.
 */
class Trie
{
public:
    void addAWord(std::string word);
    bool isAWord(std::string word);
    std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);

private:
    std::map<char, Trie> childNodes;
    bool nodeIsAWord = false;

    bool tryGetNodeAtEndOfPrefix(std::string prefix, Trie &endNode);
    void populateAllChildWords(std::string stringSoFar, std::vector<std::string> &wordsFoundSoFar);
};
#endif