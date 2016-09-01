// File name: user.h
// Author: FiniteReality
// Description: User-specific discord definitions

#ifndef _user_h_
#define _user_h_

// Information about a user
struct user_info
{
	char* _id;
	char* _name;
	short int _discrim;
};

const char* get_user_name(struct user_info* user, int* length);
const char* get_user_id(struct user_info* user);
const short int get_user_discrim(struct user_info* user);


#endif // _user_h_
