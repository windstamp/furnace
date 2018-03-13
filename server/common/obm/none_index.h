/*
 * =====================================================================================
 *
 *       Filename:  none_index.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2016 10:07:46 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __NONE_INDEX_H__
#define __NONE_INDEX_H__

#include "index.h"

template<typename EntryT, typename KeyT, typename GetKeyT>
class NoneIndex : public Index<EntryT, KeyT, GetKeyT>
{
public:
	typedef EntryT  entry_t;
	typedef KeyT    key_t;
	typedef GetKeyT get_key_t;
	
public:
	inline bool insert(EntryT* _entry) { return true; }
	inline bool insert_without_sort(EntryT* _entry) { return true; }
	inline void sort() {}
	inline void sort(EntryT* _entry) {}
	inline void erase(EntryT*) {}
	inline void erase(KeyT) {}
	inline void clear() {}
	inline bool empty() { return true; }
	inline size_t size() { return 0; }
};

#endif /* __NONE_INDEX_H__ */
