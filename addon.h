#ifndef _GLOO_ADDON_H_
#define _GLOO_ADDON_H_

#pragma once

#include "gloo/Texture.h"

#include <sstream>
#include <string>

#define TEXTURE_INTERNALFORMAT_LABEL {"DepthComponent",              \
                                      "DepthStencil",                \
                                      "Red",                         \
                                      "RG",                          \
                                      "RGB",                         \
                                      "RGBA",                        \
                                      "R8",                          \
                                      "R8SNorm",                     \
                                      "R16",                         \
                                      "R16SNorm",                    \
                                      "RG8",                         \
                                      "RG8SNorm",                    \
                                      "RG16",                        \
                                      "RG16SNorm",                   \
                                      "R3G3B2",                      \
                                      "RGB4",                        \
                                      "RGB5",                        \
                                      "RGB8",                        \
                                      "RGB8SNorm",                   \
                                      "RGB10",                       \
                                      "RGB12",                       \
                                      "RGB16SNorm",                  \
                                      "RGBA2",                       \
                                      "RGBA4",                       \
                                      "RGB5A1",                      \
                                      "RGBA8",                       \
                                      "RGBA8SNorm",                  \
                                      "RGB10A2",                     \
                                      "RGB10A2UI",                   \
                                      "RGBA12",                      \
                                      "RGBA16",                      \
                                      "SRGB8",                       \
                                      "SRGB8Alpha8",                 \
                                      "R16F",                        \
                                      "RG16F",                       \
                                      "RGB16F",                      \
                                      "RGBA16F",                     \
                                      "R32F",                        \
                                      "RG32F",                       \
                                      "RGB32F",                      \
                                      "RGBA32F",                     \
                                      "R11FG11FB10F",                \
                                      "RGB9E5",                      \
                                      "R8I",                         \
                                      "R8UI",                        \
                                      "R16I",                        \
                                      "R16UI",                       \
                                      "R32I",                        \
                                      "R32UI",                       \
                                      "RG8I",                        \
                                      "RG8UI",                       \
                                      "RG16I",                       \
                                      "RG16UI",                      \
                                      "RG32I",                       \
                                      "RG32UI",                      \
                                      "RGB8I",                       \
                                      "RGB8UI",                      \
                                      "RGB16I",                      \
                                      "RGB16UI",                     \
                                      "RGB32I",                      \
                                      "RGB32UI",                     \
                                      "RGBA8I",                      \
                                      "RGBA8UI",                     \
                                      "RGBA16I",                     \
                                      "RGBA16UI",                    \
                                      "RGBA32I",                     \
                                      "RGBA32UI",                    \
                                      "Compressed_Red",              \
                                      "Compressed_RG",               \
                                      "Compressed_RGB",              \
                                      "Compressed_RGBA",             \
                                      "Compressed_SRGB",             \
                                      "Compressed_SRGB_Alpha",       \
                                      "Compressed_Red_RGtc1",        \
                                      "Compressed_Signed_Red_RGtc1", \
                                      "Compressed_RG_RGtc2",         \
                                      "Compressed_Signed_RG_RGtc2"};
/*! Format of texture data */
#define TEXTURE_FORMAT_LABEL {"Red",            \
                              "RG",             \
                              "RGB",            \
                              "BGR",            \
                              "RGBA",           \
                              "BGRA",           \
                              "RedInteger",     \
                              "RGInteger",      \
                              "RGBInteger",     \
                              "BGRInteger",     \
                              "RGBAInteger",    \
                              "BGRAInteger",    \
                              "StencilIndex",   \
                              "DepthComponent", \
                              "DepthStencil"};
/*! Texture slot */
#define TEXTURE_SLOT_LABEL {"slot00", \
                            "slot01", \
                            "slot02", \
                            "slot03", \
                            "slot04", \
                            "slot05", \
                            "slot06", \
                            "slot07", \
                            "slot08", \
                            "slot09", \
                            "slot10", \
                            "slot11", \
                            "slot12", \
                            "slot13", \
                            "slot14", \
                            "slot15", \
                            "slot16", \
                            "slot17", \
                            "slot18", \
                            "slot19", \
                            "slot20", \
                            "slot21", \
                            "slot22", \
                            "slot23", \
                            "slot24", \
                            "slot25", \
                            "slot26", \
                            "slot27", \
                            "slot28", \
                            "slot29", \
                            "slot30", \
                            "slot31"};

namespace gloo
{
    namespace addon
    {
        inline const std::string targetToString(const Texture::Target &_target)
        {
            if (_target == Texture::Target::Texture1D)
                return "Texture1D";
            else if (_target == Texture::Target::Texture2D)
                return "Texture2D";
            else if (_target == Texture::Target::Texture3D)
                return "Texture3D";
            else if (_target == Texture::Target::Texture1DArray)
                return "Texture1DArray";
            else if (_target == Texture::Target::Texture2DArray)
                return "Texture2DArray";
            else if (_target == Texture::Target::TextureRectangle)
                return "TextureRectangle";
            else if (_target == Texture::Target::TextureCubeMap)
                return "TextureCubeMap";
            else if (_target == Texture::Target::TextureBuffer)
                return "TextureBuffer";
            else if (_target == Texture::Target::Texture2dMultiSample)
                return "Texture2dMultiSample";
            else if (_target == Texture::Target::Texture2dMultiSampleArray)
                return "Texture2dMultiSampleArray";
            else
                return "nullTarget";
        }

