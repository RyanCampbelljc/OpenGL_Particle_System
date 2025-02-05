//-----------------------------------------------------------------------------
// File:			W_Types.h
// Original Author:	Gordon Wood
//
// Common types throughout wolf (and some defines too)
//-----------------------------------------------------------------------------
#pragma once
#ifndef W_TYPES_H
#define W_TYPES_H

#define GLEW_NO_GLU
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <string>
#include <unordered_map>

using uint = unsigned int;
namespace wolf
{
#ifndef MATH_PI
#define MATH_PI 3.141592654f
#endif

inline float min(float a, float b)
{
	return a < b ? a : b;
}

inline float max(float a, float b)
{
	return a > b ? a : b;
}

inline float randFloat()
{
	return (float)rand() / (float)RAND_MAX;
}

inline float randFloat(float min, float max)
{
	return min + (max - min) * randFloat();
}

// Our attribute indices
enum Attribute {
	AT_Position = 0,
	AT_Color,
	AT_TexCoord1,
	AT_TexCoord2,
	AT_TexCoord3,
	AT_TexCoord4,
	AT_TexCoord5,
	AT_TexCoord6,
	AT_TexCoord7,
	AT_TexCoord8,
	AT_Normal,
	AT_Tangent,
	AT_BiTangent,
	AT_BoneIndices,
	AT_BoneWeights,
	AT_NUM_ATTRIBS
};

enum ComponentType {
	CT_Float = 0,
	CT_Int,
	CT_UInt,
	CT_Byte,
	CT_UByte,
	CT_UByte4,
	CT_ByteNorm,
	CT_UByteNorm,
	CT_Short,
	CT_UShort,
	CT_ShortNorm,
	CT_UShortNorm,
	AT_NUM_COMPONENT_TYPES,
	CT_Invalid
};

enum DepthFunc {
	DF_Never,
	DF_Less,
	DF_LessEqual,
	DF_Equal,
	DF_Greater,
	DF_GreaterEqual,
	DF_NotEqual,
	DF_Always,
	DF_NUM_DEPTH_FUNCS
};

enum BlendMode {
	BM_SrcAlpha,
	BM_One,
	BM_SrcColor,
	BM_OneMinusSrcColor,
	BM_OneMinusSrcAlpha,
	BM_DstAlpha,
	BM_OneMinusDstAlpha,
	BM_DstColor,
	BM_OneMinusDstColor,
	BM_Zero,
	BM_NUM_BLEND_MODES
};

static const std::unordered_map<std::string, int> stringToBlendMode = {
	{"SrcAlpha", 0},         {"One", 1},      {"SrcColor", 2},         {"OneMinusSrcColor", 3},
	{"OneMinusSrcAlpha", 4}, {"DstAlpha", 5}, {"OneMinusDstAlpha", 6}, {"DstColor", 7},
	{"OneMinusDstColor", 8}, {"Zero", 9}};

enum BlendEquation { BE_Add, BE_Subtract, BE_ReverseSubtract, BE_NUM_BLEND_EQUATIONS };

struct Color4 {
	float r, g, b, a;

	Color4(float p_fR, float p_fG, float p_fB, float p_fA)
		: r(p_fR)
		, g(p_fG)
		, b(p_fB)
		, a(p_fA)
	{
	}
};

#ifndef PI
#define PI 3.141592653589793238f
#endif

#ifndef PI_2
#define PI_2 1.57079632679f
#endif

#define DEG_TO_RAD(d) (((d) / 180.0f) * PI)

} // namespace wolf

#endif
