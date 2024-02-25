#include <sstream>

#include "gloo/addon.h"

const std::string gloo::addon::info(const gloo::Texture &_texture)
{
    std::stringstream out;
    //            << textureFormatLabel[(int)_texture.format] << ":"
    //            << textureSlotLabel[(int)_texture.slot] << ":"
    //            << _texture.width << _texture.width << " x "
    //            << _texture.height << "]";
    out << "[" << gloo::addon::targetToString(_texture.target) << " : "
        << gloo::addon::typeToString(_texture.type) << " : "
        << gloo::addon::formatToString(_texture.format) << " : "
        << gloo::addon::slotToString(_texture.slot) << " : "
        << _texture.width << " x "
        << _texture.height << "]";
    return out.str();
}

const std::string gloo::addon::targetToString(const gloo::Texture::Target &_target)
{
    if (_target == gloo::Texture::Target::Texture1D)
        return "Texture1D";
    else if (_target == gloo::Texture::Target::Texture2D)
        return "Texture2D";
    else if (_target == gloo::Texture::Target::Texture3D)
        return "Texture3D";
    else if (_target == gloo::Texture::Target::Texture1DArray)
        return "Texture1DArray";
    else if (_target == gloo::Texture::Target::Texture2DArray)
        return "Texture2DArray";
    else if (_target == gloo::Texture::Target::TextureRectangle)
        return "TextureRectangle";
    else if (_target == gloo::Texture::Target::TextureCubeMap)
        return "TextureCubeMap";
    else if (_target == gloo::Texture::Target::TextureBuffer)
        return "TextureBuffer";
    else if (_target == gloo::Texture::Target::Texture2dMultiSample)
        return "Texture2dMultiSample";
    else if (_target == gloo::Texture::Target::Texture2dMultiSampleArray)
        return "Texture2dMultiSampleArray";
    else
        return "nullTarget";
};

const std::string gloo::addon::typeToString(const gloo::Texture::Type &_type)
{
    if (_type == gloo::Texture::Type::UnsignedByte)
        return "UnsignedByte";
    else if (_type == gloo::Texture::Type::Byte)
        return "Byte";
    else if (_type == gloo::Texture::Type::UnsignedShort)
        return "UnsignedShort";
    else if (_type == gloo::Texture::Type::Short)
        return "Short";
    else if (_type == gloo::Texture::Type::UnsignedInt)
        return "UnsignedInt";
    else if (_type == gloo::Texture::Type::Int)
        return "Int";
    else if (_type == gloo::Texture::Type::HalfFloat)
        return "HalfFloat";
    else if (_type == gloo::Texture::Type::Float)
        return "Float";
    else if (_type == gloo::Texture::Type::UnsignedByte332)
        return "UnsignedByte332";
    else if (_type == gloo::Texture::Type::UnsignedByte233_Rev)
        return "UnsignedByte233_Rev";
    else if (_type == gloo::Texture::Type::UnsignedShort565)
        return "UnsignedShort565";
    else if (_type == gloo::Texture::Type::UnsignedShort565_Rev)
        return "UnsignedShort565_Rev";
    else if (_type == gloo::Texture::Type::UnsignedShort4444)
        return "UnsignedShort4444";
    else if (_type == gloo::Texture::Type::UnsignedShort4444_Rev)
        return "UnsignedShort4444_Rev";
    else if (_type == gloo::Texture::Type::UnsignedShort5551)
        return "UnsignedShort5551";
    else if (_type == gloo::Texture::Type::UnsignedShort1555_Rev)
        return "UnsignedShort1555_Rev";
    else if (_type == gloo::Texture::Type::UnsignedInt8888)
        return "UnsignedInt8888";
    else if (_type == gloo::Texture::Type::UnsignedInt8888_Rev)
        return "UnsignedInt8888_Rev";
    else if (_type == gloo::Texture::Type::UnsignedInt1010102)
        return "UnsignedInt1010102";
    else if (_type == gloo::Texture::Type::UnsignedInt2101010_Rev)
        return "UnsignedInt2101010_Rev";
    else
        return "nullType";
}

