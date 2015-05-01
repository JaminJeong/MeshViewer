#ifndef LIGHT_H
#define LIGHT_H

#include "renderengine.h"

namespace RenderEngine {

    class Light
    {
	public:
		Light(
			const vec3& position,
			const vec3& direction,
			const Color& diffuseLight,
			const Color& ambientLight,
			const Color& specularLight
		);

        ~Light();

	public:
		const vec3& GetPosition() const;
		const vec3& GetDirection() const;
		const Color& GetDiffuseLight() const;
		const Color& GetAmbientLight() const;
		const Color& GetSpecularLight() const;

	private:
		vec3 m_Position;
		vec3 m_Direction;
		Color m_DiffuseLight;
		Color m_AmbientLight;
		Color m_SpecularLigt;
	};

    class Lights
    {
	private:
		typedef vector<const Light*> ContainerType;

    public:
        Lights();
        ~Lights();
    
	public:
		typedef ContainerType::const_iterator ConstIterator;

	public:
		ConstIterator Begin() const;
		ConstIterator End() const;

		void Add(const Light* light);

	private:
		ContainerType m_Container;
    };
}


#endif // LIGHT_H
