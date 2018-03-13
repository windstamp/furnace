/*
 * =====================================================================================
 *
 *       Filename:  stl_ext.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2016 07:37:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __STL_EXT_H__
#define __STL_EXT_H__

//-----------------------------------------------------------------------------
//  散列函数 - 实例化时的扩展
//-----------------------------------------------------------------------------
namespace __gnu_cxx
{
	template<>
	struct hash<std::string>
	{
		size_t operator()(const std::string& _str) const
		{
			return __stl_hash_string(_str.data());
		}
	};
	
	template<typename T>
	struct hash<T*>
	{
		size_t operator()(T* _p) const
		{
			return (size_t)(_p);
		}
	};
	
	template<>
	struct hash<long long int>
	{
		size_t operator()(long long int _x) const
		{
			return _x;
		}
	};
	
	template<>
	struct hash<unsigned long long int>
	{
		size_t operator()(unsigned long long int _x) const
		{
			return _x;
		}
	};
}

#endif /* __STL_EXT_H__ */
