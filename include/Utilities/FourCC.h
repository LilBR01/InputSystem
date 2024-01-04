#pragma once
#include <cstdint>
#include <string>

namespace inputsystem
{
	class FourCC
	{
	private:
		uint32_t m_code;

	public:
		FourCC(uint32_t code);
		FourCC(char a, char b = ' ', char c = ' ', char d = ' ');
		
		operator uint32_t() const;

		uint32_t GetCode() const;
		std::string ToString() const;

		bool Equals(const FourCC& other) const;
		bool operator==(const FourCC& other) const;
		bool operator!=(const FourCC& other) const;

		static FourCC FromUint32(uint32_t i);
		static uint32_t ToUint32(const FourCC& fourCC);
	};
}