#pragma once

#include "Texas/PixelFormat.hpp"
#include "Texas/Dimensions.hpp"
#include "Texas/TextureType.hpp"
#include "Texas/TextureInfo.hpp"

#include <cstdint>

namespace Texas
{
    /*
        Returns the maximum amount of mip levels a texture with baseDimensions can hold.
    */
    [[nodiscard]] std::uint64_t calcMaxMipCount(Dimensions baseDimensions);

    /*
        Returns the dimensions of a mip-level based on the baseDimensions.

        Will return { 0, 0, 0 } if mipLevelIndex is equal to or higher than the maximum mip count baseDimensions can support.
    */
    [[nodiscard]] Dimensions calcMipDimensions(Dimensions baseDimensions, std::uint64_t mipLevelIndex);

    /*
        Returns the total amount of memory an image will require.
    */
    [[nodiscard]] std::uint64_t calcTotalSizeRequired(
        Dimensions baseDimensions, 
        PixelFormat pixelFormat, 
        std::uint64_t mipLevelCount, 
        std::uint64_t arrayLayerCount);

    /*
        Returns the total amount of memory an image will require.
    */
    [[nodiscard]] std::uint64_t calcTotalSizeRequired(TextureInfo const& textureInfo);

    /*
        Returns the offset from the start of a buffer to a mip level.
    */
    [[nodiscard]] std::uint64_t calcMipOffset(
        Dimensions baseDimensions,
        PixelFormat pixelFormat,
        std::uint64_t arrayLayerCount,
        std::uint64_t mipLevelIndex);

    /*
        Returns the offset from the start of a buffer to a mip level.
    */
    [[nodiscard]] std::uint64_t calcMipOffset(TextureInfo const& textureInfo, std::uint64_t mipLevelIndex);

    /*
        Returns the offset from the start of a buffer to an array layer.
    */
    [[nodiscard]] std::uint64_t calcArrayLayerOffset(
        Dimensions baseDimensions,
        PixelFormat pixelFormat,
        std::uint64_t mipLevelIndex,
        std::uint64_t arrayLayerCount,
        std::uint64_t arrayLayerIndex);

    /*
        Returns the offset from the start of a buffer to an array layer.
    */
    [[nodiscard]] std::uint64_t calcArrayLayerOffset(
        TextureInfo const& textureInfo,
        std::uint64_t mipLevelIndex,
        std::uint64_t arrayLayerIndex);

    /*
        Returns the size of a single array layer.
    */
    [[nodiscard]] std::uint64_t calcArrayLayerSize(Dimensions dimensions, PixelFormat pixelFormat);
}