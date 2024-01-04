#include "Utilities/FourCC.h"

using namespace inputsystem;

FourCC::FourCC(uint32_t code):m_code(code)
{
}

FourCC::FourCC(char a, char b, char c, char d)
{
	m_code = (static_cast<uint32_t>(a) << 24) |
			 (static_cast<uint32_t>(b) << 16) |
		     (static_cast<uint32_t>(c) << 8) |
			 static_cast<uint32_t>(d);
}

FourCC::operator uint32_t() const
{
	return m_code;
}

uint32_t FourCC::GetCode() const
{
	return m_code;
}

std::string FourCC::ToString() const
{
	char char1 = static_cast<char>((m_code >> 24) & 0xFF);
	char char2 = static_cast<char>((m_code >> 16) & 0xFF);
	char char3 = static_cast<char>((m_code >> 8) & 0xFF);
	char char4 = static_cast<char>(m_code & 0xFF);

	return std::string(1, char1) + std::string(1, char2) + std::string(1, char3) + std::string(1, char4);
}

bool FourCC::Equals(const FourCC& other) const
{
	return m_code == other.m_code;
}

bool FourCC::operator==(const FourCC& other) const
{
	return Equals(other);
}

bool FourCC::operator!=(const FourCC& other) const
{
	return !Equals(other);
}

FourCC FourCC::FromUint32(uint32_t i)
{
	return FourCC(static_cast<uint32_t>(i));
}

uint32_t FourCC::ToUint32(const FourCC& fourCC)
{
	return static_cast<uint32_t>(fourCC.GetCode());
}
