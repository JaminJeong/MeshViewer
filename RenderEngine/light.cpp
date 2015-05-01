#include "light.h"

namespace RenderEngine {

	///////////////////////////
	//		Light	 		 //
	///////////////////////////
	Light::Light(
		const vec3& position,
		const vec3& direction,
		const vec4& diffuseLight,
		const vec4& ambientLight,
		const vec4& specularLigt
	) :
	m_Position(position),
	m_Direction(direction),
	m_DiffuseLight(diffuseLight),
	m_AmbientLight(ambientLight),
	m_SpecularLigt(specularLigt)
	{
	}	

	Light::~Light()
	{
	}
	
	///////////////////////////
	//		Lights	 		 //
	///////////////////////////
	Lights::Lights()
	{
	}

	Lights::~Lights()
	{
		DeletePointer<ContainerType>(m_Container);
	}

	void Lights::Add(const Light* light)
	{
		if (light == nullptr) {
			_ASSERTE(L"NullPtr Error");
		}

		m_Container.push_back(light);
	}
}
