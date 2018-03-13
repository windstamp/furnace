/*
 * =====================================================================================
 *
 *       Filename:  random_index.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2016 11:42:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __RANDOM_INDEX_H__
#define __RANDOM_INDEX_H__

template<typename EntryT, typename TypeT, typename GetTypeT>
class RandomIndex
{
public:
	typedef EntryT entry_t;

public:
	inline bool insert(EntryT* _entry)
	{
		EntryVec& entry_vec = m_type_entry_vec_map[ getType(_entry) ];
		entry_vec.push_back(_entry);
		std::sort( entry_vec.begin(), entry_vec.end() );
		return true;
	}
	
	inline bool insert_without_sort(EntryT* _entry)
	{
		EntryVec& entry_vec = m_type_entry_vec_map[ getType(_entry) ];
		entry_vec.push_back(_entry);
		return true;
	}
	
	inline void sort()
	{
		for (TypeEntryVecMapIter iter = m_type_entry_vec_map.begin();
			 iter != m_type_entry_vec_map.end();
			 ++iter)
		{
			EntryVec& entry_vec = iter->second;
			std::sort( entry_vec.begin(), entry_vec.end() );
		}
	}
	
	inline void sort(EntryT* _entry)
	{
		EntryVec& entry_vec = m_type_entry_vec_map[ getType(_entry) ];
		std::sort( entry_vec.begin(), entry_vec.end() );
	}
	
	inline void erase(const TypeT& _type)
	{
		m_type_entry_vec_map.erase(_type);
	}
	
	inline void erase(EntryT* _entry)
	{
		TypeEntryVecMapConstIter iter_map = m_type_entry_vec_map.find( getType(_entry) );
		if ( iter_map != m_type_entry_vec_map.end() )
		{
			EntryVec& entry_vec = iter_map->second;
			
			EntryVecIter iter_vec = std::lower_bound( entry_vec.begin(), entry_vec.end(), _entry );
			
			if (iter_vec != entry_vec.end() && *iter_vec == _entry)
			{
				entry_vec.erase(_iter);
				
				if ( entry_vec.empty() )
				{
					m_type_entry_vec_map.erase( getType(_entry) );
				}
			}
		}
	}
	
	inline void clear()
	{
		m_type_entry_vec_map.clear();
	}
	
	inline bool empty() const
	{
		return m_type_entry_vec_map.empty();
	}
	
	inline size_t size() const
	{
		size_t size = 0;
		
		TypeEntryVecMapConstIter iter = m_type_entry_vec_map.begin();
		
		for (; iter != m_type_entry_vec_map.end(); ++iter)
		{
			size += iter->second.size();
		}
		
		return size;
	}
	
	EntryT* random(TypeT _type = 0)
	{
		TypeEntryVecMapConstIter iter = m_type_entry_vec_map.find(_type);
		if (iter == m_type_entry_vec_map.end()) return NULL;
		
		EntryVec& entry_vec = iter->second;
		if (entry_vec.empty()) return NULL;
		
		return entry_vec[ rand() % entry_vec.size() ];
	}
	
	template<typename FilterT>
	EntryT* random_if(const FilterT& _filter, TypeT _type = 0)
	{
		TypeEntryVecMapConstIter iter = m_type_entry_vec_map.find(_type);
		if (iter == m_type_entry_vec_map.end()) return NULL;
		
		EntryVec& entry_vec = iter->second;
		if ( entry_vec.empty() ) return NULL;
		
		bool rollback = false;
		
		const size_t begin_index = rand() % entry_vec.size();
		for ( size_t i = begin_index; rollback ? i < begin_index : true; )
		{
			if ( _filter( entry_vec[i] ) )
			{
				return entry_vec[i];
			}
			
			if ( ++i >= entry_vec.size() )
			{
				i = 0;
				rollback = true;
			}
		}
		
		return NULL;
	}
	
	template<typename ContainerT>
	void random_n(size_t _n, ContainerT* _list, TypeT _type = 0)
	{
		if (!_list) return;
		
		TypeEntryVecMapIter iter = m_type_entry_vec_map.find(type);
		if (iter == m_type_entry_vec_map.end()) return;
		
		// 构造一个副本
		EntryVec entry_vec(iter->second);
		for(size_t i = 0; i < _n && i < entry_vec.size(); ++i)
		{
			size_t r = rand() % (entry_vec.size() - i);
			_list->push_back(entry_vec[r]);
			std::swap(entry_vec[r], entry_vec[entry_vec.size() - i - 1]);
		}
	}
	
	template<typename FilterT, typename ContainerT>
	void random_n_if(size_t _n, ContainerT* _list, const FilterT& _filter, TypeT _type = 0)
	{
		if (!list) return;
		
		TypeEntryVecMapIter iter = m_type_entry_vec_map.find(_type);
		if (iter == m_type_entry_vec_map.end()) return;
		
		// 构建一个副本
		EntryVec entry_vec(iter->second);
		for (size_t i = 0; list->size() < _n && i < entry_vec.size(); ++i)
		{
			size_t r = rand() % (entry_vec.size() - i);
			if ( _filter(entry_vec[r]) ) list->push_back(entry_vec[r]);
			std::swap(entry_vec[r], entry_vec[entry_vec.size() - i - 1]);
		}
	}

private:
	typedef std::vector<EntryT*>                     EntryVec;
	typedef typename EntryVec::iterator              EntryVecIter;
	
	typedef std::map<TypeT, EntryVec>                TypeEntryVecMap;
	typedef typename TypeEntryVecMap::iterator       TypeEntryVecMapIter;
	typedef typename TypeEntryVecMap::const_iterator TypeEntryVecMapConstIter;
	
	TypeEntryVecMap m_type_entry_vec_map;
	
private:
	GetTypeT getType;
};

template<typename EntryT>
struct DefaultGetType
{
	int operator()(const EntryT*) const { return 0; }
};

template<typename EntryT, typename TypeT = int, typename GetTypeT = DefaultGetType<EntryT> >
class RandomIndex;

#endif /* __RANDOM_INDEX_H__ */
