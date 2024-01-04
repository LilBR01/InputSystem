#pragma once
#include <string>

namespace inputsystem
{
	class InternedString 
	{
		using string = std::string;

	private:
		string m_stringOriginalCase;
		string m_stringLowerCase;

	public:
		InternedString(const string& text);
		int GetSize() const;
		bool IsEmpty() const;
		string ToLower() const;
		bool Equals(const InternedString& other) const;
		int CompareTo(const InternedString& other) const;
		std::size_t GetHashCode() const;
		string ToString() const;
		bool operator==(const InternedString& other) const;
		bool operator!=(const InternedString& other) const;
		bool operator==(const string& other) const;
		bool operator!=(const string& other) const;
		bool operator<(const InternedString& other) const;
		bool operator>(const InternedString& other) const;
	};

}