// File name: channel.h
// Author: FiniteReality
// Description: Channel-specific

#ifndef _channel_h_
#define _channel_h_

#define CHANNEL_TEXT 0
#define CHANNEL_VOICE 1
#define CHANNEL_DM 2
#define CHANNEL_GROUP 3

// Information about a channel
struct channel_info
{
	char* name;
	char* id;
	int channel_type;
};

const char* get_channel_name(channel_info* channel, int* length);
const char* get_channel_id(channel_info* channel);
const int get_channel_type(channel_info* channel);


#endif // _channel_h_
