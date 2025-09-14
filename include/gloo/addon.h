#ifndef _GLOO_ADDON_H_
#define _GLOO_ADDON_H_

#pragma once

#include "gloo/Texture.h"

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
        const std::string info(const Texture &_texture);
        const std::string targetToString(const Texture::Target &_target);
        const std::string typeToString(const Texture::Type &_type);
        const std::string formatToString(const Texture::Format &_format);
        const std::string slotToString(const Texture::Slot &_slot);
    }
}

#endif // _GLOO_ADDON_H_