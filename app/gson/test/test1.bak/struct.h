#pragma once

struct people
{
	//Gson@optional
	acl::string aa;
	//Gson@optional
	acl::string bb;
};

struct user
{
	user(const char* user_name, const char* user_domain,
		int user_age, bool user_male)
	: username(user_name)
	, domain(user_domain)
	, age(user_age)
	, male(user_male)
	{}

	user() {}
	~user() {}

	user& set_username(const char* v)
	{
		username = v;
		return *this;
	}
	user& set_domain(const char* v)
	{
		domain = v;
		return *this;
	}
	user& set_age(int v)
	{
		age = v;
		return *this;
	}
	user& set_male(bool v)
	{
		male =v;
		return *this;
	}
	const char* get_username(void) const
	{
		return username.c_str();
	}
	const char* get_domain(void) const
	{
		return domain.c_str();
	}
	int get_age(void) const
	{
		return age;
	}
	bool is_male(void) const
	{
		return male;
	}

	acl::string username;
	acl::string domain;
	int age;
	bool male;
};

struct message
{
	int type;
	acl::string cmd;
	std::list<user> user_list;
	std::list<user> user_vector;
	std::map<acl::string, user> user_map;

	std::list<user*> *user_list_ptr = nullptr;
	std::vector<user*> *user_vector_ptr = nullptr;
	std::map<acl::string, user*> *user_map_ptr = nullptr;

	//const char* ptr = nullptr;		// error
	//const char* data = "hello world";	// error
	//char* data = "hello world";		// error
	//char ch = 'A';			// error
	//unsigned char ch = 'b';		// error
	//char ch1;				// error
	//const user* u1 = nullptr;		// error
	int n = 100;				// ok
	long n1 = 1000;				// ok
	long long int n2 = 1000;		// ok
	short n3 = 100;				// ok
	//short* n3_1 = &n3;			// error
	//Gson@optional
	user* u = nullptr;			// ok

	//const int n4 = 100;			// error
	//const long n5 = 1000;			// error
	//const long long int n6 = 1000;	// error
	//const short n7 = 100;			// error

	message() {}

	~message()
	{
		if (user_list_ptr)
		{
			for (auto it : *user_list_ptr)
				delete it;
			delete user_list_ptr;
		}
		if (user_vector_ptr)
		{
			for (auto it : *user_vector_ptr)
				delete it;
			delete user_vector_ptr;
		}
		if (user_map_ptr)
		{
			for (auto it : *user_map_ptr)
				delete it.second;
			delete user_map_ptr;
		}
	}
};
