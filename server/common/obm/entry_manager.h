/*
 * =====================================================================================
 *
 *       Filename:  entry_manager.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2016 05:50:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __ENTRY_MANAGER_H__
#define __ENTRY_MANAGER_H__

#include "global_def.h"

#include "hash_index.h"
#include "random_index.h"
#include "ordered_index.h"
#include "none_index.h"

//-----------------------------------------------------------------------------
//  管理器模板，最多支持三个索引
//-----------------------------------------------------------------------------
template<typename IndexT1, typename IndexT2, typename IndexT3>
class EntryManager : public IndexT1, public IndexT2, public IndexT3
{
public:
	typedef typename IndexT1::entry_t EntryT;  // 管理对象类型
	
public:
	EntryManager()
	{
		// 三个索引的对象类型必须相同
		BOOST_STATIC_ASSERT( (boost::is_same<typename IndexT1::entry_t, typename IndexT2::entry_t>::value) );
		BOOST_STATIC_ASSERT( (boost::is_same<typename IndexT2::entry_t, typename IndexT3::entry_t>::value) );
	}
	
	virtual ~EntryManager()
	{
		doSafeDel();
	}
	
public:
	bool init_add(EntryT* _entry)
	{
		doSafeDel();
		
		if (!_entry) return false;
		
		if (!IndexT1::insert_without_sort(_entry)) return false;
		
		if (!IndexT2::insert_without_sort(_entry))
		{
			IndexT1::sort(_entry);
			IndexT1::erase(_entry);
			return false;
		}
		
		if (!IndexT3::insert_without_sort(_entry))
		{
			IndexT1::sort(_entry);
			IndexT2::sort(_entry);
			IndexT1::erase(_entry);
			IndexT2::erase(_entry);
			return false;
		}
		
		return;
	}
	
	bool add(EntryT* _entry)
	{
		doSafeDel();
		
		if (!_entry) return false;
		
		if (!IndexT1::insert(_entry)) return false;
		
		if (!IndexT2::insert(_entry))
		{
			IndexT1::erase(_entry);
			return false;
		}
		
		if (!IndexT3::insert(_entry))
		{
			IndexT1::erase(_entry);
			IndexT2::erase(_entry);
			return false;
		}
		
		return true;
	}
	
	void sort()
	{
		IndexT1::sort();
		IndexT2::sort();
		IndexT3::sort();
	}
	
	void remove(EntryT* _entry)
	{
		doSafeDel();
		
		if (_entry)
		{
			IndexT1::erase(_entry);
			IndexT2::erase(_entry);
			IndexT3::erase(_entry);
		}
	}
	
	void clear()
	{
		doSafeDel();
		
		IndexT1::clear();
		IndexT2::clear();
		IndexT3::clear();
	}
	
	bool empty() const
	{
		return IndexT1::empty();
	}
	
	size_t size() const
	{
		return IndexT1::size();
	}
	
	void del(EntryT* _entry)
	{
		if (_entry)
		{
			
		}
	}
	
private:
	void doSafeDel()
	{
		const size_t size = m_safe_del_vec.size();
		for (size_t i = 0; i < size; ++i)
		{
			SAFE_DELETE(m_safe_del_vec[i]);
		}
		m_safe_del_vec.clear();
	}
	
public:
	typedef IndexT1::iterator       iterator;
	typedef IndexT1::const_iterator const_iterator;
	
	inline iterator begin()
	{
		return IndexT1::begin();
	}
	
	inline const_iterator begin() const
	{
		return IndexT1::begin();
	}
	
	inline iterator end()
	{
		return IndexT1::end();
	}
	
	inline const_iterator end() const
	{
		return IndexT1::end();
	}
	
	inline iterator end()
	{
		return IndexT1::end();
	}
	
	inline const_iterator end() const
	{
		return IndexT1::end();
	}

private:
	std::vector<EntryT*> m_safe_del_vec;
};


//-----------------------------------------------------------------------------
//  默认参数
//-----------------------------------------------------------------------------
template<typename IndexT1,  // 至少需要一个索引
		 typename IndexT2=NoneIndex<typename IndexT1::entry_t, typename IndexT1::key_t, typename IndexT1::get_key_t>,
		 typename IndexT3=NoneIndex<typename IndexT1::entry_t, typename IndexT1::key_t, typename IndexT1::get_key_t> >
class EntryManager;

#endif /* __ENTRY_MANAGER_H__ */
