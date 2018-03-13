// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "resource/res_mgr.h"

#include "fight/skill.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
Skill::Skill()
{
}

Skill::~Skill()
{
}

//-----------------------------------------------------------------------------
// 初始化和销毁
//-----------------------------------------------------------------------------
bool Skill::Init(const int64_t _skill_id)
{
	const MemSkillEntry* skill_entry = sResMgr->GetSkillEntry(_skill_id);
	if (!skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid skill entry: " << _skill_id;
		
		return false;
	}
	
	return Init(skill_entry);
}

bool Skill::Init(const MemSkillEntry* _skill_entry)
{
	if (!_skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _skill_entry";
		
		return false;
	}
	
	skill_entry_ = _skill_entry;
	
	return true;
}

void Skill::Destroy()
{
}
