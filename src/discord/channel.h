// File name: channel.h
// Author: FiniteReality
// Description: Channel definitions

#ifndef _channel_h_
#define _channel_h_

#include "user.h"
#include "guild.h"

#define CHANNEL_TEXT 0
#define CHANNEL_VOICE 1
#define CHANNEL_DM 2
#define CHANNEL_GROUP 3

// Information about a channel
struct channel_info
{
	unsigned char* name;
	unsigned char* id;
	int channel_type;
};

// Information about a DM channel
struct dm_channel
{
	struct channel_info* info;
	user_info* recipient;
};

// Information about a guild text channel
struct text_channel
{
	struct channel_info* info;
	guild_info* guild;
};

// Information about a guild voice channel
struct voice_channel
{
	struct channel_info* info;
	struct guild_info* guild;
	unsigned char* bitrate;
};

// Information about a group channel
struct group_channel
{
	struct channel_info* info;
	// user_info* owner; // TODO: do groups have owners?
};


const char* get_channel_name(struct channel_info* channel, int* length);
const char* get_channel_id(struct channel_info* channel);
const int get_channel_type(struct channel_info* channel);

const struct dm_channel* get_dm_channel(struct channel_info* channel);
const struct text_channel* get_text_channel(struct channel_info* channel);
const struct voice_channel* get_voice_channel(struct channel_info* channel);
const struct group_channel* get_group_channel(struct channel_info* channel);

const struct guild_user** get_text_channel_members(struct text_channel* channel, int* size);
const struct guild_user** get_voice_channel_members(struct voice_channel* channel, int* size);
const struct user_info** get_group_channel_members(struct group_channel* channel, int* size);


const struct channel_info** get_guild_channels(struct guild_info* guild, int* size);
const struct text_channel** get_guild_text_channels(struct guild_info* guild, int* size);
const struct voice_channel** get_guild_voice_channels(struct guild_info* guild, int* size);

#endif // _channel_h_
