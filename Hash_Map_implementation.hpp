#ifndef HASH_MAP_IMPLEMENTATION_HPP
#define HASH_MAP_IMPLEMENTATION_HPP

//default constructor of HasMap
template <typename key, typename value>
HashMap<key, value>::HashMap()
{
		table.resize(7, {0, nullptr});
}

//destructor of HashMap
template <typename key, typename value>
HashMap<key, value>::~HashMap()
{
	clear();
}

//function to push new (key,value) pairs into our HashMap
template <typename key, typename value>
void HashMap<key, value>::put(const key& k, const value& v)
{
    int index = Hashing(k);
    if (table[index].second == nullptr)
    {
        table[index].second = new std::list<std::pair<key, value>>;
		table[index].second ->push_front({k, v});
		++table[index].first;
		return;
    }

    for (auto it = table[index].second->begin(); it != table[index].second->end(); ++it)
    {
        if(it->first == k)
        {
            it->second = v;
            return;
        }
    }
    table[index].second->push_front({k, v});
    table[index].first++;
    if (table[index].first == table.size())
    {
        ReHashing();
    }
}

//function which returns value of the given key
template <typename key, typename value>
value HashMap<key, value>::get(const key& k)
{
    size_t index = Hashing(k);
    if (table[index].second != nullptr)
    {
		for (auto it = table[index].second->begin(); it != table[index].second->end(); ++it)
	    {
		    if(it->first == k)
			{
	            return it->second;       
			}
		}
	}
    throw std::runtime_error("Key not found");
}

//function which removes from HashMap the pair with the given key 
template <typename key, typename value>
void HashMap<key, value>::remove(const key& given_key)
{
		size_t index = Hashing(given_key);
		if(table[index].first == 0)
		{
				return;
		}
		auto it = table[index].second -> begin();
		for(size_t i = 0; i < table[index].first; ++i)
		{
				if(it -> first == given_key)
				{
						table[index].second -> erase(it);
						if(table[index].second -> empty())
						{
								delete table[index].second;
								table[index].second = nullptr;
						}
						break;
				}
				++it;
		}
		--table[index].first;
}

//function which checks if HashMap contains the given key or not
template <typename key, typename value>
bool HashMap<key, value>::containsKey(const key& wanted_key)
{
    int index = Hashing(wanted_key);
    if (table[index].second != nullptr)
    {
		auto it = table[index].second -> begin();
		for(it; it != table[index].second -> end(); ++it)
		{	
            if (it->first == wanted_key)
            {
                return true;
            }
		}
    }
    return false;
}

//function which checks if HashMap contains the given value or not
template <typename key, typename value>
bool HashMap<key, value>::containsValue(const value& wanted_value)
{

	for (size_t i = 0; i < table.size(); ++i)
    {
        if (table[i].second != nullptr)
        {
            for(auto it = table[i].second ->begin(); it != table[i].second -> end(); ++it)
            {
                if (it -> second == wanted_value)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

//function to return the count of (key, value) pairs containing in HashMap
template <typename key, typename value>
size_t HashMap<key, value>::size() 
{
	size_t count = 0;

				for(size_t i = 0; i < table.size(); ++i)
				{
						if(table[i].first)
						{
							count += table[i].first;
						}
				}
	return count;
}

//function which checks weather HashMap is empty or not
template <typename key, typename value>
bool HashMap<key, value>::isEmpty()
{
		return size() == 0;
}

//function to clear HashMap
template <typename key, typename value>
void HashMap<key, value>::clear()
{
		for(size_t i = 0; i < table.size(); ++i)
		{
				if (table[i].first)
				{
						delete table[i].second;
						table[i].second = nullptr;
				}
						table[i].first = 0;
		}
}

//function which returns set of all containing keys in hashMap
template <typename key, typename value>
std::vector<key> HashMap<key, value>::keySet()
{
		std::vector<key> vec;
		if(table.size())
		{
				for(size_t i = 0; i < table.size(); ++i)
				{
			
						if(table[i].first)
						{
								auto it1 = table[i].second -> begin();
								while (it1 != table[i].second -> end()) 
								{
									vec.push_back(it1 -> first);
									++it1;
								} 
						}
				}
		}
		return vec;
}

//function which returns set of all values containing in the HashMap
template <typename key, typename value>
std::vector<value> HashMap<key, value>::valueSet()
{
		std::vector<key> vec;
		if(table.size())
		{
				for(size_t i = 0; i < table.size(); ++i)
				{
						if(table[i].first)
						{
								auto it1 = table[i].second -> begin();
									while (it1 != table[i].second -> end())
									{
										vec.push_back(it1 -> second);
										++it1;
									}
						}
				}						
				
		}
		return vec;
}


//function which returns all the (key, value) pairs containing in the HashMap
template <typename key, typename value>
std::vector<std::pair<key, value>> HashMap<key, value>::entrySet()
{
		std::vector<std::pair<key, value>> vec;
		for(size_t i = 0; i < table.size(); ++i)
		{
				if(table[i].first)
				{
					auto it = table[i].second -> begin();
						for(size_t j = 0; j < table[i].first; ++j)
						{
								vec.push_back(*it);
								++it;
						}
				}
		}
		return vec;

}

//function which is responsible for resizing and rehashing the underlying data structure(vector) of the HashMap
template <typename key, typename value>
void HashMap<key, value>::ReHashing()
{
	size_t new_size = next_prime();
	std::vector<std::pair<size_t, std::list<std::pair<key, value>>*>> new_table(new_size, {0, nullptr});
	for(size_t i = 0; i < table.size(); ++i)
	{
			if(table[i].first)
			{
					auto it1 = table[i].second -> begin();
					auto it2 = table[i].second -> end();
					for(it1; it1 != it2; ++it1)
					{
						size_t index  = it1 -> first % new_size;
						if(new_table[index].second == nullptr)
						{
								new_table[index].second = new std::list<std::pair<key, value>>;
								new_table[index].second -> begin() -> first = it1 -> first;
								new_table[index].second -> begin() -> second = it1 -> second;
								++new_table[index].first;
						
						} else {
							
							new_table[index].second -> push_front({it1 -> first, it1 -> second});
							++new_table[index].first;
						}
					}
					
			}
	}
	std::swap(new_table, table);
}

//function to hash the given key 
template <typename key, typename value>
size_t HashMap<key, value>::Hashing(size_t new_key)
{
		return new_key % table.size();
}

//function which returns next prime number to be used in reHashing function
template <typename key, typename value>
size_t HashMap<key, value>::next_prime()
{
	size_t curr = table.size();
	curr++;
	while(!isPrime(curr)){
			++curr;
	}
		return curr;
}

//function which checks if the number is prime or not
template <typename key, typename value>
bool HashMap<key, value>::isPrime(size_t num)
{
		if(num < 2){
				return false;
		}
		if(num == 2)
		{
				return true;
		}
		for(size_t k = 2; k <= num/2; ++k)
		{
				if(num % k == 0)
				{
						return false;
				}
		}
		return true;
}

#endif //HASH_MAP_IMPLEMENTATION_HPP
