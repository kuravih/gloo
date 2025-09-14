#ifndef _GLOO_TEXTURE_H_
#define _GLOO_TEXTURE_H_

#pragma once

#include <glad/glad.h>

namespace gloo
{

    /**
     * Texture class.
     **/
    class Texture
    {
    public:
        /*! Type of texture target */
        enum class Target : GLenum
        {
            Texture1D = GL_TEXTURE_1D,
            Texture2D = GL_TEXTURE_2D,
            Texture3D = GL_TEXTURE_3D,
            Texture1DArray = GL_TEXTURE_1D_ARRAY,
            Texture2DArray = GL_TEXTURE_2D_ARRAY,
            TextureRectangle = GL_TEXTURE_RECTANGLE,
            TextureCubeMap = GL_TEXTURE_CUBE_MAP,
            TextureBuffer = GL_TEXTURE_BUFFER,
            Texture2dMultiSample = GL_TEXTURE_2D_MULTISAMPLE,
            Texture2dMultiSampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
        };
        /*! Type of texture data */
        enum class Type : GLenum
        {
            UnsignedByte = GL_UNSIGNED_BYTE,
            Byte = GL_BYTE,
            UnsignedShort = GL_UNSIGNED_SHORT,
            Short = GL_SHORT,
            UnsignedInt = GL_UNSIGNED_INT,
            Int = GL_INT,
            HalfFloat = GL_HALF_FLOAT,
            Float = GL_FLOAT,
            UnsignedByte332 = GL_UNSIGNED_BYTE_3_3_2,
            UnsignedByte233_Rev = GL_UNSIGNED_BYTE_2_3_3_REV,
            UnsignedShort565 = GL_UNSIGNED_SHORT_5_6_5,
            UnsignedShort565_Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
            UnsignedShort4444 = GL_UNSIGNED_SHORT_4_4_4_4,
            UnsignedShort4444_Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
            UnsignedShort5551 = GL_UNSIGNED_SHORT_5_5_5_1,
            UnsignedShort1555_Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
            UnsignedInt8888 = GL_UNSIGNED_INT_8_8_8_8,
            UnsignedInt8888_Rev = GL_UNSIGNED_INT_8_8_8_8_REV,
            UnsignedInt1010102 = GL_UNSIGNED_INT_10_10_10_2,
            UnsignedInt2101010_Rev = GL_UNSIGNED_INT_2_10_10_10_REV
        };
        /*! Internal format */
        enum class InternalFormat : GLint
        {
            DepthComponent = GL_DEPTH_COMPONENT,
            DepthStencil = GL_DEPTH_STENCIL,
            Red = GL_RED,
            RG = GL_RG,
            RGB = GL_RGB,
            RGBA = GL_RGBA,
            // --------------------------------------------------------------------------------------------------------------
            R8 = GL_R8,
            R8SNorm = GL_R8_SNORM,
            R16 = GL_R16,
            R16SNorm = GL_R16_SNORM,
            RG8 = GL_RG8,
            RG8SNorm = GL_RG8_SNORM,
            RG16 = GL_RG16,
            RG16SNorm = GL_RG16_SNORM,
            R3G3B2 = GL_R3_G3_B2,
            RGB4 = GL_RGB4,
            RGB5 = GL_RGB5,
            RGB8 = GL_RGB8,
            RGB8SNorm = GL_RGB8_SNORM,
            RGB10 = GL_RGB10,
            RGB12 = GL_RGB12,
            RGB16SNorm = GL_RGB16_SNORM,
            RGBA2 = GL_RGBA2,
            RGBA4 = GL_RGBA4,
            RGB5A1 = GL_RGB5_A1,
            RGBA8 = GL_RGBA8,
            RGBA8SNorm = GL_RGBA8_SNORM,
            RGB10A2 = GL_RGB10_A2,
            RGB10A2UI = GL_RGB10_A2UI,
            RGBA12 = GL_RGBA12,
            RGBA16 = GL_RGBA16,
            SRGB8 = GL_SRGB8,
            SRGB8Alpha8 = GL_SRGB8_ALPHA8,
            R16F = GL_R16F,
            RG16F = GL_RG16F,
            RGB16F = GL_RGB16F,
            RGBA16F = GL_RGBA16F,
            R32F = GL_R32F,
            RG32F = GL_RG32F,
            RGB32F = GL_RGB32F,
            RGBA32F = GL_RGBA32F,
            R11FG11FB10F = GL_R11F_G11F_B10F,
            RGB9E5 = GL_RGB9_E5,
            R8I = GL_R8I,
            R8UI = GL_R8UI,
            R16I = GL_R16I,
            R16UI = GL_R16UI,
            R32I = GL_R32I,
            R32UI = GL_R32UI,
            RG8I = GL_RG8I,
            RG8UI = GL_RG8UI,
            RG16I = GL_RG16I,
            RG16UI = GL_RG16UI,
            RG32I = GL_RG32I,
            RG32UI = GL_RG32UI,
            RGB8I = GL_RGB8I,
            RGB8UI = GL_RGB8UI,
            RGB16I = GL_RGB16I,
            RGB16UI = GL_RGB16UI,
            RGB32I = GL_RGB32I,
            RGB32UI = GL_RGB32UI,
            RGBA8I = GL_RGBA8I,
            RGBA8UI = GL_RGBA8UI,
            RGBA16I = GL_RGBA16I,
            RGBA16UI = GL_RGBA16UI,
            RGBA32I = GL_RGBA32I,
            RGBA32UI = GL_RGBA32UI,
            // --------------------------------------------------------------------------------------------------------------
            Compressed_Red = GL_COMPRESSED_RED,
            Compressed_RG = GL_COMPRESSED_RG,
            Compressed_RGB = GL_COMPRESSED_RGB,
            Compressed_RGBA = GL_COMPRESSED_RGBA,
            Compressed_SRGB = GL_COMPRESSED_SRGB,
            Compressed_SRGB_Alpha = GL_COMPRESSED_SRGB_ALPHA,
            Compressed_Red_RGtc1 = GL_COMPRESSED_RED_RGTC1,
            Compressed_Signed_Red_RGtc1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
            Compressed_RG_RGtc2 = GL_COMPRESSED_RG_RGTC2,
            Compressed_Signed_RG_RGtc2 = GL_COMPRESSED_SIGNED_RG_RGTC2
        };
        /*! Format of texture data */
        enum class Format : GLenum
        {
            Red = GL_RED,
            RG = GL_RG,
            RGB = GL_RGB,
            BGR = GL_BGR,
            RGBA = GL_RGBA,
            BGRA = GL_BGRA,
            RedInteger = GL_RED_INTEGER,
            RGInteger = GL_RG_INTEGER,
            RGBInteger = GL_RGB_INTEGER,
            BGRInteger = GL_BGR_INTEGER,
            RGBAInteger = GL_RGBA_INTEGER,
            BGRAInteger = GL_BGRA_INTEGER,
            StencilIndex = GL_STENCIL_INDEX,
            DepthComponent = GL_DEPTH_COMPONENT,
            DepthStencil = GL_DEPTH_STENCIL
        };
        /*! Texture slot */
        enum class Slot : GLenum
        {
            slot00 = GL_TEXTURE0,
            slot01 = GL_TEXTURE1,
            slot02 = GL_TEXTURE2,
            slot03 = GL_TEXTURE3,
            slot04 = GL_TEXTURE4,
            slot05 = GL_TEXTURE5,
            slot06 = GL_TEXTURE6,
            slot07 = GL_TEXTURE7,
            slot08 = GL_TEXTURE8,
            slot09 = GL_TEXTURE9,
            slot10 = GL_TEXTURE10,
            slot11 = GL_TEXTURE11,
            slot12 = GL_TEXTURE12,
            slot13 = GL_TEXTURE13,
            slot14 = GL_TEXTURE14,
            slot15 = GL_TEXTURE15,
            slot16 = GL_TEXTURE16,
            slot17 = GL_TEXTURE17,
            slot18 = GL_TEXTURE18,
            slot19 = GL_TEXTURE19,
            slot20 = GL_TEXTURE20,
            slot21 = GL_TEXTURE21,
            slot22 = GL_TEXTURE22,
            slot23 = GL_TEXTURE23,
            slot24 = GL_TEXTURE24,
            slot25 = GL_TEXTURE25,
            slot26 = GL_TEXTURE26,
            slot27 = GL_TEXTURE27,
            slot28 = GL_TEXTURE28,
            slot29 = GL_TEXTURE29,
            slot30 = GL_TEXTURE30,
            slot31 = GL_TEXTURE31
        };

    private:
        GLuint id;

    public:
        Target target;
        Type type;
        InternalFormat internalFormat;
        Format format;
        Slot slot;
        int width, height;
        float aspectRatio;
        Texture() = default;
        Texture(const void *_data, int _width, int _height, Type _type, InternalFormat _internalFormat, Format _format, Slot _slot, Target _target);
        Texture(int _width, int _height, Type _type, InternalFormat _internalFormat, Format _format, Slot _slot, Target _target);
        ~Texture()
        {
            Delete();
        }
        /**
         * Cast to GLuint.
         * Lets you use the objects of Shader class in regular opengl calls.
         **/
        operator GLuint() const
        {
            return id;
        }
        void Bind();
        void Unbind();
        void Delete();
        void Update(const void *_data);
        void Update();
        void Activate();
        /**
         * Deactivate the Shader.
         **/
        static void DEACTIVATE()
        {
            glActiveTexture(0);
        }
    };

}

#endif // _GLOO_TEXTURE_H_