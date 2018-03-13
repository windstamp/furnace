/************************************************************************/
/* @file:	config_mgr.h                                                */
/* @brief:	���ù�����                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-22                                                  */
/* @last:	2017-06-22                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_LOADER_CONFIG_MGR_H__
#define __WARLORD_COMMON_LOADER_CONFIG_MGR_H__

#include "define/config_define.h"

#include "singleton.h"

class ConfigMgr : public Singleton<ConfigMgr>
{
	friend class Singleton<ConfigMgr>;
	
private:
	//-------------------------------------------------------------------------
	// ���캯������������
	//-------------------------------------------------------------------------
	ConfigMgr()		{}
	~ConfigMgr()	{}

public:
	//-------------------------------------------------------------------------
	// ��ʼ�������١����¼���
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	bool	Reload(const int _reload_type);

public:
	//-------------------------------------------------------------------------
	// ��ø��������ò���
	//-------------------------------------------------------------------------
	inline const MemConfigNetwork&			GetConfigNetwork() const			{ return config_network; }
	
private:
	//-------------------------------------------------------------------------
	// �������þ�̬�����б�
	//-------------------------------------------------------------------------
	bool	LoadAllConfig();

	bool	LoadConfigNetwork();	// ����

private:
	MemConfigNetwork			config_network;				// ���� - ����
};

#define sConfigMgr	Singleton<ConfigMgr>::Instance()

#endif /* __WARLORD_COMMON_LOADER_CONFIG_MGR_H__ */
