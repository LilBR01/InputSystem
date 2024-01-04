#include<Utilities/InternedString.h>
using namespace inputsystem;
using string = std::string;

InternedString::InternedString(const string& text)
{
	if (text.empty())
	{
		m_stringOriginalCase.clear();
		m_stringLowerCase.clear();
	}
	else
	{
		m_stringOriginalCase = text;
		m_stringLowerCase = text;
	}
}

int InternedString::GetSize() const
{
	return 0;
}

bool InternedString::IsEmpty() const
{
	return false;
}

string InternedString::ToLower() const
{
	return string();
}

bool InternedString::Equals(const InternedString& other) const
{
	return false;
}

int InternedString::CompareTo(const InternedString& other) const
{
	return 0;
}

std::size_t InternedString::GetHashCode() const
{
	return std::size_t();
}

string InternedString::ToString() const
{
	return string();
}

bool InternedString::operator==(const InternedString& other) const
{
	return false;
}

bool InternedString::operator!=(const InternedString& other) const
{
	return false;
}

bool InternedString::operator==(const string& other) const
{
	return false;
}

bool InternedString::operator!=(const string& other) const
{
	return false;
}

bool InternedString::operator<(const InternedString& other) const
{
	return false;
}

bool InternedString::operator>(const InternedString& other) const
{
	return false;
}
