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
			const vec4& ambientLight,
			const vec4& specularLigt
		);

        ~Light();

	private:
		vec3 m_Position;
		vec3 m_Direction;
		vec4 m_DiffuseLight;
		vec4 m_AmbientLight;
		vec4 m_SpecularLigt;
	};

    class Lights
    {
	private:
		typedef vector<const Light*> ContainerType;

    public:
        Lights();
        ~Lights();
    
	public:
		void Add(const Light* light);

	private:
		ContainerType m_Container;
    };
}


#endif // LIGHT_H
