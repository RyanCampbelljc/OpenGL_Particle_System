//-----------------------------------------------------------------------------
// File:			FadeInAndOut.cpp
// Original Author:	Ryan Campbell
//-----------------------------------------------------------------------------
#include "affectors/FadeInAndOut.hpp"

FadeInAndOut::FadeInAndOut(float end)
	: m_end(end)
{
}

void FadeInAndOut::apply(Particle* p, float dt) const
{
	// This formula just allows the fade to be faded over life time
	// but not having to start at a fade value of 1. It will start at whatever value
	// is given to it in the spawn properties.
	while (p != nullptr) {
		float startFade = p->fade.start;
		auto scaledLifeTime = p->scaledLifeTime;
		if (scaledLifeTime <= 0.5f) {
			p->fade.value = startFade + ((m_end - startFade) * (p->scaledLifeTime * 2));
		} else { // scales from m_end to 0 evenly in second half of particles life
			p->fade.value = m_end + ((0.0f - m_end) * ((p->scaledLifeTime - 0.5f) * 2.0f));
		}
		p = p->next;
	}
}
