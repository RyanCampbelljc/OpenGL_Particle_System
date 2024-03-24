#pragma once
#include "ConstPropertyNodeReader.hpp"
#include "RandomPropertyNodeReader.hpp"
#include "Utility.hpp"
// @brief best workaround I could think of since PropertyNodeReader
// cannot have virtual template function
class PropertyNodeWrapper
{
public:
	PropertyNodeWrapper(PropertyNodeReader* reader)
		: m_randProp(nullptr)
		, m_constProp(nullptr)
	{
		auto constProp = dynamic_cast<ConstPropertyNodeReader*>(reader);
		if (constProp) {
			m_constProp = constProp;
		} else {
			m_randProp = dynamic_cast<RandomPropertyNodeReader*>(reader);
		}
	}

	~PropertyNodeWrapper()
	{
		if (m_randProp != nullptr)
			delete m_randProp;
		if (m_constProp != nullptr)
			delete m_constProp;
	}
	PropertyNodeWrapper(PropertyNodeWrapper&) = delete;
	PropertyNodeWrapper(PropertyNodeWrapper&&) = delete;

	template<typename T>
	T getValue() const
	{
		if (m_randProp != nullptr)
			return m_randProp->getValue<T>();
		if (m_constProp != nullptr)
			return m_constProp->getValue<T>();
		else {
			throw std::exception("getValue error");
		}
	}

private:
	RandomPropertyNodeReader* m_randProp;
	ConstPropertyNodeReader* m_constProp;
};