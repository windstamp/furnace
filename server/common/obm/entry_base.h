/*
 * =====================================================================================
 *
 *       Filename:  entry_base.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2016 05:49:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __ENTRY_BASE_H__
#define __ENTRY_BASE_H__

//-----------------------------------------------------------------------------
//  对象基类
//-----------------------------------------------------------------------------
template<typename ID_T>
class EntryBase
{
public:
	typedef ID_T id_t;
	
public:
	EntryBase() {}
	virtual ~EntryBase() {}
	
	virtual const char* ClassName() const = 0;
	
	virtual ID_T GetId() const = 0;
	virtual const std::string& GetName() const { static const std::string TMP; return TMP; }
};

//-----------------------------------------------------------------------------
//  Entry ID索引
//-----------------------------------------------------------------------------
template<typename EntryT>
class GetEntryId
{
public:
	typename Entry::id_t operator()(const EntryT* _entry) const
	{
		return _entry->GetId();
	}
};

template<typename EntryT>
class EntryId_HashIndex : public HashIndex<EntryT, typename EntryT::id_t, GetEntryId<EntryT> >
{
public:
	EntryT* GetEntryById(typename EntryT::id_t _id)
	{
		return this->find(_id);
	}
};

template<typename EntryT>
class EntryId_OrderedIndex : public OrderedIndex<EntryT, typename EntryT::id_t, GetEntryId<EntryT> >
{
public:
	EntryT* GetEntryById(typename EntryT::id_t _id)
	{
		return this->find(_id);
	}
};

//-----------------------------------------------------------------------------
//  Entry 名字索引
//-----------------------------------------------------------------------------
template<typename EntryT>
class GetEntryName
{
public:
	const std::string& operator()(const EntryT* _entry) const
	{
		return _entry->GetName();
	}
};

template<typename EntryT>
class EntryName_HashIndex : public HashIndex<EntryT, std::string, GetEntryName<EntryT> >
{
public:
	EntryT* GetEntryByName(const std::string& _name)
	{
		return this->find(_name);
	}
};

#endif /* __ENTRY_BASE_H__ */
