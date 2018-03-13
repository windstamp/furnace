/*
 * =====================================================================================
 *
 *       Filename:  hash_index.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2016 07:44:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __HASH_INDEX_H__
#define __HASH_INDEX_H__

//-----------------------------------------------------------------------------
//  哈希索引
//-----------------------------------------------------------------------------
template<typename EntryT, typename KeyT, typename GetKeyT, typename EqualKeyT>
class HashIndex
{
private:
	typedef __gnu_cxx::hash_map<KeyT, EntryT* __gnu_cxx::hash<KeyT>, EqualKeyT> HashMap;
	
public:
	typedef EntryT entry_t;
	typedef KeyT   key_t;
	
	typedef typename HashMap::iterator iterator;
	typedef typename HashMap::const_iterator const_iterator;

public:
	inline bool insert(EntryT* _entry)
	{
		return m_hash_map.insert( std::make_pair( GetKey(_entry), _entry ) ).second;
	}
	
	inline bool insert_without_sort(EntryT* _entry)
	{
		return insert(_entry);
	}
	
	inline void replace(EntryT* _entry)
	{
		return m_hash_map[ GetKey(_entry) ] = _entry;
	}
	
	inline void sort()
	{
		// nothing need to do.
	}
	
	inline void sort(EntryT* _entry)
	{
		// nothing need to do.
	}
	
	inline void erase(const KeyT& _key)
	{
		m_hash_map.erase(_key);
	}
	
	inline void erase(const EntryT* _entry)
	{
		m_hash_map.erase( GetKey(_entry) );
	}
	
	inline void clear()
	{
		return m_hash_map.clear();
	}
	
	inline bool empty() const
	{
		return m_hash_map.empty();
	}
	
	inline size_t size() const
	{
		return m_hash_map.size();
	}
	
public:
	inline EntryT* find(const KeyT& _key)
	{
		iterator iter = m_hash_map.find(_key);
		
		if (iter == m_hash_map.end()) return NULL;
		else return iter->second;
	}
	
	inline bool has(const KeyT& _key) const
	{
		return m_hash_map.find(_key) != m_hash_map.end();
	}
	
public:
	inline iterator begin()
	{
		return m_hash_map.begin();
	}
	
	inline const_iterator begin() const
	{
		return m_hash_map.begin();
	}
	
	inline iterator end()
	{
		return m_hash_map.end();
	}
	
	inline const_iterator end() const
	{
		return m_hash_map.end();
	}

private:
	GetKeyT GetKey;
	HashMap m_hash_map;
};

//-----------------------------------------------------------------------------
//  哈希索引 重复主键
//-----------------------------------------------------------------------------
template<typename EntryT, typename KeyT, typename GetKeyT, typename EqualKeyT>
class MultiHashIndex
{
private:
	typedef __gnu_cxx::hash_multimap<KeyT, EntryT*,
			__gnu_cxx::hash<KeyT>, EqualKeyT> HashMap;

public:
	typedef EntryT  entry_t;
	typedef KeyT    key_t;
	typedef GetKeyT get_key_t;
	
	typedef typename HashMap::iterator iterator;
	typedef typename HashMap::const_iterator const_iterator;
	
public:
	inline bool insert(EntryT* _entry)
	{
		m_hash_map.insert( std::make_pair( GetKey(_entry), _entry ) );
		return true;
	}
	
	inline void erase(const KeyT& _key)
	{
		m_hash_map.erase(_key);
	}
	
	inline void erase(const EntryT* _entry)
	{
		std::pair<iterator, iterator> range = m_hash_map.equal_range( GetKey(_entry) );
		for (iterator iter = range.first; iter != range.second; ++iter)
		{
			if (_entry == iter->second)
			{
				m_hash_map.erase(iter);
				break;
			}
		}
	}
	
	inline void clear()
	{
		m_hash_map.clear();
	}
	
	inline bool empty() const
	{
		return m_hash_map.empty();
	}
	
	inline size_t size() const
	{
		return m_hash_map.size();
	}
	
public:
	inline std::pair<iterator, iterator>
	EqualRange(const KeyT& _key)
	{
		return m_hash_map.equal_range(_key);
	}
	
	inline std::pair<const iterator, const iterator>
	EqualRange(const KeyT& _key) const
	{
		return m_hash_map.equal_range(_key);
	}
	
public:
	inline iterator begin()
	{
		return m_hash_map.begin();
	}
	
	inline const_iterator begin() const
	{
		return m_hash_map.begin();
	}
	
	inline iterator end()
	{
		return m_hash_map.end();
	}
	
	inline const_iterator end() const
	{
		return m_hash_map.end();
	}

private:
	GetKeyT GetKey;
	HashMap m_hash_map;
};


//-----------------------------------------------------------------------------
//  模板默认值声明
//-----------------------------------------------------------------------------
template<typename EntryT, typename KeyT, typename GetKeyT, typename EqualKeyT = std::equal_to<KeyT> >
class HashIndex;

template<typename EntryT, typename KeyT, typename GetKeyT, typename EqualKeyT = std::equal_to<KeyT> >
class MultiHashIndex;

#endif /* __HASH_INDEX_H__ */
