// HashMapTests.cpp
//
// ICS 45C Spring 2022
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided a few tests
// already, though I've commented them out, because they won't compile and
// link until you've implemented some things.
//
// Of course, you'll want to write lots more of these tests yourself, because
// this is an inexpensive way to know whether things are working the way
// you expect -- including scenarios that you won't happen to hit in the
// course of testing your overall program.  (You might also want to be sure
// that your HashMap implementation is complete and correct before you try
// to write the rest of the program around it, anyway; there's a very
// substantial amount of partial credit available if all that works is
// HashMap.)

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(HashMapTests, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}


TEST(HashMapTests, emptyMapContainsNoKeys)
{
    HashMap empty;
    ASSERT_FALSE(empty.contains("first"));
    ASSERT_FALSE(empty.contains("second"));
}

TEST(HashMapTests, emptyMapBucketCountIsTen)
{
    HashMap empty; 
    ASSERT_EQ(10, empty.bucketCount()); 
}

TEST(HashMapTests, emptyMapLoadFactorIsZero) 
{
    HashMap empty; 
    ASSERT_EQ(0, empty.loadFactor()); 
}


TEST(HashMapTests, containKeyAfterAddingIt)
{
    HashMap hm;
    hm.add("Boo", "perfect");
    ASSERT_TRUE(hm.contains("Boo"));
}

TEST(HashMapTests, sizeIncreaseByOneAfterAddingIt)
{
    HashMap hm; 
    hm.add("username", "password"); 
    ASSERT_EQ(1, hm.size()); 
}

TEST(HashMapTests, DoesNotContainAfterRemoveFirstElement)
{
    HashMap hm; 
    hm.add("username", "password"); 
    ASSERT_TRUE(hm.contains("username")); 
    ASSERT_TRUE(hm.remove("username")); 
    ASSERT_FALSE(hm.contains("username")); 
}

TEST(HashMapTests, DoesNotContainAfterRemoveRamdomElemet)
{
    HashMap hm; 
    hm.add("user1", "pass1"); 
    hm.add("user2", "pass2"); 
    hm.add("user3", "pass3"); 
    ASSERT_TRUE(hm.remove("user2")); 
    ASSERT_FALSE(hm.contains("user2")); 
    ASSERT_TRUE(hm.remove("user3")); 
    ASSERT_FALSE(hm.contains("user3")); 
}

TEST(HashMapTests, valueReturnEmptyStringWhenElementNotContains)
{
    HashMap hm; 
    hm.add("user1", "pass1"); 
    hm.add("user2", "pass2"); 
    hm.add("user3", "pass3"); 
    ASSERT_EQ("", hm.value("user4")); 
}

TEST(HashMapTests, valueReturnEmptyStringWhenElementIsContains)
{
    HashMap hm; 
    hm.add("user1", "pass1"); 
    hm.add("user2", "pass2"); 
    hm.add("user3", "pass3"); 
    ASSERT_EQ("pass3", hm.value("user3")); 
}

TEST(HashMapTests, returnRightMaxBucketSize)
{
    HashMap hm; 
    hm.add("ab", "pass1"); 
    hm.add("ba", "pass2"); 
    hm.add("abc", "pass3"); 
    ASSERT_EQ(2, hm.maxBucketSize());
}

TEST(HashMapTests, bucketCountIncreaseIfLoadFactorLarge)
{
    HashMap hm; 
    hm.add("user1", "pass");
    hm.add("user2", "pass");
    hm.add("user3", "pass");
    hm.add("user4", "pass");
    hm.add("user5", "pass");
    hm.add("user6", "pass");
    hm.add("user7", "pass");
    hm.add("user8", "pass");
    hm.add("user9", "pass");
    ASSERT_EQ(21, hm.bucketCount()); 
}

TEST(HashMapTests, sameValueAfterCopyConstructor)
{
    HashMap hm1; 
    hm1.add("user1", "pass");
    HashMap hm2{hm1}; 
    ASSERT_EQ(hm1.contains("user1"), hm2.contains("user1"));
}

TEST(HashMapTests, sameValueAfterEqualOperator)
{
    HashMap hm1; 
    HashMap hm2; 
    hm1.add("user1", "pass"); 
    hm2 = hm1; 
    ASSERT_EQ(hm1.value("user1"), hm2.value("user1")); 
}
