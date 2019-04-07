#pragma once

#include <cstdint>
#include <array>

namespace DTex
{
	namespace detail
	{
		namespace KTX
		{
			constexpr std::array<unsigned char, 12> kTXIdentifier = { 0xAB, 0x4B, 0x54, 0x58, 0x20, 0x31, 0x31, 0xBB, 0x0D, 0x0A, 0x1A, 0x0A };

			constexpr uint32_t correctEndian = 0x04030201;

			struct Header
			{
				std::array<unsigned char, 12> identifier;
				uint32_t endianness;
				uint32_t glType;
				uint32_t glTypeSize;
				uint32_t glFormat;
				uint32_t glInternalFormat;
				uint32_t glBaseInternalFormat;
				uint32_t pixelWidth;
				uint32_t pixelHeight;
				uint32_t pixelDepth;
				uint32_t numberOfArrayElements;
				uint32_t numberOfFaces;
				uint32_t numberOfMipmapLevels;
				uint32_t bytesOfKeyValueData;
			};
		}
	}
}