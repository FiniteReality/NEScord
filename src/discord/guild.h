// File name: guild.h
// Author: FiniteReality
// Description: Guild definitions

#ifndef _guild_h_
#define _guild_h_

#include "discord/user.h"

// This struct contains information about a guild user.
struct guild_user
{
	struct user_info* info;
	char* nickname;
	struct guild_info* guild;
};

// This struct contains information about a guild.
struct guild_info
{
	char* name;
	struct guild_user* owner;
};

const struct user_info* get_guild_user_info(struct guild_user* user);
const char* get_guild_user_nick(struct guild_user* user);
const struct guild_info* get_user_guild(struct guild_user* user);

const char* get_guild_name(struct guild_info* guild);
const struct guild_user* get_guild_owner(struct guild_info* guild);
const struct guild_user** get_guild_members(struct guild_info* guild, int max, int* out_size);

#endif // _guild_h_
