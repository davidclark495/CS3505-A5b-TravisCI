/*
 * A4: Refactoring and Testing
 * CS 3505
 * David Clark (u1225394), Zachary Atherton (u1023217)
 * 
 * 
 */
#include "gtest/gtest.h"
#include "Trie.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
TEST(IsAWordTest, EmptyTrie)
{
    Trie t;
    ASSERT_FALSE(t.isAWord("hello"));
    ASSERT_FALSE(t.isAWord(""));
}
TEST(IsAWordTest, SimpleTrie)
{
    Trie t;
    t.addAWord("hello");
    ASSERT_TRUE(t.isAWord("hello"));
}
TEST(IsAWordTest, SimilarWords)
{
    Trie t;
    t.addAWord("hello");
    ASSERT_FALSE(t.isAWord("helle"));
}

TEST(PrefixTest, SimpleTrie1)
{
    Trie t;
    t.addAWord("a");
    t.addAWord("app");
    t.addAWord("apple");
    t.addAWord("ask");
    t.addAWord("at");
    t.addAWord("do");
    t.addAWord("dog");

    vector<string> expectedResult = {"a", "app", "apple", "ask", "at"};
    vector<string> actualResult = t.allWordsStartingWithPrefix("a");

    sort(expectedResult.begin(), expectedResult.end());
    sort(actualResult.begin(), actualResult.end());

    ASSERT_EQ(expectedResult, actualResult);
}

TEST(PrefixTest, SimpleTrie2)
{
    Trie t;
    t.addAWord("a");
    t.addAWord("app");
    t.addAWord("apple");
    t.addAWord("ask");
    t.addAWord("at");
    t.addAWord("do");
    t.addAWord("dog");

    vector<string> expectedResult = {"app", "apple"};
    vector<string> actualResult = t.allWordsStartingWithPrefix("ap");

    sort(expectedResult.begin(), expectedResult.end());
    sort(actualResult.begin(), actualResult.end());

    ASSERT_EQ(expectedResult, actualResult);
}

TEST(PrefixTest, AllWords)
{
    Trie t;
    t.addAWord("a");
    t.addAWord("app");
    t.addAWord("apple");
    t.addAWord("ask");
    t.addAWord("at");
    t.addAWord("do");
    t.addAWord("dog");

    vector<string> expectedResult = {"a", "app", "apple", "ask", "at", "do", "dog"};
    vector<string> actualResult = t.allWordsStartingWithPrefix("");

    sort(expectedResult.begin(), expectedResult.end());
    sort(actualResult.begin(), actualResult.end());

    ASSERT_EQ(expectedResult, actualResult);
}

TEST(PrefixTest, NoWords)
{
    Trie t;
    t.addAWord("a");
    t.addAWord("app");
    t.addAWord("apple");
    t.addAWord("ask");
    t.addAWord("at");
    t.addAWord("do");
    t.addAWord("dog");

    vector<string> expectedResult = {};
    vector<string> actualResult = t.allWordsStartingWithPrefix("ball");

    sort(expectedResult.begin(), expectedResult.end());
    sort(actualResult.begin(), actualResult.end());

    ASSERT_EQ(expectedResult, actualResult);
}

TEST(CopyConstructorTest, SeparateCopy_SameData)
{

    Trie t1;
    t1.addAWord("apple");

    Trie t2(t1);

    ASSERT_TRUE(t2.isAWord("apple"));
    ASSERT_NE(&t2, &t1);
}
TEST(CopyConstructorTest, ChangeData)
{
    Trie t1;
    t1.addAWord("app");

    Trie t2(t1);
    t1.addAWord("apple");
    t2.addAWord("dog");

    ASSERT_FALSE(t1.isAWord("dog"));
    ASSERT_FALSE(t2.isAWord("apple"));
}
TEST(AssigmentOperatorTest, SeparateCopy_SameData)
{
    Trie t1;
    t1.addAWord("apple");

    Trie t2;
    t2 = t1;

    ASSERT_TRUE(t2.isAWord("apple"));
    ASSERT_NE(&t2, &t1);
}
TEST(AssigmentOperatorTest, ChangeData)
{
    Trie t1;
    t1.addAWord("app");

    Trie t2;
    t2 = t1;
    t1.addAWord("apple");
    t2.addAWord("dog");

    ASSERT_FALSE(t1.isAWord("dog"));
    ASSERT_FALSE(t2.isAWord("apple"));
}

TEST(DestructorTest, DestroyTemp)
{
    Trie orig;
    orig.addAWord("app");
    // ensure that when temp gets destroyed, orig survives
    {
        Trie temp;
        temp = orig;
    }
    ASSERT_TRUE(orig.isAWord("app"));
}
