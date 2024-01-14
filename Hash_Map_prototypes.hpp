#ifndef HASH_MAP_PROTOTYPES_HPP
#define HASH_MAP_PROTOTYPES_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>


template <typename key, typename value>
class HashMap
{
	private:
		std::vector<std::pair<size_t,  std::list<std::pair<key, value>>*>> table;

	public:
		HashMap();
		~HashMap();
		void put(const key&, const  value&);	
		value get(const key&);			
		void remove(const key&);	
		bool containsKey(const key&);
		bool containsValue(const value&);
		size_t size();				
		bool isEmpty();				
		void clear();				
		std::vector<key> keySet();	
		std::vector<value> valueSet();	
		std::vector<std::pair<key, value>> entrySet();

	private:
		size_t Hashing(size_t new_key);
		size_t next_prime();
		bool isPrime(size_t);
		void ReHashing();
			
};
#include "Hash_Map_implementation.hpp"

#endif //HASH_MAP_PROTOTYPES_HPP 