        inline const std::string typeToString(const Texture::Type &_type)
        {
            if (_type == Texture::Type::UnsignedByte)
                return "UnsignedByte";
            else if (_type == Texture::Type::Byte)
                return "Byte";
            else if (_type == Texture::Type::UnsignedShort)
                return "UnsignedShort";
            else if (_type == Texture::Type::Short)
                return "Short";
            else if (_type == Texture::Type::UnsignedInt)
                return "UnsignedInt";
            else if (_type == Texture::Type::Int)
                return "Int";
            else if (_type == Texture::Type::HalfFloat)
                return "HalfFloat";
            else if (_type == Texture::Type::Float)
                return "Float";
            else if (_type == Texture::Type::UnsignedByte332)
                return "UnsignedByte332";
            else if (_type == Texture::Type::UnsignedByte233_Rev)
                return "UnsignedByte233_Rev";
            else if (_type == Texture::Type::UnsignedShort565)
                return "UnsignedShort565";
            else if (_type == Texture::Type::UnsignedShort565_Rev)
                return "UnsignedShort565_Rev";
            else if (_type == Texture::Type::UnsignedShort4444)
                return "UnsignedShort4444";
            else if (_type == Texture::Type::UnsignedShort4444_Rev)
                return "UnsignedShort4444_Rev";
            else if (_type == Texture::Type::UnsignedShort5551)
                return "UnsignedShort5551";
            else if (_type == Texture::Type::UnsignedShort1555_Rev)
                return "UnsignedShort1555_Rev";
            else if (_type == Texture::Type::UnsignedInt8888)
                return "UnsignedInt8888";
            else if (_type == Texture::Type::UnsignedInt8888_Rev)
                return "UnsignedInt8888_Rev";
            else if (_type == Texture::Type::UnsignedInt1010102)
                return "UnsignedInt1010102";
            else if (_type == Texture::Type::UnsignedInt2101010_Rev)
                return "UnsignedInt2101010_Rev";
            else
                return "nullType";
        }

        inline const std::string formatToString(const Texture::Format &_format)
        {
            if (_format == Texture::Format::Red)
                return "Red";
            else if (_format == Texture::Format::RG)
                return "RG";
            else if (_format == Texture::Format::RGB)
                return "RGB";
            else if (_format == Texture::Format::BGR)
                return "BGR";
            else if (_format == Texture::Format::RGBA)
                return "RGBA";
            else if (_format == Texture::Format::BGRA)
                return "BGRA";
            else if (_format == Texture::Format::RedInteger)
                return "RedInteger";
            else if (_format == Texture::Format::RGInteger)
                return "RGInteger";
            else if (_format == Texture::Format::RGBInteger)
                return "RGBInteger";
            else if (_format == Texture::Format::BGRInteger)
                return "BGRInteger";
            else if (_format == Texture::Format::RGBAInteger)
                return "RGBAInteger";
            else if (_format == Texture::Format::BGRAInteger)
                return "BGRAInteger";
            else if (_format == Texture::Format::StencilIndex)
                return "StencilIndex";
            else if (_format == Texture::Format::DepthComponent)
                return "DepthComponent";
            else if (_format == Texture::Format::DepthStencil)
                return "DepthStencil";
            else
                return "nullFormat";
        }

        inline const std::string slotToString(const Texture::Slot &_slot)
        {
            if (_slot == Texture::Slot::slot00)
                return "slot00";
            else if (_slot == Texture::Slot::slot01)
                return "slot01";
            else if (_slot == Texture::Slot::slot02)
                return "slot02";
            else if (_slot == Texture::Slot::slot03)
                return "slot03";
            else if (_slot == Texture::Slot::slot04)
                return "slot04";
            else if (_slot == Texture::Slot::slot05)
                return "slot05";
            else if (_slot == Texture::Slot::slot06)
                return "slot06";
            else if (_slot == Texture::Slot::slot07)
                return "slot07";
            else if (_slot == Texture::Slot::slot08)
                return "slot08";
            else if (_slot == Texture::Slot::slot09)
                return "slot09";
            else if (_slot == Texture::Slot::slot10)
                return "slot10";
            else if (_slot == Texture::Slot::slot11)
                return "slot11";
            else if (_slot == Texture::Slot::slot12)
                return "slot12";
            else if (_slot == Texture::Slot::slot13)
                return "slot13";
            else if (_slot == Texture::Slot::slot14)
                return "slot14";
            else if (_slot == Texture::Slot::slot15)
                return "slot15";
            else if (_slot == Texture::Slot::slot16)
                return "slot16";
            else if (_slot == Texture::Slot::slot17)
                return "slot17";
            else if (_slot == Texture::Slot::slot18)
                return "slot18";
            else if (_slot == Texture::Slot::slot19)
                return "slot19";
            else if (_slot == Texture::Slot::slot20)
                return "slot20";
            else if (_slot == Texture::Slot::slot21)
                return "slot21";
            else if (_slot == Texture::Slot::slot22)
                return "slot22";
            else if (_slot == Texture::Slot::slot23)
                return "slot23";
            else if (_slot == Texture::Slot::slot24)
                return "slot24";
            else if (_slot == Texture::Slot::slot25)
                return "slot25";
            else if (_slot == Texture::Slot::slot26)
                return "slot26";
            else if (_slot == Texture::Slot::slot27)
                return "slot27";
            else if (_slot == Texture::Slot::slot28)
                return "slot28";
            else if (_slot == Texture::Slot::slot29)
                return "slot29";
            else if (_slot == Texture::Slot::slot30)
                return "slot30";
            else if (_slot == Texture::Slot::slot31)
                return "slot31";
            else
                return "nullSlot";
        }

        inline const std::string info(const Texture &_texture)
        {
            std::stringstream out;
            out << "[" << targetToString(_texture.target) << " : "
                << typeToString(_texture.type) << " : "
                << formatToString(_texture.format) << " : "
                << slotToString(_texture.slot) << " : "
                << _texture.width << " x "
                << _texture.height << "]";
            return out.str();
        }
    }
}

#endif // _GLOO_ADDON_H_
