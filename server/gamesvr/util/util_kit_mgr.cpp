// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "generator/id_generator.h"
#include "generator/id_generator_hero.h"
#include "generator/id_generator_item.h"
#include "generator/id_generator_player.h"

#include "util/util_kit_mgr.h"

//-----------------------------------------------------------------------------
// ��ʼ��������
//-----------------------------------------------------------------------------
bool UtilKitMgr::Init()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	// �����¼�������
	event_mgr_	= new EventMgr();
	if (!event_mgr_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "new EventMgr() failed.";
		
		return false;
	}
	
	// ��ʼ���¼�������
	if ( !event_mgr_->Init() )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "time_mgr_ Init() failed.";
		
		return false;
	}
	
	// ����ʱ�������
	time_mgr_	= new TimeMgr();
	if (!time_mgr_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "new TimeMgr() failed.";
		
		return false;
	}
	
	// ��ʼ��ʱ�������
	if ( !time_mgr_->Init() )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "time_mgr_ Init() failed.";
		
		return false;
	}
	
	// �����ͳ�ʼ��ȫ��ID������
	IdGenerator* id_generator_player = new IdGeneratorPlayer();
	if (!id_generator_player)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "new IdGeneratorPlayer() failed.";
		
		return false;
	}
	
	if ( !id_generator_player->Init(0, EIT_Player) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id_generator_player Init() failed.";
		
		return false;
	}
	
	IdGenerator* id_generator_hero = new IdGeneratorHero();
	if (!id_generator_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "new IdGeneratorHero() failed.";
		
		return false;
	}
	
	if ( !id_generator_hero->Init(0, EIT_Hero) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id_generator_hero Init() failed.";
		
		return false;
	}
	
	IdGenerator* id_generator_item = new IdGeneratorItem();
	if (!id_generator_item)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "new IdGeneratorItem() failed.";
		
		return false;
	}
	
	if ( !id_generator_item->Init(0, EIT_Item) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id_generator_item Init() failed.";
		
		return false;
	}
	
	id_generators_[EIT_Player]	= id_generator_player;
	id_generators_[EIT_Hero]	= id_generator_hero;
	id_generators_[EIT_Item]	= id_generator_item;
	
	return true;
}

void UtilKitMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
		
	if (time_mgr_)
		time_mgr_->Destroy();
	
	if (time_mgr_)
	{
		delete time_mgr_;
		
		time_mgr_	= NULL;
	}
	
	return;
}

//-----------------------------------------------------------------------------
// ÿ֡����
//-----------------------------------------------------------------------------
void UtilKitMgr::Update()
{
	if (time_mgr_)
		time_mgr_->Update();
	
	if (event_mgr_)
		event_mgr_->Update();
	
	return;
}

//-----------------------------------------------------------------------------
// ��Ա������ get/set ����
//-----------------------------------------------------------------------------
IdGenerator* UtilKitMgr::get_id_generator(const int32_t _type)
{
	if (_type < EIT_Start || _type >= EIT_End)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "type " << _type << " is outof range [" << EIT_Start << ", " << EIT_End << "]";
		
		return NULL;
	}
	
	return id_generators_[_type];
}
