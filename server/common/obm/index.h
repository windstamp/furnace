/*
 * =====================================================================================
 *
 *       Filename:  index.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2016 03:28:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __INDEX_H__
#define __INDEX_H__

template<typename EntryT, typename KeyT, typename GetKeyT>
class Index
{
public:
	virtual bool insert(EntryT* _entry) = 0;
	
	virtual bool insert_without_sort(EntryT* _entry) = 0;
	
	virtual void sort() = 0;
	
	virtual void sort(EntryT* _entry) = 0;
	
	virtual void erase(const KeyT& _key) = 0;
	
	virtual void erase(EntryT* _entry) = 0;
	
	virtual void clear() = 0;
	
	virtual bool empty() const = 0;
	
	virtual size_t size() const = 0;
};

#endif /* __INDEX_H__ */
