# HashMap Implementation in C++

This is a simple implementation of a HashMap in C++. The HashMap is designed to store key-value pairs and provides basic functionality such as insertion, retrieval, removal, and more.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Functions](#functions)
- [How to Use](#how-to-use)


## Overview

The HashMap implementation includes the following features:

- Dynamic resizing and rehashing to maintain efficiency.
- Key uniqueness enforcement.
- Support for various operations such as insertion, retrieval, removal, and more.
- it has structure like this
- ![Screenshot from 2024-01-14 22-25-01(3)](https://github.com/AnnaGmboyan/Hash_Map-Implementation/assets/138877122/c476129a-cd7d-427a-9f1d-ec1cec743239)


## Features

- **Insertion (`put`):** Add a key-value pair to the HashMap.
- **Retrieval (`get`):** Retrieve the value associated with a given key.
- **Removal (`remove`):** Remove a key-value pair from the HashMap.
- **Key and Value Sets (`keySet`, `valueSet`):** Retrieve sets of all keys or values.
- **Entry Set (`entrySet`):** Retrieve a set of all key-value pairs.
- **Size and Empty Checks (`size`, `isEmpty`):** Obtain the number of elements and check if the HashMap is empty.
- **Clear (`clear`):** Remove all elements from the HashMap.
- **Hashing and Rehashing (`ReHashing`, `Hashing`, `next_prime`, `isPrime`):** Functions related to hashing and resizing.

## Usage

```cpp
// Example usage of HashMap
#include <iostream>
#include "Hash_Map_prototypes.hpp"

int main() {
    // Create a HashMap with key and value of type int
    HashMap<int, int> myHashMap;

    // Insert key-value pairs
    myHashMap.put(1, 10);
    myHashMap.put(2, 20);
    myHashMap.put(3, 30);

    // Retrieve values
    std::cout << "Value for key 2: " << myHashMap.get(2) << std::endl;

    // Check if a key exists
    if (myHashMap.containsKey(3)) {
        std::cout << "Key 3 exists in the HashMap." << std::endl;
    }

    // Check if a value exists
    if (myHashMap.containsValue(20)) {
        std::cout << "Value 20 exists in the HashMap." << std::endl;
    }

    // Print all keys
    std::cout << "All Keys: ";
    std::vector<int> keys = myHashMap.keySet();
    for (const auto& key : keys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    // Print all values
    std::cout << "All Values: ";
    std::vector<int> values = myHashMap.valueSet();
    for (const auto& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Print all key-value pairs
    std::cout << "All Key-Value Pairs: ";
    std::vector<std::pair<int, int>> entries = myHashMap.entrySet();
    for (const auto& entry : entries) {
        std::cout << "(" << entry.first << ", " << entry.second << ") ";
    }
    std::cout << std::endl;

    // Check if HashMap is empty
    std::cout << "Is HashMap empty? " << (myHashMap.isEmpty() ? "Yes" : "No") << std::endl;

    // Get the size of the HashMap
    std::cout << "Size of HashMap: " << myHashMap.size() << std::endl;

    // Clear the HashMap
    myHashMap.clear();

    // Check if HashMap is empty after clearing
    std::cout << "Is HashMap empty after clearing? " << (myHashMap.isEmpty() ? "Yes" : "No") << std::endl;

    // ... (perform additional operations)

    return 0;
}

```
## Functions

    put(const key& k, const value& v): Insert a key-value pair.
    get(const key& k) -> value: Retrieve the value associated with a key.
    remove(const key& given_key): Remove the key-value pair with the given key.
    keySet() -> std::vector<key>: Return a vector containing all keys.
    valueSet() -> std::vector<value>: Return a vector containing all values.
    entrySet() -> std::vector<std::pair<key, value>>: Return a vector containing all key-value pairs.
    size() -> size_t: Return the total number of key-value pairs.
    isEmpty() -> bool: Check if the HashMap is empty.
    clear(): Remove all elements from the HashMap.
    ReHashing(): Resize and rehash the underlying data structure.
    Hashing(size_t new_key) -> size_t: Hash the given key.
    next_prime() -> size_t: Return the next prime number for rehashing.
    isPrime(size_t num) -> bool: Check if a given number is prime.

## How to Use

    Include the "HashMap.hpp" header file in your C++ project.
    Create a HashMap object with the desired key and value types.
    Use the provided functions to manipulate key-value pairs in the HashMap.
    // ... (perform additional operations)

    return 0;
    
}
