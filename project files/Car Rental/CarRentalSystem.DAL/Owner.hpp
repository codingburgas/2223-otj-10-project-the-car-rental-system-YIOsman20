#pragma once
#include <string>


class Owner
{
private:
	int m_id;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_email;
	std::string m_phoneNumber;
	std::string m_address;
public:
	Owner()
	{

	};

	Owner(int id, std::string firstName, std::string lastName,std::string email,std::string phoneNumber,std::string address)
	{
		m_id = id;
		m_firstName = firstName;
		m_lastName = lastName;
		m_email = email;
		m_phoneNumber = phoneNumber;
		m_address = address;

	}
	int GetId()
	{
		return m_id;
	}
	void SetId(int id)
	{
		m_id = id;
	}
	
};

