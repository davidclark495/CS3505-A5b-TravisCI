#include <string>
#include <vector>
#include <map>
#include "Trie.h"

/*
 * A4: Refactoring and Testing
 * CS 3505
 * David Clark (u1225394), Zachary Atherton (u1023217)
 * 
 * 
 * 
 * A class description is found in Trie.h
 */

//////////////////////////
///// Public Methods /////
//////////////////////////

void Trie::addAWord(std::string word)
{
    // if we've reached the end of the word, mark the node as complete
    if (word.length() == 0)
    {
        nodeIsAWord = true;
        return;
    }
    char c = word[0];
    childNodes[c].addAWord(word.substr(1)); // continue the word in a child branch/node
}

bool Trie::isAWord(std::string word)
{
    Trie endNode;
    if (tryGetNodeAtEndOfPrefix(word, endNode))
        return endNode.nodeIsAWord;
    else
        return false;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{
    std::vector<std::string> wordsFound;

    // start from the node at the end of the prefix
    Trie startNode;
    if (tryGetNodeAtEndOfPrefix(prefix, startNode))
        startNode.populateAllChildWords(prefix, wordsFound);
    return wordsFound;
}

///////////////////////////
///// Helper Methods /////
///////////////////////////

// Traverse the Trie and return true if there is a node at the end of the prefix.
// The node at the end is copied to "endNode" (an out parameter).
// This won't modify the Trie.
//
// helper for accessor methods
bool Trie::tryGetNodeAtEndOfPrefix(std::string prefix, Trie &endNode)
{
    if (prefix.length() == 0)
    {
        endNode = *this;
        return true;
    }

    char c = prefix[0];
    if (childNodes.count(c) == 0)
        return false;

    return childNodes[c].tryGetNodeAtEndOfPrefix(prefix.substr(1), endNode);
}

// Recursively updates wordsFoundSoFar to include all words starting with a given prefix.
// Builds strings based on the branches it traverses,
// and adds strings when the corresponding node is a word.
//
// helper for allWordsStartingWithPrefix
void Trie::populateAllChildWords(std::string stringSoFar, std::vector<std::string> &wordsFoundSoFar)
{
    if (nodeIsAWord)
        wordsFoundSoFar.push_back(stringSoFar);

    // for each child node, add all child words recursively
    for (auto pair : childNodes)
    {
        Trie childNode = pair.second;
        char branchChar = pair.first;
        childNode.populateAllChildWords(stringSoFar + branchChar, wordsFoundSoFar);
    }
}
