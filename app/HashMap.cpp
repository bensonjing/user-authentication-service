#include <string> 
#include "HashMap.hpp" 

namespace
{
    unsigned int defaultHashFunc(const std::string& s)
    {
        int sum = 0; 
        for (int i = 0; i < s.length(); i++)
        {
            sum += int(s[i]); 
        }
        
        return sum; 
    }
}

HashMap::HashMap() 
    : hashFunction{defaultHashFunc}
{
}

HashMap::HashMap(HashFunction hashFunction)
    : hashFunction{hashFunction}
{
}

void HashMap::arrCopy(Node** target, Node** source)
{
    for (int i = 0; i < bucketCount(); i++)
    {
        if (source[i] != nullptr)
        {
            const Node* currSource = source[i]; 
            target[i] = new Node{currSource->key, currSource->value}; 
            target[i]->next = nullptr; 

            Node* currTarget = target[i]; 
            currSource = currSource->next; 

            while (currSource != nullptr)
            {
                currTarget->next = new Node{currSource->key, \
                    currSource->value}; 
                currTarget = currTarget->next; 
                currTarget->next = nullptr; 
                currSource = currSource->next; 
            }
        }
    }
}

HashMap::HashMap(const HashMap& hm)
    : hashFunction{hm.hashFunction}, sizeNum{hm.size()}, \
        bucketCountNum{hm.bucketCount()}, \
        bucketList{new Node*[hm.bucketCount()]()}
{
    arrCopy(bucketList, hm.bucketList); 
}

HashMap::~HashMap() 
{
    for (int i = 0; i < bucketCount(); i++)
    {
        const Node* current = bucketList[i]; 
        while (current != nullptr)
        {
            const Node* temp = current; 
            current = current->next; 
            delete temp; 
        }
    }
    delete[] bucketList; 
}

void HashMap::clear() 
{
    for (int i = 0; i < bucketCount(); i++)
    {
        const Node* current = bucketList[i]; 
        while (current != nullptr)
        {
            const Node* temp = current; 
            current = current->next; 
            delete temp; 
        }
    }
}

HashMap& HashMap::operator=(const HashMap& hm) 
{
    if (this != &hm)
    {
        hashFunction = hm.hashFunction; 
        sizeNum = hm.size(); 
        bucketCountNum = hm.bucketCount(); 

        arrCopy(bucketList, hm.bucketList); 
    }

    return *this; 
}

void HashMap::add(const std::string& key, const std::string& value) 
{
    if (!contains(key)) 
    {
        unsigned int hashNum = hashFunction(key) % bucketCount(); 
        Node* newNode = new Node{key, value}; 
        newNode->next = bucketList[hashNum]; 
        bucketList[hashNum] = newNode; 

        sizeNum += 1; 
        
        if (loadFactor() > 0.8) 
        {
            rehash(); 
        }
    }
}

void HashMap::rehash() 
{
    int oldBucketNum = bucketCountNum; 
    bucketCountNum = 2 * bucketCountNum + 1; 
    Node** newBucketList = new Node*[bucketCount()](); 

    for (int i = 0; i < oldBucketNum; ++i)
    {
        Node* current = bucketList[i]; 
        while (current != nullptr) 
        {
            Node* temp = current; 
            current = current->next; 

            Node* bucket = newBucketList[hashFunction(temp->key) % \
                           bucketCount()]; 
            temp->next = bucket; 
            bucket = temp; 
            
            delete temp; 
        }
    }

    delete[] bucketList; 
    bucketList = newBucketList; 
}

bool HashMap::remove(const std::string& key)
{
    if (contains(key)) 
    {
        unsigned int hashNum = hashFunction(key) % bucketCount(); 
        Node* current = bucketList[hashNum]; 
        Node* prev = nullptr; 
        if (prev == nullptr && current->key == key)
        {
            bucketList[hashNum] = current->next; 
            delete current; 
        }
        else 
        {
            while (current->key != key)
            {
                prev = current; 
                current = current->next; 
            }
            prev->next = current->next; 
            delete current; 
        }

        return true; 
    }
    else 
    {
        return false; 
    }        
}

bool HashMap::contains(const std::string& key) const 
{
    unsigned int hashNum = hashFunction(key) % bucketCount(); 
    const Node* current = bucketList[hashNum]; 
    while (current != nullptr)
    {
        if (key == current->key)
        {
            return true; 
        }
        current = current -> next; 
    }
    return false; 
}

std::string HashMap::value(const std::string& key) const
{
    if (contains(key))
    {
        unsigned int hashNum = hashFunction(key) % bucketCount(); 
        const Node* current = bucketList[hashNum]; 
        while (current->key != key)
        {
            current = current->next; 
        }
        return current->value; 
    }
    else 
    {
        return ""; 
    }
}

unsigned int HashMap::size() const
{
    return sizeNum; 
} 

unsigned int HashMap::bucketCount() const
{
    return bucketCountNum; 
}

double HashMap::loadFactor() const 
{
    return size() / (double)bucketCount(); 
}

unsigned int HashMap::maxBucketSize() const
{
    unsigned int maxSize = 0; 
    for (int i = 0; i < bucketCount(); i++)
    {
        unsigned int bucketSize = 0; 
        const Node* current = *(bucketList + i); 
        while (current != nullptr)
        {
            bucketSize += 1; 
            current = current->next; 
        }
        if (bucketSize > maxSize)
        {
            maxSize = bucketSize; 
        }
    }

    return maxSize; 
}
