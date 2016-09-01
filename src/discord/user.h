// File name: user.h
// Author: FiniteReality
// Description: User-specific discord definitions

// Define a normal user.
// This struct contains information about said user.
typedef struct user
{
// THESE FIELDS ARE PRIVATE. I DO NOT RECOMMEND USING THEM EVEN IF THEY SHOW
// UP IN YOUR INTELLISENSE.
	char* user_id;
	char* user_name;
} user_t;

char* get_user_name(user_t* user);
char* get_user_id(user_t* user);

// Define a guild user.
// This struct contains information about said guild user.
typedef struct guild_user
{
	user* user;
	char* nickname;
} guild_user_t;

char* get_guild_user_name(guild_user_t* user);
char* get_guild_user_id(guild_user_t* user);
char* get_guild_user_nick(guild_user_t* user);
