/*
 * =====================================================================================
 *
 *       Filename:  ordered_index.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2016 11:47:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __ORDERED_INDEX_H__
#define __ORDERED_INDEX_H__ 1

//-----------------------------------------------------------------------------
//  顺序索引
//-----------------------------------------------------------------------------
template<typename EntryT, typename KeyT, typename GetKeyT, typename LessKeyT>
class OrderedIndex
{
private:
	typedef std::map<KeyT, EntryT*, LessKeyT> OrderedMap;

public:
	typedef EntryT  entry_t;
	typedef KeyT    key_t;
	typedef GetKeyT get_key_t;
	
	typedef typename OrderedMap::iterator       iterator;
	typedef typename OrderedMap::const_iterator const_iterator;

public:
	inline bool insert(EntryT* _entry)
	{
		return m_ordered_map.insert( std::make_pair( GetKey(_entry), _entry ) ).second;
	}
	
	inline bool insert_without_sort(EntryT* _entry)
	{
		return insert(_entry);
	}
	
	inline void sort()
	{
		// nothing need to do.
	}
	
	inline void sort(EntryT* _entry)
	{
		// nothing need to do.
	}
	
	inline void replace(EntryT* _entry)
	{
		m_ordered_map[ GetKey(_entry) ] = _entry;
	}
	
	inline void erase(const KeyT& _key)
	{
		m_ordered_map.erase(_key);
	}
	
	inline void erase(EntryT* _entry)
	{
		m_ordered_map.erase( GetKey(_entry) );
	}
	
	inline void clear()
	{
		m_ordered_map.clear();
	}
	
	inline bool empty() const
	{
		return m_ordered_map.empty();
	}
	
	inline size_t size() const
	{
		return m_ordered_map.size();
	}
	
public:
	inline EntryT* find(const KeyT& _key)
	{
		iterator iter = m_ordered_map.find(_key);
		
		if ( iter == m_ordered_map.end() ) return NULL;
		else return iter->second;
	}
	
	inline iterator lower_bound(const KeyT& _key)
	{
		return m_ordered_map.lower_bound(_key);
	}
	
	inline const_iterator lower_bound(const KeyT& _key) const
	{
		return m_ordered_map.lower_bound(_key);
	}
	
	inline iterator upper_bound(const KeyT& _key)
	{
		return m_ordered_map.upper_bound(_key);
	}
	
	inline const_iterator upper_bound(const KeyT& _key) const
	{
		return m_ordered_map.upper_bound(_key);
	}
	
	inline std::pair<iterator, iterator> equal_range(const KeyT& _key)
	{
		return m_ordered_map.equal_range(_key);
	}
	
	inline std::pair<const_iterator, const_iterator> equal_range(const KeyT& _key) const
	{
		return m_ordered_map.equal_range(_key);
	}

public:
	inline iterator begin()
	{
		return m_ordered_map.begin();
	}
	
	inline const_iterator begin() const
	{
		return m_ordered_map.begin();
	}
	
	inline iterator end()
	{
		return m_ordered_map.end();
	}
	
	inline const_iterator end() const
	{
		return m_ordered_map.end();
	}
	
private:
	GetKeyT    GetKey;
	OrderedMap m_ordered_map;
};

//-----------------------------------------------------------------------------
//  顺序索引 重复主键
//-----------------------------------------------------------------------------
template<typename EntryT, typename KeyT, typename GetKeyT, typename LessKeyT>
class MultiOrderedIndex
{
private:
	typedef std::multimap<KeyT, EntryT*, LessKeyT> OrderedMap;
	
public:
	typedef EntryT entry_t;
	typedef KeyT   key_t;
	
	typedef typename OrderedMap::iterator       iterator;
	typedef typename OrderedMap::const_iterator const_iterator;
	
public:
	inline bool insert(EntryT* _entry)
	{
		m_ordered_map.insert( std::make_pair( GetKey(_entry), _entry ) );
		return true;
	}
	
	inline void erase(const KeyT& _key)
	{
		m_ordered_map.erase(_key);
	}
	
	inline void erase(const EntryT* _entry)
	{
		std::pair<iterator, iterator> range = m_ordered_map.equal_range( GetKey(_entry) );
		
		for (iterator iter = range.first; iter != range.second; ++iter)
		{
			if (_entry == iter->second)
			{
				m_ordered_map.erase(iter);
				break;
			}
		}
	}
	
	inline void clear()
	{
		m_ordered_map.clear();
	}
	
	inline bool empty() const
	{
		return m_ordered_map.empty();
	}
	
	inline size_t size() const
	{
		return m_ordered_map.size();
	}
	
public:
	inline std::pair<iterator, iterator> equal_range(const KeyT& _key)
	{
		return m_ordered_map.equal_range(_key);
	}
	
	inline std::pair<const_iterator, const_iterator> equal_range(const KeyT& _key) const
	{
		return m_ordered_map.equal_range(_key);
	}
	
	inline iterator lower_bound(const KeyT& _key)
	{
		return m_ordered_map.lower_bound(_key);
	}
	
	inline const_iterator lower_bound(const KeyT& _key) const
	{
		return m_ordered_map.lower_bound(_key);
	}
	
	inline iterator upper_bound(const KeyT& _key)
	{
		return m_ordered_map.upper_bound(_key);
	}
	
	inline iterator upper_bound(const KeyT& _key) const
	{
		return m_ordered_map.upper_bound(_key);
	}

public:
	inline iterator begin()
	{
		return m_ordered_map.begin();
	}
	
	inline const_iterator begin() const
	{
		return m_ordered_map.begin();
	}
	
	inline iterator end()
	{
		return m_ordered_map.end();
	}
	
	inline const_iterator end()
	{
		return m_ordered_map.end();
	}
	
private:
	GetKeyT    GetKey;
	OrderedMap m_ordered_map;
}

//-----------------------------------------------------------------------------
//  模板默认值声明
//-----------------------------------------------------------------------------
template<typename EntryT, typename KeyT, typename GetKeyT, typename LessKeyT = std::less<KeyT> >
class OrderedIndex;

template<typename EntryT, typename KeyT, typename GetKeyT, typename LessKeyT = std::less<KeyT> >
class MultiOrderedIndex;

#endif /* __ORDERED_INDEX_H__ */
