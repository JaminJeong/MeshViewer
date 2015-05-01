#include "light.h"

namespace RenderEngine {

	///////////////////////////
	//		Light	 		 //
	///////////////////////////
	Light::Light(
		const vec3& position,
		const vec3& direction,
		const Color& diffuseLight,
		const Color& ambientLight,
		const Color& specularLight
	) :
	m_Position(position),
	m_Direction(direction),
	m_DiffuseLight(diffuseLight),
	m_AmbientLight(ambientLight),
	m_SpecularLigt(specularLight)
	{
	}	

	Light::~Light()
	{
	}

	const vec3& Light::GetPosition() const
	{
		return m_Position;
	}

	const vec3& Light::GetDirection() const
	{
		return m_Direction;
	}

	const Color& Light::GetDiffuseLight() const
	{
		return m_DiffuseLight;
	}

	const Color& Light::GetAmbientLight() const
	{
		return m_AmbientLight;
	}

	const Color& Light::GetSpecularLight() const
	{
		return m_SpecularLigt;
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

	Lights::ConstIterator Lights::Begin() const
	{
		return m_Container.begin();
	}

	Lights::ConstIterator Lights::End() const
	{
		return m_Container.end();
	}

	void Lights::Add(const Light* light)
	{
		if (light == nullptr) {
			_ASSERTE(L"NullPtr Error");
		}

		m_Container.push_back(light);
	}
}
