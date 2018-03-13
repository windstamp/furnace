/************************************************************************/
/* @file:	const_mgr.h                                                 */
/* @brief:	����������                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-21                                                  */
/* @last:	2017-06-21                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_LOADER_CONST_MGR_H__
#define __WARLORD_COMMON_LOADER_CONST_MGR_H__

#include "define/const_define.h"

#include "singleton.h"

class ConstMgr : public Singleton<ConstMgr>
{
	friend class Singleton<ConstMgr>;
	
private:
	//-------------------------------------------------------------------------
	// ���캯������������
	//-------------------------------------------------------------------------
	ConstMgr()	{}
	~ConstMgr()	{}

public:
	//-------------------------------------------------------------------------
	// ��ʼ�������١����¼���
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	bool	Reload(const int _reload_type);

public:
	//-------------------------------------------------------------------------
	// ��ø���������
	//-------------------------------------------------------------------------
	inline const MemConstParam&			GetConstParam() const			{ return const_param; }
	
private:
	//-------------------------------------------------------------------------
	// ���ؾ�̬�����б�
	//-------------------------------------------------------------------------
	bool	LoadAllConst();

	bool	LoadConstParam();	// ����

private:
	MemConstParam			const_param;				// ��������
};

#define sConstMgr	Singleton<ConstMgr>::Instance()

#endif /* __WARLORD_COMMON_LOADER_CONST_MGR_H__ */