const std::string gloo::addon::formatToString(const gloo::Texture::Format &_format)
{
    if (_format == gloo::Texture::Format::Red)
        return "Red";
    else if (_format == gloo::Texture::Format::RG)
        return "RG";
    else if (_format == gloo::Texture::Format::RGB)
        return "RGB";
    else if (_format == gloo::Texture::Format::BGR)
        return "BGR";
    else if (_format == gloo::Texture::Format::RGBA)
        return "RGBA";
    else if (_format == gloo::Texture::Format::BGRA)
        return "BGRA";
    else if (_format == gloo::Texture::Format::RedInteger)
        return "RedInteger";
    else if (_format == gloo::Texture::Format::RGInteger)
        return "RGInteger";
    else if (_format == gloo::Texture::Format::RGBInteger)
        return "RGBInteger";
    else if (_format == gloo::Texture::Format::BGRInteger)
        return "BGRInteger";
    else if (_format == gloo::Texture::Format::RGBAInteger)
        return "RGBAInteger";
    else if (_format == gloo::Texture::Format::BGRAInteger)
        return "BGRAInteger";
    else if (_format == gloo::Texture::Format::StencilIndex)
        return "StencilIndex";
    else if (_format == gloo::Texture::Format::DepthComponent)
        return "DepthComponent";
    else if (_format == gloo::Texture::Format::DepthStencil)
        return "DepthStencil";
    else
        return "nullFormat";
};

const std::string gloo::addon::slotToString(const gloo::Texture::Slot &_slot)
{
    if (_slot == gloo::Texture::Slot::slot00)
        return "slot00";
    else if (_slot == gloo::Texture::Slot::slot01)
        return "slot01";
    else if (_slot == gloo::Texture::Slot::slot02)
        return "slot02";
    else if (_slot == gloo::Texture::Slot::slot03)
        return "slot03";
    else if (_slot == gloo::Texture::Slot::slot04)
        return "slot04";
    else if (_slot == gloo::Texture::Slot::slot05)
        return "slot05";
    else if (_slot == gloo::Texture::Slot::slot06)
        return "slot06";
    else if (_slot == gloo::Texture::Slot::slot07)
        return "slot07";
    else if (_slot == gloo::Texture::Slot::slot08)
        return "slot08";
    else if (_slot == gloo::Texture::Slot::slot09)
        return "slot09";
    else if (_slot == gloo::Texture::Slot::slot10)
        return "slot10";
    else if (_slot == gloo::Texture::Slot::slot11)
        return "slot11";
    else if (_slot == gloo::Texture::Slot::slot12)
        return "slot12";
    else if (_slot == gloo::Texture::Slot::slot13)
        return "slot13";
    else if (_slot == gloo::Texture::Slot::slot14)
        return "slot14";
    else if (_slot == gloo::Texture::Slot::slot15)
        return "slot15";
    else if (_slot == gloo::Texture::Slot::slot16)
        return "slot16";
    else if (_slot == gloo::Texture::Slot::slot17)
        return "slot17";
    else if (_slot == gloo::Texture::Slot::slot18)
        return "slot18";
    else if (_slot == gloo::Texture::Slot::slot19)
        return "slot19";
    else if (_slot == gloo::Texture::Slot::slot20)
        return "slot20";
    else if (_slot == gloo::Texture::Slot::slot21)
        return "slot21";
    else if (_slot == gloo::Texture::Slot::slot22)
        return "slot22";
    else if (_slot == gloo::Texture::Slot::slot23)
        return "slot23";
    else if (_slot == gloo::Texture::Slot::slot24)
        return "slot24";
    else if (_slot == gloo::Texture::Slot::slot25)
        return "slot25";
    else if (_slot == gloo::Texture::Slot::slot26)
        return "slot26";
    else if (_slot == gloo::Texture::Slot::slot27)
        return "slot27";
    else if (_slot == gloo::Texture::Slot::slot28)
        return "slot28";
    else if (_slot == gloo::Texture::Slot::slot29)
        return "slot29";
    else if (_slot == gloo::Texture::Slot::slot30)
        return "slot30";
    else if (_slot == gloo::Texture::Slot::slot31)
        return "slot31";
    else
        return "nullSlot";
};